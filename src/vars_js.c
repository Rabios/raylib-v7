#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>
#include <vars_js.h>

void raylib_v7_load_colors(struct v7* v7) {
    js_push_color(v7, v7_get_global(v7), "LIGHTGRAY", LIGHTGRAY);
    js_push_color(v7, v7_get_global(v7), "GRAY", GRAY);
    js_push_color(v7, v7_get_global(v7), "DARKGRAY", DARKGRAY);
    js_push_color(v7, v7_get_global(v7), "YELLOW", YELLOW);
    js_push_color(v7, v7_get_global(v7), "GOLD", GOLD);
    js_push_color(v7, v7_get_global(v7), "ORANGE", ORANGE);
    js_push_color(v7, v7_get_global(v7), "PINK", PINK);
    js_push_color(v7, v7_get_global(v7), "RED", RED);
    js_push_color(v7, v7_get_global(v7), "MAROON", MAROON);
    js_push_color(v7, v7_get_global(v7), "GREEN", GREEN);
    js_push_color(v7, v7_get_global(v7), "LIME", LIME);
    js_push_color(v7, v7_get_global(v7), "DARKGREEN", DARKGREEN);
    js_push_color(v7, v7_get_global(v7), "SKYBLUE", SKYBLUE);
    js_push_color(v7, v7_get_global(v7), "BLUE", BLUE);
    js_push_color(v7, v7_get_global(v7), "DARKBLUE", DARKBLUE);
    js_push_color(v7, v7_get_global(v7), "PURPLE", PURPLE);
    js_push_color(v7, v7_get_global(v7), "VIOLET", VIOLET);
    js_push_color(v7, v7_get_global(v7), "DARKPURPLE", DARKPURPLE);
    js_push_color(v7, v7_get_global(v7), "BEIGE", BEIGE);
    js_push_color(v7, v7_get_global(v7), "BROWN", BROWN);
    js_push_color(v7, v7_get_global(v7), "DARKBROWN", DARKBROWN);
    js_push_color(v7, v7_get_global(v7), "WHITE", WHITE);
    js_push_color(v7, v7_get_global(v7), "BLACK", BLACK);
    js_push_color(v7, v7_get_global(v7), "BLANK", BLANK);
    js_push_color(v7, v7_get_global(v7), "MAGENTA", MAGENTA);
    js_push_color(v7, v7_get_global(v7), "RAYWHITE", RAYWHITE);
}

void raylib_v7_load_platform(struct v7* v7) {
#ifdef PLATFORM_DESKTOP
    js_push_key(v7, v7_get_global(v7), "PLATFORM_DESKTOP", v7_mk_number(v7, (int)true));
#else
    js_push_key(v7, v7_get_global(v7), "PLATFORM_DESKTOP", v7_mk_number(v7, (int)false));
#endif

#ifdef PLATFORM_ANDROID
    js_push_key(v7, v7_get_global(v7), "PLATFORM_ANDROID", v7_mk_number(v7, (int)true));
#else
    js_push_key(v7, v7_get_global(v7), "PLATFORM_ANDROID", v7_mk_number(v7, (int)false));
#endif

#ifdef PLATFORM_RPI
    js_push_key(v7, v7_get_global(v7), "PLATFORM_RPI", v7_mk_number(v7, (int)true));
#else
    js_push_key(v7, v7_get_global(v7), "PLATFORM_RPI", v7_mk_number(v7, (int)false));
#endif

#ifdef PLATFORM_DRM
    js_push_key(v7, v7_get_global(v7), "PLATFORM_DRM", v7_mk_number(v7, (int)true));
#else
    js_push_key(v7, v7_get_global(v7), "PLATFORM_DRM", v7_mk_number(v7, (int)false));
#endif

#ifdef PLATFORM_WEB
    js_push_key(v7, v7_get_global(v7), "PLATFORM_WEB", v7_mk_number(v7, (int)true));
#else
    js_push_key(v7, v7_get_global(v7), "PLATFORM_WEB", v7_mk_number(v7, (int)false));
#endif
}

