#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS

#include <raylib.h>
#include <physac.h>
#include <get_set.h>
#include <v7/v7.h>
#include <physac_js.h>

static inline Matrix2x2 js_matrix2x2_from_obj(struct v7* v7, v7_val_t obj);
static inline void js_push_matrix2x2(struct v7* v7, v7_val_t obj, char* var_name, Matrix2x2 matrix2x2);

static inline PhysicsShape js_physics_shape_from_obj(struct v7* v7, v7_val_t obj);
static inline PolygonData js_polygon_data_from_obj(struct v7* v7, v7_val_t obj);

static inline PhysicsBodyData js_physics_body_data_from_obj(struct v7* v7, v7_val_t obj);
static inline PhysicsBodyData js_get_physics_body_data(struct v7* v7, unsigned int arg);

//static inline PhysicsBody js_physics_body_from_obj(struct v7* v7, v7_val_t obj);
//static inline PhysicsBody js_get_physics_body(struct v7* v7, unsigned int arg);

static inline void js_return_physics_body_data(struct v7* v7, v7_val_t* res, PhysicsBodyData body);
static inline void js_return_physics_body(struct v7* v7, v7_val_t* res, PhysicsBody body);

static inline PolygonData js_polygon_data_from_obj(struct v7* v7, v7_val_t obj) {
    int vertexCount = v7_get_int(v7, v7_get(v7, obj, "vertexCount", ~0));
    Vector2 positions[PHYSAC_MAX_VERTICES] = { 0 };
    Vector2 normals[PHYSAC_MAX_VERTICES] = { 0 };
    for (int i = 0; i < vertexCount; i++) {
        positions[i] = js_vec2_from_obj(v7, v7_array_get(v7, v7_get(v7, obj, "positions", ~0), i));
    }
    for (int i = 0; i < vertexCount; i++) {
        normals[i] = js_vec2_from_obj(v7, v7_array_get(v7, v7_get(v7, obj, "normals", ~0), i));
    }
    PolygonData data = (PolygonData){
        vertexCount,
        *positions,
        *normals
    };
    return data;
}

