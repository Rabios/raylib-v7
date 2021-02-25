#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>

void js_push_val(struct v7* v7, v7_val_t obj, char* var_name, v7_val_t val) {
    v7_set(v7, obj, var_name, ~0, val);
}

void js_push_key(struct v7* v7, v7_val_t obj, char* var_name, double val) {
    v7_set(v7, obj, var_name, ~0, v7_mk_number(v7, val));
}

Color js_get_color(struct v7* v7, unsigned int arg) {
    Color color = (Color) {
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "r", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "g", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "b", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "a", ~0)),
    };
    return color;
}

void js_push_color(struct v7* v7, v7_val_t obj, char* var_name, Color color) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "r", ~0, v7_mk_number(v7, color.r));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "g", ~0, v7_mk_number(v7, color.g));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "b", ~0, v7_mk_number(v7, color.b));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "a", ~0, v7_mk_number(v7, color.a));
}

void js_return_color(struct v7* v7, v7_val_t* res, Color color) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "r", ~0, v7_mk_number(v7, color.r));
    v7_set(v7, *res, "g", ~0, v7_mk_number(v7, color.g));
    v7_set(v7, *res, "b", ~0, v7_mk_number(v7, color.b));
    v7_set(v7, *res, "a", ~0, v7_mk_number(v7, color.a));
}

Color js_color_from_obj(struct v7* v7, v7_val_t obj) {
    Color color = (Color){
        v7_get_int(v7, v7_get(v7, obj, "r", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "g", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "b", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "a", ~0)),
    };
    return color;
}

Vector2 js_get_vec2(struct v7* v7, unsigned int arg) {
    Vector2 vec2 = (Vector2) {
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "x", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "y", ~0)),
    };
    return vec2;
}

void js_push_vec2(struct v7* v7, v7_val_t obj, char* var_name, Vector2 vec2) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "x", ~0, v7_mk_number(v7, vec2.x));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "y", ~0, v7_mk_number(v7, vec2.y));
}

void js_return_vec2(struct v7* v7, v7_val_t* res, Vector2 vec2) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "x", ~0, v7_mk_number(v7, vec2.x));
    v7_set(v7, *res, "y", ~0, v7_mk_number(v7, vec2.y));
}

Vector2 js_vec2_from_obj(struct v7* v7, v7_val_t obj) {
    Vector2 vec2 = (Vector2) {
        v7_get_double(v7, v7_get(v7, obj, "x", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "y", ~0)),
    };
    return vec2;
}

Vector3 js_get_vec3(struct v7* v7, unsigned int arg) {
    Vector3 vec3 = (Vector3) {
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "x", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "y", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "z", ~0)),
    };
    return vec3;
}

void js_push_vec3(struct v7* v7, v7_val_t obj, char* var_name, Vector3 vec3) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "x", ~0, v7_mk_number(v7, vec3.x));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "y", ~0, v7_mk_number(v7, vec3.y));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "z", ~0, v7_mk_number(v7, vec3.z));
}

void js_return_vec3(struct v7* v7, v7_val_t* res, Vector3 vec3) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "x", ~0, v7_mk_number(v7, vec3.x));
    v7_set(v7, *res, "y", ~0, v7_mk_number(v7, vec3.y));
    v7_set(v7, *res, "z", ~0, v7_mk_number(v7, vec3.z));
}

Vector3 js_vec3_from_obj(struct v7* v7, v7_val_t obj) {
    Vector3 vec3 = (Vector3){
        v7_get_double(v7, v7_get(v7, obj, "x", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "y", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "z", ~0)),
    };
    return vec3;
}

void js_update_vec3(struct v7* v7, unsigned int arg, Vector3 vec3) {
    v7_set(v7, v7_arg(v7, arg), "x", ~0, v7_mk_number(v7, vec3.x));
    v7_set(v7, v7_arg(v7, arg), "y", ~0, v7_mk_number(v7, vec3.y));
    v7_set(v7, v7_arg(v7, arg), "z", ~0, v7_mk_number(v7, vec3.z));
}

Vector4 js_get_vec4(struct v7* v7, unsigned int arg) {
    Vector4 vec4 = (Vector4) {
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "x", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "y", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "z", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "w", ~0)),
    };
    return vec4;
}

void js_push_vec4(struct v7* v7, v7_val_t obj, char* var_name, Vector4 vec4) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "x", ~0, v7_mk_number(v7, vec4.x));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "y", ~0, v7_mk_number(v7, vec4.y));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "z", ~0, v7_mk_number(v7, vec4.z));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "w", ~0, v7_mk_number(v7, vec4.w));
}

void js_return_vec4(struct v7* v7, v7_val_t* res, Vector4 vec4) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "x", ~0, v7_mk_number(v7, vec4.x));
    v7_set(v7, *res, "y", ~0, v7_mk_number(v7, vec4.y));
    v7_set(v7, *res, "z", ~0, v7_mk_number(v7, vec4.z));
    v7_set(v7, *res, "w", ~0, v7_mk_number(v7, vec4.w));
}

Vector4 js_vec4_from_obj(struct v7* v7, v7_val_t obj) {
    Vector4 vec4 = (Vector4) {
        v7_get_double(v7, v7_get(v7, obj, "x", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "y", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "z", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "w", ~0)),
    };
    return vec4;
}

Quaternion js_get_quat(struct v7* v7, unsigned int arg) {
    Quaternion quat = (Quaternion) {
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "x", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "y", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "z", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "w", ~0)),
    };
    return quat;
}

void js_push_quat(struct v7* v7, v7_val_t obj, char* var_name, Quaternion quat) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "x", ~0, v7_mk_number(v7, quat.x));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "y", ~0, v7_mk_number(v7, quat.y));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "z", ~0, v7_mk_number(v7, quat.z));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "w", ~0, v7_mk_number(v7, quat.w));
}

void js_return_quat(struct v7* v7, v7_val_t *res, Quaternion quat) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "x", ~0, v7_mk_number(v7, quat.x));
    v7_set(v7, *res, "y", ~0, v7_mk_number(v7, quat.y));
    v7_set(v7, *res, "z", ~0, v7_mk_number(v7, quat.z));
    v7_set(v7, *res, "w", ~0, v7_mk_number(v7, quat.w));
}

Quaternion js_quat_from_obj(struct v7* v7, v7_val_t obj) {
    Quaternion quat = (Quaternion){
        v7_get_double(v7, v7_get(v7, obj, "x", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "y", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "z", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "w", ~0)),
    };
    return quat;
}

Rectangle js_get_rect(struct v7* v7, unsigned int arg) {
    Rectangle rect = (Rectangle) {
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "x", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "y", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "width", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "height", ~0)),
    };
    return rect;
}

void js_push_rect(struct v7* v7, v7_val_t obj, char* var_name, Rectangle rect) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "x", ~0, v7_mk_number(v7, rect.x));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "y", ~0, v7_mk_number(v7, rect.y));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "width", ~0, v7_mk_number(v7, rect.width));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "height", ~0, v7_mk_number(v7, rect.height));
}

void js_return_rect(struct v7* v7, v7_val_t* res, Rectangle rect) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "x", ~0, v7_mk_number(v7, rect.x));
    v7_set(v7, *res, "y", ~0, v7_mk_number(v7, rect.y));
    v7_set(v7, *res, "width", ~0, v7_mk_number(v7, rect.width));
    v7_set(v7, *res, "height", ~0, v7_mk_number(v7, rect.height));
}

Rectangle js_rect_from_obj(struct v7* v7, v7_val_t obj) {
    Rectangle rect = (Rectangle){
        v7_get_double(v7, v7_get(v7, obj, "x", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "y", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "width", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "height", ~0)),
    };
    return rect;
}

