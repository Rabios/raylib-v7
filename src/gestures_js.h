#ifndef RAYLIB_V7_GESTURES
#define RAYLIB_V7_GESTURES

#include <v7/v7.h>

static inline enum v7_err js_process_gesture_event(struct v7* v7);
static inline enum v7_err js_update_gestures(void);

void raylib_v7_load_gestures(struct v7* v7);

#endif