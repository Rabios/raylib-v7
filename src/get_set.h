#ifndef RAYLIB_V7_GETTERS_SETTERS
#define RAYLIB_V7_GETTERS_SETTERS

#include <raylib.h>
#include <v7/v7.h>

void js_push_val(struct v7* v7, v7_val_t obj, char* var_name, v7_val_t val);
void js_push_key(struct v7* v7, v7_val_t obj, char* var_name, double val);

Color js_get_color(struct v7* v7, unsigned int arg);
void js_push_color(struct v7* v7, v7_val_t obj, char* var_name, Color color);
void js_return_color(struct v7* v7, v7_val_t* res, Color color);
Color js_color_from_obj(struct v7* v7, v7_val_t obj);

Vector2 js_get_vec2(struct v7* v7, unsigned int arg);
void js_push_vec2(struct v7* v7, v7_val_t obj, char* var_name, Vector2 vec2);
void js_return_vec2(struct v7* v7, v7_val_t* res, Vector2 vec2);
Vector2 js_vec2_from_obj(struct v7* v7, v7_val_t obj);

Vector3 js_get_vec3(struct v7* v7, unsigned int arg);
void js_push_vec3(struct v7* v7, v7_val_t obj, char* var_name, Vector3 vec3);
void js_return_vec3(struct v7* v7, v7_val_t* res, Vector3 vec3);
Vector3 js_vec3_from_obj(struct v7* v7, v7_val_t obj);
void js_update_vec3(struct v7* v7, unsigned int arg, Vector3 vec3);

Vector4 js_get_vec4(struct v7* v7, unsigned int arg);
void js_push_vec4(struct v7* v7, v7_val_t obj, char* var_name, Vector4 vec4);
void js_return_vec4(struct v7* v7, v7_val_t* res, Vector4 vec4);
Vector4 js_vec4_from_obj(struct v7* v7, v7_val_t obj);

Quaternion js_get_quat(struct v7* v7, unsigned int arg);
void js_push_quat(struct v7* v7, v7_val_t obj, char* var_name, Quaternion quat);
void js_return_quat(struct v7* v7, v7_val_t* res, Quaternion quat);
Quaternion js_quat_from_obj(struct v7* v7, v7_val_t obj);

Rectangle js_get_rect(struct v7* v7, unsigned int arg);
void js_push_rect(struct v7* v7, v7_val_t obj, char* var_name, Rectangle rect);
void js_return_rect(struct v7* v7, v7_val_t* res, Rectangle rect);
Rectangle js_rect_from_obj(struct v7* v7, v7_val_t obj);

Camera2D js_get_camera2d(struct v7* v7, unsigned int arg);
void js_push_camera2d(struct v7* v7, v7_val_t obj, char* var_name, Camera2D camera);
void js_return_camera2d(struct v7* v7, v7_val_t* res, Camera2D camera);

Camera js_get_camera3d(struct v7* v7, unsigned int arg);
void js_push_camera3d(struct v7* v7, v7_val_t obj, char* var_name, Camera camera);
void js_return_camera3d(struct v7* v7, v7_val_t* res, Camera camera);

Texture js_get_tex2d(struct v7* v7, unsigned int arg);
void js_push_tex2d(struct v7* v7, v7_val_t obj, char *var_name, Texture texture);
void js_return_tex2d(struct v7* v7, v7_val_t* res, Texture texture);
Texture js_tex2d_from_obj(struct v7* v7, v7_val_t obj);
void js_update_tex2d(struct v7* v7, unsigned int arg, Texture texture);

RenderTexture2D js_get_render_texture_2d(struct v7* v7, unsigned int arg);
void js_push_render_texture_2d(struct v7* v7, v7_val_t obj, char* var_name, RenderTexture2D texture);
void js_return_render_texture_2d(struct v7* v7, v7_val_t* res, RenderTexture2D texture);
RenderTexture2D js_render_texture_2d_from_obj(struct v7* v7, v7_val_t obj);

Image js_get_image(struct v7* v7, unsigned int arg);
void js_push_image(struct v7* v7, v7_val_t obj, char* var_name, Image image);
void js_return_image(struct v7* v7, v7_val_t* res, Image image);
void js_update_image(struct v7* v7, unsigned int arg, Image image);
Image js_image_from_obj(struct v7* v7, v7_val_t obj);

