#include <v7/v7.h>
#include <raylib_easings/easings.h>
#include <easings_js.h>

static inline enum v7_err js_ease_linear_none(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseLinearNone(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_linear_in(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseLinearIn(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_linear_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseLinearOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_linear_in_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseLinearInOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_sine_in(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseSineIn(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_sine_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseSineOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_sine_in_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseSineInOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_circ_in(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseCircIn(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_circ_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseCircOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_circ_in_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseCircInOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_cubic_in(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseCubicIn(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_cubic_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseCubicOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_cubic_in_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseCubicInOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_quad_in(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseQuadIn(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_quad_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseQuadOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_quad_in_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseQuadInOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_expo_in(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseExpoIn(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_expo_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseExpoOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_expo_in_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseExpoInOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_back_in(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseBackIn(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_back_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseBackOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_back_in_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseBackInOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_bounce_in(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseBounceIn(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_bounce_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseBounceOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_bounce_in_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseBounceInOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_elastic_in(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseElasticIn(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_elastic_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseElasticOut(t, b, c, d));
    return V7_OK;
}

static inline enum v7_err js_ease_elastic_in_out(struct v7* v7, v7_val_t* res) {
    float t = (float)v7_get_double(v7, v7_arg(v7, 0));
    float b = (float)v7_get_double(v7, v7_arg(v7, 1));
    float c = (float)v7_get_double(v7, v7_arg(v7, 2));
    float d = (float)v7_get_double(v7, v7_arg(v7, 3));
    *res = v7_mk_number(v7, EaseElasticInOut(t, b, c, d));
    return V7_OK;
}

void raylib_v7_load_easings(struct v7* v7) {
    v7_set(v7, v7_get_global(v7), "PI", ~0, v7_mk_number(v7, PI));

    v7_set_method(v7, v7_get_global(v7), "EaseLinearNone", &js_ease_linear_none);
    v7_set_method(v7, v7_get_global(v7), "EaseLinearIn", &js_ease_linear_in);
    v7_set_method(v7, v7_get_global(v7), "EaseLinearOut", &js_ease_linear_out);
    v7_set_method(v7, v7_get_global(v7), "EaseLinearInOut", &js_ease_linear_in_out);

    v7_set_method(v7, v7_get_global(v7), "EaseSineIn", &js_ease_sine_in);
    v7_set_method(v7, v7_get_global(v7), "EaseSineOut", &js_ease_sine_out);
    v7_set_method(v7, v7_get_global(v7), "EaseSineInOut", &js_ease_sine_in_out);

    v7_set_method(v7, v7_get_global(v7), "EaseCircIn", &js_ease_circ_in);
    v7_set_method(v7, v7_get_global(v7), "EaseCircOut", &js_ease_circ_out);
    v7_set_method(v7, v7_get_global(v7), "EaseCircInOut", &js_ease_circ_in_out);

    v7_set_method(v7, v7_get_global(v7), "EaseCubicIn", &js_ease_cubic_in);
    v7_set_method(v7, v7_get_global(v7), "EaseCubicOut", &js_ease_cubic_out);
    v7_set_method(v7, v7_get_global(v7), "EaseCubicInOut", &js_ease_cubic_in_out);

    v7_set_method(v7, v7_get_global(v7), "EaseQuadIn", &js_ease_quad_in);
    v7_set_method(v7, v7_get_global(v7), "EaseQuadOut", &js_ease_quad_out);
    v7_set_method(v7, v7_get_global(v7), "EaseQuadInOut", &js_ease_quad_in_out);

    v7_set_method(v7, v7_get_global(v7), "EaseExpoIn", &js_ease_expo_in);
    v7_set_method(v7, v7_get_global(v7), "EaseExpoOut", &js_ease_expo_out);
    v7_set_method(v7, v7_get_global(v7), "EaseExpoInOut", &js_ease_expo_in_out);

    v7_set_method(v7, v7_get_global(v7), "EaseBackIn", &js_ease_back_in);
    v7_set_method(v7, v7_get_global(v7), "EaseBackOut", &js_ease_back_out);
    v7_set_method(v7, v7_get_global(v7), "EaseBackInOut", &js_ease_back_in_out);

    v7_set_method(v7, v7_get_global(v7), "EaseBounceIn", &js_ease_bounce_in);
    v7_set_method(v7, v7_get_global(v7), "EaseBounceOut", &js_ease_bounce_out);
    v7_set_method(v7, v7_get_global(v7), "EaseBounceInOut", &js_ease_bounce_in_out);

    v7_set_method(v7, v7_get_global(v7), "EaseElasticIn", &js_ease_elastic_in);
    v7_set_method(v7, v7_get_global(v7), "EaseElasticOut", &js_ease_elastic_out);
    v7_set_method(v7, v7_get_global(v7), "EaseElasticInOut", &js_ease_elastic_in_out);
}
