#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>
#include <raymath.h>
#include <raymath_js.h>

static inline enum v7_err js_clamp(struct v7* v7, v7_val_t* res) {
    float value = (float)v7_get_double(v7, v7_arg(v7, 0));
    float min = (float)v7_get_double(v7, v7_arg(v7, 1));
    float max = (float)v7_get_double(v7, v7_arg(v7, 2));
    *res = v7_mk_number(v7, (float)Clamp(value, min, max));
    return V7_OK;
}

static inline enum v7_err js_lerp(struct v7* v7, v7_val_t* res) {
    float start = (float)v7_get_double(v7, v7_arg(v7, 0));
    float end = (float)v7_get_double(v7, v7_arg(v7, 1));
    float amount = (float)v7_get_double(v7, v7_arg(v7, 2));
    *res = v7_mk_number(v7, (float)Lerp(start, end, amount));
    return V7_OK;
}

static inline enum v7_err js_normalize(struct v7* v7, v7_val_t* res) {
    float value = (float)v7_get_double(v7, v7_arg(v7, 0));
    float start = (float)v7_get_double(v7, v7_arg(v7, 1));
    float end = (float)v7_get_double(v7, v7_arg(v7, 2));
    *res = v7_mk_number(v7, (float)Normalize(value, start, end));
    return V7_OK;
}

static inline enum v7_err js_remap(struct v7* v7, v7_val_t* res) {
    float value = (float)v7_get_double(v7, v7_arg(v7, 0));
    float inputStart = (float)v7_get_double(v7, v7_arg(v7, 1));
    float inputEnd = (float)v7_get_double(v7, v7_arg(v7, 2));
    float outputStart = (float)v7_get_double(v7, v7_arg(v7, 3));
    float outputEnd = (float)v7_get_double(v7, v7_arg(v7, 4));
    *res = v7_mk_number(v7, (float)Remap(value, inputStart, inputEnd, outputStart, outputEnd));
    return V7_OK;
}

static inline enum v7_err js_vec2_zero(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, Vector2Zero());
    return V7_OK;
}

static inline enum v7_err js_vec2_one(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, Vector2One());
    return V7_OK;
}