void raylib_v7_load_variables(struct v7* v7) {
    raylib_v7_load_platform(v7);
    js_push_key(v7, v7_get_global(v7), "PI", PI);
    js_push_key(v7, v7_get_global(v7), "DEG2RAD", DEG2RAD);
    js_push_key(v7, v7_get_global(v7), "RAD2DEG", RAD2DEG);

    js_push_key(v7, v7_get_global(v7), "FLAG_VSYNC_HINT", FLAG_VSYNC_HINT);
    js_push_key(v7, v7_get_global(v7), "FLAG_FULLSCREEN_MODE", FLAG_FULLSCREEN_MODE);
    js_push_key(v7, v7_get_global(v7), "FLAG_WINDOW_RESIZABLE", FLAG_WINDOW_RESIZABLE);
    js_push_key(v7, v7_get_global(v7), "FLAG_WINDOW_UNDECORATED", FLAG_WINDOW_UNDECORATED);
    js_push_key(v7, v7_get_global(v7), "FLAG_WINDOW_HIDDEN", FLAG_WINDOW_HIDDEN);
    js_push_key(v7, v7_get_global(v7), "FLAG_WINDOW_MINIMIZED", FLAG_WINDOW_MINIMIZED);
    js_push_key(v7, v7_get_global(v7), "FLAG_WINDOW_MAXIMIZED", FLAG_WINDOW_MAXIMIZED);
    js_push_key(v7, v7_get_global(v7), "FLAG_WINDOW_UNFOCUSED", FLAG_WINDOW_UNFOCUSED);
    js_push_key(v7, v7_get_global(v7), "FLAG_WINDOW_TOPMOST", FLAG_WINDOW_TOPMOST);
    js_push_key(v7, v7_get_global(v7), "FLAG_WINDOW_ALWAYS_RUN", FLAG_WINDOW_ALWAYS_RUN);
    js_push_key(v7, v7_get_global(v7), "FLAG_WINDOW_TRANSPARENT", FLAG_WINDOW_TRANSPARENT);
    js_push_key(v7, v7_get_global(v7), "FLAG_WINDOW_HIGHDPI", FLAG_WINDOW_HIGHDPI);
    js_push_key(v7, v7_get_global(v7), "FLAG_MSAA_4X_HINT", FLAG_MSAA_4X_HINT);
    js_push_key(v7, v7_get_global(v7), "FLAG_INTERLACED_HINT", FLAG_INTERLACED_HINT);

    js_push_key(v7, v7_get_global(v7), "LOG_ALL", LOG_ALL);
    js_push_key(v7, v7_get_global(v7), "LOG_TRACE", LOG_TRACE);
    js_push_key(v7, v7_get_global(v7), "LOG_DEBUG", LOG_DEBUG);
    js_push_key(v7, v7_get_global(v7), "LOG_INFO", LOG_INFO);
    js_push_key(v7, v7_get_global(v7), "LOG_WARNING", LOG_WARNING);
    js_push_key(v7, v7_get_global(v7), "LOG_ERROR", LOG_ERROR);
    js_push_key(v7, v7_get_global(v7), "LOG_FATAL", LOG_FATAL);
    js_push_key(v7, v7_get_global(v7), "LOG_NONE", LOG_NONE);

    js_push_key(v7, v7_get_global(v7), "KEY_APOSTROPHE", KEY_APOSTROPHE);
    js_push_key(v7, v7_get_global(v7), "KEY_COMMA", KEY_COMMA);
    js_push_key(v7, v7_get_global(v7), "KEY_MINUS", KEY_MINUS);
    js_push_key(v7, v7_get_global(v7), "KEY_PERIOD", KEY_PERIOD);
    js_push_key(v7, v7_get_global(v7), "KEY_SLASH", KEY_SLASH);
    js_push_key(v7, v7_get_global(v7), "KEY_SEMICOLON", KEY_SEMICOLON);
    js_push_key(v7, v7_get_global(v7), "KEY_EQUAL", KEY_EQUAL);

    js_push_key(v7, v7_get_global(v7), "KEY_ZERO", KEY_ZERO);
    js_push_key(v7, v7_get_global(v7), "KEY_ONE", KEY_ONE);
    js_push_key(v7, v7_get_global(v7), "KEY_TWO", KEY_TWO);
    js_push_key(v7, v7_get_global(v7), "KEY_THREE", KEY_THREE);
    js_push_key(v7, v7_get_global(v7), "KEY_FOUR", KEY_FOUR);
    js_push_key(v7, v7_get_global(v7), "KEY_FIVE", KEY_FIVE);
    js_push_key(v7, v7_get_global(v7), "KEY_SIX", KEY_SIX);
    js_push_key(v7, v7_get_global(v7), "KEY_SEVEN", KEY_SEVEN);
    js_push_key(v7, v7_get_global(v7), "KEY_EIGHT", KEY_EIGHT);
    js_push_key(v7, v7_get_global(v7), "KEY_NINE", KEY_NINE);

    js_push_key(v7, v7_get_global(v7), "KEY_A", KEY_A);
    js_push_key(v7, v7_get_global(v7), "KEY_B", KEY_B);
    js_push_key(v7, v7_get_global(v7), "KEY_C", KEY_C);
    js_push_key(v7, v7_get_global(v7), "KEY_D", KEY_D);
    js_push_key(v7, v7_get_global(v7), "KEY_E", KEY_E);
    js_push_key(v7, v7_get_global(v7), "KEY_F", KEY_F);
    js_push_key(v7, v7_get_global(v7), "KEY_G", KEY_G);
    js_push_key(v7, v7_get_global(v7), "KEY_H", KEY_H);
    js_push_key(v7, v7_get_global(v7), "KEY_I", KEY_I);
    js_push_key(v7, v7_get_global(v7), "KEY_J", KEY_J);
    js_push_key(v7, v7_get_global(v7), "KEY_K", KEY_K);
    js_push_key(v7, v7_get_global(v7), "KEY_L", KEY_L);
    js_push_key(v7, v7_get_global(v7), "KEY_M", KEY_M);
    js_push_key(v7, v7_get_global(v7), "KEY_N", KEY_N);
    js_push_key(v7, v7_get_global(v7), "KEY_O", KEY_O);
    js_push_key(v7, v7_get_global(v7), "KEY_P", KEY_P);
    js_push_key(v7, v7_get_global(v7), "KEY_Q", KEY_Q);
    js_push_key(v7, v7_get_global(v7), "KEY_R", KEY_R);
    js_push_key(v7, v7_get_global(v7), "KEY_S", KEY_S);
    js_push_key(v7, v7_get_global(v7), "KEY_T", KEY_T);
    js_push_key(v7, v7_get_global(v7), "KEY_U", KEY_U);
    js_push_key(v7, v7_get_global(v7), "KEY_V", KEY_V);
    js_push_key(v7, v7_get_global(v7), "KEY_W", KEY_W);
    js_push_key(v7, v7_get_global(v7), "KEY_X", KEY_X);
    js_push_key(v7, v7_get_global(v7), "KEY_Y", KEY_Y);
    js_push_key(v7, v7_get_global(v7), "KEY_Z", KEY_Z);

    js_push_key(v7, v7_get_global(v7), "KEY_SPACE", KEY_SPACE);
    js_push_key(v7, v7_get_global(v7), "KEY_ESCAPE", KEY_ESCAPE);
    js_push_key(v7, v7_get_global(v7), "KEY_ENTER", KEY_ENTER);
    js_push_key(v7, v7_get_global(v7), "KEY_TAB", KEY_TAB);
    js_push_key(v7, v7_get_global(v7), "KEY_BACKSPACE", KEY_BACKSPACE);
    js_push_key(v7, v7_get_global(v7), "KEY_INSERT", KEY_INSERT);
    js_push_key(v7, v7_get_global(v7), "KEY_DELETE", KEY_DELETE);
    js_push_key(v7, v7_get_global(v7), "KEY_RIGHT", KEY_RIGHT);
    js_push_key(v7, v7_get_global(v7), "KEY_LEFT", KEY_LEFT);
    js_push_key(v7, v7_get_global(v7), "KEY_DOWN", KEY_DOWN);
    js_push_key(v7, v7_get_global(v7), "KEY_UP", KEY_UP);
    js_push_key(v7, v7_get_global(v7), "KEY_PAGE_UP", KEY_PAGE_UP);
    js_push_key(v7, v7_get_global(v7), "KEY_PAGE_DOWN", KEY_PAGE_DOWN);
    js_push_key(v7, v7_get_global(v7), "KEY_HOME", KEY_HOME);
    js_push_key(v7, v7_get_global(v7), "KEY_END", KEY_END);
    js_push_key(v7, v7_get_global(v7), "KEY_CAPS_LOCK", KEY_CAPS_LOCK);
    js_push_key(v7, v7_get_global(v7), "KEY_SCROLL_LOCK", KEY_SCROLL_LOCK);
    js_push_key(v7, v7_get_global(v7), "KEY_NUM_LOCK", KEY_NUM_LOCK);
    js_push_key(v7, v7_get_global(v7), "KEY_PRINT_SCREEN", KEY_PRINT_SCREEN);
    js_push_key(v7, v7_get_global(v7), "KEY_PAUSE", KEY_PAUSE);

    js_push_key(v7, v7_get_global(v7), "KEY_F1", KEY_F1);
    js_push_key(v7, v7_get_global(v7), "KEY_F2", KEY_F2);
    js_push_key(v7, v7_get_global(v7), "KEY_F3", KEY_F3);
    js_push_key(v7, v7_get_global(v7), "KEY_F4", KEY_F4);
    js_push_key(v7, v7_get_global(v7), "KEY_F5", KEY_F5);
    js_push_key(v7, v7_get_global(v7), "KEY_F6", KEY_F6);
    js_push_key(v7, v7_get_global(v7), "KEY_F7", KEY_F7);
    js_push_key(v7, v7_get_global(v7), "KEY_F8", KEY_F8);
    js_push_key(v7, v7_get_global(v7), "KEY_F9", KEY_F9);
    js_push_key(v7, v7_get_global(v7), "KEY_F10", KEY_F10);
    js_push_key(v7, v7_get_global(v7), "KEY_F11", KEY_F11);
    js_push_key(v7, v7_get_global(v7), "KEY_F12", KEY_F12);

    js_push_key(v7, v7_get_global(v7), "KEY_LEFT_SHIFT", KEY_LEFT_SHIFT);
    js_push_key(v7, v7_get_global(v7), "KEY_LEFT_CONTROL", KEY_LEFT_CONTROL);
    js_push_key(v7, v7_get_global(v7), "KEY_LEFT_ALT", KEY_LEFT_ALT);
    js_push_key(v7, v7_get_global(v7), "KEY_LEFT_SUPER", KEY_LEFT_SUPER);
    js_push_key(v7, v7_get_global(v7), "KEY_RIGHT_SHIFT", KEY_RIGHT_SHIFT);
    js_push_key(v7, v7_get_global(v7), "KEY_RIGHT_CONTROL", KEY_RIGHT_CONTROL);
    js_push_key(v7, v7_get_global(v7), "KEY_RIGHT_ALT", KEY_RIGHT_ALT);
    js_push_key(v7, v7_get_global(v7), "KEY_RIGHT_SUPER", KEY_RIGHT_SUPER);
    js_push_key(v7, v7_get_global(v7), "KEY_KB_MENU", KEY_KB_MENU);
    js_push_key(v7, v7_get_global(v7), "KEY_LEFT_BRACKET", KEY_LEFT_BRACKET);
    js_push_key(v7, v7_get_global(v7), "KEY_BACKSLASH", KEY_BACKSLASH);
    js_push_key(v7, v7_get_global(v7), "KEY_RIGHT_BRACKET", KEY_RIGHT_BRACKET);
    js_push_key(v7, v7_get_global(v7), "KEY_GRAVE", KEY_GRAVE);

    js_push_key(v7, v7_get_global(v7), "KEY_KP_0", KEY_KP_0);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_1", KEY_KP_1);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_2", KEY_KP_2);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_3", KEY_KP_3);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_4", KEY_KP_4);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_5", KEY_KP_5);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_6", KEY_KP_6);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_7", KEY_KP_7);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_8", KEY_KP_8);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_9", KEY_KP_9);

    js_push_key(v7, v7_get_global(v7), "KEY_KP_DECIMAL", KEY_KP_DECIMAL);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_DIVIDE", KEY_KP_DIVIDE);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_MULTIPLY", KEY_KP_MULTIPLY);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_SUBTRACT", KEY_KP_SUBTRACT);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_ADD", KEY_KP_ADD);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_ENTER", KEY_KP_ENTER);
    js_push_key(v7, v7_get_global(v7), "KEY_KP_EQUAL", KEY_KP_EQUAL);

    js_push_key(v7, v7_get_global(v7), "KEY_BACK", KEY_BACK);
    js_push_key(v7, v7_get_global(v7), "KEY_MENU", KEY_MENU);
    js_push_key(v7, v7_get_global(v7), "KEY_VOLUME_UP", KEY_VOLUME_UP);
    js_push_key(v7, v7_get_global(v7), "KEY_VOLUME_DOWN", KEY_VOLUME_DOWN);

    js_push_key(v7, v7_get_global(v7), "MOUSE_LEFT_BUTTON", MOUSE_LEFT_BUTTON);
    js_push_key(v7, v7_get_global(v7), "MOUSE_RIGHT_BUTTON", MOUSE_RIGHT_BUTTON);
    js_push_key(v7, v7_get_global(v7), "MOUSE_MIDDLE_BUTTON", MOUSE_MIDDLE_BUTTON);

    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_DEFAULT", MOUSE_CURSOR_DEFAULT);
    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_ARROW", MOUSE_CURSOR_ARROW);
    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_IBEAM", MOUSE_CURSOR_IBEAM);
    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_CROSSHAIR", MOUSE_CURSOR_CROSSHAIR);
    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_POINTING_HAND", MOUSE_CURSOR_POINTING_HAND);
    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_RESIZE_EW", MOUSE_CURSOR_RESIZE_EW);
    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_RESIZE_NS", MOUSE_CURSOR_RESIZE_NS);
    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_RESIZE_NWSE", MOUSE_CURSOR_RESIZE_NWSE);
    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_RESIZE_NESW", MOUSE_CURSOR_RESIZE_NESW);
    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_RESIZE_ALL", MOUSE_CURSOR_RESIZE_ALL);
    js_push_key(v7, v7_get_global(v7), "MOUSE_CURSOR_NOT_ALLOWED", MOUSE_CURSOR_NOT_ALLOWED);

    js_push_key(v7, v7_get_global(v7), "GAMEPAD_PLAYER1", GAMEPAD_PLAYER1);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_PLAYER2", GAMEPAD_PLAYER2);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_PLAYER3", GAMEPAD_PLAYER3);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_PLAYER4", GAMEPAD_PLAYER4);

    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_UNKNOWN", GAMEPAD_BUTTON_UNKNOWN);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_LEFT_FACE_UP", GAMEPAD_BUTTON_LEFT_FACE_UP);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_LEFT_FACE_DOWN", GAMEPAD_BUTTON_LEFT_FACE_DOWN);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_LEFT_FACE_LEFT", GAMEPAD_BUTTON_LEFT_FACE_LEFT);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_LEFT_FACE_RIGHT", GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_RIGHT_FACE_UP", GAMEPAD_BUTTON_RIGHT_FACE_UP);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_RIGHT_FACE_DOWN", GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_RIGHT_FACE_LEFT", GAMEPAD_BUTTON_RIGHT_FACE_LEFT);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_RIGHT_FACE_RIGHT", GAMEPAD_BUTTON_RIGHT_FACE_RIGHT);

    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_LEFT_TRIGGER_1", GAMEPAD_BUTTON_LEFT_TRIGGER_1);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_LEFT_TRIGGER_2", GAMEPAD_BUTTON_LEFT_TRIGGER_2);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_RIGHT_TRIGGER_1", GAMEPAD_BUTTON_RIGHT_TRIGGER_1);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_RIGHT_TRIGGER_2", GAMEPAD_BUTTON_RIGHT_TRIGGER_2);

    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_MIDDLE_LEFT", GAMEPAD_BUTTON_MIDDLE_LEFT);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_MIDDLE", GAMEPAD_BUTTON_MIDDLE);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_MIDDLE_RIGHT", GAMEPAD_BUTTON_MIDDLE_RIGHT);

    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_LEFT_THUMB", GAMEPAD_BUTTON_LEFT_THUMB);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_BUTTON_RIGHT_THUMB", GAMEPAD_BUTTON_RIGHT_THUMB);

    js_push_key(v7, v7_get_global(v7), "GAMEPAD_AXIS_LEFT_X", GAMEPAD_AXIS_LEFT_X);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_AXIS_LEFT_Y", GAMEPAD_AXIS_LEFT_Y);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_AXIS_RIGHT_X", GAMEPAD_AXIS_RIGHT_X);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_AXIS_RIGHT_Y", GAMEPAD_AXIS_RIGHT_Y);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_AXIS_LEFT_TRIGGER", GAMEPAD_AXIS_LEFT_TRIGGER);
    js_push_key(v7, v7_get_global(v7), "GAMEPAD_AXIS_RIGHT_TRIGGER", GAMEPAD_AXIS_RIGHT_TRIGGER);

    js_push_key(v7, v7_get_global(v7), "LOC_VERTEX_POSITION", LOC_VERTEX_POSITION);
    js_push_key(v7, v7_get_global(v7), "LOC_VERTEX_TEXCOORD01", LOC_VERTEX_TEXCOORD01);
    js_push_key(v7, v7_get_global(v7), "LOC_VERTEX_TEXCOORD02", LOC_VERTEX_TEXCOORD02);
    js_push_key(v7, v7_get_global(v7), "LOC_VERTEX_NORMAL", LOC_VERTEX_NORMAL);
    js_push_key(v7, v7_get_global(v7), "LOC_VERTEX_TANGENT", LOC_VERTEX_TANGENT);
    js_push_key(v7, v7_get_global(v7), "LOC_VERTEX_COLOR", LOC_VERTEX_COLOR);
    js_push_key(v7, v7_get_global(v7), "LOC_MATRIX_MVP", LOC_MATRIX_MVP);
    js_push_key(v7, v7_get_global(v7), "LOC_MATRIX_MODEL", LOC_MATRIX_MODEL);
    js_push_key(v7, v7_get_global(v7), "LOC_MATRIX_VIEW", LOC_MATRIX_VIEW);
    js_push_key(v7, v7_get_global(v7), "LOC_MATRIX_PROJECTION", LOC_MATRIX_PROJECTION);
    js_push_key(v7, v7_get_global(v7), "LOC_VECTOR_VIEW", LOC_VECTOR_VIEW);
    js_push_key(v7, v7_get_global(v7), "LOC_COLOR_DIFFUSE", LOC_COLOR_DIFFUSE);
    js_push_key(v7, v7_get_global(v7), "LOC_COLOR_SPECULAR", LOC_COLOR_SPECULAR);
    js_push_key(v7, v7_get_global(v7), "LOC_COLOR_AMBIENT", LOC_COLOR_AMBIENT);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_ALBEDO", LOC_MAP_ALBEDO);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_DIFFUSE", LOC_MAP_ALBEDO);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_METALNESS", LOC_MAP_METALNESS);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_SPECULAR", LOC_MAP_METALNESS);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_NORMAL", LOC_MAP_NORMAL);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_ROUGHNESS", LOC_MAP_ROUGHNESS);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_OCCLUSION", LOC_MAP_OCCLUSION);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_EMISSION", LOC_MAP_EMISSION);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_HEIGHT", LOC_MAP_HEIGHT);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_CUBEMAP", LOC_MAP_CUBEMAP);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_IRRADIANCE", LOC_MAP_IRRADIANCE);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_PREFILTER", LOC_MAP_PREFILTER);
    js_push_key(v7, v7_get_global(v7), "LOC_MAP_BRDF", LOC_MAP_BRDF);

    js_push_key(v7, v7_get_global(v7), "UNIFORM_FLOAT", UNIFORM_FLOAT);
    js_push_key(v7, v7_get_global(v7), "UNIFORM_VEC2", UNIFORM_VEC2);
    js_push_key(v7, v7_get_global(v7), "UNIFORM_VEC3", UNIFORM_VEC3);
    js_push_key(v7, v7_get_global(v7), "UNIFORM_VEC4", UNIFORM_VEC4);
    js_push_key(v7, v7_get_global(v7), "UNIFORM_INT", UNIFORM_INT);
    js_push_key(v7, v7_get_global(v7), "UNIFORM_IVEC2", UNIFORM_IVEC2);
    js_push_key(v7, v7_get_global(v7), "UNIFORM_IVEC3", UNIFORM_IVEC3);
    js_push_key(v7, v7_get_global(v7), "UNIFORM_IVEC4", UNIFORM_IVEC4);
    js_push_key(v7, v7_get_global(v7), "UNIFORM_SAMPLER2D", UNIFORM_SAMPLER2D);

    js_push_key(v7, v7_get_global(v7), "MAP_ALBEDO", MAP_ALBEDO);
    js_push_key(v7, v7_get_global(v7), "MAP_DIFFUSE", MAP_ALBEDO);
    js_push_key(v7, v7_get_global(v7), "MAP_METALNESS", MAP_METALNESS);
    js_push_key(v7, v7_get_global(v7), "MAP_SPECULAR", MAP_METALNESS);
    js_push_key(v7, v7_get_global(v7), "MAP_NORMAL", MAP_NORMAL);
    js_push_key(v7, v7_get_global(v7), "MAP_OCCLUSION", MAP_OCCLUSION);
    js_push_key(v7, v7_get_global(v7), "MAP_EMISSION", MAP_EMISSION);
    js_push_key(v7, v7_get_global(v7), "MAP_HEIGHT", MAP_HEIGHT);
    js_push_key(v7, v7_get_global(v7), "MAP_CUBEMAP", MAP_CUBEMAP);
    js_push_key(v7, v7_get_global(v7), "MAP_IRRADIANCE", MAP_IRRADIANCE);
    js_push_key(v7, v7_get_global(v7), "MAP_PREFILTER", MAP_PREFILTER);
    js_push_key(v7, v7_get_global(v7), "MAP_BRDF", MAP_BRDF);

    js_push_key(v7, v7_get_global(v7), "UNCOMPRESSED_GRAYSCALE", UNCOMPRESSED_GRAYSCALE);
    js_push_key(v7, v7_get_global(v7), "UNCOMPRESSED_GRAY_ALPHA", UNCOMPRESSED_GRAY_ALPHA);
    js_push_key(v7, v7_get_global(v7), "UNCOMPRESSED_R5G6B5", UNCOMPRESSED_R5G6B5);
    js_push_key(v7, v7_get_global(v7), "UNCOMPRESSED_R8G8B8", UNCOMPRESSED_R8G8B8);
    js_push_key(v7, v7_get_global(v7), "UNCOMPRESSED_R5G5B5A1", UNCOMPRESSED_R5G5B5A1);
    js_push_key(v7, v7_get_global(v7), "UNCOMPRESSED_R4G4B4A4", UNCOMPRESSED_R4G4B4A4);
    js_push_key(v7, v7_get_global(v7), "UNCOMPRESSED_R8G8B8A8", UNCOMPRESSED_R8G8B8A8);
    js_push_key(v7, v7_get_global(v7), "UNCOMPRESSED_R32", UNCOMPRESSED_R32);
    js_push_key(v7, v7_get_global(v7), "UNCOMPRESSED_R32G32B32", UNCOMPRESSED_R32G32B32);
    js_push_key(v7, v7_get_global(v7), "UNCOMPRESSED_R32G32B32A32", UNCOMPRESSED_R32G32B32A32);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_DXT1_RGB", COMPRESSED_DXT1_RGB);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_DXT1_RGBA", COMPRESSED_DXT1_RGBA);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_DXT3_RGBA", COMPRESSED_DXT3_RGBA);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_DXT5_RGBA", COMPRESSED_DXT5_RGBA);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_ETC1_RGB", COMPRESSED_ETC1_RGB);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_ETC2_RGB", COMPRESSED_ETC2_RGB);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_ETC2_EAC_RGBA", COMPRESSED_ETC2_EAC_RGBA);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_PVRT_RGB", COMPRESSED_PVRT_RGB);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_PVRT_RGBA", COMPRESSED_PVRT_RGBA);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_ASTC_4x4_RGBA", COMPRESSED_ASTC_4x4_RGBA);
    js_push_key(v7, v7_get_global(v7), "COMPRESSED_ASTC_8x8_RGBA", COMPRESSED_ASTC_8x8_RGBA);

    js_push_key(v7, v7_get_global(v7), "FILTER_POINT", FILTER_POINT);
    js_push_key(v7, v7_get_global(v7), "FILTER_BILINEAR", FILTER_BILINEAR);
    js_push_key(v7, v7_get_global(v7), "FILTER_TRILINEAR", FILTER_TRILINEAR);
    js_push_key(v7, v7_get_global(v7), "FILTER_ANISOTROPIC_4X", FILTER_ANISOTROPIC_4X);
    js_push_key(v7, v7_get_global(v7), "FILTER_ANISOTROPIC_8X", FILTER_ANISOTROPIC_8X);
    js_push_key(v7, v7_get_global(v7), "FILTER_ANISOTROPIC_16X", FILTER_ANISOTROPIC_16X);

    js_push_key(v7, v7_get_global(v7), "WRAP_REPEAT", WRAP_REPEAT);
    js_push_key(v7, v7_get_global(v7), "WRAP_CLAMP", WRAP_CLAMP);
    js_push_key(v7, v7_get_global(v7), "WRAP_MIRROR_REPEAT", WRAP_MIRROR_REPEAT);
    js_push_key(v7, v7_get_global(v7), "WRAP_MIRROR_CLAMP", WRAP_MIRROR_CLAMP);

    js_push_key(v7, v7_get_global(v7), "CUBEMAP_AUTO_DETECT", CUBEMAP_AUTO_DETECT);
    js_push_key(v7, v7_get_global(v7), "CUBEMAP_LINE_VERTICAL", CUBEMAP_LINE_VERTICAL);
    js_push_key(v7, v7_get_global(v7), "CUBEMAP_LINE_HORIZONTAL", CUBEMAP_LINE_HORIZONTAL);
    js_push_key(v7, v7_get_global(v7), "CUBEMAP_CROSS_THREE_BY_FOUR", CUBEMAP_CROSS_THREE_BY_FOUR);
    js_push_key(v7, v7_get_global(v7), "CUBEMAP_CROSS_FOUR_BY_THREE", CUBEMAP_CROSS_FOUR_BY_THREE);
    js_push_key(v7, v7_get_global(v7), "CUBEMAP_PANORAMA", CUBEMAP_PANORAMA);

    js_push_key(v7, v7_get_global(v7), "FONT_DEFAULT", FONT_DEFAULT);
    js_push_key(v7, v7_get_global(v7), "FONT_BITMAP", FONT_BITMAP);
    js_push_key(v7, v7_get_global(v7), "FONT_SDF", FONT_SDF);

    js_push_key(v7, v7_get_global(v7), "BLEND_ALPHA", BLEND_ALPHA);
    js_push_key(v7, v7_get_global(v7), "BLEND_ADDITIVE", BLEND_ADDITIVE);
    js_push_key(v7, v7_get_global(v7), "BLEND_MULTIPLIED", BLEND_MULTIPLIED);
    js_push_key(v7, v7_get_global(v7), "BLEND_ADD_COLORS", BLEND_ADD_COLORS);
    js_push_key(v7, v7_get_global(v7), "BLEND_SUBTRACT_COLORS", BLEND_SUBTRACT_COLORS);
    js_push_key(v7, v7_get_global(v7), "BLEND_CUSTOM", BLEND_CUSTOM);

    js_push_key(v7, v7_get_global(v7), "GESTURE_NONE", GESTURE_NONE);
    js_push_key(v7, v7_get_global(v7), "GESTURE_TAP", GESTURE_TAP);
    js_push_key(v7, v7_get_global(v7), "GESTURE_DOUBLETAP", GESTURE_DOUBLETAP);
    js_push_key(v7, v7_get_global(v7), "GESTURE_HOLD", GESTURE_HOLD);
    js_push_key(v7, v7_get_global(v7), "GESTURE_DRAG", GESTURE_DRAG);
    js_push_key(v7, v7_get_global(v7), "GESTURE_SWIPE_RIGHT", GESTURE_SWIPE_RIGHT);
    js_push_key(v7, v7_get_global(v7), "GESTURE_SWIPE_LEFT", GESTURE_SWIPE_LEFT);
    js_push_key(v7, v7_get_global(v7), "GESTURE_SWIPE_UP", GESTURE_SWIPE_UP);
    js_push_key(v7, v7_get_global(v7), "GESTURE_SWIPE_DOWN", GESTURE_SWIPE_DOWN);
    js_push_key(v7, v7_get_global(v7), "GESTURE_PINCH_IN", GESTURE_PINCH_IN);
    js_push_key(v7, v7_get_global(v7), "GESTURE_PINCH_OUT", GESTURE_PINCH_OUT);

    js_push_key(v7, v7_get_global(v7), "CAMERA_CUSTOM", CAMERA_CUSTOM);
    js_push_key(v7, v7_get_global(v7), "CAMERA_FREE", CAMERA_FREE);
    js_push_key(v7, v7_get_global(v7), "CAMERA_ORBITAL", CAMERA_ORBITAL);
    js_push_key(v7, v7_get_global(v7), "CAMERA_FIRST_PERSON", CAMERA_FIRST_PERSON);
    js_push_key(v7, v7_get_global(v7), "CAMERA_THIRD_PERSON", CAMERA_THIRD_PERSON);

    js_push_key(v7, v7_get_global(v7), "CAMERA_PERSPECTIVE", CAMERA_PERSPECTIVE);
    js_push_key(v7, v7_get_global(v7), "CAMERA_ORTHOGRAPHIC", CAMERA_ORTHOGRAPHIC);

    js_push_key(v7, v7_get_global(v7), "NPT_9PATCH", NPT_9PATCH);
    js_push_key(v7, v7_get_global(v7), "NPT_3PATCH_VERTICAL", NPT_3PATCH_VERTICAL);
    js_push_key(v7, v7_get_global(v7), "NPT_3PATCH_HORIZONTAL", NPT_3PATCH_HORIZONTAL);
}
