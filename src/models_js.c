#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>
#include <models_js.h>

static inline enum v7_err js_draw_line3d(struct v7* v7) {
    DrawLine3D(js_get_vec3(v7, 0), js_get_vec3(v7, 1), js_get_color(v7, 2));
    return V7_OK;
}

static inline enum v7_err js_draw_point3d(struct v7* v7) {
    DrawPoint3D(js_get_vec3(v7, 0), js_get_color(v7, 1));
    return V7_OK;
}

static inline enum v7_err js_draw_circle3d(struct v7* v7) {
    DrawCircle3D(js_get_vec3(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), js_get_vec3(v7, 2), v7_get_double(v7, v7_arg(v7, 4)), js_get_color(v7, 4));
    return V7_OK;
}

static inline enum v7_err js_draw_triangle3d(struct v7* v7) {
    DrawTriangle3D(js_get_vec3(v7, 0), js_get_vec3(v7, 1), js_get_vec3(v7, 2), js_get_color(v7, 3));
    return V7_OK;
}

static inline enum v7_err js_draw_triangle_strip_3d(struct v7* v7) {
    int pointsCount = v7_get_int(v7, v7_arg(v7, 1));
    Vector3* points;
    for (int i = 0; i < pointsCount; i++) {
        points[i] = js_vec3_from_obj(v7, v7_array_get(v7, v7_arg(v7, 0), i));
    }
    DrawTriangleStrip3D(points, pointsCount, js_get_color(v7, 2));
    return V7_OK;
}

static inline enum v7_err js_draw_cube(struct v7* v7) {
    DrawCube(js_get_vec3(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3)), js_get_color(v7, 4));
    return V7_OK;
}

static inline enum v7_err js_draw_cube_v(struct v7* v7) {
    DrawCubeV(js_get_vec3(v7, 0), js_get_vec3(v7, 1), js_get_color(v7, 2));
    return V7_OK;
}

static inline enum v7_err js_draw_cube_wires(struct v7* v7) {
    DrawCubeWires(js_get_vec3(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3)), js_get_color(v7, 4));
    return V7_OK;
}

static inline enum v7_err js_draw_cube_wires_v(struct v7* v7) {
    DrawCubeWiresV(js_get_vec3(v7, 0), js_get_vec3(v7, 1), js_get_color(v7, 2));
    return V7_OK;
}

static inline enum v7_err js_draw_cube_texture(struct v7* v7) {
    DrawCubeTexture(js_get_tex2d(v7, 0), js_get_vec3(v7, 1), v7_get_double(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3)), v7_get_double(v7, v7_arg(v7, 4)), js_get_color(v7, 5));
    return V7_OK;
}

static inline enum v7_err js_draw_sphere(struct v7* v7) {
    DrawSphere(js_get_vec3(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), js_get_color(v7, 2));
    return V7_OK;
}

static inline enum v7_err js_draw_sphere_ex(struct v7* v7) {
    DrawSphereEx(js_get_vec3(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), js_get_color(v7, 4));
    return V7_OK;
}

static inline enum v7_err js_draw_sphere_wires(struct v7* v7) {
    DrawSphereWires(js_get_vec3(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), js_get_color(v7, 4));
    return V7_OK;
}

static inline enum v7_err js_draw_cylinder(struct v7* v7) {
    DrawCylinder(js_get_vec3(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4)), js_get_color(v7, 5));
    return V7_OK;
}

static inline enum v7_err js_draw_cylinder_wires(struct v7* v7) {
    DrawCylinderWires(js_get_vec3(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2)), v7_get_double(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4)), js_get_color(v7, 5));
    return V7_OK;
}

static inline enum v7_err js_draw_plane(struct v7* v7) {
    DrawPlane(js_get_vec3(v7, 0), js_get_vec2(v7, 1), js_get_color(v7, 2));
    return V7_OK;
}

static inline enum v7_err js_draw_ray(struct v7* v7) {
    DrawRay(js_get_ray(v7, 0), js_get_color(v7, 1));
    return V7_OK;
}

