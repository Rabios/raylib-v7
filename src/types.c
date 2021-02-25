#include <v7/v7.h>
#include <raylib.h>
#include <gestures.h>
#include <get_set.h>
#include <types.h>

static inline enum v7_err js_color(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    unsigned int r = v7_get_int(v7, v7_arg(v7, 0));
    unsigned int g = v7_get_int(v7, v7_arg(v7, 1));
    unsigned int b = v7_get_int(v7, v7_arg(v7, 2));
    unsigned int a = v7_get_int(v7, v7_arg(v7, 3));

    js_push_key(v7, this, "r", r);
    js_push_key(v7, this, "g", g);
    js_push_key(v7, this, "b", b);
    js_push_key(v7, this, "a", a);

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_vec2(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    float x = (float) v7_get_double(v7, v7_arg(v7, 0));
    float y = (float) v7_get_double(v7, v7_arg(v7, 1));
    
    js_push_key(v7, this, "x", x);
    js_push_key(v7, this, "y", y);

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_vec3(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    float x = (float)v7_get_double(v7, v7_arg(v7, 0));
    float y = (float)v7_get_double(v7, v7_arg(v7, 1));
    float z = (float)v7_get_double(v7, v7_arg(v7, 2));
    
    js_push_key(v7, this, "x", x);
    js_push_key(v7, this, "y", y);
    js_push_key(v7, this, "z", z);

    *res = this;
    return V7_OK;
}

// NOTE: Quaternion type also uses js_vec4
static inline enum v7_err js_vec4(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    float x = (float)v7_get_double(v7, v7_arg(v7, 0));
    float y = (float)v7_get_double(v7, v7_arg(v7, 1));
    float z = (float)v7_get_double(v7, v7_arg(v7, 2));
    float w = (float)v7_get_double(v7, v7_arg(v7, 3));
    
    js_push_key(v7, this, "x", x);
    js_push_key(v7, this, "y", y);
    js_push_key(v7, this, "z", z);
    js_push_key(v7, this, "w", w);

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_rect(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);
    
    float x = (float)v7_get_double(v7, v7_arg(v7, 0));
    float y = (float)v7_get_double(v7, v7_arg(v7, 1));
    float width = (float)v7_get_double(v7, v7_arg(v7, 2));
    float height = (float)v7_get_double(v7, v7_arg(v7, 3));

    js_push_key(v7, this, "x", x);
    js_push_key(v7, this, "y", y);
    js_push_key(v7, this, "width", width);
    js_push_key(v7, this, "height", height);

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_matrix(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    float m0 = (float)v7_get_double(v7, v7_arg(v7, 0));
    float m1 = (float)v7_get_double(v7, v7_arg(v7, 1));
    float m2 = (float)v7_get_double(v7, v7_arg(v7, 2));
    float m3 = (float)v7_get_double(v7, v7_arg(v7, 3));
    float m4 = (float)v7_get_double(v7, v7_arg(v7, 4));
    float m5 = (float)v7_get_double(v7, v7_arg(v7, 5));
    float m6 = (float)v7_get_double(v7, v7_arg(v7, 6));
    float m7 = (float)v7_get_double(v7, v7_arg(v7, 7));
    float m8 = (float)v7_get_double(v7, v7_arg(v7, 8));
    float m9 = (float)v7_get_double(v7, v7_arg(v7, 9));
    float m10 = (float)v7_get_double(v7, v7_arg(v7, 10));
    float m11 = (float)v7_get_double(v7, v7_arg(v7, 11));
    float m12 = (float)v7_get_double(v7, v7_arg(v7, 12));
    float m13 = (float)v7_get_double(v7, v7_arg(v7, 13));
    float m14 = (float)v7_get_double(v7, v7_arg(v7, 14));
    float m15 = (float)v7_get_double(v7, v7_arg(v7, 15));

    js_push_key(v7, this, "m0", m0);
    js_push_key(v7, this, "m1", m1);
    js_push_key(v7, this, "m2", m2);
    js_push_key(v7, this, "m3", m3);
    js_push_key(v7, this, "m4", m4);
    js_push_key(v7, this, "m5", m5);
    js_push_key(v7, this, "m6", m6);
    js_push_key(v7, this, "m7", m7);
    js_push_key(v7, this, "m8", m8);
    js_push_key(v7, this, "m9", m9);
    js_push_key(v7, this, "m10", m10);
    js_push_key(v7, this, "m11", m11);
    js_push_key(v7, this, "m12", m12);
    js_push_key(v7, this, "m13", m13);
    js_push_key(v7, this, "m14", m14);
    js_push_key(v7, this, "m15", m15);

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_ray(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    Vector3 position = js_get_vec3(v7, 0);
    Vector3 direction = js_get_vec3(v7, 1);

    js_push_vec3(v7, this, "position", position);
    js_push_vec3(v7, this, "direction", direction);

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_bounding_box(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    Vector3 min = js_get_vec3(v7, 0);
    Vector3 max = js_get_vec3(v7, 1);

    js_push_vec3(v7, this, "min", min);
    js_push_vec3(v7, this, "max", max);

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_npatch_info(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    Rectangle source = js_get_rect(v7, 0);

    int left = v7_get_int(v7, v7_arg(v7, 1));
    int right = v7_get_int(v7, v7_arg(v7, 2));
    int top = v7_get_int(v7, v7_arg(v7, 3));
    int bottom = v7_get_int(v7, v7_arg(v7, 4));
    int type = v7_get_int(v7, v7_arg(v7, 5));
    
    js_push_rect(v7, this, "source", source);
    js_push_key(v7, this, "left", left);
    js_push_key(v7, this, "right", right);
    js_push_key(v7, this, "top", top);
    js_push_key(v7, this, "bottom", bottom);
    js_push_key(v7, this, "type", type);

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_transform(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    Vector3 translation = js_get_vec3(v7, 0);
    Quaternion rotation = js_get_quat(v7, 1);
    Vector3 scale = js_get_vec3(v7, 2);

    js_push_vec3(v7, this, "translation", translation);
    js_push_quat(v7, this, "rotation", rotation);
    js_push_vec3(v7, this, "scale", scale);

    *res = this;
    return V7_OK;
}

// NOTE: Camera type also uses js_camera_3d
static inline enum v7_err js_camera_3d(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    Vector3 position = js_get_vec3(v7, 0);
    Vector3 target = js_get_vec3(v7, 1);
    Vector3 up = js_get_vec3(v7, 2);
    float fovy = (float)v7_get_double(v7, v7_arg(v7, 3));
    int type = v7_get_int(v7, v7_arg(v7, 4));

    js_push_vec3(v7, this, "position", position);
    js_push_vec3(v7, this, "target", target);
    js_push_vec3(v7, this, "up", up);
    js_push_key(v7, this, "fovy", fovy);
    js_push_key(v7, this, "type", type);

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_camera_2d(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    Vector2 offset = js_get_vec2(v7, 0);
    Vector2 target = js_get_vec2(v7, 1);
    float rotation = (float)v7_get_double(v7, v7_arg(v7, 2));
    float zoom = (float)v7_get_double(v7, v7_arg(v7, 3));

    js_push_vec2(v7, this, "offset", offset);
    js_push_vec2(v7, this, "target", target);
    js_push_key(v7, this, "rotation", rotation);
    js_push_key(v7, this, "zoom", zoom);

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_vr_device_info(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);

    int hResolution = v7_get_int(v7, v7_arg(v7, 0));
    int vResolution = v7_get_int(v7, v7_arg(v7, 1));
    float hScreenSize = (float)v7_get_double(v7, v7_arg(v7, 2));
    float vScreenSize = (float)v7_get_double(v7, v7_arg(v7, 3));
    float vScreenCenter = (float)v7_get_double(v7, v7_arg(v7, 4));
    float eyeToScreenDistance = (float)v7_get_double(v7, v7_arg(v7, 5));
    float lensSeparationDistance = (float)v7_get_double(v7, v7_arg(v7, 6));
    float interpupillaryDistance = (float)v7_get_double(v7, v7_arg(v7, 7));
    float lensDistortionValues[4] = { v7_array_get(v7, v7_arg(v7, 8), 0), v7_array_get(v7, v7_arg(v7, 8), 1), v7_array_get(v7, v7_arg(v7, 8), 2), v7_array_get(v7, v7_arg(v7, 8), 3) };
    float chromaAbCorrection[4] = { v7_array_get(v7, v7_arg(v7, 9), 0), v7_array_get(v7, v7_arg(v7, 9), 1), v7_array_get(v7, v7_arg(v7, 9), 2), v7_array_get(v7, v7_arg(v7, 9), 3) };
    
    js_push_key(v7, this, "hResolution", hResolution);
    js_push_key(v7, this, "vResolution", vResolution);
    js_push_key(v7, this, "hScreenSize", hScreenSize);
    js_push_key(v7, this, "vScreenSize", vScreenSize);
    js_push_key(v7, this, "vScreenCenter", vScreenCenter);
    js_push_key(v7, this, "eyeToScreenDistance", eyeToScreenDistance);
    js_push_key(v7, this, "lensSeparationDistance", lensSeparationDistance);
    js_push_key(v7, this, "interpupillaryDistance", interpupillaryDistance);

    js_push_val(v7, this, "lensDistortionValues", v7_mk_array(v7));
    for (int i = 0; i < 4; i++) {
        v7_val_t arr = v7_get(v7, this, "lensDistortionValues", ~0);
        v7_array_push(v7, arr, v7_mk_number(v7, lensDistortionValues[i]));
    }

    js_push_val(v7, this, "chromaAbCorrection", v7_mk_array(v7));
    for (int i = 0; i < 4; i++) {
        v7_val_t arr = v7_get(v7, this, "lensDistortionValues", ~0);
        v7_array_push(v7, arr, v7_mk_number(v7, chromaAbCorrection[i]));
    }

    *res = this;
    return V7_OK;
}

static inline enum v7_err js_gesture_event(struct v7* v7, v7_val_t* res) {
    v7_val_t this = v7_get_this(v7);
    int touchAction = v7_get_int(v7, v7_arg(v7, 0));
    int pointerCount = v7_get_int(v7, v7_arg(v7, 1));
    int pointerId[4] = {
        v7_get_int(v7, v7_get(v7, v7_arg(v7, 2), "0", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, 2), "1", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, 2), "2", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, 2), "3", ~0)),
    };
    v7_val_t *position = v7_get(v7, this, "position", ~0);
    
    js_push_key(v7, this, "touchAction", touchAction);
    js_push_key(v7, this, "pointerCount", pointerCount);

    js_push_val(v7, this, "pointerId", v7_mk_array(v7));
    for (int i = 0; i < 4; i++) v7_array_push(v7, v7_get(v7, this, "pointerId", ~0), v7_mk_number(v7, pointerId[i]));
    
    js_push_val(v7, this, "position", v7_mk_array(v7));
    js_push_vec2(v7, v7_get(v7, this, "position", ~0), "0", js_get_vec2(v7, 3));
    js_push_vec2(v7, v7_get(v7, this, "position", ~0), "1", js_get_vec2(v7, 4));
    js_push_vec2(v7, v7_get(v7, this, "position", ~0), "2", js_get_vec2(v7, 5));
    js_push_vec2(v7, v7_get(v7, this, "position", ~0), "3", js_get_vec2(v7, 6));

    *res = this;
    return V7_OK;
}

void raylib_v7_load_types(struct v7* v7) {
    v7_set(v7, v7_get_global(v7), "Color", ~0, v7_mk_function_with_proto(v7, js_color, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Vector2", ~0, v7_mk_function_with_proto(v7, js_vec2, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Vector3", ~0, v7_mk_function_with_proto(v7, js_vec3, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Vector4", ~0, v7_mk_function_with_proto(v7, js_vec4, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Quaternion", ~0, v7_mk_function_with_proto(v7, js_vec4, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Rectangle", ~0, v7_mk_function_with_proto(v7, js_rect, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Matrix", ~0, v7_mk_function_with_proto(v7, js_matrix, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Ray", ~0, v7_mk_function_with_proto(v7, js_ray, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "BoundingBox", ~0, v7_mk_function_with_proto(v7, js_bounding_box, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "NPatchInfo", ~0, v7_mk_function_with_proto(v7, js_npatch_info, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Tranform", ~0, v7_mk_function_with_proto(v7, js_transform, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Camera3D", ~0, v7_mk_function_with_proto(v7, js_camera_3d, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Camera", ~0, v7_mk_function_with_proto(v7, js_camera_3d, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "Camera2D", ~0, v7_mk_function_with_proto(v7, js_camera_2d, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "VrDeviceInfo", ~0, v7_mk_function_with_proto(v7, js_vr_device_info, v7_mk_object(v7)));
    v7_set(v7, v7_get_global(v7), "GestureEvent", ~0, v7_mk_function_with_proto(v7, js_gesture_event, v7_mk_object(v7)));
}