static inline Matrix2x2 js_matrix2x2_from_obj(struct v7* v7, v7_val_t obj) {
    Matrix2x2 matrix2x2 = (Matrix2x2){
        v7_get_double(v7, v7_get(v7, obj, "m00", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m01", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m10", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m11", ~0)),
    };
    return matrix2x2;
}

static inline PhysicsShape js_physics_shape_from_obj(struct v7* v7, v7_val_t obj) {
    PhysicsBodyData bodyData = js_physics_body_data_from_obj(v7, v7_get(v7, obj, "body", ~0));
    PhysicsShape shape = (PhysicsShape){
        v7_get_int(v7, v7_get(v7, obj, "type", ~0)),
        &bodyData,
        v7_get_double(v7, v7_get(v7, obj, "radius", ~0)),
        js_matrix2x2_from_obj(v7, v7_get(v7, obj, "transform", ~0)),
        js_polygon_data_from_obj(v7, v7_get(v7, obj, "vertexData", ~0)),
    };
    return shape;
}

static inline void js_push_matrix2x2(struct v7* v7, v7_val_t obj, char* var_name, Matrix2x2 matrix2x2) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m00", ~0, matrix2x2.m00);
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m01", ~0, matrix2x2.m01);
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m10", ~0, matrix2x2.m10);
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m11", ~0, matrix2x2.m11);
}

static inline PhysicsBodyData js_physics_body_data_from_obj(struct v7* v7, v7_val_t obj) {
    PhysicsBodyData body = (PhysicsBodyData){
        v7_get_int(v7, v7_get(v7, obj, "id", ~0)),
        (bool)v7_get_bool(v7, v7_get(v7, obj, "enabled", ~0)),
        js_vec2_from_obj(v7, v7_get(v7, obj, "position", ~0)),
        js_vec2_from_obj(v7, v7_get(v7, obj, "velocity", ~0)),
        js_vec2_from_obj(v7, v7_get(v7, obj, "force", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "angularVelocty", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "torque", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "orient", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "inertia", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "inverseInertia", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "mass", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "inverseMass", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "staticFriction", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "dynamicFriction", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "restitution", ~0)),
        (bool)v7_get_bool(v7, v7_get(v7, obj, "useGravity", ~0)),
        (bool)v7_get_bool(v7, v7_get(v7, obj, "isGrounded", ~0)),
        (bool)v7_get_bool(v7, v7_get(v7, obj, "freezeOrient", ~0)),
        js_physics_shape_from_obj(v7, v7_get(v7, obj, "shape", ~0)),
    };
    return body;
}

/*
static inline PhysicsBody js_physics_body_from_obj(struct v7* v7, v7_val_t obj) {
    PhysicsBodyData body = js_physics_body_data_from_obj(v7, obj);
    return (PhysicsBody)&body;
}
*/

static inline PhysicsBodyData js_get_physics_body_data(struct v7* v7, unsigned int arg) {
    PhysicsBodyData body = (PhysicsBodyData) {
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "id", ~0)),
        v7_get_bool(v7, v7_get(v7, v7_arg(v7, arg), "enabled", ~0)),
        js_vec2_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "position", ~0)),
        js_vec2_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "velocity", ~0)),
        js_vec2_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "force", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "angularVelocty", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "torque", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "orient", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "inertia", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "inverseInertia", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "mass", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "inverseMass", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "staticFriction", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "dynamicFriction", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "restitution", ~0)),
        v7_get_bool(v7, v7_get(v7, v7_arg(v7, arg), "useGravity", ~0)),
        v7_get_bool(v7, v7_get(v7, v7_arg(v7, arg), "isGrounded", ~0)),
        v7_get_bool(v7, v7_get(v7, v7_arg(v7, arg), "freezeOrient", ~0)),
        js_physics_shape_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "shape", ~0)),
    };
    return body;
}

/*
static inline PhysicsBody js_get_physics_body(struct v7* v7, unsigned int arg) {
    PhysicsBodyData body = js_get_physics_body_data(v7, arg);
    return (PhysicsBody)&body;
}
*/

