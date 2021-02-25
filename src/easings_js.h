#ifndef RAYLIB_V7_EASINGS
#define RAYLIB_V7_EASINGS

#include <v7/v7.h>

static inline enum v7_err js_ease_linear_none(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_linear_in(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_linear_out(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_linear_in_out(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_ease_sine_in(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_sine_out(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_sine_in_out(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_ease_circ_in(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_circ_out(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_circ_in_out(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_ease_cubic_in(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_cubic_out(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_cubic_in_out(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_ease_quad_in(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_quad_out(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_quad_in_out(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_ease_expo_in(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_expo_out(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_expo_in_out(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_ease_back_in(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_back_out(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_back_in_out(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_ease_bounce_in(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_bounce_out(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_bounce_in_out(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_ease_elastic_in(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_elastic_out(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_ease_elastic_in_out(struct v7* v7, v7_val_t* res);

void raylib_v7_load_easings(struct v7* v7);

#endif