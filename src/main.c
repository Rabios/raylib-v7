// Written by Rabia Alhaffar in 7/February/2021
// raylib-v7, JavaScript bindings for raylib powered by v7 JavaScript engine!
// Updated: 25/February/2021
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <raylib.h>
#include <rlights_js.h>
#include <easings_js.h>
#include <v7/v7.h>
#include <get_set.h>
#include <types.h>
#include <core_js.h>
#include <shapes_js.h>
#include <vars_js.h>
#include <raymath_js.h>
#include <gestures_js.h>
#include <raygui_js.h>
#include <shaders_js.h>
#include <text_js.h>
#include <textures_js.h>
#include <audio_js.h>
#include <rlgl_js.h>
#include <physac_js.h>
#include <models_js.h>
//#include <rnet_js.h>
#include <miniz/miniz.c>
#include <miniz/miniz.h>

#ifdef WIN32
//#include <windows.h>
#include <stdint.h>
#define MAX_PATH 4096
uint32_t GetModuleFileNameA(void *, const char *, uint32_t );


#else
#include <unistd.h>
#endif

#ifdef WIN32
#define stat _stat
#include <dirent/dirent.h>
#ifndef strcasecmp
#define strcasecmp strcmpi
#endif
#else
#include <dirent.h>
#endif

#ifndef RAYLIB_VERSION
#define RAYLIB_VERSION "3.5"
#endif

/* Use platform specific functions. */
static inline FILE *open_self_platform(void)
{
  #ifdef WIN32
  char path[MAX_PATH + 1];
  memset(path, '\0', sizeof(path));

  GetModuleFileNameA(NULL, path, MAX_PATH);
  return fopen(path, "rb");
  #elif defined(__linux__)
  return fopen("/proc/self/exe", "r");
  #else
  /* TODO: Implement for Darwin and BSD hosts. */
  return NULL; /* fallback to argv0 */
  #endif
}

static FILE *v7_open_self(const char *argv0)
{
  FILE *self = open_self_platform();

  if (self == NULL)
    self = fopen(argv0, "rb");

  return self;
}

static mz_zip_archive zip_file;

static inline void append_file(FILE* dst, FILE* src)
{
    size_t count;
    do {
        uint8_t buffer[4096];
        count = fread(buffer, 1, 4096, src);
        fwrite(buffer, 1, count, dst);
    } while (count == 4096);
}

static inline int build_executable(const char* argv0, const char* input_path)
{
    printf("Create new executable from %s\n", input_path);

    struct stat st;
    int result = stat(input_path, &st);
    if (result) {
        printf("%s: Can't get file information.\n", input_path);
        return 1;
    }

    size_t arg_len = strlen(input_path);
    size_t len = arg_len + 5; // + ".exe\0" (or _out\0)

    char* output_path = malloc(len);

    strcpy(output_path, input_path);

    if (output_path[arg_len - 1] == '/') {
        // Remove trailing '/'.
        output_path[arg_len - 1] = '\0';
        arg_len--;
    }

#ifndef WIN32
    strncpy(output_path + arg_len, "_out", 5);
#else
    strncpy(output_path + arg_len, ".exe", 5);
#endif

    FILE* output = fopen(output_path, "wb");
    if (output == NULL) {
        printf("Can't open %s for writing.\n", output_path);
        return -1;
    }

    FILE* self = v7_open_self(argv0);

    // Copy self into output.
    append_file(output, self);
    fclose(self);

    if (S_ISREG(st.st_mode)) {
        // Consider input as a bare bundle, just append file to get output.
        FILE* input = fopen(input_path, "rb");

        append_file(output, input);
        fclose(input);
    }
    else if (S_ISDIR(st.st_mode)) {
        // We need to explore the directory and write each file to a zip file.
        mz_zip_archive zip;
        mz_zip_zero_struct(&zip);

        if (!mz_zip_writer_init_cfile(&zip, output, 0)) {
            puts("Can't initialize zip writter inside output.");
            return -1;
        }

        DIR* d = opendirX(input_path);
        chdir(input_path);

        struct dirent* entry;

        // NOTE: Hardcoded 512 path limit.
        char dest_path[512];

        while ((entry = readdirX(d))) {
            char* original_path = entry->d_name;
            memset(dest_path, 0, 512);

            struct stat st;
            if (stat(original_path, &st)) {
                printf("Skip %s (stat() failed)\n", original_path);
                continue;
            }

            if (!S_ISREG(st.st_mode)) {
                printf("Skip %s (not a file)\n", original_path);
                continue;
            }

            size_t len = strlen(original_path);
            if (len > 512) {
                printf("Skipping %s: path too long\n", original_path);
                continue;
            }

            if (len > 3 && strcmp(original_path + len - 3, ".js") == 0) {
                len -= 3;
            }

            strncpy(dest_path, original_path, len);

            printf("Add %s (original: %s)...\n", dest_path, original_path);

            if (!mz_zip_writer_add_file(&zip, dest_path, original_path, NULL, 0,
                MZ_BEST_COMPRESSION)) {
                printf("miniz error: %x\n", mz_zip_get_last_error(&zip));
            }
        }

        closedirX(d);

        puts("Finalizing zip archive...");

        if (!mz_zip_writer_finalize_archive(&zip)) {
            puts("Can't finalize archive.");
            return -1;
        }
        mz_zip_end(&zip);

#ifndef WIN32
        puts("Set execute bit.");
        chmod(output_path, 0777);
#endif
    }
    free(output_path);
    return 0;
}

