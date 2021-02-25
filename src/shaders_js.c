#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>
#include <shaders_js.h>

static inline enum v7_err js_load_shader(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 1);
    js_return_shader(v7, res, LoadShader(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1)));
    return V7_OK;
}

static inline enum v7_err js_load_shader_code(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 1);
    js_return_shader(v7, res, LoadShaderCode(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1)));
    return V7_OK;
}

static inline enum v7_err js_unload_shader(struct v7* v7) {
    UnloadShader(js_get_shader(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_get_shader_default(struct v7* v7, v7_val_t* res) {
    js_return_shader(v7, res, GetShaderDefault());
    return V7_OK;
}

static inline enum v7_err js_get_texture_default(struct v7* v7, v7_val_t* res) {
    js_return_tex2d(v7, res, GetTextureDefault());
    return V7_OK;
}

static inline enum v7_err js_get_shapes_texture(struct v7* v7, v7_val_t* res) {
    js_return_tex2d(v7, res, GetShapesTexture());
    return V7_OK;
}

static inline enum v7_err js_get_shapes_texture_rec(struct v7* v7, v7_val_t* res) {
    js_return_rect(v7, res, GetShapesTextureRec());
    return V7_OK;
}

static inline enum v7_err js_set_shapes_texture(struct v7* v7) {
    SetShapesTexture(js_get_tex2d(v7, 0), js_get_rect(v7, 1));
    return V7_OK;
}

static inline enum v7_err js_get_shader_location(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_number(v7, (int)GetShaderLocation(js_get_shader(v7, 0), v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_get_shader_location_attrib(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_number(v7, (int)GetShaderLocationAttrib(js_get_shader(v7, 0), v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_set_shader_value(struct v7* v7) {
    SetShaderValue(js_get_shader(v7, 0), v7_get_int(v7, v7_arg(v7, 1)), v7_get_ptr(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_set_shader_value_v(struct v7* v7) {
    SetShaderValueV(js_get_shader(v7, 0), v7_get_int(v7, v7_arg(v7, 1)), v7_get_ptr(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4)));
    return V7_OK;
}

static inline enum v7_err js_set_shader_value_matrix(struct v7* v7) {
    SetShaderValueMatrix(js_get_shader(v7, 0), v7_get_int(v7, v7_arg(v7, 1)), js_get_matrix(v7, 2));
    return V7_OK;
}


static inline enum v7_err js_set_shader_value_texture(struct v7* v7) {
    SetShaderValueTexture(js_get_shader(v7, 0), v7_get_int(v7, v7_arg(v7, 1)), js_get_tex2d(v7, 2));
    return V7_OK;
}

static inline enum v7_err js_set_matrix_projection(struct v7* v7) {
    SetMatrixProjection(js_get_matrix(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_set_matrix_modelview(struct v7* v7) {
    SetMatrixModelview(js_get_matrix(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_get_matrix_modelview(struct v7* v7, v7_val_t* res) {
    js_return_matrix(v7, res, GetMatrixModelview());
    return V7_OK;
}

static inline enum v7_err js_get_matrix_projection(struct v7* v7, v7_val_t* res) {
    js_return_matrix(v7, res, GetMatrixProjection());
    return V7_OK;
}

static inline enum v7_err js_gen_texture_cubemap(struct v7* v7, v7_val_t* res) {
    js_return_tex2d(v7, res, GenTextureCubemap(js_get_shader(v7, 0), js_get_tex2d(v7, 1), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gen_texture_irradiance(struct v7* v7, v7_val_t* res) {
    js_return_tex2d(v7, res, GenTextureIrradiance(js_get_shader(v7, 0), js_get_tex2d(v7, 1), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gen_texture_prefilter(struct v7* v7, v7_val_t* res) {
    js_return_tex2d(v7, res, GenTexturePrefilter(js_get_shader(v7, 0), js_get_tex2d(v7, 1), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gen_texture_brdf(struct v7* v7, v7_val_t* res) {
    js_return_tex2d(v7, res, GenTextureBRDF(js_get_shader(v7, 0), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_begin_shader_mode(struct v7* v7) {
    BeginShaderMode(js_get_shader(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_end_shader_mode(void) {
    EndShaderMode();
    return V7_OK;
}

static inline enum v7_err js_begin_blend_mode(struct v7* v7) {
    BeginBlendMode(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_end_blend_mode(void) {
    EndBlendMode();
    return V7_OK;
}

static inline enum v7_err js_init_vr_simulator(void) {
    InitVrSimulator();
    return V7_OK;
}

static inline enum v7_err js_close_vr_simulator(void) {
    CloseVrSimulator();
    return V7_OK;
}

static inline enum v7_err js_update_vr_tracking(struct v7* v7) {
    Camera camera = js_get_camera3d(v7, 0);
    UpdateVrTracking(&camera);
    js_push_vec3(v7, v7_arg(v7, 0), "position", camera.position);
    js_push_vec3(v7, v7_arg(v7, 0), "target", camera.target);
    js_push_vec3(v7, v7_arg(v7, 0), "up", camera.up);
    js_push_key(v7, v7_arg(v7, 0), "fovy", camera.fovy);
    js_push_key(v7, v7_arg(v7, 0), "type", camera.type);
    return V7_OK;
}

static inline enum v7_err js_set_vr_configuration(struct v7* v7) {
    SetVrConfiguration(js_get_vr_device_info(v7, 0), js_get_shader(v7, 1));
    return V7_OK;
}

static inline enum v7_err js_vr_simulator_ready(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsVrSimulatorReady());
    return V7_OK;
}

static inline enum v7_err js_toggle_vr_mode(void) {
    ToggleVrMode();
    return V7_OK;
}

static inline enum v7_err js_begin_vr_drawing(void) {
    BeginVrDrawing();
    return V7_OK;
}

static inline enum v7_err js_end_vr_drawing(void) {
    EndVrDrawing();
    return V7_OK;
}

void raylib_v7_load_shaders(struct v7* v7) {
    v7_set_method(v7, v7_get_global(v7), "LoadShader", &js_load_shader);
    v7_set_method(v7, v7_get_global(v7), "LoadShaderCode", &js_load_shader_code);
    v7_set_method(v7, v7_get_global(v7), "UnloadShader", &js_unload_shader);

    v7_set_method(v7, v7_get_global(v7), "GetShaderDefault", &js_get_shader_default);
    v7_set_method(v7, v7_get_global(v7), "GetTextureDefault", &js_get_texture_default);
    v7_set_method(v7, v7_get_global(v7), "GetShapesTexture", &js_get_shapes_texture);
    v7_set_method(v7, v7_get_global(v7), "GetShapesTextureRec", &js_get_shapes_texture_rec);
    v7_set_method(v7, v7_get_global(v7), "SetShapesTexture", &js_set_shapes_texture);

    v7_set_method(v7, v7_get_global(v7), "GetShaderLocation", &js_get_shader_location);
    v7_set_method(v7, v7_get_global(v7), "GetShaderLocationAttrib", &js_get_shader_location_attrib);
    v7_set_method(v7, v7_get_global(v7), "SetShaderValue", &js_set_shader_value);
    v7_set_method(v7, v7_get_global(v7), "SetShaderValueV", &js_set_shader_value_v);
    v7_set_method(v7, v7_get_global(v7), "SetShaderValueMatrix", &js_set_shader_value_matrix);
    v7_set_method(v7, v7_get_global(v7), "SetShaderValueTexture", &js_set_shader_value_texture);
    v7_set_method(v7, v7_get_global(v7), "SetMatrixProjection", &js_set_matrix_projection);
    v7_set_method(v7, v7_get_global(v7), "SetMatrixModelview", &js_set_matrix_modelview);
    v7_set_method(v7, v7_get_global(v7), "GetMatrixModelview", &js_get_matrix_modelview);
    v7_set_method(v7, v7_get_global(v7), "GetMatrixProjection", &js_get_matrix_projection);

    v7_set_method(v7, v7_get_global(v7), "GenTextureCubemap", &js_gen_texture_cubemap);
    v7_set_method(v7, v7_get_global(v7), "GenTextureIrradiance", &js_gen_texture_irradiance);
    v7_set_method(v7, v7_get_global(v7), "GenTexturePrefilter", &js_gen_texture_prefilter);
    v7_set_method(v7, v7_get_global(v7), "GenTextureBRDF", &js_gen_texture_brdf);

    v7_set_method(v7, v7_get_global(v7), "BeginShaderMode", &js_begin_shader_mode);
    v7_set_method(v7, v7_get_global(v7), "EndShaderMode", &js_end_shader_mode);
    v7_set_method(v7, v7_get_global(v7), "BeginBlendMode", &js_begin_blend_mode);
    v7_set_method(v7, v7_get_global(v7), "EndBlendMode", &js_end_blend_mode);

    v7_set_method(v7, v7_get_global(v7), "InitVrSimulator", &js_init_vr_simulator);
    v7_set_method(v7, v7_get_global(v7), "CloseVrSimulator", &js_close_vr_simulator);
    v7_set_method(v7, v7_get_global(v7), "UpdateVrTracking", &js_update_vr_tracking);
    v7_set_method(v7, v7_get_global(v7), "SetVrConfiguration", &js_set_vr_configuration);
    v7_set_method(v7, v7_get_global(v7), "IsVrSimulatorReady", &js_vr_simulator_ready);
    v7_set_method(v7, v7_get_global(v7), "ToggleVrMode", &js_toggle_vr_mode);
    v7_set_method(v7, v7_get_global(v7), "BeginVrDrawing", &js_begin_vr_drawing);
    v7_set_method(v7, v7_get_global(v7), "EndVrDrawing", &js_end_vr_drawing);
}