static inline void js_return_physics_body_data(struct v7* v7, v7_val_t* res, PhysicsBodyData body) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "id", ~0, v7_mk_number(v7, body.id));
    v7_set(v7, *res, "enabled", ~0, v7_mk_boolean(v7, (int)body.enabled));
    js_push_vec2(v7, *res, "position", body.position);
    js_push_vec2(v7, *res, "velocity", body.velocity);
    js_push_vec2(v7, *res, "force", body.force);
    v7_set(v7, *res, "angularVelocity", ~0, v7_mk_number(v7, body.angularVelocity));
    v7_set(v7, *res, "torque", ~0, v7_mk_number(v7, body.torque));
    v7_set(v7, *res, "orient", ~0, v7_mk_number(v7, body.orient));
    v7_set(v7, *res, "inertia", ~0, v7_mk_number(v7, body.inertia));
    v7_set(v7, *res, "inverseInertia", ~0, v7_mk_number(v7, body.inverseInertia));
    v7_set(v7, *res, "mass", ~0, v7_mk_number(v7, body.mass));
    v7_set(v7, *res, "inverseMass", ~0, v7_mk_number(v7, body.inverseMass));
    v7_set(v7, *res, "staticFriction", ~0, v7_mk_number(v7, body.staticFriction));
    v7_set(v7, *res, "dynamicFriction", ~0, v7_mk_number(v7, body.dynamicFriction));
    v7_set(v7, *res, "restitution", ~0, v7_mk_number(v7, body.restitution));
    v7_set(v7, *res, "useGravity", ~0, v7_mk_boolean(v7, (int)body.useGravity));
    v7_set(v7, *res, "isGrounded", ~0, v7_mk_boolean(v7, (int)body.isGrounded));
    v7_set(v7, *res, "freezeOrient", ~0, v7_mk_boolean(v7, (int)body.freezeOrient));
    v7_set(v7, *res, "shape", ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, *res, "shape", ~0), "type", ~0, v7_mk_number(v7, body.shape.type));
    v7_set(v7, v7_get(v7, *res, "shape", ~0), "body", ~0, *res);
    v7_set(v7, v7_get(v7, *res, "shape", ~0), "radius", ~0, v7_mk_number(v7, body.shape.radius));
    v7_set(v7, v7_get(v7, *res, "shape", ~0), "transform", ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "transform", ~0), "m00", ~0, v7_mk_number(v7, body.shape.transform.m00));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "transform", ~0), "m01", ~0, v7_mk_number(v7, body.shape.transform.m01));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "transform", ~0), "m10", ~0, v7_mk_number(v7, body.shape.transform.m10));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "transform", ~0), "m11", ~0, v7_mk_number(v7, body.shape.transform.m11));
    v7_set(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0), "vertexCount", ~0, v7_mk_number(v7, body.shape.vertexData.vertexCount));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0), "positions", ~0, v7_mk_array(v7));
    for (int i = 0; i < body.shape.vertexData.vertexCount; i++) {
        v7_val_t obj = v7_mk_object(v7);
        v7_set(v7, obj, "x", ~0, v7_mk_number(v7, body.shape.vertexData.positions[i].x));
        v7_set(v7, obj, "y", ~0, v7_mk_number(v7, body.shape.vertexData.positions[i].y));
        v7_array_push(v7, v7_get(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0), "positions", ~0), obj);
    }
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0), "normals", ~0, v7_mk_array(v7));
    for (int i = 0; i < body.shape.vertexData.vertexCount; i++) {
        v7_val_t obj = v7_mk_object(v7);
        v7_set(v7, obj, "x", ~0, v7_mk_number(v7, body.shape.vertexData.normals[i].x));
        v7_set(v7, obj, "y", ~0, v7_mk_number(v7, body.shape.vertexData.normals[i].y));
        v7_array_push(v7, v7_get(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0), "normals", ~0), obj);
    }
}