Camera2D js_get_camera2d(struct v7* v7, unsigned int arg) {
    Camera2D camera = (Camera2D) {
        js_vec2_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "offset", ~0)),
        js_vec2_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "target", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "rotation", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "zoom", ~0)),
    };
    return camera;
}

void js_push_camera2d(struct v7* v7, v7_val_t obj, char* var_name, Camera2D camera) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    js_push_vec2(v7, v7_get(v7, obj, var_name, ~0), "offset", camera.offset);
    js_push_vec2(v7, v7_get(v7, obj, var_name, ~0), "target", camera.target);
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "rotation", ~0, v7_mk_number(v7, camera.rotation));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "zoom", ~0, v7_mk_number(v7, camera.zoom));
}

void js_return_camera2d(struct v7* v7, v7_val_t* res, Camera2D camera) {
    *res = v7_mk_object(v7);
    js_push_vec2(v7, *res, "offset", camera.offset);
    js_push_vec2(v7, *res, "target", camera.target);
    v7_set(v7, *res, "rotation", ~0, v7_mk_number(v7, camera.rotation));
    v7_set(v7, *res, "zoom", ~0, v7_mk_number(v7, camera.zoom));
}

Camera js_get_camera3d(struct v7* v7, unsigned int arg) {
    Camera camera = (Camera){
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "position", ~0)),
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "target", ~0)),
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "up", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "fovy", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "type", ~0)),
    };
    return camera;
}

void js_push_camera3d(struct v7* v7, v7_val_t obj, char* var_name, Camera camera) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    js_push_vec3(v7, v7_get(v7, obj, var_name, ~0), "position", camera.position);
    js_push_vec3(v7, v7_get(v7, obj, var_name, ~0), "target", camera.target);
    js_push_vec3(v7, v7_get(v7, obj, var_name, ~0), "up", camera.up);
    js_push_key(v7, v7_get(v7, obj, var_name, ~0), "fovy", camera.fovy);
    js_push_key(v7, v7_get(v7, obj, var_name, ~0), "type", camera.type);
}

void js_return_camera3d(struct v7* v7, v7_val_t* res, Camera camera) {
    *res = v7_mk_object(v7);
    js_push_vec3(v7, *res, "position", camera.position);
    js_push_vec3(v7, *res, "target", camera.target);
    js_push_vec3(v7, *res, "up", camera.up);
    v7_set(v7, *res, "fovy", ~0, v7_mk_number(v7, camera.fovy));
    v7_set(v7, *res, "type", ~0, v7_mk_number(v7, camera.type));
}

Texture js_get_tex2d(struct v7* v7, unsigned int arg) {
    Texture texture = (Texture){
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "id", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "width", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "height", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "mipmaps", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "format", ~0))
    };
    return texture;
}

void js_push_tex2d(struct v7* v7, v7_val_t obj, char* var_name, Texture texture) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "id", ~0, v7_mk_number(v7, texture.id));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "width", ~0, v7_mk_number(v7, texture.width));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "height", ~0, v7_mk_number(v7, texture.height));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "mipmaps", ~0, v7_mk_number(v7, texture.mipmaps));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "format", ~0, v7_mk_number(v7, texture.format));
}

void js_return_tex2d(struct v7* v7, v7_val_t* res, Texture texture) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "id", ~0, v7_mk_number(v7, texture.id));
    v7_set(v7, *res, "width", ~0, v7_mk_number(v7, texture.width));
    v7_set(v7, *res, "height", ~0, v7_mk_number(v7, texture.height));
    v7_set(v7, *res, "mipmaps", ~0, v7_mk_number(v7, texture.mipmaps));
    v7_set(v7, *res, "format", ~0, v7_mk_number(v7, texture.format));
}

Texture js_tex2d_from_obj(struct v7* v7, v7_val_t obj) {
    Texture texture = (Texture) {
        v7_get_int(v7, v7_get(v7, obj, "id", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "width", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "height", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "mipmaps", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "format", ~0)),
    };
    return texture;
}

void js_update_tex2d(struct v7* v7, unsigned int arg, Texture texture) {
    v7_set(v7, v7_arg(v7, arg), "id", ~0, v7_mk_number(v7, texture.id));
    v7_set(v7, v7_arg(v7, arg), "width", ~0, v7_mk_number(v7, texture.width));
    v7_set(v7, v7_arg(v7, arg), "height", ~0, v7_mk_number(v7, texture.height));
    v7_set(v7, v7_arg(v7, arg), "mipmaps", ~0, v7_mk_number(v7, texture.mipmaps));
    v7_set(v7, v7_arg(v7, arg), "format", ~0, v7_mk_number(v7, texture.format));
}

RenderTexture2D js_get_render_texture_2d(struct v7* v7, unsigned int arg) {
    RenderTexture2D texture = (RenderTexture2D){
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "id", ~0)),
        js_tex2d_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "texture", ~0)),
        js_tex2d_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "depth", ~0)),
    };
    return texture;
}

void js_push_render_texture_2d(struct v7* v7, v7_val_t obj, char* var_name, RenderTexture2D texture) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "id", ~0, v7_mk_number(v7, texture.id));
    js_push_tex2d(v7, obj, "texture", texture.texture);
    js_push_tex2d(v7, obj, "depth", texture.depth);
}

void js_return_render_texture_2d(struct v7* v7, v7_val_t* res, RenderTexture2D texture) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "id", ~0, texture.id);
    js_push_tex2d(v7, *res, "texture", texture.texture);
    js_push_tex2d(v7, *res, "depth", texture.depth);
}

Image js_get_image(struct v7* v7, unsigned int arg) {
    Image image = (Image){
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "data", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "width", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "height", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "mipmaps", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "format", ~0)),
    };
    return image;
}

void js_push_image(struct v7* v7, v7_val_t obj, char* var_name, Image image) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "data", ~0, v7_mk_foreign(v7, image.data));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "width", ~0, v7_mk_number(v7, image.width));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "height", ~0, v7_mk_number(v7, image.height));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "mipmaps", ~0, v7_mk_number(v7, image.mipmaps));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "format", ~0, v7_mk_number(v7, image.format));
}

void js_return_image(struct v7* v7, v7_val_t* res, Image image) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "data", ~0, v7_mk_foreign(v7, image.data));
    v7_set(v7, *res, "width", ~0, v7_mk_number(v7, image.width));
    v7_set(v7, *res, "height", ~0, v7_mk_number(v7, image.height));
    v7_set(v7, *res, "mipmaps", ~0, v7_mk_number(v7, image.mipmaps));
    v7_set(v7, *res, "format", ~0, v7_mk_number(v7, image.format));
}

void js_update_image(struct v7* v7, unsigned int arg, Image image) {
    v7_set(v7, v7_arg(v7, arg), "data", ~0, v7_mk_foreign(v7, image.data));
    v7_set(v7, v7_arg(v7, arg), "width", ~0, v7_mk_number(v7, image.width));
    v7_set(v7, v7_arg(v7, arg), "height", ~0, v7_mk_number(v7, image.height));
    v7_set(v7, v7_arg(v7, arg), "mipmaps", ~0, v7_mk_number(v7, image.mipmaps));
    v7_set(v7, v7_arg(v7, arg), "format", ~0, v7_mk_number(v7, image.format));
}

Image js_image_from_obj(struct v7* v7, v7_val_t obj) {
    Image image = (Image) {
        v7_get_ptr(v7, v7_get(v7, obj, "data", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "width", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "height", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "mipmaps", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "format", ~0)),
    };
    return image;
}

Shader js_get_shader(struct v7* v7, unsigned int arg) {
    int locs[32] = { 0 };
    for (int i = 0; i < 32; i++) locs[i] = v7_get_int(v7, v7_array_get(v7, v7_get(v7, v7_arg(v7, arg), "locs", ~0), i));
    Shader shader = (Shader){
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "id", ~0)),
        locs
    };
    return shader;
}