static char* load_mod_zip_func(char* name)
{
    int index = mz_zip_reader_locate_file(&zip_file, name, NULL, 0);
    if (index == -1) {
        printf("RAYLIB-V7: %s: File not found.\n", name);
        return NULL;
    }

    mz_zip_archive_file_stat stat;
    if (!mz_zip_reader_file_stat(&zip_file, index, &stat)) {
        printf("RAYLIB-V7: %s: Can't get file information.\n", name);
        return NULL;
    }

    size_t size = stat.m_uncomp_size;
    char* buffer = malloc(size + 1);
    if (buffer == NULL) {
        printf("RAYLIB-V7: %s: Can't allocate file buffer.\n", name);
        return NULL;
    }
    buffer[size] = '\0';

    mz_zip_reader_extract_to_mem(&zip_file, index, buffer, size, 0);
    return buffer;
}

int main(int argc, char** argv) {
    enum v7_err err_code = V7_OK;
    struct v7* v7 = v7_create();
    v7_val_t result;

    raylib_v7_load_core(v7);
    raylib_v7_load_shapes(v7);
    raylib_v7_load_types(v7);
    raylib_v7_load_colors(v7);
    raylib_v7_load_variables(v7);
    raylib_v7_load_rlights(v7);
    raylib_v7_load_easings(v7);
    raylib_v7_load_raymath(v7);
    raylib_v7_load_gestures(v7);
    raylib_v7_load_raygui(v7);
    raylib_v7_load_shaders(v7);
    raylib_v7_load_text(v7);
    raylib_v7_load_textures(v7);
    raylib_v7_load_audio(v7);
    raylib_v7_load_rlgl(v7);
    raylib_v7_load_physac(v7);
    raylib_v7_load_models(v7);
    //raylib_v7_load_rnet(v7);

    mz_zip_zero_struct(&zip_file);
    if (mz_zip_reader_init_cfile(&zip_file, v7_open_self(argv[0]), 0, 0)) {
        char* code = load_mod_zip_func("main");
        if (code != NULL) {
            v7_exec(v7, code, &result);
            if (err_code != V7_OK) {
                v7_print_error(stderr, v7, "ERROR", result);
            }
            free(code);
        }
    }
    if (argc >= 1) {
        if (TextIsEqual(argv[1], "-h") || TextIsEqual(argv[1], "--help")) {
            printf("%s\n\n\0", "raylib-v7 USAGE:");
            printf("%s         %s\n\0", "raylib-v7 --run/-r [file]", "Runs JavaScript file");
            printf("%s       %s\n\0", "raylib-v7 --rundir/-d [dir]", "Runs directory of project containing main.js");
            printf("%s            %s\n\0", "raylib-v7 --version/-v", "Prints used raylib version");
            printf("%s        %s\n\0", "raylib-v7 --eval/-e [code]", "Evals JavaScript code (And executes it)");
            printf("%s     %s\n\0", "raylib-v7 --compile/-c [file]", "Builds executable of your JavaScript code");
            printf("%s               %s\n\0", "raylib-v7 --help/-h", "Shows help for using raylib-v7");

        }
        else if (TextIsEqual(argv[1], "-v") || TextIsEqual(argv[1], "--version")) {
            printf("%s%s\n\0", "RAYLIB VERSION: ", RAYLIB_VERSION);
            printf("%s%s\n\0", "V7 JAVASCRIPT ENGINE VERSION: ", V7_VERSION);

        }
        else if (TextIsEqual(argv[1], "-r") || TextIsEqual(argv[1], "--run")) {
            if (argv[2] != NULL) {
                err_code = v7_exec_file(v7, argv[2], &result);
                if (err_code != V7_OK) {
                    v7_print_error(stderr, v7, "ERROR", result);
                }
            }

        }
        else if (TextIsEqual(argv[1], "-d") || TextIsEqual(argv[1], "--rundir")) {
            if (argv[2] != NULL) {
                if (ChangeDirectory(argv[2])) {
                    err_code = v7_exec_file(v7, "main.js", &result);
                    if (err_code != V7_OK) {
                        v7_print_error(stderr, v7, "ERROR", result);
                    }
                }
            }

        }
        else if (TextIsEqual(argv[1], "-e") || TextIsEqual(argv[1], "--eval")) {
            if (argv[2] != NULL) {
                err_code = v7_exec(v7, argv[2], &result);
                if (err_code != V7_OK) {
                    v7_print_error(stderr, v7, "ERROR", result);
                }
            }

        }
        else if (TextIsEqual(argv[1], "-c") || TextIsEqual(argv[1], "--compile")) {
            if (argv[2] != NULL) {
                if (build_executable(argv[0], argv[2]) != -1) {
                    printf("RAYLIB-V7: SUCCESSED BUILDING EXECUTABLE...\n\0");
                }
            }
        }
    } else {
        printf("RAYLIB-V7: NO ARGUMENTS PASSED, Type '-h' or `--help` FOR HELP!\n\0");
    }

    v7_destroy(v7);
    exit((int)err_code);
}
