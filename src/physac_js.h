#ifndef RAYLIB_V7_PHYSAC
#define RAYLIB_V7_PHYSAC

#include <v7/v7.h>

static inline enum v7_err js_init_physics(void);
static inline enum v7_err js_run_physics_step(void);
static inline enum v7_err js_set_physics_time_step(struct v7* v7);
static inline enum v7_err js_physics_enabled(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_physics_gravity(struct v7* v7);
static inline enum v7_err js_create_physics_body_circle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_create_physics_body_rectangle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_create_physics_body_polygon(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_physics_add_force(struct v7* v7);
static inline enum v7_err js_physics_add_torque(struct v7* v7);
static inline enum v7_err js_physics_shatter(struct v7* v7);
static inline enum v7_err js_get_physics_bodies_count(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_physac_get_physics_body(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_physics_shape_type(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_physics_shape_vertices_count(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_physics_shape_vertex(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_physics_body_rotation(struct v7* v7);
static inline enum v7_err js_destroy_physics_body(struct v7* v7);
static inline enum v7_err js_reset_physics(void);
static inline enum v7_err js_close_physics(void);

void raylib_v7_load_physac(struct v7* v7);

#endif