void js_push_shader(struct v7* v7, v7_val_t obj, char* var_name, Shader shader) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "id", ~0, v7_mk_number(v7, shader.id));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "locs", ~0, v7_mk_array(v7));
    for (int i = 0; i < 32; i++) v7_array_push(v7, v7_get(v7, v7_get(v7, obj, var_name, ~0), "locs", ~0), v7_mk_number(v7, shader.locs[i]));
}

void js_return_shader(struct v7* v7, v7_val_t* res, Shader shader) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "id", ~0, v7_mk_number(v7, shader.id));
    v7_set(v7, *res, "locs", ~0, v7_mk_array(v7));
    for (int i = 0; i < 32; i++) v7_array_push(v7, v7_get(v7, *res, "locs", ~0), v7_mk_number(v7, shader.locs[i]));
}

Shader js_shader_from_obj(struct v7* v7, v7_val_t obj) {
    int locs[32] = { 0 };
    //for (int i = 0; i < 32; i++) locs[i] = v7_get_int(v7, v7_array_get(v7, obj, "locs", ~0), i);
    Shader shader = (Shader){
        v7_get_int(v7, v7_get(v7, obj, "id", ~0)),
        locs
    };
    return shader;
}

Ray js_get_ray(struct v7* v7, unsigned int arg) {
    Ray ray = (Ray){
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "position", ~0)),
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "direction", ~0)),
    };
    return ray;
}

void js_push_ray(struct v7* v7, v7_val_t obj, char* var_name, Ray ray) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    js_push_vec3(v7, v7_get(v7, obj, var_name, ~0), "position", ray.position);
    js_push_vec3(v7, v7_get(v7, obj, var_name, ~0), "direction", ray.direction);
}

void js_return_ray(struct v7* v7, v7_val_t* res, Ray ray) {
    *res = v7_mk_object(v7);
    js_push_vec3(v7, *res, "position", ray.position);
    js_push_vec3(v7, *res, "direction", ray.direction);
}

Matrix js_get_matrix(struct v7* v7, unsigned int arg) {
    Matrix matrix = (Matrix){
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m0", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m1", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m2", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m3", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m4", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m5", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m6", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m7", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m8", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m9", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m10", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m11", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m12", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m13", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m14", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "m15", ~0)),
    };
    return matrix;
}

void js_push_matrix(struct v7* v7, v7_val_t obj, char* var_name, Matrix matrix) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m0", ~0, v7_mk_number(v7, matrix.m0));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m1", ~0, v7_mk_number(v7, matrix.m1));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m2", ~0, v7_mk_number(v7, matrix.m2));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m3", ~0, v7_mk_number(v7, matrix.m3));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m4", ~0, v7_mk_number(v7, matrix.m4));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m5", ~0, v7_mk_number(v7, matrix.m5));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m6", ~0, v7_mk_number(v7, matrix.m6));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m7", ~0, v7_mk_number(v7, matrix.m7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m8", ~0, v7_mk_number(v7, matrix.m8));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m9", ~0, v7_mk_number(v7, matrix.m9));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m10", ~0, v7_mk_number(v7, matrix.m10));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m11", ~0, v7_mk_number(v7, matrix.m11));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m12", ~0, v7_mk_number(v7, matrix.m12));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m13", ~0, v7_mk_number(v7, matrix.m13));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m14", ~0, v7_mk_number(v7, matrix.m14));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "m15", ~0, v7_mk_number(v7, matrix.m15));
}

void js_return_matrix(struct v7* v7, v7_val_t* res, Matrix matrix) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "m0", ~0, v7_mk_number(v7, matrix.m0));
    v7_set(v7, *res, "m1", ~0, v7_mk_number(v7, matrix.m1));
    v7_set(v7, *res, "m2", ~0, v7_mk_number(v7, matrix.m2));
    v7_set(v7, *res, "m3", ~0, v7_mk_number(v7, matrix.m3));
    v7_set(v7, *res, "m4", ~0, v7_mk_number(v7, matrix.m4));
    v7_set(v7, *res, "m5", ~0, v7_mk_number(v7, matrix.m5));
    v7_set(v7, *res, "m6", ~0, v7_mk_number(v7, matrix.m6));
    v7_set(v7, *res, "m7", ~0, v7_mk_number(v7, matrix.m7));
    v7_set(v7, *res, "m8", ~0, v7_mk_number(v7, matrix.m8));
    v7_set(v7, *res, "m9", ~0, v7_mk_number(v7, matrix.m9));
    v7_set(v7, *res, "m10", ~0, v7_mk_number(v7, matrix.m10));
    v7_set(v7, *res, "m11", ~0, v7_mk_number(v7, matrix.m11));
    v7_set(v7, *res, "m12", ~0, v7_mk_number(v7, matrix.m12));
    v7_set(v7, *res, "m13", ~0, v7_mk_number(v7, matrix.m13));
    v7_set(v7, *res, "m14", ~0, v7_mk_number(v7, matrix.m14));
    v7_set(v7, *res, "m15", ~0, v7_mk_number(v7, matrix.m15));
}

Matrix js_matrix_from_obj(struct v7* v7, v7_val_t obj) {
    Matrix matrix = (Matrix){
        v7_get_double(v7, v7_get(v7, obj, "m0", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m1", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m2", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m3", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m4", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m5", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m6", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m7", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m8", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m9", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m10", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m11", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m12", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m13", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m14", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "m15", ~0)),
    };
    return matrix;
}

Font js_get_font(struct v7* v7, unsigned int arg) {
    Font font = (Font){
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "baseSize", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "charsCount", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "charsPadding", ~0)),
        js_tex2d_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "texture", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "recs", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "chars", ~0)),
    };
    return font;
}

void js_return_font(struct v7* v7, v7_val_t* res, Font font) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "baseSize", ~0, v7_mk_number(v7, font.baseSize));
    v7_set(v7, *res, "charsCount", ~0, v7_mk_number(v7, font.charsCount));
    v7_set(v7, *res, "charsPadding", ~0, v7_mk_number(v7, font.charsPadding));
    js_push_tex2d(v7, *res, "texture", font.texture);
    v7_set(v7, *res, "recs", ~0, v7_mk_foreign(v7, font.recs));
    v7_set(v7, *res, "chars", ~0, v7_mk_foreign(v7, font.chars));
}

VrDeviceInfo js_get_vr_device_info(struct v7* v7, unsigned int arg) {
    float lensDistortionValues[4] = {
        v7_get_double(v7, v7_get(v7, v7_get(v7, v7_arg(v7, arg), "lensDistortionValues", ~0), "0", ~0)),
        v7_get_double(v7, v7_get(v7, v7_get(v7, v7_arg(v7, arg), "lensDistortionValues", ~0), "1", ~0)),
        v7_get_double(v7, v7_get(v7, v7_get(v7, v7_arg(v7, arg), "lensDistortionValues", ~0), "2", ~0)),
        v7_get_double(v7, v7_get(v7, v7_get(v7, v7_arg(v7, arg), "lensDistortionValues", ~0), "3", ~0)),
    };

    float chromaAbCorrection[4] = {
        v7_get_double(v7, v7_get(v7, v7_get(v7, v7_arg(v7, arg), "chromaAbCorrection", ~0), "0", ~0)),
        v7_get_double(v7, v7_get(v7, v7_get(v7, v7_arg(v7, arg), "chromaAbCorrection", ~0), "1", ~0)),
        v7_get_double(v7, v7_get(v7, v7_get(v7, v7_arg(v7, arg), "chromaAbCorrection", ~0), "2", ~0)),
        v7_get_double(v7, v7_get(v7, v7_get(v7, v7_arg(v7, arg), "chromaAbCorrection", ~0), "3", ~0)),
    };

    VrDeviceInfo vr_device_info = (VrDeviceInfo){
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "hResolution", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "vResolution", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "hScreenSize", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "vScreenSize", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "vScreenCenter", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "eyeToScreenDistance", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "lensSeparationDistance", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "interpupillaryDistance", ~0)),
        *lensDistortionValues,
        *chromaAbCorrection,
    };
    return vr_device_info;
}

