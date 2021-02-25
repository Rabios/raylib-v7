#include <raylib.h>
#include <rlgl.h>
#include <v7/v7.h>
#include <get_set.h>
#include <rlgl_js.h>

static inline enum v7_err js_rl_matrix_mode(struct v7* v7) {
    rlMatrixMode(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_rl_push_matrix(void) {
    rlPushMatrix();
    return V7_OK;
}

static inline enum v7_err js_rl_pop_matrix(void) {
    rlPopMatrix();
    return V7_OK;
}

static inline enum v7_err js_rl_load_identity(void) {
    rlLoadIdentity();
    return V7_OK;
}

static inline enum v7_err js_rl_translatef(struct v7* v7) {
    rlTranslatef(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_rl_rotatef(struct v7* v7) {
    rlRotatef(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_rl_scalef(struct v7* v7) {
    rlScalef(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_rl_multmatrixf(struct v7* v7) {
    float matrix[16] = {
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "0", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "1", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "2", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "3", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "4", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "5", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "6", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "7", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "8", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "9", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "10", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "11", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "12", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "13", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "14", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, 0), "15", ~0)),
    };
    rlMultMatrixf(matrix);
    return V7_OK;
}

static inline enum v7_err js_rl_frustum(struct v7* v7) {
    rlFrustum(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3)), v7_get_double(v7, v7_arg(v7, 4)), v7_get_double(v7, v7_arg(v7, 5)));
    return V7_OK;
}

static inline enum v7_err js_rl_ortho(struct v7* v7) {
    rlOrtho(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3)), v7_get_double(v7, v7_arg(v7, 4)), v7_get_double(v7, v7_arg(v7, 5)));
    return V7_OK;
}

static inline enum v7_err js_rl_viewport(struct v7* v7) {
    rlViewport(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_rl_begin(struct v7* v7) {
    rlBegin(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_rl_end(void) {
    rlEnd();
    return V7_OK;
}

static inline enum v7_err js_rl_vertex2i(struct v7* v7) {
    rlVertex2i(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_rl_vertex2f(struct v7* v7) {
    rlVertex2f(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_rl_vertex3f(struct v7* v7) {
    rlVertex3f(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_rl_texcoord2f(struct v7* v7) {
    rlTexCoord2f(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_rl_normal3f(struct v7* v7) {
    rlNormal3f(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_rl_color4ub(struct v7* v7) {
    rlColor4ub(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_rl_color3f(struct v7* v7) {
    rlColor3f(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_rl_color4f(struct v7* v7) {
    rlColor4f(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_rl_enable_texture(struct v7* v7) {
    rlEnableTexture(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_rl_disable_texture(void) {
    rlDisableTexture();
    return V7_OK;
}

static inline enum v7_err js_rl_texture_parameters(struct v7* v7) {
    rlTextureParameters(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_rl_enable_shader(struct v7* v7) {
    rlEnableShader(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_rl_disable_shader(void) {
    rlDisableShader();
    return V7_OK;
}

static inline enum v7_err js_rl_enable_framebuffer(struct v7* v7) {
    rlEnableFramebuffer(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_rl_disable_framebuffer(void) {
    rlDisableFramebuffer();
    return V7_OK;
}

static inline enum v7_err js_rl_enable_depth_test(void) {
    rlEnableDepthTest();
    return V7_OK;
}

static inline enum v7_err js_rl_disable_depth_test(void) {
    rlDisableDepthTest();
    return V7_OK;
}

static inline enum v7_err js_rl_enable_depth_mask(void) {
    rlEnableDepthMask();
    return V7_OK;
}

static inline enum v7_err js_rl_disable_depth_mask(void) {
    rlDisableDepthMask();
    return V7_OK;
}

static inline enum v7_err js_rl_enable_backface_culling(void) {
    rlEnableBackfaceCulling();
    return V7_OK;
}

static inline enum v7_err js_rl_disable_backface_culling(void) {
    rlDisableBackfaceCulling();
    return V7_OK;
}

static inline enum v7_err js_rl_enable_scissor_test(void) {
    rlEnableScissorTest();
    return V7_OK;
}

static inline enum v7_err js_rl_disable_scissor_test(void) {
    rlDisableScissorTest();
    return V7_OK;
}

static inline enum v7_err js_rl_scissor(struct v7* v7) {
    rlScissor(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_rl_enable_wire_mode(void) {
    rlEnableWireMode();
    return V7_OK;
}

static inline enum v7_err js_rl_disable_wire_mode(void) {
    rlDisableWireMode();
    return V7_OK;
}

static inline enum v7_err js_rl_set_line_width(struct v7* v7) {
    rlSetLineWidth(v7_get_double(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_rl_get_line_width(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, rlGetLineWidth());
    return V7_OK;
}

static inline enum v7_err js_rl_enable_smooth_lines(void) {
    rlEnableSmoothLines();
    return V7_OK;
}

static inline enum v7_err js_rl_disable_smooth_lines(void) {
    rlDisableSmoothLines();
    return V7_OK;
}

static inline enum v7_err js_rl_clear_color(struct v7* v7) {
    rlClearColor(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_rl_clear_screen_buffers(void) {
    rlClearScreenBuffers();
    return V7_OK;
}

static inline enum v7_err js_rl_update_buffer(struct v7* v7) {
    rlUpdateBuffer(v7_get_int(v7, v7_arg(v7, 0)), v7_get_ptr(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_rl_load_attrib_buffer(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, rlLoadAttribBuffer(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_ptr(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), v7_get_bool(v7, v7_arg(v7, 4))));
    return V7_OK;
}

static inline enum v7_err js_rlgl_init(struct v7* v7) {
    rlglInit(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_rlgl_close(void) {
    rlglClose();
    return V7_OK;
}

static inline enum v7_err js_rlgl_draw(void) {
    rlglDraw();
    return V7_OK;
}

static inline enum v7_err js_rl_check_errors(void) {
    rlCheckErrors();
    return V7_OK;
}

static inline enum v7_err js_rl_get_version(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, rlGetVersion());
    return V7_OK;
}

static inline enum v7_err js_rl_check_buffer_limit(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, rlCheckBufferLimit(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_rl_set_debug_marker(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    rlSetDebugMarker(v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_rl_set_blend_mode(struct v7* v7) {
    rlSetBlendMode(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_rl_load_extensions(struct v7* v7) {
    rlLoadExtensions(v7_get_ptr(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_rl_load_texture(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, rlLoadTexture(v7_get_ptr(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4))));
    return V7_OK;
}

static inline enum v7_err js_rl_load_texture_depth(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, rlLoadTextureDepth(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_bool(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_rl_load_texture_cubemap(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, rlLoadTextureCubemap(v7_get_ptr(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_bool(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_rl_update_texture(struct v7* v7) {
    rlUpdateTexture(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4)), v7_get_int(v7, v7_arg(v7, 5)), v7_get_ptr(v7, v7_arg(v7, 6)));
    return V7_OK;
}

static inline enum v7_err js_rl_get_gl_texture_formats(struct v7* v7) {
    unsigned int glInternalFormat = v7_get_int(v7, v7_arg(v7, 1));
    unsigned int glFormat = v7_get_int(v7, v7_arg(v7, 2));
    unsigned int glType = v7_get_int(v7, v7_arg(v7, 3));
    rlGetGlTextureFormats(v7_get_int(v7, v7_arg(v7, 0)), &glInternalFormat, &glFormat, &glType);
    return V7_OK;
}

static inline enum v7_err js_rl_unload_texture(struct v7* v7) {
    rlUnloadTexture(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_rl_generate_mipmaps(struct v7* v7) {
    Texture texture = js_get_tex2d(v7, 0);
    rlGenerateMipmaps(&texture);
    js_update_tex2d(v7, 0, texture);
    return V7_OK;
}

static inline enum v7_err js_rl_read_texture_pixels(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_foreign(v7, rlReadTexturePixels(js_get_tex2d(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_rl_read_screen_pixels(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_foreign(v7, rlReadScreenPixels(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_rl_load_framebuffer(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, rlLoadFramebuffer(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_rl_framebuffer_attach(struct v7* v7) {
    rlFramebufferAttach(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_rl_framebuffer_complete(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)rlFramebufferComplete(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_rl_unload_framebuffer(struct v7* v7) {
    rlUnloadFramebuffer(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_rl_load_mesh(struct v7* v7) {
    Mesh mesh = js_get_mesh(v7, 0);
    rlLoadMesh(&mesh, v7_get_bool(v7, v7_arg(v7, 1)));
    js_update_mesh(v7, 0, mesh);
    return V7_OK;
}

static inline enum v7_err js_rl_update_mesh(struct v7* v7) {
    rlUpdateMesh(js_get_mesh(v7, 0), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_rl_update_mesh_at(struct v7* v7) {
    rlUpdateMeshAt(js_get_mesh(v7, 0), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_rl_draw_mesh(struct v7* v7) {
    rlDrawMesh(js_get_mesh(v7, 0), js_get_material(v7, 1), js_get_matrix(v7, 2));
    return V7_OK;
}

static inline enum v7_err js_rl_draw_mesh_instanced(struct v7* v7) {
    rlDrawMeshInstanced(js_get_mesh(v7, 0), js_get_material(v7, 1), v7_get_ptr(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_rl_unload_mesh(struct v7* v7) {
    rlUnloadMesh(js_get_mesh(v7, 0));
    return V7_OK;
}

void raylib_v7_load_rlgl(struct v7* v7) {
    js_push_key(v7, v7_get_global(v7), "RL_TEXTURE_WRAP_S", RL_TEXTURE_WRAP_S);
    js_push_key(v7, v7_get_global(v7), "RL_TEXTURE_WRAP_T", RL_TEXTURE_WRAP_T);
    js_push_key(v7, v7_get_global(v7), "RL_TEXTURE_MAG_FILTER", RL_TEXTURE_MAG_FILTER);
    js_push_key(v7, v7_get_global(v7), "RL_TEXTURE_MIN_FILTER", RL_TEXTURE_MIN_FILTER);
    js_push_key(v7, v7_get_global(v7), "RL_TEXTURE_ANISOTROPIC_FILTER", RL_TEXTURE_ANISOTROPIC_FILTER);

    js_push_key(v7, v7_get_global(v7), "RL_FILTER_NEAREST", RL_FILTER_NEAREST);
    js_push_key(v7, v7_get_global(v7), "RL_FILTER_LINEAR", RL_FILTER_LINEAR);
    js_push_key(v7, v7_get_global(v7), "RL_FILTER_MIP_NEAREST", RL_FILTER_MIP_NEAREST);
    js_push_key(v7, v7_get_global(v7), "RL_FILTER_NEAREST_MIP_LINEAR", RL_FILTER_NEAREST_MIP_LINEAR);
    js_push_key(v7, v7_get_global(v7), "RL_FILTER_LINEAR_MIP_NEAREST", RL_FILTER_LINEAR_MIP_NEAREST);
    js_push_key(v7, v7_get_global(v7), "RL_FILTER_MIP_LINEAR", RL_FILTER_MIP_LINEAR);

    js_push_key(v7, v7_get_global(v7), "RL_WRAP_REPEAT", RL_WRAP_REPEAT);
    js_push_key(v7, v7_get_global(v7), "RL_WRAP_CLAMP", RL_WRAP_CLAMP);
    js_push_key(v7, v7_get_global(v7), "RL_WRAP_MIRROR_REPEAT", RL_WRAP_MIRROR_REPEAT);
    js_push_key(v7, v7_get_global(v7), "RL_WRAP_MIRROR_CLAMP", RL_WRAP_MIRROR_CLAMP);

    js_push_key(v7, v7_get_global(v7), "RL_MODELVIEW", RL_MODELVIEW);
    js_push_key(v7, v7_get_global(v7), "RL_PROJECTION", RL_PROJECTION);
    js_push_key(v7, v7_get_global(v7), "RL_TEXTURE", RL_TEXTURE);

    js_push_key(v7, v7_get_global(v7), "RL_LINES", RL_LINES);
    js_push_key(v7, v7_get_global(v7), "RL_TRIANGLES", RL_TRIANGLES);
    js_push_key(v7, v7_get_global(v7), "RL_QUADS", RL_QUADS);

    js_push_key(v7, v7_get_global(v7), "OPENGL_11", OPENGL_11);
    js_push_key(v7, v7_get_global(v7), "OPENGL_21", OPENGL_21);
    js_push_key(v7, v7_get_global(v7), "OPENGL_33", OPENGL_33);
    js_push_key(v7, v7_get_global(v7), "OPENGL_ES_20", OPENGL_ES_20);

    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_COLOR_CHANNEL0", RL_ATTACHMENT_COLOR_CHANNEL0);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_COLOR_CHANNEL1", RL_ATTACHMENT_COLOR_CHANNEL1);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_COLOR_CHANNEL2", RL_ATTACHMENT_COLOR_CHANNEL2);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_COLOR_CHANNEL3", RL_ATTACHMENT_COLOR_CHANNEL3);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_COLOR_CHANNEL4", RL_ATTACHMENT_COLOR_CHANNEL4);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_COLOR_CHANNEL5", RL_ATTACHMENT_COLOR_CHANNEL5);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_COLOR_CHANNEL6", RL_ATTACHMENT_COLOR_CHANNEL6);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_COLOR_CHANNEL7", RL_ATTACHMENT_COLOR_CHANNEL7);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_DEPTH", RL_ATTACHMENT_DEPTH);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_STENCIL", RL_ATTACHMENT_STENCIL);

    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_CUBEMAP_POSITIVE_X", RL_ATTACHMENT_CUBEMAP_POSITIVE_X);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_CUBEMAP_NEGATIVE_X", RL_ATTACHMENT_CUBEMAP_NEGATIVE_X);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_CUBEMAP_POSITIVE_Y", RL_ATTACHMENT_CUBEMAP_POSITIVE_Y);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_CUBEMAP_NEGATIVE_Y", RL_ATTACHMENT_CUBEMAP_NEGATIVE_Y);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_CUBEMAP_POSITIVE_Z", RL_ATTACHMENT_CUBEMAP_POSITIVE_Z);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_CUBEMAP_NEGATIVE_Z", RL_ATTACHMENT_CUBEMAP_NEGATIVE_Z);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_TEXTURE2D", RL_ATTACHMENT_TEXTURE2D);
    js_push_key(v7, v7_get_global(v7), "RL_ATTACHMENT_RENDERBUFFER", RL_ATTACHMENT_RENDERBUFFER);

    v7_set_method(v7, v7_get_global(v7), "rlMatrixMode", &js_rl_matrix_mode);
    v7_set_method(v7, v7_get_global(v7), "rlPushMatrix", &js_rl_push_matrix);
    v7_set_method(v7, v7_get_global(v7), "rlPopMatrix", &js_rl_pop_matrix);
    v7_set_method(v7, v7_get_global(v7), "rlLoadIdentity", &js_rl_load_identity);
    v7_set_method(v7, v7_get_global(v7), "rlTranslatef", &js_rl_translatef);
    v7_set_method(v7, v7_get_global(v7), "rlRotatef", &js_rl_rotatef);
    v7_set_method(v7, v7_get_global(v7), "rlScalef", &js_rl_scalef);
    v7_set_method(v7, v7_get_global(v7), "rlMultMatrixf", &js_rl_multmatrixf);
    v7_set_method(v7, v7_get_global(v7), "rlFrustum", &js_rl_frustum);
    v7_set_method(v7, v7_get_global(v7), "rlOrtho", &js_rl_ortho);
    v7_set_method(v7, v7_get_global(v7), "rlViewport", &js_rl_viewport);

    v7_set_method(v7, v7_get_global(v7), "rlBegin", &js_rl_begin);
    v7_set_method(v7, v7_get_global(v7), "rlEnd", &js_rl_end);
    v7_set_method(v7, v7_get_global(v7), "rlVertex2i", &js_rl_vertex2i);
    v7_set_method(v7, v7_get_global(v7), "rlVertex2f", &js_rl_vertex2f);
    v7_set_method(v7, v7_get_global(v7), "rlVertex3f", &js_rl_vertex3f);
    v7_set_method(v7, v7_get_global(v7), "rlTexCoord2f", &js_rl_texcoord2f);
    v7_set_method(v7, v7_get_global(v7), "rlNormal3f", &js_rl_normal3f);
    v7_set_method(v7, v7_get_global(v7), "rlColor4ub", &js_rl_color4ub);
    v7_set_method(v7, v7_get_global(v7), "rlColor3f", &js_rl_color3f);
    v7_set_method(v7, v7_get_global(v7), "rlColor4f", &js_rl_color4f);

    v7_set_method(v7, v7_get_global(v7), "rlEnableTexture", &js_rl_enable_texture);
    v7_set_method(v7, v7_get_global(v7), "rlDisableTexture", &js_rl_disable_texture);
    v7_set_method(v7, v7_get_global(v7), "rlTextureParameters", &js_rl_texture_parameters);
    v7_set_method(v7, v7_get_global(v7), "rlEnableShader", &js_rl_enable_shader);
    v7_set_method(v7, v7_get_global(v7), "rlDisableShader", &js_rl_disable_shader);
    v7_set_method(v7, v7_get_global(v7), "rlEnableFramebuffer", &js_rl_enable_framebuffer);
    v7_set_method(v7, v7_get_global(v7), "rlDisableFramebuffer", &js_rl_disable_framebuffer);
    v7_set_method(v7, v7_get_global(v7), "rlEnableDepthTest", &js_rl_enable_depth_test);
    v7_set_method(v7, v7_get_global(v7), "rlDisableDepthTest", &js_rl_disable_depth_test);
    v7_set_method(v7, v7_get_global(v7), "rlEnableDepthMask", &js_rl_enable_depth_mask);
    v7_set_method(v7, v7_get_global(v7), "rlDisableDepthMask", &js_rl_disable_depth_mask);
    v7_set_method(v7, v7_get_global(v7), "rlEnableBackfaceCulling", &js_rl_enable_backface_culling);
    v7_set_method(v7, v7_get_global(v7), "rlDisableBackfaceCulling", &js_rl_disable_backface_culling);
    v7_set_method(v7, v7_get_global(v7), "rlEnableScissorTest", &js_rl_enable_scissor_test);
    v7_set_method(v7, v7_get_global(v7), "rlDisableScissorTest", &js_rl_disable_scissor_test);
    v7_set_method(v7, v7_get_global(v7), "rlScissor", &js_rl_scissor);
    v7_set_method(v7, v7_get_global(v7), "rlEnableWireMode", &js_rl_enable_wire_mode);
    v7_set_method(v7, v7_get_global(v7), "rlDisableWireMode", &js_rl_disable_wire_mode);
    v7_set_method(v7, v7_get_global(v7), "rlSetLineWidth", &js_rl_set_line_width);
    v7_set_method(v7, v7_get_global(v7), "rlGetLineWidth", &js_rl_get_line_width);
    v7_set_method(v7, v7_get_global(v7), "rlEnableSmoothLines", &js_rl_enable_smooth_lines);
    v7_set_method(v7, v7_get_global(v7), "rlDisableSmoothLines", &js_rl_disable_smooth_lines);

    v7_set_method(v7, v7_get_global(v7), "rlClearColor", &js_rl_clear_color);
    v7_set_method(v7, v7_get_global(v7), "rlClearScreenBuffers", &js_rl_clear_screen_buffers);
    v7_set_method(v7, v7_get_global(v7), "rlUpdateBuffer", &js_rl_update_buffer);
    v7_set_method(v7, v7_get_global(v7), "rlLoadAttribBuffer", &js_rl_load_attrib_buffer);

    v7_set_method(v7, v7_get_global(v7), "rlglInit", &js_rlgl_init);
    v7_set_method(v7, v7_get_global(v7), "rlglClose", &js_rlgl_close);
    v7_set_method(v7, v7_get_global(v7), "rlglDraw", &js_rlgl_draw);
    v7_set_method(v7, v7_get_global(v7), "rlCheckErrors", &js_rl_check_errors);

    v7_set_method(v7, v7_get_global(v7), "rlGetVersion", &js_rl_get_version);
    v7_set_method(v7, v7_get_global(v7), "rlCheckBufferLimit", &js_rl_check_buffer_limit);
    v7_set_method(v7, v7_get_global(v7), "rlSetDebugMarker", &js_rl_set_debug_marker);
    v7_set_method(v7, v7_get_global(v7), "rlSetBlendMode", &js_rl_set_blend_mode);
    v7_set_method(v7, v7_get_global(v7), "rlLoadExtensions", &js_rl_load_extensions);

    v7_set_method(v7, v7_get_global(v7), "rlLoadTexture", &js_rl_load_texture);
    v7_set_method(v7, v7_get_global(v7), "rlLoadTextureDepth", &js_rl_load_texture_depth);
    v7_set_method(v7, v7_get_global(v7), "rlLoadTextureCubemap", &js_rl_load_texture_cubemap);
    v7_set_method(v7, v7_get_global(v7), "rlUpdateTexture", &js_rl_update_texture);
    v7_set_method(v7, v7_get_global(v7), "rlGetGlTextureFormats", &js_rl_get_gl_texture_formats);
    v7_set_method(v7, v7_get_global(v7), "rlUnloadTexture", &js_rl_unload_texture);

    v7_set_method(v7, v7_get_global(v7), "rlGenerateMipmaps", &js_rl_generate_mipmaps);
    v7_set_method(v7, v7_get_global(v7), "rlReadTexturePixels", &js_rl_read_texture_pixels);
    v7_set_method(v7, v7_get_global(v7), "rlReadScreenPixels", &js_rl_read_screen_pixels);

    v7_set_method(v7, v7_get_global(v7), "rlLoadFramebuffer", &js_rl_load_framebuffer);
    v7_set_method(v7, v7_get_global(v7), "rlFramebufferAttach", &js_rl_framebuffer_attach);
    v7_set_method(v7, v7_get_global(v7), "rlFramebufferComplete", &js_rl_framebuffer_complete);
    v7_set_method(v7, v7_get_global(v7), "rlUnloadFramebuffer", &js_rl_unload_framebuffer);

    v7_set_method(v7, v7_get_global(v7), "rlLoadMesh", &js_rl_load_mesh);
    v7_set_method(v7, v7_get_global(v7), "rlUpdateMesh", &js_rl_update_mesh);
    v7_set_method(v7, v7_get_global(v7), "rlUpdateMeshAt", &js_rl_update_mesh_at);
    v7_set_method(v7, v7_get_global(v7), "rlDrawMesh", &js_rl_draw_mesh);
    v7_set_method(v7, v7_get_global(v7), "rlDrawMeshInstanced", &js_rl_draw_mesh_instanced);
    v7_set_method(v7, v7_get_global(v7), "rlUnloadMesh", &js_rl_unload_mesh);
}
