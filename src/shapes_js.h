#ifndef RAYLIB_V7_SHAPES
#define RAYLIB_V7_SHAPES

#include <v7/v7.h>

static inline enum v7_err js_draw_pixel(struct v7* v7);
static inline enum v7_err js_draw_pixel_v(struct v7* v7);
static inline enum v7_err js_draw_line(struct v7* v7);
static inline enum v7_err js_draw_line_v(struct v7* v7);
static inline enum v7_err js_draw_line_ex(struct v7* v7);
static inline enum v7_err js_draw_line_bezier(struct v7* v7);
static inline enum v7_err js_draw_line_strip(struct v7* v7);
static inline enum v7_err js_draw_circle(struct v7* v7);
static inline enum v7_err js_draw_circle_sector(struct v7* v7);
static inline enum v7_err js_draw_circle_sector_lines(struct v7* v7);
static inline enum v7_err js_draw_circle_gradient(struct v7* v7);
static inline enum v7_err js_draw_circle_v(struct v7* v7);
static inline enum v7_err js_draw_circle_lines(struct v7* v7);
static inline enum v7_err js_draw_ellipse(struct v7* v7);
static inline enum v7_err js_draw_ellipse_lines(struct v7* v7);
static inline enum v7_err js_draw_ring(struct v7* v7);
static inline enum v7_err js_draw_ring_lines(struct v7* v7);
static inline enum v7_err js_draw_rectangle(struct v7* v7);
static inline enum v7_err js_draw_rectangle_v(struct v7* v7);
static inline enum v7_err js_draw_rectangle_rec(struct v7* v7);
static inline enum v7_err js_draw_rectangle_pro(struct v7* v7);
static inline enum v7_err js_draw_rectangle_gradient_v(struct v7* v7);
static inline enum v7_err js_draw_rectangle_gradient_h(struct v7* v7);
static inline enum v7_err js_draw_rectangle_gradient_ex(struct v7* v7);
static inline enum v7_err js_draw_rectangle_lines(struct v7* v7);
static inline enum v7_err js_draw_rectangle_lines_ex(struct v7* v7);
static inline enum v7_err js_draw_rectangle_rounded(struct v7* v7);
static inline enum v7_err js_draw_rectangle_rounded_lines(struct v7* v7);
static inline enum v7_err js_draw_triangle(struct v7* v7);
static inline enum v7_err js_draw_triangle_lines(struct v7* v7);
static inline enum v7_err js_draw_triangle_fan(struct v7* v7);
static inline enum v7_err js_draw_triangle_strip(struct v7* v7);
static inline enum v7_err js_draw_poly(struct v7* v7);
static inline enum v7_err js_draw_poly_lines(struct v7* v7);

static inline enum v7_err js_check_collision_recs(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_circles(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_circle_rec(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_point_rec(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_point_circle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_point_triangle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_lines(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_collision_rec(struct v7* v7, v7_val_t* res);

void raylib_v7_load_shapes(struct v7* v7);

#endif