CharInfo js_get_char_info(struct v7* v7, unsigned int arg) {
    CharInfo char_info = (CharInfo) {
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "value", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "offsetX", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "offsetY", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "advanceX", ~0)),
        js_image_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "image", ~0)),
    };
    return char_info;
}

void js_return_char_info(struct v7* v7, v7_val_t* res, CharInfo char_info) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "value", ~0, v7_mk_number(v7, char_info.value));
    v7_set(v7, *res, "offsetX", ~0, v7_mk_number(v7, char_info.offsetX));
    v7_set(v7, *res, "offsetY", ~0, v7_mk_number(v7, char_info.offsetY));
    v7_set(v7, *res, "advanceX", ~0, v7_mk_number(v7, char_info.advanceX));
    js_push_image(v7, *res, "image", char_info.image);
}

NPatchInfo js_get_npatch_info(struct v7* v7, unsigned int arg) {
    NPatchInfo npatch_info = (NPatchInfo) {
        v7_get(v7, v7_arg(v7, arg), "source", ~0),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "left", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "top", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "right", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "bottom", ~0)),
        v7_get_double(v7, v7_get(v7, v7_arg(v7, arg), "type", ~0)),
    };
    return npatch_info;
}

void js_push_npatch_info(struct v7* v7, v7_val_t obj, char* var_name, NPatchInfo npatch_info) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    js_push_rect(v7, obj, "source", npatch_info.source);
    js_push_key(v7, obj, "left", npatch_info.left);
    js_push_key(v7, obj, "top", npatch_info.top);
    js_push_key(v7, obj, "right", npatch_info.right);
    js_push_key(v7, obj, "bottom", npatch_info.bottom);
    js_push_key(v7, obj, "type", npatch_info.type);
}

void js_return_npatch_info(struct v7* v7, v7_val_t* res, NPatchInfo npatch_info) {
    *res = v7_mk_object(v7);
    js_push_rect(v7, *res, "source", npatch_info.source);
    v7_set(v7, *res, "left", ~0, v7_mk_number(v7, npatch_info.left));
    v7_set(v7, *res, "top", ~0, v7_mk_number(v7, npatch_info.top));
    v7_set(v7, *res, "right", ~0, v7_mk_number(v7, npatch_info.right));
    v7_set(v7, *res, "bottom", ~0, v7_mk_number(v7, npatch_info.bottom));
    v7_set(v7, *res, "type", ~0, v7_mk_number(v7, npatch_info.type));
}

Wave js_get_wave(struct v7* v7, unsigned int arg) {
    Wave wave = (Wave) {
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "sampleCount", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "sampleRate", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "sampleSize", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "channels", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "data", ~0))
    };
    return wave;
}

void js_return_wave(struct v7* v7, v7_val_t* res, Wave wave) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "sampleCount", ~0, v7_mk_number(v7, wave.sampleCount));
    v7_set(v7, *res, "sampleRate", ~0, v7_mk_number(v7, wave.sampleRate));
    v7_set(v7, *res, "sampleSize", ~0, v7_mk_number(v7, wave.sampleSize));
    v7_set(v7, *res, "channels", ~0, v7_mk_number(v7, wave.channels));
    v7_set(v7, *res, "data", ~0, v7_mk_foreign(v7, wave.data));
}

AudioStream js_get_audio_stream(struct v7* v7, unsigned int arg) {
    AudioStream stream = (AudioStream){
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "buffer", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "sampleRate", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "sampleSize", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "channels", ~0)),
    };
    return stream;
}

void js_push_audio_stream(struct v7* v7, v7_val_t obj, char* var_name, AudioStream stream) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "buffer", ~0, v7_mk_foreign(v7, stream.buffer));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "sampleRate", ~0, v7_mk_number(v7, stream.sampleRate));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "sampleSize", ~0, v7_mk_number(v7, stream.sampleSize));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "channels", ~0, v7_mk_number(v7, stream.channels));
}

void js_return_audio_stream(struct v7* v7, v7_val_t* res, AudioStream stream) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "buffer", ~0, v7_mk_foreign(v7, stream.buffer));
    v7_set(v7, *res, "sampleRate", ~0, v7_mk_number(v7, stream.sampleRate));
    v7_set(v7, *res, "sampleSize", ~0, v7_mk_number(v7, stream.sampleSize));
    v7_set(v7, *res, "channels", ~0, v7_mk_number(v7, stream.channels));
}

AudioStream js_audio_stream_from_obj(struct v7* v7, v7_val_t obj) {
    AudioStream stream = (AudioStream) {
        v7_get_ptr(v7, v7_get(v7, obj, "buffer", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "sampleRate", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "sampleSize", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "channels", ~0)),
    };
    return stream;
}

Sound js_get_sound(struct v7* v7, unsigned int arg) {
    Sound sound = (Sound){
        js_audio_stream_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "stream", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "sampleCount", ~0)),
    };
    return sound;
}

void js_return_sound(struct v7* v7, v7_val_t* res, Sound sound) {
    *res = v7_mk_object(v7);
    js_push_audio_stream(v7, *res, "stream", sound.stream);
    v7_set(v7, *res, "sampleCount", ~0, v7_mk_number(v7, sound.sampleCount));
}

Music js_get_music(struct v7* v7, unsigned int arg) {
    Music music = (Music) {
        js_audio_stream_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "stream", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "sampleCount", ~0)),
        v7_get_bool(v7, v7_get(v7, v7_arg(v7, arg), "looping", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "ctxType", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "ctxData", ~0)),
    };
    return music;
}

void js_return_music(struct v7* v7, v7_val_t* res, Music music) {
    *res = v7_mk_object(v7);
    js_push_audio_stream(v7, *res, "stream", music.stream);
    v7_set(v7, *res, "sampleCount", ~0, v7_mk_number(v7, music.sampleCount));
    v7_set(v7, *res, "looping", ~0, v7_mk_boolean(v7, music.looping));
    v7_set(v7, *res, "ctxType", ~0, v7_mk_number(v7, music.ctxType));
    v7_set(v7, *res, "ctxData", ~0, v7_mk_foreign(v7, music.ctxData));
}

Transform js_get_transform(struct v7* v7, unsigned int arg) {
    Transform transform = (Transform){
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "translation", ~0)),
        js_quat_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "rotation", ~0)),
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "scale", ~0)),
    };
    return transform;
}

void js_push_transform(struct v7* v7, v7_val_t obj, char* var_name, Transform transform) {
    js_push_vec3(v7, v7_get(v7, obj, var_name, ~0), "translation", transform.translation);
    js_push_quat(v7, v7_get(v7, obj, var_name, ~0), "rotation", transform.rotation);
    js_push_vec3(v7, v7_get(v7, obj, var_name, ~0), "scale", transform.scale);
}

void js_return_transform(struct v7* v7, v7_val_t* res, Transform transform) {
    *res = v7_mk_object(v7);
    js_push_vec3(v7, *res, "translation", transform.translation);
    js_push_quat(v7, *res, "rotation", transform.rotation);
    js_push_vec3(v7, *res, "scale", transform.scale);
}

