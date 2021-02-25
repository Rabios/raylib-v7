cmake_minimum_required(VERSION 3.1)
project(raylib-v7 LANGUAGES C)
set(CMAKE_C_STANDARD 99)

# Globals
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(RAYLIB_DIR "${LIB_DIR}/raylib")
set(V7_DIR "${LIB_DIR}/v7")
set(MINIZ_DIR "${LIB_DIR}/miniz")
set(MAIN
   "${LIB_DIR}/dirent/dirent.h"
   "${SRC_DIR}/main.c"
   "${SRC_DIR}/get_set.c"
   "${SRC_DIR}/types.c"
   "${SRC_DIR}/vars_js.c"
   "${SRC_DIR}/core_js.c"
   "${SRC_DIR}/shapes_js.c"
   "${SRC_DIR}/text_js.c"
   "${SRC_DIR}/textures_js.c"
   "${SRC_DIR}/models_js.c"
   "${SRC_DIR}/shaders_js.c"
   "${SRC_DIR}/audio_js.c"
   "${SRC_DIR}/easings_js.c"
   "${SRC_DIR}/rlgl_js.c"
   "${SRC_DIR}/physac_js.c"
   "${SRC_DIR}/raymath_js.c"
   "${SRC_DIR}/raygui_js.c"
   "${SRC_DIR}/rlights_js.c"
   "${SRC_DIR}/rnet_js.c"
   "${SRC_DIR}/gestures_js.c")

set(LIBS
   "${LIB_DIR}/raylib_easings/easings.h"
   "${LIB_DIR}/rlights/rlights.h"
   "${LIB_DIR}/raygui/raygui.h"
   "${LIB_DIR}/raygui/ricons.h"
   "${LIB_DIR}/raygui/gui_textbox_extended.h")

# Build all with raylib and V7
add_executable(${PROJECT_NAME} ${MAIN} ${LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE ${LIB_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})
target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC)

# raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
add_subdirectory(${RAYLIB_DIR})
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")
target_link_libraries(${PROJECT_NAME} PRIVATE "raylib" ${RAYLIB_LIBS})

# V7
add_subdirectory(${V7_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE "v7" ${V7_LIBS})

# miniz
add_subdirectory(${MINIZ_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE "miniz" ${MINIZ_LIBS})