Shader js_get_shader(struct v7* v7, unsigned int arg);
void js_push_shader(struct v7* v7, v7_val_t obj, char* var_name, Shader shader);
void js_return_shader(struct v7* v7, v7_val_t* res, Shader shader);
Shader js_shader_from_obj(struct v7* v7, v7_val_t obj);

Ray js_get_ray(struct v7* v7, unsigned int arg);
void js_push_ray(struct v7* v7, v7_val_t obj, char* var_name, Ray ray);
void js_return_ray(struct v7* v7, v7_val_t* res, Ray ray);
Ray js_ray_from_obj(struct v7* v7, v7_val_t obj);

Matrix js_get_matrix(struct v7* v7, unsigned int arg);
void js_push_matrix(struct v7* v7, v7_val_t obj, char* var_name, Matrix matrix);
void js_return_matrix(struct v7* v7, v7_val_t* res, Matrix matrix);
Matrix js_matrix_from_obj(struct v7* v7, v7_val_t obj);

Font js_get_font(struct v7* v7, unsigned int arg);
void js_return_font(struct v7* v7, v7_val_t* res, Font font);

CharInfo js_get_char_info(struct v7* v7, unsigned int arg);
void js_return_char_info(struct v7* v7, v7_val_t* res, CharInfo char_info);

VrDeviceInfo js_get_vr_device_info(struct v7* v7, unsigned int arg);

NPatchInfo js_get_npatch_info(struct v7* v7, unsigned int arg);
void js_return_npatch_info(struct v7* v7, v7_val_t* res, NPatchInfo npatch_info);

Wave js_get_wave(struct v7* v7, unsigned int arg);
void js_return_wave(struct v7* v7, v7_val_t* res, Wave wave);

AudioStream js_get_audio_stream(struct v7* v7, unsigned int arg);
void js_push_audio_stream(struct v7* v7, v7_val_t obj, char* var_name, AudioStream stream);
void js_return_audio_stream(struct v7* v7, v7_val_t* res, AudioStream stream);
AudioStream js_audio_stream_from_obj(struct v7* v7, v7_val_t obj);

Sound js_get_sound(struct v7* v7, unsigned int arg);
void js_return_sound(struct v7* v7, v7_val_t* res, Sound sound);

Music js_get_music(struct v7* v7, unsigned int arg);
void js_return_music(struct v7* v7, v7_val_t* res, Music music);

Transform js_get_transform(struct v7* v7, unsigned int arg);
void js_push_transform(struct v7* v7, v7_val_t obj, char* var_name, Transform transform);
void js_return_transform(struct v7* v7, v7_val_t* res, Transform transform);

Mesh js_get_mesh(struct v7* v7, unsigned int arg);
void js_push_mesh(struct v7* v7, v7_val_t obj, char* var_name, Mesh mesh);
void js_return_mesh(struct v7* v7, v7_val_t* res, Mesh mesh);
Mesh js_mesh_from_obj(struct v7* v7, v7_val_t obj);
void js_update_mesh(struct v7* v7, unsigned int arg, Mesh mesh);

MaterialMap js_material_map_from_obj(struct v7* v7, v7_val_t obj);

Material js_get_material(struct v7* v7, unsigned int arg);
void js_push_material(struct v7* v7, v7_val_t obj, char* var_name, Material material);
void js_return_material(struct v7* v7, v7_val_t* res, Material material);
Material js_material_from_obj(struct v7* v7, v7_val_t obj);
void js_update_material(struct v7* v7, unsigned int arg, Material material);

BoneInfo js_bone_info_from_obj(struct v7* v7, v7_val_t obj);

Model js_get_model(struct v7* v7, unsigned int arg);
void js_push_model(struct v7* v7, v7_val_t obj, char* var_name, Model model);
void js_return_model(struct v7* v7, v7_val_t* res, Model model);
void js_update_model(struct v7* v7, unsigned int arg, Model model);

ModelAnimation js_get_model_animation(struct v7* v7, unsigned int arg);
void js_return_model_animation(struct v7* v7, v7_val_t* res, ModelAnimation anim);

BoundingBox js_get_bounding_box(struct v7* v7, unsigned int arg);
void js_return_bounding_box(struct v7* v7, v7_val_t* res, BoundingBox box);

void js_return_ray_hit_info(struct v7* v7, v7_val_t* res, RayHitInfo info);

#endif