Transform js_transform_from_obj(struct v7* v7, v7_val_t obj) {
    Transform transform = (Transform){
        js_vec3_from_obj(v7, v7_get(v7, obj, "translation", ~0)),
        js_quat_from_obj(v7, v7_get(v7, obj, "rotation", ~0)),
        js_vec3_from_obj(v7, v7_get(v7, obj, "scale", ~0)),
    };
    return transform;
}

Mesh js_get_mesh(struct v7* v7, unsigned int arg) {
    Mesh mesh = (Mesh){
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "vertexCount", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "triangleCount", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "vertices", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "texcoords", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "texcoords2", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "normals", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "tangents", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "colors", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "indices", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "animVertices", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "animNormals", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "boneIds", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "boneWeights", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "vaoId", ~0)),
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "vboId", ~0)),
    };
    return mesh;
}

void js_push_mesh(struct v7* v7, v7_val_t obj, char* var_name, Mesh mesh) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "vertexCount", ~0, v7_mk_number(v7, mesh.vertexCount));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "triangleCount", ~0, v7_mk_number(v7, mesh.triangleCount));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "vertices", ~0, v7_mk_foreign(v7, mesh.vertices));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "texcoords", ~0, v7_mk_foreign(v7, mesh.texcoords));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "texcoords2", ~0, v7_mk_foreign(v7, mesh.texcoords2));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "normals", ~0, v7_mk_foreign(v7, mesh.normals));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "tangents", ~0, v7_mk_foreign(v7, mesh.tangents));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "colors", ~0, v7_mk_foreign(v7, mesh.colors));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "indices", ~0, v7_mk_foreign(v7, mesh.indices));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "animVertices", ~0, v7_mk_foreign(v7, mesh.animVertices));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "animNormals", ~0, v7_mk_foreign(v7, mesh.animNormals));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "boneIds", ~0, v7_mk_foreign(v7, mesh.boneIds));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "boneWeights", ~0, v7_mk_foreign(v7, mesh.boneWeights));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "vaoId", ~0, v7_mk_number(v7, mesh.vaoId));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "vboId", ~0, v7_mk_foreign(v7, mesh.vboId));
}

void js_return_mesh(struct v7* v7, v7_val_t* res, Mesh mesh) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "vertexCount", ~0, v7_mk_number(v7, mesh.vertexCount));
    v7_set(v7, *res, "triangleCount", ~0, v7_mk_number(v7, mesh.triangleCount));
    v7_set(v7, *res, "vertices", ~0, v7_mk_foreign(v7, mesh.vertices));
    v7_set(v7, *res, "texcoords", ~0, v7_mk_foreign(v7, mesh.texcoords));
    v7_set(v7, *res, "texcoords2", ~0, v7_mk_foreign(v7, mesh.texcoords2));
    v7_set(v7, *res, "normals", ~0, v7_mk_foreign(v7, mesh.normals));
    v7_set(v7, *res, "tangents", ~0, v7_mk_foreign(v7, mesh.tangents));
    v7_set(v7, *res, "colors", ~0, v7_mk_foreign(v7, mesh.colors));
    v7_set(v7, *res, "indices", ~0, v7_mk_foreign(v7, mesh.indices));
    v7_set(v7, *res, "animVertices", ~0, v7_mk_foreign(v7, mesh.animVertices));
    v7_set(v7, *res, "animNormals", ~0, v7_mk_foreign(v7, mesh.animNormals));
    v7_set(v7, *res, "boneIds", ~0, v7_mk_foreign(v7, mesh.boneIds));
    v7_set(v7, *res, "boneWeights", ~0, v7_mk_foreign(v7, mesh.boneWeights));
    v7_set(v7, *res, "vaoId", ~0, v7_mk_number(v7, mesh.vaoId));
    v7_set(v7, *res, "vboId", ~0, v7_mk_foreign(v7, mesh.vboId));
}

Mesh js_mesh_from_obj(struct v7* v7, v7_val_t obj) {
    Mesh mesh = (Mesh){
        v7_get_int(v7, v7_get(v7, obj, "vertexCount", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "triangleCount", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "vertices", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "texcoords", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "texcoords2", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "normals", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "tangents", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "colors", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "indices", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "animVertices", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "animNormals", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "boneIds", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "boneWeights", ~0)),
        v7_get_int(v7, v7_get(v7, obj, "vaoId", ~0)),
        v7_get_ptr(v7, v7_get(v7, obj, "vboId", ~0)),
    };
    return mesh;
}

void js_update_mesh(struct v7* v7, unsigned int arg, Mesh mesh) {
    v7_set(v7, v7_arg(v7, arg), "vertexCount", ~0, v7_mk_number(v7, mesh.vertexCount));
    v7_set(v7, v7_arg(v7, arg), "triangleCount", ~0, v7_mk_number(v7, mesh.triangleCount));
    v7_set(v7, v7_arg(v7, arg), "vertices", ~0, v7_mk_foreign(v7, mesh.vertices));
    v7_set(v7, v7_arg(v7, arg), "texcoords", ~0, v7_mk_foreign(v7, mesh.texcoords));
    v7_set(v7, v7_arg(v7, arg), "texcoords2", ~0, v7_mk_foreign(v7, mesh.texcoords2));
    v7_set(v7, v7_arg(v7, arg), "normals", ~0, v7_mk_foreign(v7, mesh.normals));
    v7_set(v7, v7_arg(v7, arg), "tangents", ~0, v7_mk_foreign(v7, mesh.tangents));
    v7_set(v7, v7_arg(v7, arg), "colors", ~0, v7_mk_foreign(v7, mesh.colors));
    v7_set(v7, v7_arg(v7, arg), "indices", ~0, v7_mk_foreign(v7, mesh.indices));
    v7_set(v7, v7_arg(v7, arg), "animVertices", ~0, v7_mk_foreign(v7, mesh.animVertices));
    v7_set(v7, v7_arg(v7, arg), "animNormals", ~0, v7_mk_foreign(v7, mesh.animNormals));
    v7_set(v7, v7_arg(v7, arg), "boneIds", ~0, v7_mk_foreign(v7, mesh.boneIds));
    v7_set(v7, v7_arg(v7, arg), "boneWeights", ~0, v7_mk_foreign(v7, mesh.boneWeights));
    v7_set(v7, v7_arg(v7, arg), "vaoId", ~0, v7_mk_number(v7, mesh.vaoId));
    v7_set(v7, v7_arg(v7, arg), "vboId", ~0, v7_mk_foreign(v7, mesh.vboId));
}

MaterialMap js_material_map_from_obj(struct v7* v7, v7_val_t obj) {
    MaterialMap map = (MaterialMap){
        js_tex2d_from_obj(v7, v7_get(v7, obj, "texture", ~0)),
        js_color_from_obj(v7, v7_get(v7, obj, "color", ~0)),
        v7_get_double(v7, v7_get(v7, obj, "value", ~0))
    };
    return map;
}

Material js_get_material(struct v7* v7, unsigned int arg) {
    MaterialMap maps[12] = { 0 };
    for (int i = 0; i < 12; i++) maps[i] = js_material_map_from_obj(v7, v7_array_get(v7, v7_get(v7, v7_arg(v7, arg), "maps", ~0), i));
    Material material = (Material){
        js_shader_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "shader", ~0)),
        maps,
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "params", ~0)),
    };
    return material;
}

void js_push_material(struct v7* v7, v7_val_t obj, char* var_name, Material material) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    js_push_shader(v7, v7_get(v7, obj, var_name, ~0), "shader", material.shader);
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "maps", ~0, v7_mk_array(v7));
    v7_val_t arr = v7_get(v7, v7_get(v7, obj, var_name, ~0), "maps", ~0);

    v7_array_push(v7, arr, v7_mk_object(v7));
    for (int i = 0; i < 12; i++) {
        js_push_tex2d(v7, v7_array_get(v7, arr, i), "texture", material.maps[i].texture);
        js_push_color(v7, v7_array_get(v7, arr, i), "color", material.maps[i].color);
        v7_set(v7, v7_array_get(v7, arr, i), "value", ~0, v7_mk_number(v7, material.maps[i].value));
    }
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "params", ~0, v7_mk_foreign(v7, material.params));
}