static inline enum v7_err js_vec2_add(struct v7* v7, v7_val_t* res) {
    Vector2 v1 = js_get_vec2(v7, 0);
    Vector2 v2 = js_get_vec2(v7, 1);
    js_return_vec2(v7, res, Vector2Add(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec2_add_value(struct v7* v7, v7_val_t* res) {
    Vector2 v = js_get_vec2(v7, 0);
    float add = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_vec2(v7, res, Vector2AddValue(v, add));
    return V7_OK;
}

static inline enum v7_err js_vec2_subtract(struct v7* v7, v7_val_t* res) {
    Vector2 v1 = js_get_vec2(v7, 0);
    Vector2 v2 = js_get_vec2(v7, 1);
    js_return_vec2(v7, res, Vector2Subtract(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec2_subtract_value(struct v7* v7, v7_val_t* res) {
    Vector2 v = js_get_vec2(v7, 0);
    float sub = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_vec2(v7, res, Vector2SubtractValue(v, sub));
    return V7_OK;
}

static inline enum v7_err js_vec2_length(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (float)Vector2Length(js_get_vec2(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_vec2_length_sqr(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (float)Vector2LengthSqr(js_get_vec2(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_vec2_dot_product(struct v7* v7, v7_val_t* res) {
    Vector2 v1 = js_get_vec2(v7, 0);
    Vector2 v2 = js_get_vec2(v7, 1);
    *res = v7_mk_number(v7, (float)Vector2DotProduct(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec2_distance(struct v7* v7, v7_val_t* res) {
    Vector2 v1 = js_get_vec2(v7, 0);
    Vector2 v2 = js_get_vec2(v7, 1);
    *res = v7_mk_number(v7, (float)Vector2Distance(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec2_angle(struct v7* v7, v7_val_t* res) {
    Vector2 v1 = js_get_vec2(v7, 0);
    Vector2 v2 = js_get_vec2(v7, 1);
    *res = v7_mk_number(v7, (float)Vector2Angle(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec2_scale(struct v7* v7, v7_val_t* res) {
    Vector2 v = js_get_vec2(v7, 0);
    float scale = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_vec2(v7, res, Vector2Scale(v, scale));
    return V7_OK;
}

static inline enum v7_err js_vec2_multiply(struct v7* v7, v7_val_t* res) {
    Vector2 v1 = js_get_vec2(v7, 0);
    Vector2 v2 = js_get_vec2(v7, 1);
    js_return_vec2(v7, res, Vector2Multiply(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec2_negate(struct v7* v7, v7_val_t* res) {
    Vector2 v = js_get_vec2(v7, 0);
    js_return_vec2(v7, res, Vector2Negate(v));
    return V7_OK;
}

static inline enum v7_err js_vec2_divide(struct v7* v7, v7_val_t* res) {
    Vector2 v1 = js_get_vec2(v7, 0);
    Vector2 v2 = js_get_vec2(v7, 1);
    js_return_vec2(v7, res, Vector2Divide(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec2_normalize(struct v7* v7, v7_val_t* res) {
    Vector2 v = js_get_vec2(v7, 0);
    js_return_vec2(v7, res, Vector2Normalize(v));
    return V7_OK;
}

static inline enum v7_err js_vec2_lerp(struct v7* v7, v7_val_t* res) {
    Vector2 v1 = js_get_vec2(v7, 0);
    Vector2 v2 = js_get_vec2(v7, 1);
    float amount = (float)v7_get_double(v7, v7_arg(v7, 2));
    js_return_vec2(v7, res, Vector2Lerp(v1, v2, amount));
    return V7_OK;
}

static inline enum v7_err js_vec2_rotate(struct v7* v7, v7_val_t* res) {
    Vector2 v = js_get_vec2(v7, 0);
    float degs = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_vec2(v7, res, Vector2Rotate(v, degs));
    return V7_OK;
}

static inline enum v7_err js_vec3_zero(struct v7* v7, v7_val_t* res) {
    js_return_vec3(v7, res, Vector3Zero());
    return V7_OK;
}

static inline enum v7_err js_vec3_one(struct v7* v7, v7_val_t* res) {
    js_return_vec3(v7, res, Vector3One());
    return V7_OK;
}

static inline enum v7_err js_vec3_add(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    js_return_vec3(v7, res, Vector3Add(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec3_add_value(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    float add = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_vec3(v7, res, Vector3AddValue(v, add));
    return V7_OK;
}

static inline enum v7_err js_vec3_subtract(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    js_return_vec3(v7, res, Vector3Subtract(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec3_subtract_value(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    float sub = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_vec3(v7, res, Vector3SubtractValue(v, sub));
    return V7_OK;
}

static inline enum v7_err js_vec3_scale(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    float scale = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_vec3(v7, res, Vector3Scale(v, scale));
    return V7_OK;
}

static inline enum v7_err js_vec3_multiply(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    js_return_vec3(v7, res, Vector3Multiply(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec3_cross_product(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    js_return_vec3(v7, res, Vector3CrossProduct(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec3_perpendicular(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    js_return_vec3(v7, res, Vector3Perpendicular(v));
    return V7_OK;
}

static inline enum v7_err js_vec3_length(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (float)Vector3Length(js_get_vec3(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_vec3_length_sqr(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (float)Vector3LengthSqr(js_get_vec3(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_vec3_dot_product(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    *res = v7_mk_number(v7, (float)Vector3DotProduct(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec3_distance(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    *res = v7_mk_number(v7, (float)Vector3Distance(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec3_negate(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    js_return_vec3(v7, res, Vector3Negate(v));
    return V7_OK;
}

static inline enum v7_err js_vec3_divide(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    js_return_vec3(v7, res, Vector3Divide(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec3_normalize(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    js_return_vec3(v7, res, Vector3Normalize(v));
    return V7_OK;
}

static inline enum v7_err js_vec3_ortho_normalize(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    Vector3OrthoNormalize(&v1, &v2);
    return V7_OK;
}

static inline enum v7_err js_vec3_transform(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    Matrix mat = js_get_matrix(v7, 1);
    js_return_vec3(v7, res, Vector3Transform(v, mat));
    return V7_OK;
}

static inline enum v7_err js_vec3_rotate_by_quaternion(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    Quaternion q = js_get_quat(v7, 1);
    js_return_vec3(v7, res, Vector3RotateByQuaternion(v, q));
    return V7_OK;
}

static inline enum v7_err js_vec3_lerp(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    float amount = (float)v7_get_double(v7, v7_arg(v7, 2));
    js_return_vec3(v7, res, Vector3Lerp(v1, v2, amount));
    return V7_OK;
}

static inline enum v7_err js_vec3_min(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    js_return_vec3(v7, res, Vector3Min(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec3_max(struct v7* v7, v7_val_t* res) {
    Vector3 v1 = js_get_vec3(v7, 0);
    Vector3 v2 = js_get_vec3(v7, 1);
    js_return_vec3(v7, res, Vector3Max(v1, v2));
    return V7_OK;
}

static inline enum v7_err js_vec3_barycenter(struct v7* v7, v7_val_t* res) {
    Vector3 p = js_get_vec3(v7, 0);
    Vector3 a = js_get_vec3(v7, 1);
    Vector3 b = js_get_vec3(v7, 2);
    Vector3 c = js_get_vec3(v7, 3);
    js_return_vec3(v7, res, Vector3Barycenter(p, a, b, c));
    return V7_OK;
}

static inline enum v7_err js_vec3_to_float_v(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    float3 result = Vector3ToFloatV(v);
    *res = v7_mk_object(v7);
    v7_def(v7, *res, "v", ~0, (V7_DESC_WRITABLE(true) | V7_DESC_CONFIGURABLE(true)), v7_mk_array(v7));
    for (int i = 0; i < 3; i++) v7_array_push(v7, v7_get(v7, *res, "v", ~0), v7_mk_number(v7, result.v[i]));
    return V7_OK;
}

static inline enum v7_err js_vec3_to_float(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    float3 result = Vector3ToFloatV(v);
    *res = v7_mk_array(v7);
    for (int i = 0; i < 3; i++) v7_array_push(v7, *res, v7_mk_number(v7, result.v[i]));
    return V7_OK;
}

static inline enum v7_err js_vec3_unproject(struct v7* v7, v7_val_t* res) {
    Vector3 source = js_get_vec3(v7, 0);
    Matrix projection = js_get_matrix(v7, 1);
    Matrix view = js_get_matrix(v7, 2);
    js_return_vec3(v7, res, Vector3Unproject(source, projection, view));
    return V7_OK;
}

static inline enum v7_err js_vec3_reflect(struct v7* v7, v7_val_t* res) {
    Vector3 v = js_get_vec3(v7, 0);
    Vector3 normal = js_get_vec3(v7, 1);
    js_return_vec3(v7, res, Vector3Reflect(v, normal));
    return V7_OK;
}

static inline enum v7_err js_matrix_determinant(struct v7* v7, v7_val_t* res) {
    Matrix mat = js_get_matrix(v7, 0);
    *res = v7_mk_number(v7, (float)MatrixDeterminant(mat));
    return V7_OK;
}

static inline enum v7_err js_matrix_trace(struct v7* v7, v7_val_t* res) {
    Matrix mat = js_get_matrix(v7, 0);
    *res = v7_mk_number(v7, (float)MatrixTrace(mat));
    return V7_OK;
}

static inline enum v7_err js_matrix_transpose(struct v7* v7, v7_val_t* res) {
    Matrix mat = js_get_matrix(v7, 0);
    js_return_matrix(v7, res, MatrixTranspose(mat));
    return V7_OK;
}

static inline enum v7_err js_matrix_invert(struct v7* v7, v7_val_t* res) {
    Matrix mat = js_get_matrix(v7, 0);
    js_return_matrix(v7, res, MatrixInvert(mat));
    return V7_OK;
}

static inline enum v7_err js_matrix_normalize(struct v7* v7, v7_val_t* res) {
    Matrix mat = js_get_matrix(v7, 0);
    js_return_matrix(v7, res, MatrixNormalize(mat));
    return V7_OK;
}

static inline enum v7_err js_matrix_identity(struct v7* v7, v7_val_t* res) {
    js_return_matrix(v7, res, MatrixIdentity());
    return V7_OK;
}

static inline enum v7_err js_matrix_add(struct v7* v7, v7_val_t* res) {
    Matrix left = js_get_matrix(v7, 0);
    Matrix right = js_get_matrix(v7, 1);
    js_return_matrix(v7, res, MatrixAdd(left, right));
    return V7_OK;
}

static inline enum v7_err js_matrix_subtract(struct v7* v7, v7_val_t* res) {
    Matrix left = js_get_matrix(v7, 0);
    Matrix right = js_get_matrix(v7, 1);
    js_return_matrix(v7, res, MatrixSubtract(left, right));
    return V7_OK;
}

static inline enum v7_err js_matrix_translate(struct v7* v7, v7_val_t* res) {
    float x = (float)v7_get_double(v7, v7_arg(v7, 0));
    float y = (float)v7_get_double(v7, v7_arg(v7, 1));
    float z = (float)v7_get_double(v7, v7_arg(v7, 2));
    js_return_matrix(v7, res, MatrixTranslate(x, y, z));
    return V7_OK;
}

static inline enum v7_err js_matrix_rotate(struct v7* v7, v7_val_t* res) {
    Vector3 axis = js_get_vec3(v7, 0);
    float angle = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_matrix(v7, res, MatrixRotate(axis, angle));
    return V7_OK;
}

static inline enum v7_err js_matrix_rotate_xyz(struct v7* v7, v7_val_t* res) {
    Vector3 ang = js_get_vec3(v7, 0);
    js_return_matrix(v7, res, MatrixRotateXYZ(ang));
    return V7_OK;
}

static inline enum v7_err js_matrix_rotate_x(struct v7* v7, v7_val_t* res) {
    float angle = (float)v7_get_double(v7, v7_arg(v7, 0));
    js_return_matrix(v7, res, MatrixRotateX(angle));
    return V7_OK;
}

static inline enum v7_err js_matrix_rotate_y(struct v7* v7, v7_val_t* res) {
    float angle = (float)v7_get_double(v7, v7_arg(v7, 0));
    js_return_matrix(v7, res, MatrixRotateY(angle));
    return V7_OK;
}

static inline enum v7_err js_matrix_rotate_z(struct v7* v7, v7_val_t* res) {
    float angle = (float)v7_get_double(v7, v7_arg(v7, 0));
    js_return_matrix(v7, res, MatrixRotateZ(angle));
    return V7_OK;
}

static inline enum v7_err js_matrix_scale(struct v7* v7, v7_val_t* res) {
    float x = (float)v7_get_double(v7, v7_arg(v7, 0));
    float y = (float)v7_get_double(v7, v7_arg(v7, 1));
    float z = (float)v7_get_double(v7, v7_arg(v7, 2));
    js_return_matrix(v7, res, MatrixScale(x, y, z));
    return V7_OK;
}

static inline enum v7_err js_matrix_multiply(struct v7* v7, v7_val_t* res) {
    Matrix left = js_get_matrix(v7, 0);
    Matrix right = js_get_matrix(v7, 1);
    js_return_matrix(v7, res, MatrixMultiply(left, right));
    return V7_OK;
}

static inline enum v7_err js_matrix_frustum(struct v7* v7, v7_val_t* res) {
    double left = v7_get_double(v7, v7_arg(v7, 0));
    double right = v7_get_double(v7, v7_arg(v7, 1));
    double bottom = v7_get_double(v7, v7_arg(v7, 2));
    double top = v7_get_double(v7, v7_arg(v7, 3));
    double near = v7_get_double(v7, v7_arg(v7, 4));
    double far = v7_get_double(v7, v7_arg(v7, 5));
    js_return_matrix(v7, res, MatrixFrustum(left, right, bottom, top, near, far));
    return V7_OK;
}

static inline enum v7_err js_matrix_perspective(struct v7* v7, v7_val_t* res) {
    double fovy = v7_get_double(v7, v7_arg(v7, 0));
    double aspect = v7_get_double(v7, v7_arg(v7, 1));
    double near = v7_get_double(v7, v7_arg(v7, 2));
    double far = v7_get_double(v7, v7_arg(v7, 3));
    js_return_matrix(v7, res, MatrixPerspective(fovy, aspect, near, far));
    return V7_OK;
}

static inline enum v7_err js_matrix_ortho(struct v7* v7, v7_val_t* res) {
    double left = v7_get_double(v7, v7_arg(v7, 0));
    double right = v7_get_double(v7, v7_arg(v7, 1));
    double bottom = v7_get_double(v7, v7_arg(v7, 2));
    double top = v7_get_double(v7, v7_arg(v7, 3));
    double near = v7_get_double(v7, v7_arg(v7, 4));
    double far = v7_get_double(v7, v7_arg(v7, 5));
    js_return_matrix(v7, res, MatrixOrtho(left, right, bottom, top, near, far));
    return V7_OK;
}

static inline enum v7_err js_matrix_look_at(struct v7* v7, v7_val_t* res) {
    Vector3 eye = js_get_vec3(v7, 0);
    Vector3 target = js_get_vec3(v7, 1);
    Vector3 up = js_get_vec3(v7, 2);
    js_return_matrix(v7, res, MatrixLookAt(eye, target, up));
    return V7_OK;
}

static inline enum v7_err js_matrix_to_float_v(struct v7* v7, v7_val_t* res) {
    Matrix mat = js_get_matrix(v7, 0);
    float16 result = MatrixToFloatV(mat);
    *res = v7_mk_object(v7);
    v7_def(v7, *res, "v", ~0, (V7_DESC_WRITABLE(true) | V7_DESC_CONFIGURABLE(true)), v7_mk_array(v7));
    for (int i = 0; i < 16; i++) v7_array_push(v7, v7_get(v7, *res, "v", ~0), v7_mk_number(v7, result.v[i]));
    return V7_OK;
}

static inline enum v7_err js_matrix_to_float(struct v7* v7, v7_val_t* res) {
    Matrix mat = js_get_matrix(v7, 0);
    float16 result = MatrixToFloatV(mat);
    *res = v7_mk_array(v7);
    for (int i = 0; i < 16; i++) v7_array_push(v7, *res, v7_mk_number(v7, result.v[i]));
    return V7_OK;
}

static inline enum v7_err js_quaternion_add(struct v7* v7, v7_val_t* res) {
    Quaternion q1 = js_get_quat(v7, 0);
    Quaternion q2 = js_get_quat(v7, 1);
    js_return_quat(v7, res, QuaternionAdd(q1, q2));
    return V7_OK;
}

static inline enum v7_err js_quaternion_add_value(struct v7* v7, v7_val_t* res) {
    Quaternion q = js_get_quat(v7, 0);
    float add = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_quat(v7, res, QuaternionAddValue(q, add));
    return V7_OK;
}

static inline enum v7_err js_quaternion_subtract(struct v7* v7, v7_val_t* res) {
    Quaternion q1 = js_get_quat(v7, 0);
    Quaternion q2 = js_get_quat(v7, 1);
    js_return_quat(v7, res, QuaternionSubtract(q1, q2));
    return V7_OK;
}

static inline enum v7_err js_quaternion_subtract_value(struct v7* v7, v7_val_t* res) {
    Quaternion q = js_get_quat(v7, 0);
    float sub = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_quat(v7, res, QuaternionSubtractValue(q, sub));
    return V7_OK;
}

static inline enum v7_err js_quaternion_identity(struct v7* v7, v7_val_t* res) {
    js_return_quat(v7, res, QuaternionIdentity());
    return V7_OK;
}

static inline enum v7_err js_quaternion_length(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (double)QuaternionLength(js_get_quat(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_quaternion_normalize(struct v7* v7, v7_val_t* res) {
    Quaternion q = js_get_quat(v7, 0);
    js_return_quat(v7, res, QuaternionNormalize(q));
    return V7_OK;
}

static inline enum v7_err js_quaternion_invert(struct v7* v7, v7_val_t* res) {
    Quaternion q = js_get_quat(v7, 0);
    js_return_quat(v7, res, QuaternionInvert(q));
    return V7_OK;
}

static inline enum v7_err js_quaternion_multiply(struct v7* v7, v7_val_t* res) {
    Quaternion q1 = js_get_quat(v7, 0);
    Quaternion q2 = js_get_quat(v7, 1);
    js_return_quat(v7, res, QuaternionMultiply(q1, q2));
    return V7_OK;
}

static inline enum v7_err js_quaternion_scale(struct v7* v7, v7_val_t* res) {
    Quaternion q = js_get_quat(v7, 0);
    float mul = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_quat(v7, res, QuaternionScale(q, mul));
    return V7_OK;
}

static inline enum v7_err js_quaternion_divide(struct v7* v7, v7_val_t* res) {
    Quaternion q1 = js_get_quat(v7, 0);
    Quaternion q2 = js_get_quat(v7, 1);
    js_return_quat(v7, res, QuaternionDivide(q1, q2));
    return V7_OK;
}

static inline enum v7_err js_quaternion_lerp(struct v7* v7, v7_val_t* res) {
    Quaternion q1 = js_get_quat(v7, 0);
    Quaternion q2 = js_get_quat(v7, 1);
    float amount = (float)v7_get_double(v7, v7_arg(v7, 2));
    js_return_quat(v7, res, QuaternionLerp(q1, q2, amount));
    return V7_OK;
}

static inline enum v7_err js_quaternion_nlerp(struct v7* v7, v7_val_t* res) {
    Quaternion q1 = js_get_quat(v7, 0);
    Quaternion q2 = js_get_quat(v7, 1);
    float amount = (float)v7_get_double(v7, v7_arg(v7, 2));
    js_return_quat(v7, res, QuaternionNlerp(q1, q2, amount));
    return V7_OK;
}

static inline enum v7_err js_quaternion_slerp(struct v7* v7, v7_val_t* res) {
    Quaternion q1 = js_get_quat(v7, 0);
    Quaternion q2 = js_get_quat(v7, 1);
    float amount = (float)v7_get_double(v7, v7_arg(v7, 2));
    js_return_quat(v7, res, QuaternionSlerp(q1, q2, amount));
    return V7_OK;
}

static inline enum v7_err js_quaternion_from_vector3_to_vector3(struct v7* v7, v7_val_t* res) {
    Vector3 from = js_get_vec3(v7, 0);
    Vector3 to = js_get_vec3(v7, 1);
    js_return_quat(v7, res, QuaternionFromVector3ToVector3(from, to));
    return V7_OK;
}

static inline enum v7_err js_quaternion_from_matrix(struct v7* v7, v7_val_t* res) {
    Matrix mat = js_get_matrix(v7, 0);
    js_return_quat(v7, res, QuaternionFromMatrix(mat));
    return V7_OK;
}

static inline enum v7_err js_quaternion_to_matrix(struct v7* v7, v7_val_t* res) {
    Quaternion q = js_get_quat(v7, 0);
    js_return_matrix(v7, res, QuaternionToMatrix(q));
    return V7_OK;
}

static inline enum v7_err js_quaternion_from_axis_angle(struct v7* v7, v7_val_t* res) {
    Vector3 axis = js_get_vec3(v7, 0);
    float angle = (float)v7_get_double(v7, v7_arg(v7, 1));
    js_return_quat(v7, res, QuaternionFromAxisAngle(axis, angle));
    return V7_OK;
}

static inline enum v7_err js_quaternion_to_axis_angle(struct v7* v7, v7_val_t* res) {
    Quaternion q = js_get_quat(v7, 0);
    Vector3 outAxis = js_get_vec3(v7, 1);
    float outAngle = (float)v7_get_double(v7, v7_arg(v7, 2));
    QuaternionToAxisAngle(q, &outAxis, &outAngle);
    return V7_OK;
}

static inline enum v7_err js_quaternion_from_euler(struct v7* v7, v7_val_t* res) {
    float roll = (float)v7_get_double(v7, v7_arg(v7, 0));
    float pitch = (float)v7_get_double(v7, v7_arg(v7, 1));
    float yaw = (float)v7_get_double(v7, v7_arg(v7, 2));
    js_return_quat(v7, res, QuaternionFromEuler(roll, pitch, yaw));
    return V7_OK;
}

static inline enum v7_err js_quaternion_to_euler(struct v7* v7, v7_val_t* res) {
    Quaternion q = js_get_quat(v7, 0);
    js_return_vec3(v7, res, QuaternionToEuler(q));
    return V7_OK;
}

static inline enum v7_err js_quaternion_transform(struct v7* v7, v7_val_t* res) {
    Quaternion q = js_get_quat(v7, 0);
    Matrix mat = js_get_matrix(v7, 1);
    js_return_quat(v7, res, QuaternionTransform(q, mat));
    return V7_OK;
}

void raylib_v7_load_raymath(struct v7* v7) {
    v7_set_method(v7, v7_get_global(v7), "Clamp", &js_clamp);
    v7_set_method(v7, v7_get_global(v7), "Lerp", &js_lerp);
    v7_set_method(v7, v7_get_global(v7), "Normalize", &js_normalize);
    v7_set_method(v7, v7_get_global(v7), "Remap", &js_remap);

    v7_set_method(v7, v7_get_global(v7), "Vector2Zero", &js_vec2_zero);
    v7_set_method(v7, v7_get_global(v7), "Vector2One", &js_vec2_one);
    v7_set_method(v7, v7_get_global(v7), "Vector2Add", &js_vec2_add);
    v7_set_method(v7, v7_get_global(v7), "Vector2AddValue", &js_vec2_add_value);
    v7_set_method(v7, v7_get_global(v7), "Vector2Subtract", &js_vec2_subtract);
    v7_set_method(v7, v7_get_global(v7), "Vector2SubtractValue", &js_vec2_subtract_value);
    v7_set_method(v7, v7_get_global(v7), "Vector2Length", &js_vec2_length);
    v7_set_method(v7, v7_get_global(v7), "Vector2LengthSqr", &js_vec2_length_sqr);
    v7_set_method(v7, v7_get_global(v7), "Vector2DotProduct", &js_vec2_dot_product);
    v7_set_method(v7, v7_get_global(v7), "Vector2Distance", &js_vec2_distance);
    v7_set_method(v7, v7_get_global(v7), "Vector2Angle", &js_vec2_angle);
    v7_set_method(v7, v7_get_global(v7), "Vector2Scale", &js_vec2_scale);
    v7_set_method(v7, v7_get_global(v7), "Vector2Multiply", &js_vec2_multiply);
    v7_set_method(v7, v7_get_global(v7), "Vector2Negate", &js_vec2_negate);
    v7_set_method(v7, v7_get_global(v7), "Vector2Divide", &js_vec2_divide);
    v7_set_method(v7, v7_get_global(v7), "Vector2Normalize", &js_vec2_normalize);
    v7_set_method(v7, v7_get_global(v7), "Vector2Lerp", &js_vec2_lerp);
    v7_set_method(v7, v7_get_global(v7), "Vector2Rotate", &js_vec2_rotate);

    v7_set_method(v7, v7_get_global(v7), "Vector3Zero", &js_vec3_zero);
    v7_set_method(v7, v7_get_global(v7), "Vector3One", &js_vec3_one);
    v7_set_method(v7, v7_get_global(v7), "Vector3Add", &js_vec3_add);
    v7_set_method(v7, v7_get_global(v7), "Vector3AddValue", &js_vec3_add_value);
    v7_set_method(v7, v7_get_global(v7), "Vector3Subtract", &js_vec3_subtract);
    v7_set_method(v7, v7_get_global(v7), "Vector3SubtractValue", &js_vec3_subtract_value);
    v7_set_method(v7, v7_get_global(v7), "Vector3Scale", &js_vec3_scale);
    v7_set_method(v7, v7_get_global(v7), "Vector3Multiply", &js_vec3_multiply);
    v7_set_method(v7, v7_get_global(v7), "Vector3CrossProduct", &js_vec3_cross_product);
    v7_set_method(v7, v7_get_global(v7), "Vector3Perpendicular", &js_vec3_perpendicular);
    v7_set_method(v7, v7_get_global(v7), "Vector3Length", &js_vec3_length);
    v7_set_method(v7, v7_get_global(v7), "Vector3LengthSqr", &js_vec3_length_sqr);
    v7_set_method(v7, v7_get_global(v7), "Vector3DotProduct", &js_vec3_dot_product);
    v7_set_method(v7, v7_get_global(v7), "Vector3Distance", &js_vec3_distance);
    v7_set_method(v7, v7_get_global(v7), "Vector3Negate", &js_vec3_negate);
    v7_set_method(v7, v7_get_global(v7), "Vector3Divide", &js_vec3_divide);
    v7_set_method(v7, v7_get_global(v7), "Vector3Normalize", &js_vec3_normalize);
    v7_set_method(v7, v7_get_global(v7), "Vector3OrthoNormalize", &js_vec3_ortho_normalize);
    v7_set_method(v7, v7_get_global(v7), "Vector3Transform", &js_vec3_transform);
    v7_set_method(v7, v7_get_global(v7), "Vector3RotateByQuaternion", &js_vec3_rotate_by_quaternion);
    v7_set_method(v7, v7_get_global(v7), "Vector3Lerp", &js_vec3_lerp);
    v7_set_method(v7, v7_get_global(v7), "Vector3Min", &js_vec3_min);
    v7_set_method(v7, v7_get_global(v7), "Vector3Max", &js_vec3_max);
    v7_set_method(v7, v7_get_global(v7), "Vector3Barycenter", &js_vec3_barycenter);
    v7_set_method(v7, v7_get_global(v7), "Vector3ToFloatV", &js_vec3_to_float_v);
    v7_set_method(v7, v7_get_global(v7), "Vector3ToFloat", &js_vec3_to_float);
    v7_set_method(v7, v7_get_global(v7), "Vector3Unproject", &js_vec3_unproject);
    v7_set_method(v7, v7_get_global(v7), "Vector3Reflect", &js_vec3_reflect);

    v7_set_method(v7, v7_get_global(v7), "MatrixDeterminant", &js_matrix_determinant);
    v7_set_method(v7, v7_get_global(v7), "MatrixTrace", &js_matrix_trace);
    v7_set_method(v7, v7_get_global(v7), "MatrixTranspose", &js_matrix_transpose);
    v7_set_method(v7, v7_get_global(v7), "MatrixInvert", &js_matrix_invert);
    v7_set_method(v7, v7_get_global(v7), "MatrixNormalize", &js_matrix_normalize);
    v7_set_method(v7, v7_get_global(v7), "MatrixIdentity", &js_matrix_identity);
    v7_set_method(v7, v7_get_global(v7), "MatrixAdd", &js_matrix_add);
    v7_set_method(v7, v7_get_global(v7), "MatrixSubtract", &js_matrix_subtract);
    v7_set_method(v7, v7_get_global(v7), "MatrixTranslate", &js_matrix_translate);
    v7_set_method(v7, v7_get_global(v7), "MatrixRotate", &js_matrix_rotate);
    v7_set_method(v7, v7_get_global(v7), "MatrixRotateXYZ", &js_matrix_rotate_xyz);
    v7_set_method(v7, v7_get_global(v7), "MatrixRotateX", &js_matrix_rotate_x);
    v7_set_method(v7, v7_get_global(v7), "MatrixRotateY", &js_matrix_rotate_y);
    v7_set_method(v7, v7_get_global(v7), "MatrixRotateZ", &js_matrix_rotate_z);
    v7_set_method(v7, v7_get_global(v7), "MatrixScale", &js_matrix_scale);
    v7_set_method(v7, v7_get_global(v7), "MatrixMultiply", &js_matrix_multiply);
    v7_set_method(v7, v7_get_global(v7), "MatrixFrustum", &js_matrix_frustum);
    v7_set_method(v7, v7_get_global(v7), "MatrixPerspective", &js_matrix_perspective);
    v7_set_method(v7, v7_get_global(v7), "MatrixOrtho", &js_matrix_ortho);
    v7_set_method(v7, v7_get_global(v7), "MatrixLookAt", &js_matrix_look_at);
    v7_set_method(v7, v7_get_global(v7), "MatrixToFloatV", &js_matrix_to_float_v);
    v7_set_method(v7, v7_get_global(v7), "MatrixToFloat", &js_matrix_to_float);

    v7_set_method(v7, v7_get_global(v7), "QuaternionAdd", &js_quaternion_add);
    v7_set_method(v7, v7_get_global(v7), "QuaternionAddValue", &js_quaternion_add_value);
    v7_set_method(v7, v7_get_global(v7), "QuaternionSubtract", &js_quaternion_subtract);
    v7_set_method(v7, v7_get_global(v7), "QuaternionSubtractValue", &js_quaternion_subtract_value);
    v7_set_method(v7, v7_get_global(v7), "QuaternionIdentity", &js_quaternion_identity);
    v7_set_method(v7, v7_get_global(v7), "QuaternionLength", &js_quaternion_length);
    v7_set_method(v7, v7_get_global(v7), "QuaternionNormalize", &js_quaternion_normalize);
    v7_set_method(v7, v7_get_global(v7), "QuaternionInvert", &js_quaternion_invert);
    v7_set_method(v7, v7_get_global(v7), "QuaternionMultiply", &js_quaternion_multiply);
    v7_set_method(v7, v7_get_global(v7), "QuaternionScale", &js_quaternion_scale);
    v7_set_method(v7, v7_get_global(v7), "QuaternionDivide", &js_quaternion_divide);
    v7_set_method(v7, v7_get_global(v7), "QuaternionLerp", &js_quaternion_lerp);
    v7_set_method(v7, v7_get_global(v7), "QuaternionNlerp", &js_quaternion_nlerp);
    v7_set_method(v7, v7_get_global(v7), "QuaternionSlerp", &js_quaternion_slerp);
    v7_set_method(v7, v7_get_global(v7), "QuaternionFromVector3ToVector3", &js_quaternion_from_vector3_to_vector3);
    v7_set_method(v7, v7_get_global(v7), "QuaternionFromMatrix", &js_quaternion_from_matrix);
    v7_set_method(v7, v7_get_global(v7), "QuaternionToMatrix", &js_quaternion_to_matrix);
    v7_set_method(v7, v7_get_global(v7), "QuaternionFromAxisAngle", &js_quaternion_from_axis_angle);
    v7_set_method(v7, v7_get_global(v7), "QuaternionToAxisAngle", &js_quaternion_to_axis_angle);
    v7_set_method(v7, v7_get_global(v7), "QuaternionFromEuler", &js_quaternion_from_euler);
    v7_set_method(v7, v7_get_global(v7), "QuaternionToEuler", &js_quaternion_to_euler);
    v7_set_method(v7, v7_get_global(v7), "QuaternionTransform", &js_quaternion_transform);
}