static inline void js_return_physics_body(struct v7* v7, v7_val_t* res, PhysicsBody body) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "id", ~0, v7_mk_number(v7, body->id));
    v7_set(v7, *res, "enabled", ~0, v7_mk_boolean(v7, (int)body->enabled));
    js_push_vec2(v7, *res, "position", body->position);
    js_push_vec2(v7, *res, "velocity", body->velocity);
    js_push_vec2(v7, *res, "force", body->force);
    v7_set(v7, *res, "angularVelocity", ~0, v7_mk_number(v7, body->angularVelocity));
    v7_set(v7, *res, "torque", ~0, v7_mk_number(v7, body->torque));
    v7_set(v7, *res, "orient", ~0, v7_mk_number(v7, body->orient));
    v7_set(v7, *res, "inertia", ~0, v7_mk_number(v7, body->inertia));
    v7_set(v7, *res, "inverseInertia", ~0, v7_mk_number(v7, body->inverseInertia));
    v7_set(v7, *res, "mass", ~0, v7_mk_number(v7, body->mass));
    v7_set(v7, *res, "inverseMass", ~0, v7_mk_number(v7, body->inverseMass));
    v7_set(v7, *res, "staticFriction", ~0, v7_mk_number(v7, body->staticFriction));
    v7_set(v7, *res, "dynamicFriction", ~0, v7_mk_number(v7, body->dynamicFriction));
    v7_set(v7, *res, "restitution", ~0, v7_mk_number(v7, body->restitution));
    v7_set(v7, *res, "useGravity", ~0, v7_mk_boolean(v7, (int)body->useGravity));
    v7_set(v7, *res, "isGrounded", ~0, v7_mk_boolean(v7, (int)body->isGrounded));
    v7_set(v7, *res, "freezeOrient", ~0, v7_mk_boolean(v7, (int)body->freezeOrient));
    v7_set(v7, *res, "shape", ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, *res, "shape", ~0), "type", ~0, v7_mk_number(v7, body->shape.type));
    v7_set(v7, v7_get(v7, *res, "shape", ~0), "body", ~0, *res);
    v7_set(v7, v7_get(v7, *res, "shape", ~0), "radius", ~0, v7_mk_number(v7, body->shape.radius));
    v7_set(v7, v7_get(v7, *res, "shape", ~0), "transform", ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "transform", ~0), "m00", ~0, v7_mk_number(v7, body->shape.transform.m00));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "transform", ~0), "m01", ~0, v7_mk_number(v7, body->shape.transform.m01));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "transform", ~0), "m10", ~0, v7_mk_number(v7, body->shape.transform.m10));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "transform", ~0), "m11", ~0, v7_mk_number(v7, body->shape.transform.m11));
    v7_set(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0), "vertexCount", ~0, v7_mk_number(v7, body->shape.vertexData.vertexCount));
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0), "positions", ~0, v7_mk_array(v7));
    for (int i = 0; i < body->shape.vertexData.vertexCount; i++) {
        v7_val_t obj = v7_mk_object(v7);
        v7_set(v7, obj, "x", ~0, v7_mk_number(v7, body->shape.vertexData.positions[i].x));
        v7_set(v7, obj, "y", ~0, v7_mk_number(v7, body->shape.vertexData.positions[i].y));
        v7_array_push(v7, v7_get(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0), "positions", ~0), obj);
    }
    v7_set(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0), "normals", ~0, v7_mk_array(v7));
    for (int i = 0; i < body->shape.vertexData.vertexCount; i++) {
        v7_val_t obj = v7_mk_object(v7);
        v7_set(v7, obj, "x", ~0, v7_mk_number(v7, body->shape.vertexData.normals[i].x));
        v7_set(v7, obj, "y", ~0, v7_mk_number(v7, body->shape.vertexData.normals[i].y));
        v7_array_push(v7, v7_get(v7, v7_get(v7, v7_get(v7, *res, "shape", ~0), "vertexData", ~0), "normals", ~0), obj);
    }
}

static inline enum v7_err js_init_physics(void) {
    InitPhysics();
    return V7_OK;
}

static inline enum v7_err js_run_physics_step(void) {
    RunPhysicsStep();
    return V7_OK;
}