void js_return_material(struct v7* v7, v7_val_t* res, Material material) {
    *res = v7_mk_object(v7);
    js_push_shader(v7, *res, "shader", material.shader);
    v7_set(v7, *res, "maps", ~0, v7_mk_array(v7));

    v7_val_t arr = v7_get(v7, *res, "maps", ~0);
    for (int i = 0; i < 12; i++) {
        v7_array_push(v7, arr, v7_mk_object(v7));
        js_push_tex2d(v7, v7_array_get(v7, arr, i), "texture", material.maps[i].texture);
        js_push_color(v7, v7_array_get(v7, arr, i), "color", material.maps[i].color);
        v7_set(v7, v7_array_get(v7, arr, i), "value", ~0, v7_mk_number(v7, material.maps[i].value));
    }
    v7_set(v7, *res, "params", ~0, v7_mk_foreign(v7, material.params));
}

Material js_material_from_obj(struct v7* v7, v7_val_t obj) {
    MaterialMap maps[12] = { 0 };
    for (int i = 0; i < 12; i++) maps[i] = js_material_map_from_obj(v7, v7_array_get(v7, v7_get(v7, obj, "maps", ~0), i));
    Material material = (Material){
        js_shader_from_obj(v7, v7_get(v7, obj, "shader", ~0)),
        maps,
        v7_get_ptr(v7, v7_get(v7, obj, "params", ~0)),
    };
    return material;
}

void js_update_material(struct v7* v7, unsigned int arg, Material material) {
    js_push_shader(v7, v7_arg(v7, arg), "shader", material.shader);
    v7_set(v7, v7_arg(v7, arg), "maps", ~0, v7_mk_array(v7));

    v7_val_t arr = v7_get(v7, v7_arg(v7, arg), "maps", ~0);
    for (int i = 0; i < 12; i++) {
        v7_array_push(v7, arr, v7_mk_object(v7));
        js_push_tex2d(v7, v7_array_get(v7, arr, i), "texture", material.maps[i].texture);
        js_push_color(v7, v7_array_get(v7, arr, i), "color", material.maps[i].color);
        v7_set(v7, v7_array_get(v7, arr, i), "value", ~0, v7_mk_number(v7, material.maps[i].value));
    }
    v7_set(v7, v7_arg(v7, arg), "params", ~0, v7_mk_foreign(v7, material.params));
}

BoneInfo js_bone_info_from_obj(struct v7* v7, v7_val_t obj) {
    v7_val_t objstr = v7_get(v7, obj, "name", ~0);
    size_t lenstr;
    BoneInfo bone = (BoneInfo){
        v7_get_string(v7, &objstr, &lenstr),
        v7_get_int(v7, v7_get(v7, obj, "parent", ~0))
    };
    return bone;
}

Model js_get_model(struct v7* v7, unsigned int arg) {
    int meshCount = v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "meshCount", ~0));
    int materialCount = v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "materialCount", ~0));
    int boneCount = v7_get_int(v7, v7_get(v7, v7_arg(v7, arg), "boneCount", ~0));

    Mesh* meshes;
    for (int i = 0; i < meshCount; i++) {
        meshes[i] = js_mesh_from_obj(v7, v7_array_get(v7, v7_get(v7, v7_arg(v7, arg), "meshes", ~0), i));
    }

    Material* materials;
    for (int i = 0; i < materialCount; i++) {
        materials[i] = js_material_from_obj(v7, v7_array_get(v7, v7_get(v7, v7_arg(v7, arg), "materials", ~0), i));
    }

    BoneInfo *bones;
    for (int i = 0; i < boneCount; i++) {
        bones[i] = js_bone_info_from_obj(v7, v7_array_get(v7, v7_get(v7, v7_arg(v7, arg), "bones", ~0), i));
    }

    Model model = (Model){
        js_matrix_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "transform", ~0)),
        meshCount,
        materialCount,
        meshes,
        materials,
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "meshMaterial", ~0)),
        boneCount,
        bones,
        v7_get_ptr(v7, v7_get(v7, v7_arg(v7, arg), "bindPose", ~0)),
    };
    return model;
}

void js_push_model(struct v7* v7, v7_val_t obj, char* var_name, Model model) {
    v7_set(v7, obj, var_name, ~0, v7_mk_object(v7));
    js_push_matrix(v7, v7_get(v7, obj, var_name, ~0), "transform", model.transform);
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "meshCount", ~0, v7_mk_number(v7, model.meshCount));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "materialCount", ~0, v7_mk_number(v7, model.materialCount));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "meshes", ~0, v7_mk_array(v7));

    v7_val_t arr = v7_get(v7, v7_get(v7, obj, var_name, ~0), "meshes", ~0);
    for (int i = 0; i < model.meshCount; i++) {
        v7_array_push(v7, arr, v7_mk_object(v7));
        v7_set(v7, v7_array_get(v7, arr, i), "vertexCount", ~0, v7_mk_number(v7, model.meshes[i].vertexCount));
        v7_set(v7, v7_array_get(v7, arr, i), "triangleCount", ~0, v7_mk_number(v7, model.meshes[i].triangleCount));
        v7_set(v7, v7_array_get(v7, arr, i), "vertices", ~0, v7_mk_foreign(v7, model.meshes[i].vertices));
        v7_set(v7, v7_array_get(v7, arr, i), "texcoords", ~0, v7_mk_foreign(v7, model.meshes[i].texcoords));
        v7_set(v7, v7_array_get(v7, arr, i), "texcoords2", ~0, v7_mk_foreign(v7, model.meshes[i].texcoords2));
        v7_set(v7, v7_array_get(v7, arr, i), "normals", ~0, v7_mk_foreign(v7, model.meshes[i].normals));
        v7_set(v7, v7_array_get(v7, arr, i), "tangents", ~0, v7_mk_foreign(v7, model.meshes[i].tangents));
        v7_set(v7, v7_array_get(v7, arr, i), "colors", ~0, v7_mk_foreign(v7, model.meshes[i].colors));
        v7_set(v7, v7_array_get(v7, arr, i), "indices", ~0, v7_mk_foreign(v7, model.meshes[i].indices));
        v7_set(v7, v7_array_get(v7, arr, i), "animVertices", ~0, v7_mk_foreign(v7, model.meshes[i].animVertices));
        v7_set(v7, v7_array_get(v7, arr, i), "animNormals", ~0, v7_mk_foreign(v7, model.meshes[i].animNormals));
        v7_set(v7, v7_array_get(v7, arr, i), "boneIds", ~0, v7_mk_foreign(v7, model.meshes[i].boneIds));
        v7_set(v7, v7_array_get(v7, arr, i), "boneWeights", ~0, v7_mk_foreign(v7, model.meshes[i].boneWeights));
        v7_set(v7, v7_array_get(v7, arr, i), "vaoId", ~0, v7_mk_number(v7, model.meshes[i].vaoId));
        v7_set(v7, v7_array_get(v7, arr, i), "vboId", ~0, v7_mk_foreign(v7, model.meshes[i].vboId));
    }
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "materials", ~0, v7_mk_array(v7));

    v7_val_t arr1 = v7_get(v7, v7_get(v7, obj, var_name, ~0), "materials", ~0);
    for (int i = 0; i < model.materialCount; i++) {
        v7_array_push(v7, arr1, v7_mk_object(v7));
        js_push_shader(v7, v7_array_get(v7, arr1, i), "shader", model.materials[i].shader);
        v7_set(v7, v7_array_get(v7, arr1, i), "maps", ~0, v7_mk_array(v7));

        v7_val_t arr2 = v7_get(v7, arr1, "maps", ~0);
        for (int j = 0; j < 12; j++) {
            v7_array_push(v7, arr2, v7_mk_object(v7));
            js_push_tex2d(v7, v7_array_get(v7, arr2, j), "texture", model.materials[i].maps[j].texture);
            js_push_color(v7, v7_array_get(v7, arr2, j), "color", model.materials[i].maps[j].color);
            v7_set(v7, v7_array_get(v7, arr2, j), "value", ~0, v7_mk_number(v7, model.materials[i].maps[j].value));
        }
        v7_set(v7, v7_get(v7, obj, var_name, ~0), "params", ~0, v7_mk_foreign(v7, model.materials[i].params));
    }

    v7_set(v7, v7_get(v7, obj, var_name, ~0), "meshMaterial", ~0, v7_mk_foreign(v7, model.meshMaterial));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "boneCount", ~0, v7_mk_number(v7, model.boneCount));
    v7_set(v7, v7_get(v7, obj, var_name, ~0), "bones", ~0, v7_mk_array(v7));

    v7_val_t arr3 = v7_get(v7, v7_get(v7, obj, var_name, ~0), "bones", ~0);
    for (int i = 0; i < model.boneCount; i++) {
        v7_array_push(v7, arr3, v7_mk_object(v7));
        v7_set(v7, v7_array_get(v7, arr3, i), "name", ~0, v7_mk_string(v7, model.bones[i].name, ~0, 0));
        v7_set(v7, v7_array_get(v7, arr3, i), "parent", ~0, v7_mk_number(v7, model.bones[i].parent));
    }

    v7_set(v7, v7_get(v7, obj, var_name, ~0), "bindPose", ~0, v7_mk_foreign(v7, model.bindPose));
}

