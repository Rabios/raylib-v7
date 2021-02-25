#ifndef RAYLIB_V7_MODELS
#define RAYLIB_V7_MODELS

#include <v7/v7.h>

static inline enum v7_err js_draw_line3d(struct v7* v7);
static inline enum v7_err js_draw_point3d(struct v7* v7);
static inline enum v7_err js_draw_circle3d(struct v7* v7);
static inline enum v7_err js_draw_triangle3d(struct v7* v7);
static inline enum v7_err js_draw_triangle_strip_3d(struct v7* v7);
static inline enum v7_err js_draw_cube(struct v7* v7);
static inline enum v7_err js_draw_cube_v(struct v7* v7);
static inline enum v7_err js_draw_cube_wires(struct v7* v7);
static inline enum v7_err js_draw_cube_wires_v(struct v7* v7);
static inline enum v7_err js_draw_cube_texture(struct v7* v7);
static inline enum v7_err js_draw_sphere(struct v7* v7);
static inline enum v7_err js_draw_sphere_ex(struct v7* v7);
static inline enum v7_err js_draw_sphere_wires(struct v7* v7);
static inline enum v7_err js_draw_cylinder(struct v7* v7);
static inline enum v7_err js_draw_cylinder_wires(struct v7* v7);
static inline enum v7_err js_draw_plane(struct v7* v7);
static inline enum v7_err js_draw_ray(struct v7* v7);
static inline enum v7_err js_draw_grid(struct v7* v7);
static inline enum v7_err js_draw_gizmo(struct v7* v7);

static inline enum v7_err js_load_model(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_model_from_mesh(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_model(struct v7* v7);
static inline enum v7_err js_unload_model_keep_meshes(struct v7* v7);

static inline enum v7_err js_load_meshes(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_mesh(struct v7* v7);
static inline enum v7_err js_export_mesh(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_load_materials(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_material_default(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_material(struct v7* v7);
static inline enum v7_err js_set_material_texture(struct v7* v7);
static inline enum v7_err js_set_model_mesh_material(struct v7* v7);

static inline enum v7_err js_load_model_animations(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_update_model_animation(struct v7* v7);
static inline enum v7_err js_unload_model_animation(struct v7* v7);
static inline enum v7_err js_model_animation_valid(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gen_mesh_poly(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_mesh_plane(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_mesh_cube(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_mesh_sphere(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_mesh_hemi_sphere(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_mesh_cylinder(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_mesh_torus(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_mesh_knot(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_mesh_heightmap(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_mesh_cubicmap(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_mesh_bounding_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_mesh_tangents(struct v7* v7);
static inline enum v7_err js_mesh_binormals(struct v7* v7);
static inline enum v7_err js_mesh_normals_smooth(struct v7* v7);

static inline enum v7_err js_draw_model(struct v7* v7);
static inline enum v7_err js_draw_model_ex(struct v7* v7);
static inline enum v7_err js_draw_model_wires(struct v7* v7);
static inline enum v7_err js_draw_model_wires_ex(struct v7* v7);
static inline enum v7_err js_draw_bounding_box(struct v7* v7);
static inline enum v7_err js_draw_billboard(struct v7* v7);
static inline enum v7_err js_draw_billboard_rec(struct v7* v7);

static inline enum v7_err js_check_collision_spheres(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_boxes(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_box_sphere(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_ray_sphere(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_ray_sphere_ex(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_check_collision_ray_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_collision_ray_mesh(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_collision_ray_model(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_collision_ray_triangle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_collision_ray_ground(struct v7* v7, v7_val_t* res);

void raylib_v7_load_models(struct v7* v7);

#endif
