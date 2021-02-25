#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>
#include <gestures.h>
#include <gestures_js.h>

static inline enum v7_err js_process_gesture_event(struct v7* v7) {
    v7_val_t touchAction = v7_get(v7, v7_arg(v7, 0), "touchAction", ~0);
    v7_val_t pointerCount = v7_get(v7, v7_arg(v7, 0), "pointerCount", ~0);
    v7_val_t pointerId = v7_get(v7, v7_arg(v7, 0), "pointerId", ~0);
    v7_val_t position = v7_get(v7, v7_arg(v7, 0), "position", ~0);
    ProcessGestureEvent((GestureEvent) { touchAction, pointerCount, pointerId, position });
    return V7_OK;
}

static inline enum v7_err js_update_gestures(void) {
    UpdateGestures();
    return V7_OK;
}

void raylib_v7_load_gestures(struct v7* v7) {
    js_push_key(v7, v7_get_global(v7), "TOUCH_UP", TOUCH_UP);
    js_push_key(v7, v7_get_global(v7), "TOUCH_DOWN", TOUCH_DOWN);
    js_push_key(v7, v7_get_global(v7), "TOUCH_MOVE", TOUCH_MOVE);

    v7_set_method(v7, v7_get_global(v7), "ProcessGestureEvent", &js_process_gesture_event);
    v7_set_method(v7, v7_get_global(v7), "UpdateGestures", &js_update_gestures);
}