void js_return_model(struct v7* v7, v7_val_t* res, Model model) {
    *res = v7_mk_object(v7);
    js_push_matrix(v7, *res, "transform", model.transform);
    v7_set(v7, *res, "meshCount", ~0, v7_mk_number(v7, model.meshCount));
    v7_set(v7, *res, "materialCount", ~0, v7_mk_number(v7, model.materialCount));
    v7_set(v7, *res, "meshes", ~0, v7_mk_array(v7));

    v7_val_t arr = v7_get(v7, *res, "meshes", ~0);
    for (int i = 0; i < model.meshCount; i++) {
        v7_array_push(v7, arr, v7_mk_object(v7));
        v7_set(v7, v7_array_get(v7, arr, i), "vertexCount", ~0, v7_mk_number(v7, model.meshes[i].vertexCount));
        v7_set(v7, v7_array_get(v7, arr, i), "triangleCount", ~0, v7_mk_number(v7, model.meshes[i].triangleCount));
        v7_set(v7, v7_array_get(v7, arr, i), "vertices", ~0, v7_mk_foreign(v7, model.meshes[i].vertices));
        v7_set(v7, v7_array_get(v7, arr, i), "texcoords", ~0, v7_mk_foreign(v7, model.meshes[i].texcoords));
        v7_set(v7, v7_array_get(v7, arr, i), "texcoords2", ~0, v7_mk_foreign(v7, model.meshes[i].texcoords2));
        v7_set(v7, v7_array_get(v7, arr, i), "normals", ~0, v7_mk_foreign(v7, model.meshes[i].normals));
        v7_set(v7, v7_array_get(v7, arr, i), "tangents", ~0, v7_mk_foreign(v7, model.meshes[i].tangents));
        v7_set(v7, v7_array_get(v7, arr, i), "colors", ~0, v7_mk_foreign(v7, model.meshes[i].colors));
        v7_set(v7, v7_array_get(v7, arr, i), "indices", ~0, v7_mk_foreign(v7, model.meshes[i].indices));
        v7_set(v7, v7_array_get(v7, arr, i), "animVertices", ~0, v7_mk_foreign(v7, model.meshes[i].animVertices));
        v7_set(v7, v7_array_get(v7, arr, i), "animNormals", ~0, v7_mk_foreign(v7, model.meshes[i].animNormals));
        v7_set(v7, v7_array_get(v7, arr, i), "boneIds", ~0, v7_mk_foreign(v7, model.meshes[i].boneIds));
        v7_set(v7, v7_array_get(v7, arr, i), "boneWeights", ~0, v7_mk_foreign(v7, model.meshes[i].boneWeights));
        v7_set(v7, v7_array_get(v7, arr, i), "vaoId", ~0, v7_mk_number(v7, model.meshes[i].vaoId));
        v7_set(v7, v7_array_get(v7, arr, i), "vboId", ~0, v7_mk_foreign(v7, model.meshes[i].vboId));
    }
    v7_set(v7, *res, "materials", ~0, v7_mk_array(v7));

    v7_val_t arr1 = v7_get(v7, *res, "materials", ~0);
    for (int i = 0; i < model.materialCount; i++) {
        v7_array_push(v7, arr1, v7_mk_object(v7));
        js_push_shader(v7, v7_array_get(v7, arr1, i), "shader", model.materials[i].shader);
        v7_set(v7, v7_array_get(v7, arr1, i), "maps", ~0, v7_mk_array(v7));

        v7_val_t arr2 = v7_get(v7, arr1, "maps", ~0);
        for (int j = 0; j < 12; j++) {
            v7_array_push(v7, arr2, v7_mk_object(v7));
            js_push_tex2d(v7, v7_array_get(v7, arr2, j), "texture", model.materials[i].maps[j].texture);
            js_push_color(v7, v7_array_get(v7, arr2, j), "color", model.materials[i].maps[j].color);
            v7_set(v7, v7_array_get(v7, arr2, j), "value", ~0, v7_mk_number(v7, model.materials[i].maps[j].value));
        }
        v7_set(v7, *res, "params", ~0, v7_mk_foreign(v7, model.materials[i].params));
    }

    v7_set(v7, *res, "meshMaterial", ~0, v7_mk_foreign(v7, model.meshMaterial));
    v7_set(v7, *res, "boneCount", ~0, v7_mk_number(v7, model.boneCount));
    v7_set(v7, *res, "bones", ~0, v7_mk_array(v7));

    v7_val_t arr3 = v7_get(v7, *res, "bones", ~0);
    for (int i = 0; i < model.boneCount; i++) {
        v7_array_push(v7, arr3, v7_mk_object(v7));
        v7_set(v7, v7_array_get(v7, arr3, i), "name", ~0, v7_mk_string(v7, model.bones[i].name, ~0, 0));
        v7_set(v7, v7_array_get(v7, arr3, i), "parent", ~0, v7_mk_number(v7, model.bones[i].parent));
    }

    v7_set(v7, *res, "bindPose", ~0, v7_mk_foreign(v7, model.bindPose));
}

