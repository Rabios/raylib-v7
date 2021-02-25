#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>
#include <core_js.h>

static inline enum v7_err js_init_window(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 2);
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    char* title = v7_get_string(v7, &strarg, &lenstr);
    InitWindow(width, height, title);
    return V7_OK;
}

static inline enum v7_err js_window_should_close(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)WindowShouldClose());
    return V7_OK;
}

static inline enum v7_err js_close_window(void) {
    CloseWindow();
    return V7_OK;
}

static inline enum v7_err js_window_ready(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsWindowReady());
    return V7_OK;
}

static inline enum v7_err js_window_fullscreen(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsWindowFullscreen());
    return V7_OK;
}

static inline enum v7_err js_window_maximized(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsWindowMaximized());
    return V7_OK;
}

static inline enum v7_err js_window_minimized(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsWindowMinimized());
    return V7_OK;
}

static inline enum v7_err js_window_focused(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsWindowFocused());
    return V7_OK;
}

static inline enum v7_err js_window_resized(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsWindowResized());
    return V7_OK;
}

static inline enum v7_err js_window_state(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsWindowState(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_set_window_state(struct v7* v7, v7_val_t* res) {
    SetWindowState(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_clear_window_state(struct v7* v7, v7_val_t* res) {
    ClearWindowState(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_toggle_fullscreen(void) {
    ToggleFullscreen();
    return V7_OK;
}

static inline enum v7_err js_maximize_window(void) {
    MaximizeWindow();
    return V7_OK;
}

static inline enum v7_err js_minimize_window(void) {
    MinimizeWindow();
    return V7_OK;
}

static inline enum v7_err js_restore_window(void) {
    RestoreWindow();
    return V7_OK;
}

static inline enum v7_err js_set_window_icon(struct v7* v7) {
    Image icon = js_get_image(v7, 0);
    SetWindowIcon(icon);
    return V7_OK;
}

static inline enum v7_err js_set_window_title(struct v7* v7) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    char* title = v7_get_string(v7, &strarg, &lenstr);
    SetWindowTitle(title);
    return V7_OK;
}

static inline enum v7_err js_set_window_position(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    SetWindowPosition(x, y);
    return V7_OK;
}

static inline enum v7_err js_set_window_monitor(struct v7* v7) {
    int monitor = v7_get_int(v7, v7_arg(v7, 0));
    SetWindowMonitor(monitor);
    return V7_OK;
}

static inline enum v7_err js_set_window_min_size(struct v7* v7) {
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    SetWindowMinSize(width, height);
    return V7_OK;
}

static inline enum v7_err js_set_window_size(struct v7* v7) {
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    SetWindowSize(width, height);
    return V7_OK;
}

static inline enum v7_err js_get_window_handle(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_foreign(v7, GetWindowHandle());
    return V7_OK;
}

static inline enum v7_err js_get_screen_width(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetScreenWidth());
    return V7_OK;
}

static inline enum v7_err js_get_screen_height(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetScreenHeight());
    return V7_OK;
}

static inline enum v7_err js_get_monitor_count(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMonitorCount());
    return V7_OK;
}

static inline enum v7_err js_get_monitor_position(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, GetMonitorPosition(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_monitor_width(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMonitorWidth(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_monitor_height(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMonitorHeight(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_monitor_physical_width(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMonitorPhysicalWidth(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_monitor_physical_height(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMonitorPhysicalHeight(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_monitor_refresh_rate(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMonitorRefreshRate(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_window_position(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, GetWindowPosition(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_window_scale_dpi(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, GetWindowScaleDPI(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_monitor_name(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_string(v7, GetMonitorName(v7_get_int(v7, v7_arg(v7, 0))), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_set_clipboard_text(struct v7* v7) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    SetClipboardText(v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_get_clipboard_text(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_string(v7, GetClipboardText(), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_show_cursor(void) {
    ShowCursor();
    return V7_OK;
}

static inline enum v7_err js_hide_cursor(void) {
    HideCursor();
    return V7_OK;
}

static inline enum v7_err js_cursor_hidden(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsCursorHidden());
    return V7_OK;
}

static inline enum v7_err js_enable_cursor(void) {
    EnableCursor();
    return V7_OK;
}

static inline enum v7_err js_disable_cursor(void) {
    DisableCursor();
    return V7_OK;
}

static inline enum v7_err js_cursor_onscreen(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsCursorOnScreen());
    return V7_OK;
}

static inline enum v7_err js_clear_background(struct v7* v7) {
    Color color = js_get_color(v7, 0);
    ClearBackground(color);
    return V7_OK;
}

static inline enum v7_err js_begin_drawing(struct v7* v7) {
    BeginDrawing();
    return V7_OK;
}

static inline enum v7_err js_end_drawing(void) {
    EndDrawing();
    return V7_OK;
}

static inline enum v7_err js_begin_mode2d(struct v7* v7) {
    BeginMode2D(js_get_camera2d(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_end_mode2d(void) {
    EndMode2D();
    return V7_OK;
}

static inline enum v7_err js_begin_mode3d(struct v7* v7) {
    BeginMode3D(js_get_camera3d(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_end_mode3d(void) {
    EndMode3D();
    return V7_OK;
}

static inline enum v7_err js_begin_texture_mode(struct v7* v7) {
    BeginTextureMode(js_get_render_texture_2d(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_end_texture_mode(void) {
    EndTextureMode();
    return V7_OK;
}

static inline enum v7_err js_begin_scissor_mode(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    int width = v7_get_int(v7, v7_arg(v7, 2));
    int height = v7_get_int(v7, v7_arg(v7, 3));
    BeginScissorMode(x, y, width, height);
    return V7_OK;
}

static inline enum v7_err js_end_scissor_mode(void) {
    EndScissorMode();
    return V7_OK;
}

static inline enum v7_err js_get_mouse_ray(struct v7* v7, v7_val_t* res) {
    Vector2 mousePosition = js_get_vec2(v7, 0);
    Camera camera = js_get_camera3d(v7, 1);
    js_return_ray(v7, res, GetMouseRay(mousePosition, camera));
    return V7_OK;
}

static inline enum v7_err js_get_camera_matrix(struct v7* v7, v7_val_t* res) {
    Camera camera = js_get_camera3d(v7, 0);
    js_return_matrix(v7, res, GetCameraMatrix(camera));
    return V7_OK;
}

static inline enum v7_err js_get_camera_matrix2d(struct v7* v7, v7_val_t* res) {
    Camera2D camera = js_get_camera2d(v7, 0);
    js_return_matrix(v7, res, GetCameraMatrix2D(camera));
    return V7_OK;
}

static inline enum v7_err js_get_world_to_screen(struct v7* v7, v7_val_t* res) {
    Vector3 position = js_get_vec3(v7, 0);
    Camera camera = js_get_camera3d(v7, 1);
    js_return_vec2(v7, res, GetWorldToScreen(position, camera));
    return V7_OK;
}

static inline enum v7_err js_get_world_to_screen_ex(struct v7* v7, v7_val_t* res) {
    Vector3 position = js_get_vec3(v7, 0);
    Camera camera = js_get_camera3d(v7, 1);
    int width = v7_get_int(v7, v7_arg(v7, 2));
    int height = v7_get_int(v7, v7_arg(v7, 3));
    js_return_vec2(v7, res, GetWorldToScreenEx(position, camera, width, height));
    return V7_OK;
}

static inline enum v7_err js_get_world_to_screen2d(struct v7* v7, v7_val_t* res) {
    Vector2 position = js_get_vec2(v7, 0);
    Camera2D camera = js_get_camera2d(v7, 1);
    js_return_vec2(v7, res, GetWorldToScreen2D(position, camera));
    return V7_OK;
}

static inline enum v7_err js_get_screen_to_world2d(struct v7* v7, v7_val_t* res) {
    Vector2 position = js_get_vec2(v7, 0);
    Camera2D camera = js_get_camera2d(v7, 1);
    js_return_vec2(v7, res, GetScreenToWorld2D(position, camera));
    return V7_OK;
}

static inline enum v7_err js_set_target_fps(struct v7* v7) {
    int fps = v7_get_int(v7, v7_arg(v7, 0));
    SetTargetFPS(fps);
    return V7_OK;
}

static inline enum v7_err js_get_fps(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetFPS());
    return V7_OK;
}

static inline enum v7_err js_get_frame_time(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetFrameTime());
    return V7_OK;
}

static inline enum v7_err js_get_time(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetTime());
    return V7_OK;
}

static inline enum v7_err js_set_config_flags(struct v7* v7) {
    SetConfigFlags(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_set_tracelog_level(struct v7* v7) {
    SetTraceLogLevel(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_set_tracelog_exit(struct v7* v7) {
    SetTraceLogExit(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_set_tracelog_callback(struct v7* v7) {
    v7_val_t* args = v7_get_arguments(v7);
    SetTraceLogCallback(args[0]);
    return V7_OK;
}

static inline enum v7_err js_tracelog(struct v7* v7) {
    v7_val_t* args = v7_get_arguments(v7);
    v7_del(v7, args, "0", ~0);
    v7_del(v7, args, "1", ~0);
    v7_val_t strarg = v7_arg(v7, 1);
    size_t lenstr;
    TraceLog(v7_get_int(v7, v7_arg(v7, 0)), v7_get_string(v7, &strarg, &lenstr), args);
    return V7_OK;
}

static inline enum v7_err js_memalloc(struct v7* v7, v7_val_t* res) {
    int size = v7_get_int(v7, v7_arg(v7, 0));
    *res = v7_mk_foreign(v7, MemAlloc(size));
    return V7_OK;
}

static inline enum v7_err js_memfree(struct v7* v7) {
    MemFree(v7_get_ptr(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_take_screenshot(struct v7* v7) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    TakeScreenshot(v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_get_random_value(struct v7* v7, v7_val_t* res) {
    int min = v7_get_int(v7, v7_arg(v7, 0));
    int max = v7_get_int(v7, v7_arg(v7, 1));
    *res = v7_mk_number(v7, GetRandomValue(min, max));
    return V7_OK;
}

static inline enum v7_err js_load_file_data(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_foreign(v7, LoadFileData(v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_unload_file_data(struct v7* v7) {
    UnloadFileData(v7_get_ptr(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_save_file_data(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_boolean(v7, (int)SaveFileData(v7_get_string(v7, &strarg, &lenstr), v7_get_ptr(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_load_file_text(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_string(v7, LoadFileText(v7_get_string(v7, &strarg, &lenstr)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_unload_file_text(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    UnloadFileText(v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_save_file_text(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr0;
    v7_val_t strarg1 = v7_arg(v7, 1);
    size_t lenstr1;
    *res = v7_mk_boolean(v7, (int)SaveFileText(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1)));
    return V7_OK;
}

static inline enum v7_err js_file_exists(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_boolean(v7, (int)FileExists(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_directory_exists(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_boolean(v7, (int)DirectoryExists(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_is_file_extension(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr0;
    v7_val_t strarg1 = v7_arg(v7, 1);
    size_t lenstr1;
    *res = v7_mk_boolean(v7, (int)IsFileExtension(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1)));
    return V7_OK;
}

static inline enum v7_err js_get_file_extension(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_string(v7, GetFileExtension(v7_get_string(v7, &strarg, &lenstr)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_get_filename(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_string(v7, GetFileName(v7_get_string(v7, &strarg, &lenstr)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_get_filename_without_ext(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_string(v7, GetFileNameWithoutExt(v7_get_string(v7, &strarg, &lenstr)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_get_directory_path(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_string(v7, GetDirectoryPath(v7_get_string(v7, &strarg, &lenstr)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_get_prev_directory_path(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_string(v7, GetPrevDirectoryPath(v7_get_string(v7, &strarg, &lenstr)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_get_working_directory(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_string(v7, GetWorkingDirectory(), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_get_directory_files(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    int count = v7_get_int(v7, v7_arg(v7, 1));
    *res = v7_mk_array(v7); 
    char** files = GetDirectoryFiles(v7_get_string(v7, &strarg, &lenstr), &count);
    for (int i = 0; i < count; i++) v7_array_push(v7, *res, v7_mk_string(v7, files[i], ~0, 0));
    return V7_OK;
}

static inline enum v7_err js_clear_directory_files(void) {
    ClearDirectoryFiles();
    return V7_OK;
}

static inline enum v7_err js_change_directory(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_boolean(v7, (int)ChangeDirectory(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_file_dropped(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsFileDropped());
    return V7_OK;
}

static inline enum v7_err js_get_dropped_files(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_array(v7);
    int count = v7_get_int(v7, v7_arg(v7, 0));
    char **dropped_files = GetDroppedFiles(&count);
    for (int i = 0; i < count; i++) {
        v7_array_push(v7, *res, v7_mk_string(v7, dropped_files[i], ~0, 0));
    }
    return V7_OK;
}

static inline enum v7_err js_clear_dropped_files(void) {
    ClearDroppedFiles();
    return V7_OK;
}

static inline enum v7_err js_get_file_mod_time(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_number(v7, GetFileModTime(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_compress_data(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_string(v7, CompressData(v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_decompress_data(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    *res = v7_mk_string(v7, DecompressData(v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_save_storage_value(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)SaveStorageValue(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_load_storage_value(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (int)LoadStorageValue(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_open_url(struct v7* v7) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    OpenURL(v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_key_pressed(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsKeyPressed(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_key_down(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsKeyDown(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_key_released(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsKeyReleased(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_key_up(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsKeyUp(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_set_exit_key(struct v7* v7, v7_val_t* res) {
    SetExitKey(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_get_key_pressed(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetKeyPressed());
    return V7_OK;
}

static inline enum v7_err js_get_char_pressed(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetCharPressed());
    return V7_OK;
}

static inline enum v7_err js_gamepad_available(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, IsGamepadAvailable(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_gamepad_name(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, IsGamepadName(v7_get_int(v7, v7_arg(v7, 0)), v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_get_gamepad_name(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_string(v7, GetGamepadName(v7_get_int(v7, v7_arg(v7, 0))), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_gamepad_button_pressed(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsGamepadButtonPressed(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_gamepad_button_down(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsGamepadButtonDown(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_gamepad_button_released(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsGamepadButtonReleased(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_gamepad_button_up(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsGamepadButtonUp(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_get_gamepad_button_pressed(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (int)GetGamepadButtonPressed());
    return V7_OK;
}

static inline enum v7_err js_get_gamepad_axis_count(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (int)GetGamepadAxisCount(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_gamepad_axis_movement(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetGamepadAxisMovement(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_mouse_button_pressed(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsMouseButtonPressed(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_mouse_button_down(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsMouseButtonDown(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_mouse_button_released(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsMouseButtonReleased(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_mouse_button_up(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsMouseButtonUp(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_mouse_x(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMouseX());
    return V7_OK;
}

static inline enum v7_err js_get_mouse_y(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMouseY());
    return V7_OK;
}

static inline enum v7_err js_get_mouse_position(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, GetMousePosition());
    return V7_OK;
}

static inline enum v7_err js_set_mouse_position(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    SetMousePosition(x, y);
    return V7_OK;
}

static inline enum v7_err js_set_mouse_offset(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    SetMouseOffset(x, y);
    return V7_OK;
}

static inline enum v7_err js_set_mouse_scale(struct v7* v7) {
    int x = v7_get_int(v7, v7_arg(v7, 0));
    int y = v7_get_int(v7, v7_arg(v7, 1));
    SetMouseScale(x, y);
    return V7_OK;
}

static inline enum v7_err js_get_mouse_wheel_move(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMouseWheelMove());
    return V7_OK;
}

static inline enum v7_err js_get_mouse_cursor(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMouseCursor());
    return V7_OK;
}

static inline enum v7_err js_set_mouse_cursor(struct v7* v7) {
    SetMouseCursor(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_get_touch_x(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetTouchX());
    return V7_OK;
}

static inline enum v7_err js_get_touch_y(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetTouchY());
    return V7_OK;
}

static inline enum v7_err js_get_touch_position(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, GetTouchPosition(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_set_gestures_enabled(struct v7* v7) {
    SetGesturesEnabled(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_gesture_detected(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsGestureDetected(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_gesture_detected(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetGestureDetected());
    return V7_OK;
}

static inline enum v7_err js_get_touch_points_count(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetTouchPointsCount());
    return V7_OK;
}

static inline enum v7_err js_get_gesture_hold_duration(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetGestureHoldDuration());
    return V7_OK;
}

static inline enum v7_err js_get_gesture_drag_vector(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, GetGestureDragVector());
    return V7_OK;
}

static inline enum v7_err js_get_gesture_drag_angle(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetGestureDragAngle());
    return V7_OK;
}

static inline enum v7_err js_get_gesture_pinch_vector(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, GetGesturePinchVector());
    return V7_OK;
}

static inline enum v7_err js_get_gesture_pinch_angle(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetGesturePinchAngle());
    return V7_OK;
}

static inline enum v7_err js_set_camera_mode(struct v7* v7) {
    SetCameraMode(js_get_camera3d(v7, 0), v7_get_int(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_update_camera(struct v7* v7) {
    Camera camera = js_get_camera3d(v7, 0);
    UpdateCamera(&camera);
    js_push_vec3(v7, v7_arg(v7, 0), "position", camera.position);
    js_push_vec3(v7, v7_arg(v7, 0), "target", camera.target);
    js_push_vec3(v7, v7_arg(v7, 0), "up", camera.up);
    js_push_key(v7, v7_arg(v7, 0), "fovy", camera.fovy);
    js_push_key(v7, v7_arg(v7, 0), "type", camera.type);
    return V7_OK;
}

static inline enum v7_err js_set_camera_pan_control(struct v7* v7) {
    SetCameraPanControl(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_set_camera_alt_control(struct v7* v7) {
    SetCameraAltControl(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_set_camera_smooth_zoom_control(struct v7* v7) {
    SetCameraSmoothZoomControl(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_set_camera_move_controls(struct v7* v7) {
    int keyFront = v7_get_int(v7, v7_arg(v7, 0));
    int keyBack = v7_get_int(v7, v7_arg(v7, 1));
    int keyRight = v7_get_int(v7, v7_arg(v7, 2));
    int keyLeft = v7_get_int(v7, v7_arg(v7, 3));
    int keyUp = v7_get_int(v7, v7_arg(v7, 4));
    int keyDown = v7_get_int(v7, v7_arg(v7, 5));
    SetCameraMoveControls(keyFront, keyBack, keyRight, keyLeft, keyUp, keyDown);
    return V7_OK;
}

void raylib_v7_load_core(struct v7* v7) {
    v7_set_method(v7, v7_get_global(v7), "InitWindow", &js_init_window);
    v7_set_method(v7, v7_get_global(v7), "WindowShouldClose", &js_window_should_close);
    v7_set_method(v7, v7_get_global(v7), "CloseWindow", &js_close_window);
    v7_set_method(v7, v7_get_global(v7), "IsWindowReady", &js_window_ready);
    v7_set_method(v7, v7_get_global(v7), "IsWindowFullscreen", &js_window_fullscreen);
    v7_set_method(v7, v7_get_global(v7), "IsWindowMaximized", &js_window_maximized);
    v7_set_method(v7, v7_get_global(v7), "IsWindowMinimized", &js_window_minimized);
    v7_set_method(v7, v7_get_global(v7), "IsWindowFocused", &js_window_focused);
    v7_set_method(v7, v7_get_global(v7), "IsWindowResized", &js_window_resized);
    v7_set_method(v7, v7_get_global(v7), "IsWindowState", &js_window_state);
    v7_set_method(v7, v7_get_global(v7), "SetWindowState", &js_set_window_state);
    v7_set_method(v7, v7_get_global(v7), "ClearWindowState", &js_clear_window_state);
    v7_set_method(v7, v7_get_global(v7), "ToggleFullscreen", &js_toggle_fullscreen);
    v7_set_method(v7, v7_get_global(v7), "MaximizeWindow", &js_maximize_window);
    v7_set_method(v7, v7_get_global(v7), "MinimizeWindow", &js_minimize_window);
    v7_set_method(v7, v7_get_global(v7), "RestoreWindow", &js_restore_window);
    v7_set_method(v7, v7_get_global(v7), "SetWindowIcon", &js_set_window_icon);
    v7_set_method(v7, v7_get_global(v7), "SetWindowTitle", &js_set_window_title);
    v7_set_method(v7, v7_get_global(v7), "SetWindowPosition", &js_set_window_position);
    v7_set_method(v7, v7_get_global(v7), "SetWindowMonitor", &js_set_window_monitor);
    v7_set_method(v7, v7_get_global(v7), "SetWindowMinSize", &js_set_window_min_size);
    v7_set_method(v7, v7_get_global(v7), "SetWindowSize", &js_set_window_size);
    v7_set_method(v7, v7_get_global(v7), "GetWindowHandle", &js_get_window_handle);
    v7_set_method(v7, v7_get_global(v7), "GetScreenWidth", &js_get_screen_width);
    v7_set_method(v7, v7_get_global(v7), "GetScreenHeight", &js_get_screen_height);
    v7_set_method(v7, v7_get_global(v7), "GetMonitorCount", &js_get_monitor_count);
    v7_set_method(v7, v7_get_global(v7), "GetMonitorPosition", &js_get_monitor_position);
    v7_set_method(v7, v7_get_global(v7), "GetMonitorWidth", &js_get_monitor_width);
    v7_set_method(v7, v7_get_global(v7), "GetMonitorHeight", &js_get_monitor_height);
    v7_set_method(v7, v7_get_global(v7), "GetMonitorPhysicalWidth", &js_get_monitor_physical_width);
    v7_set_method(v7, v7_get_global(v7), "GetMonitorPhysicalHeight", &js_get_monitor_physical_height);
    v7_set_method(v7, v7_get_global(v7), "GetMonitorRefreshRate", &js_get_monitor_refresh_rate);
    v7_set_method(v7, v7_get_global(v7), "GetWindowPosition", &js_get_window_position);
    v7_set_method(v7, v7_get_global(v7), "GetWindowScaleDPI", &js_get_window_scale_dpi);
    v7_set_method(v7, v7_get_global(v7), "GetMonitorName", &js_get_monitor_name);
    v7_set_method(v7, v7_get_global(v7), "SetClipboardText", &js_set_clipboard_text);
    v7_set_method(v7, v7_get_global(v7), "GetClipboardText", &js_get_clipboard_text);

    v7_set_method(v7, v7_get_global(v7), "ShowCursor", &js_show_cursor);
    v7_set_method(v7, v7_get_global(v7), "HideCursor", &js_hide_cursor);
    v7_set_method(v7, v7_get_global(v7), "IsCursorHidden", &js_cursor_hidden);
    v7_set_method(v7, v7_get_global(v7), "EnableCursor", &js_enable_cursor);
    v7_set_method(v7, v7_get_global(v7), "DisableCursor", &js_disable_cursor);
    v7_set_method(v7, v7_get_global(v7), "IsCursorOnScreen", &js_cursor_onscreen);

    v7_set_method(v7, v7_get_global(v7), "ClearBackground", &js_clear_background);
    v7_set_method(v7, v7_get_global(v7), "BeginDrawing", &js_begin_drawing);
    v7_set_method(v7, v7_get_global(v7), "EndDrawing", &js_end_drawing);
    v7_set_method(v7, v7_get_global(v7), "BeginMode2D", &js_begin_mode2d);
    v7_set_method(v7, v7_get_global(v7), "EndMode2D", &js_end_mode2d);
    v7_set_method(v7, v7_get_global(v7), "BeginMode3D", &js_begin_mode3d);
    v7_set_method(v7, v7_get_global(v7), "EndMode3D", &js_end_mode3d);
    v7_set_method(v7, v7_get_global(v7), "BeginTextureMode", &js_begin_texture_mode);
    v7_set_method(v7, v7_get_global(v7), "EndTextureMode", &js_end_texture_mode);
    v7_set_method(v7, v7_get_global(v7), "BeginScissorMode", &js_begin_scissor_mode);
    v7_set_method(v7, v7_get_global(v7), "EndScissorMode", &js_end_scissor_mode);

    v7_set_method(v7, v7_get_global(v7), "GetMouseRay", &js_get_mouse_ray);
    v7_set_method(v7, v7_get_global(v7), "GetCameraMatrix", &js_get_camera_matrix);
    v7_set_method(v7, v7_get_global(v7), "GetCameraMatrix2D", &js_get_camera_matrix2d);
    v7_set_method(v7, v7_get_global(v7), "GetWorldToScreen", &js_get_world_to_screen);
    v7_set_method(v7, v7_get_global(v7), "GetWorldToScreenEx", &js_get_world_to_screen_ex);
    v7_set_method(v7, v7_get_global(v7), "GetWorldToScreen2D", &js_get_world_to_screen2d);
    v7_set_method(v7, v7_get_global(v7), "GetScreenToWorld2D", &js_get_screen_to_world2d);

    v7_set_method(v7, v7_get_global(v7), "SetTargetFPS", &js_set_target_fps);
    v7_set_method(v7, v7_get_global(v7), "GetFPS", &js_get_fps);
    v7_set_method(v7, v7_get_global(v7), "GetFrameTime", &js_get_frame_time);
    v7_set_method(v7, v7_get_global(v7), "GetTime", &js_get_time);

    v7_set_method(v7, v7_get_global(v7), "SetConfigFlags", &js_set_config_flags);
    v7_set_method(v7, v7_get_global(v7), "SetTraceLogLevel", &js_set_tracelog_level);
    v7_set_method(v7, v7_get_global(v7), "SetTraceLogExit", &js_set_tracelog_exit);
    v7_set_method(v7, v7_get_global(v7), "SetTraceLogCallback", &js_set_tracelog_callback);
    v7_set_method(v7, v7_get_global(v7), "TraceLog", &js_tracelog);

    v7_set_method(v7, v7_get_global(v7), "MemAlloc", &js_memalloc);
    v7_set_method(v7, v7_get_global(v7), "MemFree", &js_memfree);
    v7_set_method(v7, v7_get_global(v7), "TakeScreenshot", &js_take_screenshot);
    v7_set_method(v7, v7_get_global(v7), "GetRandomValue", &js_get_random_value);

    v7_set_method(v7, v7_get_global(v7), "LoadFileData", &js_load_file_data);
    v7_set_method(v7, v7_get_global(v7), "UnloadFileData", &js_unload_file_data);
    v7_set_method(v7, v7_get_global(v7), "SaveFileData", &js_save_file_data);
    v7_set_method(v7, v7_get_global(v7), "LoadFileText", &js_load_file_text);
    v7_set_method(v7, v7_get_global(v7), "LoadText", &js_load_file_text);
    v7_set_method(v7, v7_get_global(v7), "UnloadFileText", &js_unload_file_text);
    v7_set_method(v7, v7_get_global(v7), "FileExists", &js_file_exists);
    v7_set_method(v7, v7_get_global(v7), "DirectoryExists", &js_directory_exists);
    v7_set_method(v7, v7_get_global(v7), "IsFileExtension", &js_is_file_extension);
    v7_set_method(v7, v7_get_global(v7), "GetFileExtension", &js_get_file_extension);
    v7_set_method(v7, v7_get_global(v7), "GetExtension", &js_get_file_extension);
    v7_set_method(v7, v7_get_global(v7), "GetFileName", &js_get_filename);
    v7_set_method(v7, v7_get_global(v7), "GetFileNameWithoutExt", &js_get_filename_without_ext);
    v7_set_method(v7, v7_get_global(v7), "GetDirectoryPath", &js_get_directory_path);
    v7_set_method(v7, v7_get_global(v7), "GetPrevDirectoryPath", &js_get_prev_directory_path);
    v7_set_method(v7, v7_get_global(v7), "GetWorkingDirectory", &js_get_working_directory);
    v7_set_method(v7, v7_get_global(v7), "GetDirectoryFiles", &js_get_directory_files);
    v7_set_method(v7, v7_get_global(v7), "ClearDirectoryFiles", &js_clear_directory_files);
    v7_set_method(v7, v7_get_global(v7), "ChangeDirectory", &js_change_directory);
    v7_set_method(v7, v7_get_global(v7), "IsFileDropped", &js_file_dropped);
    v7_set_method(v7, v7_get_global(v7), "GetDroppedFiles", &js_get_dropped_files);
    v7_set_method(v7, v7_get_global(v7), "ClearDroppedFiles", &js_clear_dropped_files);
    v7_set_method(v7, v7_get_global(v7), "GetFileModTime", &js_get_file_mod_time);

    v7_set_method(v7, v7_get_global(v7), "CompressData", &js_compress_data);
    v7_set_method(v7, v7_get_global(v7), "DecompressData", &js_decompress_data);

    v7_set_method(v7, v7_get_global(v7), "SaveStorageValue", &js_save_storage_value);
    v7_set_method(v7, v7_get_global(v7), "LoadStorageValue", &js_load_storage_value);

    v7_set_method(v7, v7_get_global(v7), "OpenURL", &js_open_url);

    v7_set_method(v7, v7_get_global(v7), "IsKeyPressed", &js_key_pressed);
    v7_set_method(v7, v7_get_global(v7), "IsKeyDown", &js_key_down);
    v7_set_method(v7, v7_get_global(v7), "IsKeyReleased", &js_key_released);
    v7_set_method(v7, v7_get_global(v7), "IsKeyUp", &js_key_up);
    v7_set_method(v7, v7_get_global(v7), "SetExitKey", &js_set_exit_key);
    v7_set_method(v7, v7_get_global(v7), "GetKeyPressed", &js_get_key_pressed);
    v7_set_method(v7, v7_get_global(v7), "GetCharPressed", &js_get_char_pressed);

    v7_set_method(v7, v7_get_global(v7), "IsGamepadAvailable", &js_gamepad_available);
    v7_set_method(v7, v7_get_global(v7), "IsGamepadName", &js_gamepad_name);
    v7_set_method(v7, v7_get_global(v7), "GetGamepadName", &js_get_gamepad_name);
    v7_set_method(v7, v7_get_global(v7), "IsGamepadButtonPressed", &js_gamepad_button_pressed);
    v7_set_method(v7, v7_get_global(v7), "IsGamepadButtonDown", &js_gamepad_button_down);
    v7_set_method(v7, v7_get_global(v7), "IsGamepadButtonReleased", &js_gamepad_button_released);
    v7_set_method(v7, v7_get_global(v7), "IsGamepadButtonUp", &js_gamepad_button_up);
    v7_set_method(v7, v7_get_global(v7), "GetGamepadButtonPressed", &js_get_gamepad_button_pressed);
    v7_set_method(v7, v7_get_global(v7), "GetGamepadAxisCount", &js_get_gamepad_axis_count);
    v7_set_method(v7, v7_get_global(v7), "GetGamepadAxisMovement", &js_get_gamepad_axis_movement);

    v7_set_method(v7, v7_get_global(v7), "IsMouseButtonPressed", &js_mouse_button_pressed);
    v7_set_method(v7, v7_get_global(v7), "IsMouseButtonDown", &js_mouse_button_down);
    v7_set_method(v7, v7_get_global(v7), "IsMouseButtonReleased", &js_mouse_button_released);
    v7_set_method(v7, v7_get_global(v7), "IsMouseButtonUp", &js_mouse_button_up);
    v7_set_method(v7, v7_get_global(v7), "GetMouseX", &js_get_mouse_x);
    v7_set_method(v7, v7_get_global(v7), "GetMouseY", &js_get_mouse_y);
    v7_set_method(v7, v7_get_global(v7), "GetMousePosition", &js_get_mouse_position);
    v7_set_method(v7, v7_get_global(v7), "SetMousePosition", &js_set_mouse_position);
    v7_set_method(v7, v7_get_global(v7), "SetMouseOffset", &js_set_mouse_offset);
    v7_set_method(v7, v7_get_global(v7), "SetMouseScale", &js_set_mouse_scale);
    v7_set_method(v7, v7_get_global(v7), "GetMouseWheelMove", &js_get_mouse_wheel_move);
    v7_set_method(v7, v7_get_global(v7), "GetMouseCursor", &js_get_mouse_cursor);
    v7_set_method(v7, v7_get_global(v7), "SetMouseCursor", &js_set_mouse_cursor);
    
    v7_set_method(v7, v7_get_global(v7), "GetTouchX", &js_get_touch_x);
    v7_set_method(v7, v7_get_global(v7), "GetTouchY", &js_get_touch_y);
    v7_set_method(v7, v7_get_global(v7), "GetTouchPosition", &js_get_touch_position);

    v7_set_method(v7, v7_get_global(v7), "SetGesturesEnabled", &js_set_gestures_enabled);
    v7_set_method(v7, v7_get_global(v7), "IsGestureDetected", &js_gesture_detected);
    v7_set_method(v7, v7_get_global(v7), "GetGestureDetected", &js_get_gesture_detected);
    v7_set_method(v7, v7_get_global(v7), "GetTouchPointsCount", &js_get_touch_points_count);
    v7_set_method(v7, v7_get_global(v7), "GetGestureHoldDuration", &js_get_gesture_hold_duration);
    v7_set_method(v7, v7_get_global(v7), "GetGestureDragVector", &js_get_gesture_drag_vector);
    v7_set_method(v7, v7_get_global(v7), "GetGestureDragAngle", &js_get_gesture_drag_angle);
    v7_set_method(v7, v7_get_global(v7), "GetGesturePinchVector", &js_get_gesture_pinch_vector);
    v7_set_method(v7, v7_get_global(v7), "GetGesturePinchAngle", &js_get_gesture_pinch_angle);

    v7_set_method(v7, v7_get_global(v7), "SetCameraMode", &js_set_camera_mode);
    v7_set_method(v7, v7_get_global(v7), "UpdateCamera", &js_update_camera);
    v7_set_method(v7, v7_get_global(v7), "SetCameraPanControl", &js_set_camera_pan_control);
    v7_set_method(v7, v7_get_global(v7), "SetCameraAltControl", &js_set_camera_alt_control);
    v7_set_method(v7, v7_get_global(v7), "SetCameraSmoothZoomControl", &js_set_camera_smooth_zoom_control);
    v7_set_method(v7, v7_get_global(v7), "SetCameraMoveControls", &js_set_camera_move_controls);
}