static inline enum v7_err js_draw_grid(struct v7* v7) {
    DrawGrid(v7_get_int(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_draw_gizmo(struct v7* v7) {
    DrawGizmo(js_get_vec3(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_load_model(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    js_return_model(v7, res, LoadModel(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_load_model_from_mesh(struct v7* v7, v7_val_t* res) {
    js_return_model(v7, res, LoadModelFromMesh(js_get_mesh(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_unload_model(struct v7* v7) {
    UnloadModel(js_get_model(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_unload_model_keep_meshes(struct v7* v7) {
    UnloadModelKeepMeshes(js_get_model(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_load_meshes(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    int count = v7_get_int(v7, v7_arg(v7, 1));
    Mesh* meshes = LoadMeshes(v7_get_string(v7, &strarg, &lenstr), &count);
    *res = v7_mk_array(v7);
    for (int i = 0; i < count; i++) {
        v7_val_t obj = v7_mk_object(v7);
        v7_set(v7, obj, "vertexCount", ~0, v7_mk_number(v7, meshes[i].vertexCount));
        v7_set(v7, obj, "triangleCount", ~0, v7_mk_number(v7, meshes[i].triangleCount));
        v7_set(v7, obj, "vertices", ~0, v7_mk_foreign(v7, meshes[i].vertices));
        v7_set(v7, obj, "texcoords", ~0, v7_mk_foreign(v7, meshes[i].texcoords));
        v7_set(v7, obj, "texcoords2", ~0, v7_mk_foreign(v7, meshes[i].texcoords2));
        v7_set(v7, obj, "normals", ~0, v7_mk_foreign(v7, meshes[i].normals));
        v7_set(v7, obj, "tangents", ~0, v7_mk_foreign(v7, meshes[i].tangents));
        v7_set(v7, obj, "colors", ~0, v7_mk_foreign(v7, meshes[i].colors));
        v7_set(v7, obj, "indices", ~0, v7_mk_foreign(v7, meshes[i].indices));
        v7_set(v7, obj, "animVertices", ~0, v7_mk_foreign(v7, meshes[i].animVertices));
        v7_set(v7, obj, "animNormals", ~0, v7_mk_foreign(v7, meshes[i].animNormals));
        v7_set(v7, obj, "boneIds", ~0, v7_mk_foreign(v7, meshes[i].boneIds));
        v7_set(v7, obj, "boneWeights", ~0, v7_mk_foreign(v7, meshes[i].boneWeights));
        v7_set(v7, obj, "vaoId", ~0, v7_mk_number(v7, meshes[i].vaoId));
        v7_set(v7, obj, "vboId", ~0, v7_mk_foreign(v7, meshes[i].vboId));
        v7_array_push(v7, *res, obj);
    }
    return V7_OK;
}

static inline enum v7_err js_unload_mesh(struct v7* v7) {
    UnloadMesh(js_get_mesh(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_export_mesh(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 1);
    size_t lenstr;
    *res = v7_mk_boolean(v7, (int)ExportMesh(js_get_mesh(v7, 0), v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_load_materials(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    int count = v7_get_int(v7, v7_arg(v7, 1));
    Material* materials = LoadMaterials(v7_get_string(v7, &strarg, &lenstr), &count);
    *res = v7_mk_array(v7);
    for (int i = 0; i < count; i++) {
        v7_val_t obj = v7_mk_object(v7);
        js_push_shader(v7, obj, "shader", materials[i].shader);
        v7_array_push(v7, *res, obj);
    }
    return V7_OK;
}

static inline enum v7_err js_load_material_default(struct v7* v7, v7_val_t* res) {
    js_return_material(v7, res, LoadMaterialDefault());
    return V7_OK;
}

static inline enum v7_err js_unload_material(struct v7* v7) {
    UnloadMaterial(js_get_material(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_set_material_texture(struct v7* v7) {
    Material material = js_get_material(v7, 0);
    SetMaterialTexture(&material, v7_get_int(v7, v7_arg(v7, 1)), js_get_tex2d(v7, 2));
    js_update_material(v7, 0, material);
    return V7_OK;
}

static inline enum v7_err js_set_model_mesh_material(struct v7* v7) {
    Model model = js_get_model(v7, 0);
    SetModelMeshMaterial(&model, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    js_update_model(v7, 0, model);
    return V7_OK;
}

static inline enum v7_err js_load_model_animations(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    int animsCount = v7_get_int(v7, v7_arg(v7, 1));
    ModelAnimation* anims = LoadModelAnimations(v7_get_string(v7, &strarg, &lenstr), &animsCount);
    *res = v7_mk_array(v7);
    for (int i = 0; i < animsCount; i++) {
        v7_array_push(v7, *res, v7_mk_object(v7));
        v7_set(v7, v7_array_get(v7, *res, i), "boneCount", ~0, v7_mk_number(v7, anims[i].boneCount));
        v7_set(v7, v7_array_get(v7, *res, i), "frameCount", ~0, v7_mk_number(v7, anims[i].frameCount));
        v7_set(v7, v7_array_get(v7, *res, i), "bones", ~0, v7_mk_array(v7));
        v7_set(v7, v7_array_get(v7, *res, i), "framePoses", ~0, v7_mk_array(v7));

        v7_val_t arr0 = v7_get(v7, v7_array_get(v7, *res, i), "bones", ~0);
        for (int j = 0; j < anims[j].boneCount; j++) {
            v7_array_push(v7, arr0, v7_mk_object(v7));
            v7_set(v7, v7_array_get(v7, arr0, j), "name", ~0, v7_mk_string(v7, anims[i].bones[j].name, ~0, 0));
            v7_set(v7, v7_array_get(v7, arr0, j), "parent", ~0, v7_mk_number(v7, anims[i].bones[j].parent));
        }

        v7_val_t arr1 = v7_get(v7, v7_array_get(v7, *res, i), "framePoses", ~0);
        for (int k = 0; k < anims[i].frameCount; k++) {
            v7_array_push(v7, arr1, v7_mk_object(v7));
            js_push_vec3(v7, v7_array_get(v7, arr1, k), "translation", anims[i].framePoses[k]->translation);
            js_push_quat(v7, v7_array_get(v7, arr1, k), "rotation", anims[i].framePoses[k]->rotation);
            js_push_vec3(v7, v7_array_get(v7, arr1, k), "scale", anims[i].framePoses[k]->scale);
        }
    }
    return V7_OK;
}

static inline enum v7_err js_update_model_animation(struct v7* v7) {
    UpdateModelAnimation(js_get_model(v7, 0), js_get_model_animation(v7, 1), v7_get_int(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_unload_model_animation(struct v7* v7) {
    UnloadModelAnimation(js_get_model_animation(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_model_animation_valid(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsModelAnimationValid(js_get_model(v7, 0), js_get_model_animation(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_gen_mesh_poly(struct v7* v7, v7_val_t* res) {
    js_return_mesh(v7, res, GenMeshPoly(v7_get_int(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_gen_mesh_plane(struct v7* v7, v7_val_t* res) {
    js_return_mesh(v7, res, GenMeshPlane(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gen_mesh_cube(struct v7* v7, v7_val_t* res) {
    js_return_mesh(v7, res, GenMeshCube(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_double(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gen_mesh_sphere(struct v7* v7, v7_val_t* res) {
    js_return_mesh(v7, res, GenMeshSphere(v7_get_double(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gen_mesh_hemi_sphere(struct v7* v7, v7_val_t* res) {
    js_return_mesh(v7, res, GenMeshHemiSphere(v7_get_double(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gen_mesh_cylinder(struct v7* v7, v7_val_t* res) {
    js_return_mesh(v7, res, GenMeshCylinder(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gen_mesh_torus(struct v7* v7, v7_val_t* res) {
    js_return_mesh(v7, res, GenMeshTorus(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gen_mesh_knot(struct v7* v7, v7_val_t* res) {
    js_return_mesh(v7, res, GenMeshKnot(v7_get_double(v7, v7_arg(v7, 0)), v7_get_double(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gen_mesh_heightmap(struct v7* v7, v7_val_t* res) {
    js_return_mesh(v7, res, GenMeshHeightmap(js_get_image(v7, 0), js_get_vec3(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_gen_mesh_cubicmap(struct v7* v7, v7_val_t* res) {
    js_return_mesh(v7, res, GenMeshCubicmap(js_get_image(v7, 0), js_get_vec3(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_mesh_bounding_box(struct v7* v7, v7_val_t* res) {
    js_return_bounding_box(v7, res, MeshBoundingBox(js_get_mesh(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_mesh_tangents(struct v7* v7) {
    Mesh mesh = js_get_mesh(v7, 0);
    MeshTangents(&mesh);
    js_update_mesh(v7, 0, mesh);
    return V7_OK;
}

static inline enum v7_err js_mesh_binormals(struct v7* v7) {
    Mesh mesh = js_get_mesh(v7, 0);
    MeshBinormals(&mesh);
    js_update_mesh(v7, 0, mesh);
    return V7_OK;
}

static inline enum v7_err js_mesh_normals_smooth(struct v7* v7) {
    Mesh mesh = js_get_mesh(v7, 0);
    MeshNormalsSmooth(&mesh);
    js_update_mesh(v7, 0, mesh);
    return V7_OK;
}

static inline enum v7_err js_draw_model(struct v7* v7) {
    DrawModel(js_get_model(v7, 0), js_get_vec3(v7, 1), v7_get_double(v7, v7_arg(v7, 2)), js_get_color(v7, 3));
    return V7_OK;
}

static inline enum v7_err js_draw_model_ex(struct v7* v7) {
    DrawModelEx(js_get_model(v7, 0), js_get_vec3(v7, 1), js_get_vec3(v7, 2), v7_get_double(v7, v7_arg(v7, 3)), js_get_vec3(v7, 4), js_get_color(v7, 5));
    return V7_OK;
}

static inline enum v7_err js_draw_model_wires(struct v7* v7) {
    DrawModelWires(js_get_model(v7, 0), js_get_vec3(v7, 1), v7_get_double(v7, v7_arg(v7, 2)), js_get_color(v7, 3));
    return V7_OK;
}

static inline enum v7_err js_draw_model_wires_ex(struct v7* v7) {
    DrawModelWiresEx(js_get_model(v7, 0), js_get_vec3(v7, 1), js_get_vec3(v7, 2), v7_get_double(v7, v7_arg(v7, 3)), js_get_vec3(v7, 4), js_get_color(v7, 5));
    return V7_OK;
}

static inline enum v7_err js_draw_bounding_box(struct v7* v7) {
    DrawBoundingBox(js_get_bounding_box(v7, 0), js_get_color(v7, 1));
    return V7_OK;
}

static inline enum v7_err js_draw_billboard(struct v7* v7) {
    DrawBillboard(js_get_camera3d(v7, 0), js_get_tex2d(v7, 1), js_get_vec3(v7, 2), v7_get_double(v7, v7_arg(v7, 3)), js_get_color(v7, 4));
    return V7_OK;
}

static inline enum v7_err js_draw_billboard_rec(struct v7* v7) {
    DrawBillboardRec(js_get_camera3d(v7, 0), js_get_tex2d(v7, 1), js_get_rect(v7, 2), js_get_vec3(v7, 3), v7_get_double(v7, v7_arg(v7, 4)), js_get_color(v7, 5));
    return V7_OK;
}

static inline enum v7_err js_check_collision_spheres(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)CheckCollisionSpheres(js_get_vec3(v7, 0), v7_get_double(v7, v7_arg(v7, 1)), js_get_vec3(v7, 2), v7_get_double(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_check_collision_boxes(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)CheckCollisionBoxes(js_get_bounding_box(v7, 0), js_get_bounding_box(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_check_collision_box_sphere(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)CheckCollisionBoxSphere(js_get_bounding_box(v7, 0), js_get_vec3(v7, 1), v7_get_double(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_check_collision_ray_sphere(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)CheckCollisionRaySphere(js_get_ray(v7, 0), js_get_vec3(v7, 1), v7_get_double(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_check_collision_ray_sphere_ex(struct v7* v7, v7_val_t* res) {
    Vector3 collisionPoint = js_get_vec3(v7, 3);
    *res = v7_mk_boolean(v7, (int)CheckCollisionRaySphereEx(js_get_ray(v7, 0), js_get_vec3(v7, 1), v7_get_double(v7, v7_arg(v7, 2)), &collisionPoint));
    js_update_vec3(v7, 3, collisionPoint);
    return V7_OK;
}

static inline enum v7_err js_check_collision_ray_box(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)CheckCollisionRayBox(js_get_ray(v7, 0), js_get_bounding_box(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_get_collision_ray_mesh(struct v7* v7, v7_val_t* res) {
    js_return_ray_hit_info(v7, res, GetCollisionRayMesh(js_get_ray(v7, 0), js_get_mesh(v7, 1), js_get_matrix(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_get_collision_ray_model(struct v7* v7, v7_val_t* res) {
    js_return_ray_hit_info(v7, res, GetCollisionRayModel(js_get_ray(v7, 0), js_get_model(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_get_collision_ray_triangle(struct v7* v7, v7_val_t* res) {
    js_return_ray_hit_info(v7, res, GetCollisionRayTriangle(js_get_ray(v7, 0), js_get_vec3(v7, 1), js_get_vec3(v7, 2), js_get_vec3(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_get_collision_ray_ground(struct v7* v7, v7_val_t* res) {
    js_return_ray_hit_info(v7, res, GetCollisionRayGround(js_get_ray(v7, 0), v7_get_double(v7, v7_arg(v7, 1))));
    return V7_OK;
}

void raylib_v7_load_models(struct v7* v7) {
    v7_set_method(v7, v7_get_global(v7), "DrawLine3D", &js_draw_line3d);
    v7_set_method(v7, v7_get_global(v7), "DrawPoint3D", &js_draw_point3d);
    v7_set_method(v7, v7_get_global(v7), "DrawCircle3D", &js_draw_circle3d);
    v7_set_method(v7, v7_get_global(v7), "DrawTriangle3D", &js_draw_triangle3d);
    v7_set_method(v7, v7_get_global(v7), "DrawTriangleStrip3D", &js_draw_triangle_strip_3d);
    v7_set_method(v7, v7_get_global(v7), "DrawCube", &js_draw_cube);
    v7_set_method(v7, v7_get_global(v7), "DrawCubeV", &js_draw_cube_v);
    v7_set_method(v7, v7_get_global(v7), "DrawCubeWires", &js_draw_cube_wires);
    v7_set_method(v7, v7_get_global(v7), "DrawCubeWiresV", &js_draw_cube_wires_v);
    v7_set_method(v7, v7_get_global(v7), "DrawCubeTexture", &js_draw_cube_texture);
    v7_set_method(v7, v7_get_global(v7), "DrawSphere", &js_draw_sphere);
    v7_set_method(v7, v7_get_global(v7), "DrawSphereEx", &js_draw_sphere_ex);
    v7_set_method(v7, v7_get_global(v7), "DrawSphereWires", &js_draw_sphere_wires);
    v7_set_method(v7, v7_get_global(v7), "DrawCylinder", &js_draw_cylinder);
    v7_set_method(v7, v7_get_global(v7), "DrawCylinderWires", &js_draw_cylinder_wires);
    v7_set_method(v7, v7_get_global(v7), "DrawPlane", &js_draw_plane);
    v7_set_method(v7, v7_get_global(v7), "DrawRay", &js_draw_ray);
    v7_set_method(v7, v7_get_global(v7), "DrawGrid", &js_draw_grid);
    v7_set_method(v7, v7_get_global(v7), "DrawGizmo", &js_draw_gizmo);

    v7_set_method(v7, v7_get_global(v7), "LoadModel", &js_load_model);
    v7_set_method(v7, v7_get_global(v7), "LoadModelFromMesh", &js_load_model_from_mesh);
    v7_set_method(v7, v7_get_global(v7), "UnloadModel", &js_unload_model);
    v7_set_method(v7, v7_get_global(v7), "UnloadModelKeepMeshes", &js_unload_model_keep_meshes);

    v7_set_method(v7, v7_get_global(v7), "LoadMeshes", &js_load_meshes);
    v7_set_method(v7, v7_get_global(v7), "UnloadMesh", &js_unload_mesh);
    v7_set_method(v7, v7_get_global(v7), "ExportMesh", &js_export_mesh);

    v7_set_method(v7, v7_get_global(v7), "LoadMaterials", &js_load_materials);
    v7_set_method(v7, v7_get_global(v7), "LoadMaterialDefault", &js_load_material_default);
    v7_set_method(v7, v7_get_global(v7), "UnloadMaterial", &js_unload_material);
    v7_set_method(v7, v7_get_global(v7), "SetMaterialTexture", &js_set_material_texture);
    v7_set_method(v7, v7_get_global(v7), "SetModelMeshMaterial", &js_set_model_mesh_material);

    v7_set_method(v7, v7_get_global(v7), "LoadModelAnimations", &js_load_model_animations);
    v7_set_method(v7, v7_get_global(v7), "UpdateModelAnimation", &js_update_model_animation);
    v7_set_method(v7, v7_get_global(v7), "UnloadModelAnimation", &js_unload_model_animation);
    v7_set_method(v7, v7_get_global(v7), "IsModelAnimationValid", &js_model_animation_valid);

    v7_set_method(v7, v7_get_global(v7), "GenMeshPoly", &js_gen_mesh_poly);
    v7_set_method(v7, v7_get_global(v7), "GenMeshPlane", &js_gen_mesh_plane);
    v7_set_method(v7, v7_get_global(v7), "GenMeshCube", &js_gen_mesh_cube);
    v7_set_method(v7, v7_get_global(v7), "GenMeshSphere", &js_gen_mesh_sphere);
    v7_set_method(v7, v7_get_global(v7), "GenMeshHemiSphere", &js_gen_mesh_hemi_sphere);
    v7_set_method(v7, v7_get_global(v7), "GenMeshCylinder", &js_gen_mesh_cylinder);
    v7_set_method(v7, v7_get_global(v7), "GenMeshTorus", &js_gen_mesh_torus);
    v7_set_method(v7, v7_get_global(v7), "GenMeshKnot", &js_gen_mesh_knot);
    v7_set_method(v7, v7_get_global(v7), "GenMeshHeightmap", &js_gen_mesh_heightmap);
    v7_set_method(v7, v7_get_global(v7), "GenMeshCubicmap", &js_gen_mesh_cubicmap);

    v7_set_method(v7, v7_get_global(v7), "MeshBoundingBox", &js_mesh_bounding_box);
    v7_set_method(v7, v7_get_global(v7), "MeshTangents", &js_mesh_tangents);
    v7_set_method(v7, v7_get_global(v7), "MeshBinormals", &js_mesh_binormals);
    v7_set_method(v7, v7_get_global(v7), "MeshNormalsSmooth", &js_mesh_normals_smooth);

    v7_set_method(v7, v7_get_global(v7), "DrawModel", &js_draw_model);
    v7_set_method(v7, v7_get_global(v7), "DrawModelEx", &js_draw_model_ex);
    v7_set_method(v7, v7_get_global(v7), "DrawModelWires", &js_draw_model_wires);
    v7_set_method(v7, v7_get_global(v7), "DrawModelWiresEx", &js_draw_model_wires_ex);
    v7_set_method(v7, v7_get_global(v7), "DrawBoundingBox", &js_draw_bounding_box);
    v7_set_method(v7, v7_get_global(v7), "DrawBillboard", &js_draw_billboard);
    v7_set_method(v7, v7_get_global(v7), "DrawBillboardRec", &js_draw_billboard_rec);

    v7_set_method(v7, v7_get_global(v7), "CheckCollisionSpheres", &js_check_collision_spheres);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionBoxes", &js_check_collision_boxes);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionBoxSphere", &js_check_collision_box_sphere);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionRaySphere", &js_check_collision_ray_sphere);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionRaySphereEx", &js_check_collision_ray_sphere_ex);
    v7_set_method(v7, v7_get_global(v7), "CheckCollisionRayBox", &js_check_collision_ray_box);
    v7_set_method(v7, v7_get_global(v7), "GetCollisionRayMesh", &js_get_collision_ray_mesh);
    v7_set_method(v7, v7_get_global(v7), "GetCollisionRayModel", &js_get_collision_ray_model);
    v7_set_method(v7, v7_get_global(v7), "GetCollisionRayTriangle", &js_get_collision_ray_triangle);
    v7_set_method(v7, v7_get_global(v7), "GetCollisionRayGround", &js_get_collision_ray_ground);
}
