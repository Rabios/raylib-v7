#ifndef RAYLIB_V7_RLGL
#define RAYLIB_V7_RLGL

#include <v7/v7.h>

static inline enum v7_err js_rl_matrix_mode(struct v7* v7);
static inline enum v7_err js_rl_push_matrix(void);
static inline enum v7_err js_rl_pop_matrix(void);
static inline enum v7_err js_rl_load_identity(void);
static inline enum v7_err js_rl_translatef(struct v7* v7);
static inline enum v7_err js_rl_rotatef(struct v7* v7);
static inline enum v7_err js_rl_scalef(struct v7* v7);
static inline enum v7_err js_rl_multmatrixf(struct v7* v7);
static inline enum v7_err js_rl_frustum(struct v7* v7);
static inline enum v7_err js_rl_ortho(struct v7* v7);
static inline enum v7_err js_rl_viewport(struct v7* v7);

static inline enum v7_err js_rl_begin(struct v7* v7);
static inline enum v7_err js_rl_end(void);
static inline enum v7_err js_rl_vertex2i(struct v7* v7);
static inline enum v7_err js_rl_vertex2f(struct v7* v7);
static inline enum v7_err js_rl_vertex3f(struct v7* v7);
static inline enum v7_err js_rl_texcoord2f(struct v7* v7);
static inline enum v7_err js_rl_normal3f(struct v7* v7);
static inline enum v7_err js_rl_color4ub(struct v7* v7);
static inline enum v7_err js_rl_color3f(struct v7* v7);
static inline enum v7_err js_rl_color4f(struct v7* v7);

static inline enum v7_err js_rl_enable_texture(struct v7* v7);
static inline enum v7_err js_rl_disable_texture(void);
static inline enum v7_err js_rl_texture_parameters(struct v7* v7);
static inline enum v7_err js_rl_enable_shader(struct v7* v7);
static inline enum v7_err js_rl_disable_shader(void);
static inline enum v7_err js_rl_enable_framebuffer(struct v7* v7);
static inline enum v7_err js_rl_disable_framebuffer(void);
static inline enum v7_err js_rl_enable_depth_test(void);
static inline enum v7_err js_rl_disable_depth_test(void);
static inline enum v7_err js_rl_enable_depth_mask(void);
static inline enum v7_err js_rl_disable_depth_mask(void);
static inline enum v7_err js_rl_enable_backface_culling(void);
static inline enum v7_err js_rl_disable_backface_culling(void);
static inline enum v7_err js_rl_enable_scissor_test(void);
static inline enum v7_err js_rl_disable_scissor_test(void);
static inline enum v7_err js_rl_scissor(struct v7* v7);
static inline enum v7_err js_rl_enable_wire_mode(void);
static inline enum v7_err js_rl_disable_wire_mode(void);
static inline enum v7_err js_rl_set_line_width(struct v7* v7);
static inline enum v7_err js_rl_get_line_width(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_rl_enable_smooth_lines(void);
static inline enum v7_err js_rl_disable_smooth_lines(void);

static inline enum v7_err js_rl_clear_color(struct v7* v7);
static inline enum v7_err js_rl_clear_screen_buffers(void);
static inline enum v7_err js_rl_update_buffer(struct v7* v7);
static inline enum v7_err js_rl_load_attrib_buffer(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_rlgl_init(struct v7* v7);
static inline enum v7_err js_rlgl_close(void);
static inline enum v7_err js_rlgl_draw(void);
static inline enum v7_err js_rl_check_errors(void);

static inline enum v7_err js_rl_get_version(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_rl_check_buffer_limit(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_rl_set_debug_marker(struct v7* v7);
static inline enum v7_err js_rl_set_blend_mode(struct v7* v7);
static inline enum v7_err js_rl_load_extensions(struct v7* v7);

static inline enum v7_err js_rl_load_texture(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_rl_load_texture_depth(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_rl_load_texture_cubemap(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_rl_update_texture(struct v7* v7);
static inline enum v7_err js_rl_get_gl_texture_formats(struct v7* v7);
static inline enum v7_err js_rl_unload_texture(struct v7* v7);

static inline enum v7_err js_rl_generate_mipmaps(struct v7* v7);
static inline enum v7_err js_rl_read_texture_pixels(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_rl_read_screen_pixels(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_rl_load_framebuffer(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_rl_framebuffer_attach(struct v7* v7);
static inline enum v7_err js_rl_framebuffer_complete(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_rl_unload_framebuffer(struct v7* v7);

static inline enum v7_err js_rl_load_mesh(struct v7* v7);
static inline enum v7_err js_rl_update_mesh(struct v7* v7);
static inline enum v7_err js_rl_update_mesh_at(struct v7* v7);
static inline enum v7_err js_rl_draw_mesh(struct v7* v7);
static inline enum v7_err js_rl_draw_mesh_instanced(struct v7* v7);
static inline enum v7_err js_rl_unload_mesh(struct v7* v7);

void raylib_v7_load_rlgl(struct v7* v7);

#endif
