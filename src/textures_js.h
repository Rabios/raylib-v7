#ifndef RAYLIB_V7_TEXTURES
#define RAYLIB_V7_TEXTURES

#include <v7/v7.h>

static inline enum v7_err js_load_image(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_image_raw(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_image_anim(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_image_from_memory(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_image(struct v7* v7);
static inline enum v7_err js_export_image(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_export_image_as_code(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gen_image_color(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_image_gradient_v(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_image_gradient_h(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_image_gradient_radial(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_image_checked(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_image_white_noise(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_image_perlin_noise(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_image_cellular(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_image_copy(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_image_from_image(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_image_text(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_image_text_ex(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_image_format(struct v7* v7);
static inline enum v7_err js_image_to_pot(struct v7* v7);
static inline enum v7_err js_image_crop(struct v7* v7);
static inline enum v7_err js_image_alpha_crop(struct v7* v7);
static inline enum v7_err js_image_alpha_clear(struct v7* v7);
static inline enum v7_err js_image_alpha_mask(struct v7* v7);
static inline enum v7_err js_image_alpha_premultiply(struct v7* v7);
static inline enum v7_err js_image_resize(struct v7* v7);
static inline enum v7_err js_image_resize_nn(struct v7* v7);
static inline enum v7_err js_image_resize_canvas(struct v7* v7);
static inline enum v7_err js_image_mipmaps(struct v7* v7);
static inline enum v7_err js_image_dither(struct v7* v7);
static inline enum v7_err js_image_flip_vertical(struct v7* v7);
static inline enum v7_err js_image_flip_horizontal(struct v7* v7);
static inline enum v7_err js_image_rotate_cw(struct v7* v7);
static inline enum v7_err js_image_rotate_ccw(struct v7* v7);
static inline enum v7_err js_image_color_tint(struct v7* v7);
static inline enum v7_err js_image_color_invert(struct v7* v7);
static inline enum v7_err js_image_color_grayscale(struct v7* v7);
static inline enum v7_err js_image_color_contrast(struct v7* v7);
static inline enum v7_err js_image_color_brightness(struct v7* v7);
static inline enum v7_err js_image_color_replace(struct v7* v7);
static inline enum v7_err js_load_image_colors(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_image_palette(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_image_alpha_border(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_image_clear_background(struct v7* v7);
static inline enum v7_err js_image_draw_pixel(struct v7* v7);
static inline enum v7_err js_image_draw_pixel_v(struct v7* v7);
static inline enum v7_err js_image_draw_line(struct v7* v7);
static inline enum v7_err js_image_draw_line_v(struct v7* v7);
static inline enum v7_err js_image_draw_circle(struct v7* v7);
static inline enum v7_err js_image_draw_circle_v(struct v7* v7);
static inline enum v7_err js_image_draw_rectangle(struct v7* v7);
static inline enum v7_err js_image_draw_rectangle_v(struct v7* v7);
static inline enum v7_err js_image_draw_rectangle_rec(struct v7* v7);
static inline enum v7_err js_image_draw_rectangle_lines(struct v7* v7);
static inline enum v7_err js_image_draw(struct v7* v7);
static inline enum v7_err js_image_draw_text(struct v7* v7);
static inline enum v7_err js_image_draw_text_ex(struct v7* v7);

static inline enum v7_err js_load_texture(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_texture_from_image(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_texture_cubemap(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_render_texture(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_texture(struct v7* v7);
static inline enum v7_err js_unload_render_texture(struct v7* v7);
static inline enum v7_err js_update_texture(struct v7* v7);
static inline enum v7_err js_update_texture_rec(struct v7* v7);
static inline enum v7_err js_get_texture_data(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_screen_data(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gen_texture_mipmaps(struct v7* v7);
static inline enum v7_err js_set_texture_filter(struct v7* v7);
static inline enum v7_err js_set_texture_wrap(struct v7* v7);

static inline enum v7_err js_draw_texture(struct v7* v7);
static inline enum v7_err js_draw_texture_v(struct v7* v7);
static inline enum v7_err js_draw_texture_ex(struct v7* v7);
static inline enum v7_err js_draw_texture_rec(struct v7* v7);
static inline enum v7_err js_draw_texture_quad(struct v7* v7);
static inline enum v7_err js_draw_texture_tiled(struct v7* v7);
static inline enum v7_err js_draw_texture_pro(struct v7* v7);
static inline enum v7_err js_draw_texture_npatch(struct v7* v7);

static inline enum v7_err js_fade(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_color_to_int(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_color_normalize(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_color_from_normalized(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_color_to_hsv(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_color_from_hsv(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_color_alpha(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_color_alpha_blend(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_color_get_color(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_pixel_color(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_pixel_color(struct v7* v7);
static inline enum v7_err js_get_pixel_data_size(struct v7* v7, v7_val_t* res);

void raylib_v7_load_textures(struct v7* v7);

#endif