static inline enum v7_err js_set_physics_time_step(struct v7* v7) {
    SetPhysicsTimeStep(v7_get_double(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_physics_enabled(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsPhysicsEnabled());
    return V7_OK;
}

static inline enum v7_err js_set_physics_gravity(struct v7* v7) {
    SetPhysicsGravity(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_create_physics_body_circle(struct v7* v7, v7_val_t* res) {
    js_return_physics_body(v7, res, CreatePhysicsBodyCircle(js_get_vec2(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_create_physics_body_rectangle(struct v7* v7, v7_val_t* res) {
    js_return_physics_body(v7, res, CreatePhysicsBodyRectangle(js_get_vec2(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_create_physics_body_polygon(struct v7* v7, v7_val_t* res) {
    js_return_physics_body(v7, res, CreatePhysicsBodyPolygon(js_get_vec2(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_physics_add_force(struct v7* v7) {
    PhysicsBodyData body = js_get_physics_body_data(v7, 0);
    PhysicsAddForce(&body, js_get_vec2(v7, 1));
    return V7_OK;
}

static inline enum v7_err js_physics_add_torque(struct v7* v7) {
    PhysicsBodyData body = js_get_physics_body_data(v7, 0);
    PhysicsAddTorque(&body, v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_physics_shatter(struct v7* v7) {
    PhysicsBodyData body = js_get_physics_body_data(v7, 0);
    PhysicsShatter(&body, js_get_vec2(v7, 1), v7_get_double(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_get_physics_bodies_count(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetPhysicsBodiesCount());
    return V7_OK;
}

static inline enum v7_err js_physac_get_physics_body(struct v7* v7, v7_val_t* res) {
    js_return_physics_body(v7, res, GetPhysicsBody(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_physics_shape_type(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetPhysicsShapeType(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_physics_shape_vertices_count(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetPhysicsShapeVerticesCount(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_physics_shape_vertex(struct v7* v7, v7_val_t* res) {
    PhysicsBodyData body = js_get_physics_body_data(v7, 0);
    js_return_vec2(v7, res, GetPhysicsShapeVertex(&body, v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_set_physics_body_rotation(struct v7* v7) {
    PhysicsBodyData body = js_get_physics_body_data(v7, 0);
    SetPhysicsBodyRotation(&body, v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_destroy_physics_body(struct v7* v7) {
    PhysicsBodyData body = js_get_physics_body_data(v7, 0);
    DestroyPhysicsBody(&body);
    return V7_OK;
}

static inline enum v7_err js_reset_physics(void) {
    ResetPhysics();
    return V7_OK;
}

static inline enum v7_err js_close_physics(void) {
    ClosePhysics();
    return V7_OK;
}

void raylib_v7_load_physac(struct v7* v7) {
    js_push_key(v7, v7_get_global(v7), "PHYSAC_PI", PHYSAC_PI);
    js_push_key(v7, v7_get_global(v7), "PHYSAC_DEG2RAD", PHYSAC_DEG2RAD);
    js_push_key(v7, v7_get_global(v7), "PHYSICS_CIRCLE", PHYSICS_CIRCLE);
    js_push_key(v7, v7_get_global(v7), "PHYSICS_POLYGON", PHYSICS_POLYGON);

    v7_set_method(v7, v7_get_global(v7), "InitPhysics", &js_init_physics);
    v7_set_method(v7, v7_get_global(v7), "RunPhysicsStep", &js_run_physics_step);
    v7_set_method(v7, v7_get_global(v7), "SetPhysicsTimeStep", &js_set_physics_time_step);
    v7_set_method(v7, v7_get_global(v7), "IsPhysicsEnabled", &js_physics_enabled);
    v7_set_method(v7, v7_get_global(v7), "SetPhysicsGravity", &js_set_physics_gravity);
    v7_set_method(v7, v7_get_global(v7), "CreatePhysicsBodyCircle", &js_create_physics_body_circle);
    v7_set_method(v7, v7_get_global(v7), "CreatePhysicsBodyRectangle", &js_create_physics_body_rectangle);
    v7_set_method(v7, v7_get_global(v7), "CreatePhysicsBodyPolygon", &js_create_physics_body_polygon);
    v7_set_method(v7, v7_get_global(v7), "PhysicsAddForce", &js_physics_add_force);
    v7_set_method(v7, v7_get_global(v7), "PhysicsAddTorque", &js_physics_add_torque);
    v7_set_method(v7, v7_get_global(v7), "PhysicsShatter", &js_physics_shatter);
    v7_set_method(v7, v7_get_global(v7), "GetPhysicsBodiesCount", &js_get_physics_bodies_count);
    v7_set_method(v7, v7_get_global(v7), "GetPhysicsBody", &js_physac_get_physics_body);
    v7_set_method(v7, v7_get_global(v7), "GetPhysicsShapeType", &js_get_physics_shape_type);
    v7_set_method(v7, v7_get_global(v7), "GetPhysicsShapeVerticesCount", &js_get_physics_shape_vertices_count);
    v7_set_method(v7, v7_get_global(v7), "GetPhysicsShapeVertex", &js_get_physics_shape_vertex);
    v7_set_method(v7, v7_get_global(v7), "SetPhysicsBodyRotation", &js_set_physics_body_rotation);
    v7_set_method(v7, v7_get_global(v7), "DestroyPhysicsBody", &js_destroy_physics_body);
    v7_set_method(v7, v7_get_global(v7), "ResetPhysics", &js_reset_physics);
    v7_set_method(v7, v7_get_global(v7), "ClosePhysics", &js_close_physics);
}
