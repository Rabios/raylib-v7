#ifndef RAYLIB_V7_RAYMATH
#define RAYLIB_V7_RAYMATH

#include <v7/v7.h>

static inline enum v7_err js_clamp(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_lerp(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_normalize(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_remap(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_vec2_zero(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_one(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_add(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_add_value(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_subtract(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_subtract_value(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_length(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_length_sqr(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_dot_product(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_distance(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_angle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_scale(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_multiply(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_negate(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_divide(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_normalize(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_lerp(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec2_rotate(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_vec3_zero(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_one(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_add(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_add_value(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_subtract(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_subtract_value(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_scale(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_multiply(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_cross_product(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_perpendicular(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_length(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_length_sqr(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_dot_product(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_distance(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_negate(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_divide(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_normalize(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_ortho_normalize(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_transform(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_rotate_by_quaternion(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_lerp(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_min(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_max(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_barycenter(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_to_float_v(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_to_float(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_unproject(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_vec3_reflect(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_matrix_determinant(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_trace(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_transpose(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_invert(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_normalize(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_identity(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_add(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_subtract(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_translate(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_rotate(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_rotate_xyz(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_rotate_x(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_rotate_y(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_rotate_z(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_scale(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_multiply(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_frustum(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_perspective(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_ortho(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_look_at(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_to_float_v(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_matrix_to_float(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_quaternion_add(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_add_value(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_subtract(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_subtract_value(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_identity(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_length(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_normalize(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_invert(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_multiply(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_scale(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_divide(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_lerp(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_nlerp(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_slerp(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_from_vector3_to_vector3(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_from_matrix(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_to_matrix(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_from_axis_angle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_to_axis_angle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_from_euler(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_to_euler(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_quaternion_transform(struct v7* v7, v7_val_t* res);

void raylib_v7_load_raymath(struct v7* v7);

#endif