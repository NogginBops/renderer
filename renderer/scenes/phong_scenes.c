#include <assert.h>
#include <stdlib.h>
#include "../core/api.h"
#include "../shaders/phong_shader.h"
#include "phong_scenes.h"

scene_t *phong_ornitier_scene(void) {
    const char *meshes[] = {
        "assets/ornitier/base.obj",
        "assets/ornitier/body.obj",
        "assets/ornitier/coat.obj",
        "assets/ornitier/hands.obj",
        "assets/ornitier/hat.obj",
        "assets/ornitier/legs.obj",
    };
    phong_material_t materials[] = {
        {
            0.5f,
            32,
            "assets/ornitier/base_emission.tga",
            "assets/ornitier/base_diffuse.tga",
            "assets/ornitier/base_specular.tga",
        },
        {
            0.5f,
            32,
            "assets/ornitier/body_emission.tga",
            "assets/ornitier/body_diffuse.tga",
            "assets/ornitier/body_specular.tga",
        },
        {
            0.5f,
            32,
            NULL,
            "assets/ornitier/coat_diffuse.tga",
            "assets/ornitier/coat_specular.tga",
        },
        {
            0.5f,
            32,
            NULL,
            "assets/ornitier/hands_diffuse.tga",
            "assets/ornitier/hands_specular.tga",
        },
        {
            0.5f,
            32,
            NULL,
            "assets/ornitier/hat_diffuse.tga",
            "assets/ornitier/hat_specular.tga",
        },
        {
            0.5f,
            32,
            NULL,
            "assets/ornitier/legs_diffuse.tga",
            "assets/ornitier/legs_specular.tga",
        },
    };
    vec4_t background = vec4_new(0.314f, 0.235f, 0.278f, 1);
    model_t **models = NULL;
    model_t *model;
    scene_t *scene;
    mat4_t scale, translation, root;
    int num_meshes = ARRAY_SIZE(meshes);
    int i;

    assert(ARRAY_SIZE(materials) == num_meshes);

    translation = mat4_translate(5.863f, 156.991f, 110.488f);
    scale = mat4_scale(0.0016f, 0.0016f, 0.0016f);
    root = mat4_mul_mat4(scale, translation);
    for (i = 0; i < num_meshes; i++) {
        model = phong_create_model(meshes[i], root, materials[i]);
        darray_push(models, model);
    }

    scene = (scene_t*)malloc(sizeof(scene_t));
    scene->background = background;
    scene->models     = models;

    return scene;
}