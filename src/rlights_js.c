#define RLIGHTS_IMPLEMENTATION

#include <raylib.h>
#include <rlights/rlights.h>
#include <v7/v7.h>
#include <get_set.h>
#include <rlights_js.h>

static inline enum v7_err js_create_light(struct v7* v7, v7_val_t* res) {
    int type = v7_get_int(v7, v7_arg(v7, 0));
    Vector3 position = js_get_vec3(v7, 1);
    Vector3 target = js_get_vec3(v7, 2);
    Color color = js_get_color(v7, 3);
    Shader shader = js_get_shader(v7, 4);
    Light light = CreateLight(type, position, target, color, shader);
    *res = v7_mk_object(v7);
    js_push_val(v7, *res, "type", v7_mk_number(v7, light.type));
    js_push_vec3(v7, *res, "position", light.position);
    js_push_vec3(v7, *res, "target", light.target);
    js_push_color(v7, *res, "color", light.color);
    js_push_val(v7, *res, "enabled", v7_mk_boolean(v7, (int)light.enabled));

    js_push_key(v7, *res, "enabledLoc", light.enabledLoc);
    js_push_key(v7, *res, "typeLoc", light.typeLoc);
    js_push_key(v7, *res, "posLoc", light.posLoc);
    js_push_key(v7, *res, "targetLoc", light.targetLoc);
    js_push_key(v7, *res, "colorLoc", light.colorLoc);
    return V7_OK;
}

static inline enum v7_err js_update_light_values(struct v7* v7) {
    Shader shader = js_get_shader(v7, 0);
    Light light = (Light){
        v7_get_int(v7, v7_get(v7, v7_arg(v7, 1), "type", ~0)),
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, 1), "position", ~0)),
        js_vec3_from_obj(v7, v7_get(v7, v7_arg(v7, 1), "target", ~0)),
        js_color_from_obj(v7, v7_get(v7, v7_arg(v7, 1), "color", ~0)),
        (bool)v7_get_bool(v7, v7_get(v7, v7_arg(v7, 1), "enabled", ~0)),

        v7_get_int(v7, v7_get(v7, v7_arg(v7, 1), "enabledLoc", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, 1), "typeLoc", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, 1), "posLoc", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, 1), "targetLoc", ~0)),
        v7_get_int(v7, v7_get(v7, v7_arg(v7, 1), "colorLoc", ~0)),
    };
    UpdateLightValues(shader, light);
    return V7_OK;
}

void raylib_v7_load_rlights(struct v7* v7) {
    js_push_key(v7, v7_get_global(v7), "LIGHT_DIRECTIONAL", LIGHT_DIRECTIONAL);
    js_push_key(v7, v7_get_global(v7), "LIGHT_POINT", LIGHT_POINT);

    v7_set_method(v7, v7_get_global(v7), "CreateLight", &js_create_light);
    v7_set_method(v7, v7_get_global(v7), "UpdateLightValues", &js_update_light_values);
}