void js_update_model(struct v7* v7, unsigned int arg, Model model) {
    js_push_matrix(v7, v7_arg(v7, arg), "transform", model.transform);
    v7_set(v7, v7_arg(v7, arg), "meshCount", ~0, v7_mk_number(v7, model.meshCount));
    v7_set(v7, v7_arg(v7, arg), "materialCount", ~0, v7_mk_number(v7, model.materialCount));
    v7_set(v7, v7_arg(v7, arg), "meshes", ~0, v7_mk_array(v7));

    v7_val_t arr = v7_get(v7, v7_arg(v7, arg), "meshes", ~0);
    for (int i = 0; i < model.meshCount; i++) {
        v7_array_push(v7, arr, v7_mk_object(v7));
        v7_set(v7, v7_array_get(v7, arr, i), "vertexCount", ~0, v7_mk_number(v7, model.meshes[i].vertexCount));
        v7_set(v7, v7_array_get(v7, arr, i), "triangleCount", ~0, v7_mk_number(v7, model.meshes[i].triangleCount));
        v7_set(v7, v7_array_get(v7, arr, i), "vertices", ~0, v7_mk_foreign(v7, model.meshes[i].vertices));
        v7_set(v7, v7_array_get(v7, arr, i), "texcoords", ~0, v7_mk_foreign(v7, model.meshes[i].texcoords));
        v7_set(v7, v7_array_get(v7, arr, i), "texcoords2", ~0, v7_mk_foreign(v7, model.meshes[i].texcoords2));
        v7_set(v7, v7_array_get(v7, arr, i), "normals", ~0, v7_mk_foreign(v7, model.meshes[i].normals));
        v7_set(v7, v7_array_get(v7, arr, i), "tangents", ~0, v7_mk_foreign(v7, model.meshes[i].tangents));
        v7_set(v7, v7_array_get(v7, arr, i), "colors", ~0, v7_mk_foreign(v7, model.meshes[i].colors));
        v7_set(v7, v7_array_get(v7, arr, i), "indices", ~0, v7_mk_foreign(v7, model.meshes[i].indices));
        v7_set(v7, v7_array_get(v7, arr, i), "animVertices", ~0, v7_mk_foreign(v7, model.meshes[i].animVertices));
        v7_set(v7, v7_array_get(v7, arr, i), "animNormals", ~0, v7_mk_foreign(v7, model.meshes[i].animNormals));
        v7_set(v7, v7_array_get(v7, arr, i), "boneIds", ~0, v7_mk_foreign(v7, model.meshes[i].boneIds));
        v7_set(v7, v7_array_get(v7, arr, i), "boneWeights", ~0, v7_mk_foreign(v7, model.meshes[i].boneWeights));
        v7_set(v7, v7_array_get(v7, arr, i), "vaoId", ~0, v7_mk_number(v7, model.meshes[i].vaoId));
        v7_set(v7, v7_array_get(v7, arr, i), "vboId", ~0, v7_mk_foreign(v7, model.meshes[i].vboId));
    }
    v7_set(v7, v7_arg(v7, arg), "materials", ~0, v7_mk_array(v7));

    v7_val_t arr1 = v7_get(v7, v7_arg(v7, arg), "materials", ~0);
    for (int i = 0; i < model.materialCount; i++) {
        v7_array_push(v7, arr1, v7_mk_object(v7));
        js_push_shader(v7, v7_array_get(v7, arr1, i), "shader", model.materials[i].shader);
        v7_set(v7, v7_array_get(v7, arr1, i), "maps", ~0, v7_mk_array(v7));

        v7_val_t arr2 = v7_get(v7, arr1, "maps", ~0);
        for (int j = 0; j < 12; j++) {
            v7_array_push(v7, arr2, v7_mk_object(v7));
            js_push_tex2d(v7, v7_array_get(v7, arr2, j), "texture", model.materials[i].maps[j].texture);
            js_push_color(v7, v7_array_get(v7, arr2, j), "color", model.materials[i].maps[j].color);
            v7_set(v7, v7_array_get(v7, arr2, j), "value", ~0, v7_mk_number(v7, model.materials[i].maps[j].value));
        }
        v7_set(v7, v7_arg(v7, arg), "params", ~0, v7_mk_foreign(v7, model.materials[i].params));
    }

    v7_set(v7, v7_arg(v7, arg), "meshMaterial", ~0, v7_mk_foreign(v7, model.meshMaterial));
    v7_set(v7, v7_arg(v7, arg), "boneCount", ~0, v7_mk_number(v7, model.boneCount));
    v7_set(v7, v7_arg(v7, arg), "bones", ~0, v7_mk_array(v7));

    v7_val_t arr3 = v7_get(v7, v7_arg(v7, arg), "bones", ~0);
    for (int i = 0; i < model.boneCount; i++) {
        v7_array_push(v7, arr3, v7_mk_object(v7));
        v7_set(v7, v7_array_get(v7, arr3, i), "name", ~0, v7_mk_string(v7, model.bones[i].name, ~0, 0));
        v7_set(v7, v7_array_get(v7, arr3, i), "parent", ~0, v7_mk_number(v7, model.bones[i].parent));
    }

    v7_set(v7, v7_arg(v7, arg), "bindPose", ~0, v7_mk_foreign(v7, model.bindPose));
}

ModelAnimation js_get_model_animation(struct v7* v7, unsigned int arg) {
    int boneCount = v7_get_int(v7, v7_arg(v7, 0));
    int frameCount = v7_get_int(v7, v7_arg(v7, 1));

    BoneInfo* bones;
    for (int i = 0; i < boneCount; i++) {
        bones[i] = js_bone_info_from_obj(v7, v7_array_get(v7, v7_get(v7, v7_arg(v7, arg), "bones", ~0), i));
    }

    Transform* framePoses;
    for (int i = 0; i < frameCount; i++) {
        framePoses[i] = js_transform_from_obj(v7, v7_array_get(v7, v7_get(v7, v7_arg(v7, arg), "framePoses", ~0), i));
    }

    ModelAnimation anim = (ModelAnimation){
        boneCount,
        frameCount,
        bones,
        &framePoses
    };
    return anim;
}

void js_return_model_animation(struct v7* v7, v7_val_t* res, ModelAnimation anim) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "boneCount", ~0, v7_mk_number(v7, anim.boneCount));
    v7_set(v7, *res, "frameCount", ~0, v7_mk_number(v7, anim.frameCount));
    v7_set(v7, *res, "bones", ~0, v7_mk_array(v7));
    v7_set(v7, *res, "framePoses", ~0, v7_mk_array(v7));

    v7_val_t arr0 = v7_get(v7, *res, "bones", ~0);
    for (int i = 0; i < anim.boneCount; i++) {
        v7_array_push(v7, arr0, v7_mk_object(v7));
        v7_set(v7, v7_array_get(v7, arr0, i), "name", ~0, v7_mk_string(v7, anim.bones[i].name, ~0, 0));
        v7_set(v7, v7_array_get(v7, arr0, i), "parent", ~0, v7_mk_number(v7, anim.bones[i].parent));
    }

    v7_val_t arr1 = v7_get(v7, *res, "framePoses", ~0);
    for (int i = 0; i < anim.frameCount; i++) {
        v7_array_push(v7, arr1, v7_mk_object(v7));
        js_push_vec3(v7, v7_array_get(v7, arr1, i), "translation", anim.framePoses[i]->translation);
        js_push_quat(v7, v7_array_get(v7, arr1, i), "rotation", anim.framePoses[i]->rotation);
        js_push_vec3(v7, v7_array_get(v7, arr1, i), "scale", anim.framePoses[i]->scale);
    }
}

BoundingBox js_get_bounding_box(struct v7* v7, unsigned int arg) {
    BoundingBox box = (BoundingBox){
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "min", ~0)),
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, arg), "max", ~0)),
    };
    return box;
}

void js_return_bounding_box(struct v7* v7, v7_val_t* res, BoundingBox box) {
    *res = v7_mk_object(v7);
    js_push_vec3(v7, *res, "min", box.min);
    js_push_vec3(v7, *res, "max", box.max);
}

void js_return_ray_hit_info(struct v7* v7, v7_val_t* res, RayHitInfo info) {
    *res = v7_mk_object(v7);
    v7_set(v7, *res, "hit", ~0, v7_mk_boolean(v7, (int)info.hit));
    v7_set(v7, *res, "distance", ~0, v7_mk_number(v7, info.distance));
    js_push_vec3(v7, *res, "position", info.position);
    js_push_vec3(v7, *res, "normal", info.normal);
}
