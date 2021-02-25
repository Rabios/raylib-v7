#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>
#include <textures_js.h>

static inline enum v7_err js_load_image(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    js_return_image(v7, res, LoadImage(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_load_image_raw(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    int width = v7_get_int(v7, v7_arg(v7, 1));
    int height = v7_get_int(v7, v7_arg(v7, 2));
    int format = v7_get_int(v7, v7_arg(v7, 3));
    int headerSize = v7_get_int(v7, v7_arg(v7, 4));
    js_return_image(v7, res, LoadImageRaw(v7_get_string(v7, &strarg, &lenstr), width, height, format, headerSize));
    return V7_OK;
}

static inline enum v7_err js_load_image_anim(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    int *frames = v7_get_int(v7, v7_arg(v7, 1));
    js_return_image(v7, res, LoadImageAnim(v7_get_string(v7, &strarg, &lenstr), frames));
    return V7_OK;
}

static inline enum v7_err js_load_image_from_memory(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    size_t lenstr1;
    v7_val_t strarg0 = v7_arg(v7, 0);
    v7_val_t strarg1 = v7_arg(v7, 1);
    int dataSize = v7_get_int(v7, v7_arg(v7, 2));
    js_return_image(v7, res, LoadImageFromMemory(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1), dataSize));
    return V7_OK;
}

static inline enum v7_err js_unload_image(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    UnloadImage(image);
    return V7_OK;
}

static inline enum v7_err js_export_image(struct v7* v7, v7_val_t* res) {
    Image image = js_get_image(v7, 0);
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)ExportImage(image, v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_export_image_as_code(struct v7* v7, v7_val_t* res) {
    Image image = js_get_image(v7, 0);
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)ExportImageAsCode(image, v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_gen_image_color(struct v7* v7, v7_val_t* res) {
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    Color color = js_get_color(v7, 2);
    js_return_image(v7, res, GenImageColor(width, height, color));
    return V7_OK;
}

static inline enum v7_err js_gen_image_gradient_v(struct v7* v7, v7_val_t* res) {
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    Color top = js_get_color(v7, 2);
    Color bottom = js_get_color(v7, 3);
    js_return_image(v7, res, GenImageGradientV(width, height, top, bottom));
    return V7_OK;
}

static inline enum v7_err js_gen_image_gradient_h(struct v7* v7, v7_val_t* res) {
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    Color left = js_get_color(v7, 2);
    Color right = js_get_color(v7, 3);
    js_return_image(v7, res, GenImageGradientH(width, height, left, right));
    return V7_OK;
}

static inline enum v7_err js_gen_image_gradient_radial(struct v7* v7, v7_val_t* res) {
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    float density = (float)v7_get_double(v7, v7_arg(v7, 2));
    Color inner = js_get_color(v7, 3);
    Color outer = js_get_color(v7, 4);
    js_return_image(v7, res, GenImageGradientRadial(width, height, density, inner, outer));
    return V7_OK;
}

static inline enum v7_err js_gen_image_checked(struct v7* v7, v7_val_t* res) {
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    int checksX = v7_get_int(v7, v7_arg(v7, 2));
    int checksY = v7_get_int(v7, v7_arg(v7, 3));
    Color col1 = js_get_color(v7, 4);
    Color col2 = js_get_color(v7, 5);
    js_return_image(v7, res, GenImageChecked(width, height, checksX, checksY, col1, col2));
    return V7_OK;
}

static inline enum v7_err js_gen_image_white_noise(struct v7* v7, v7_val_t* res) {
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    float factor = (float)v7_get_double(v7, v7_arg(v7, 2));
    js_return_image(v7, res, GenImageWhiteNoise(width, height, factor));
    return V7_OK;
}

static inline enum v7_err js_gen_image_perlin_noise(struct v7* v7, v7_val_t* res) {
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    int offsetX = v7_get_int(v7, v7_arg(v7, 2));
    int offsetY = v7_get_int(v7, v7_arg(v7, 3));
    float scale = (float)v7_get_double(v7, v7_arg(v7, 4));
    js_return_image(v7, res, GenImagePerlinNoise(width, height, offsetX, offsetY, scale));
    return V7_OK;
}

static inline enum v7_err js_gen_image_cellular(struct v7* v7, v7_val_t* res) {
    int width = v7_get_int(v7, v7_arg(v7, 0));
    int height = v7_get_int(v7, v7_arg(v7, 1));
    int tileSize = v7_get_int(v7, v7_arg(v7, 2));
    js_return_image(v7, res, GenImageCellular(width, height, tileSize));
    return V7_OK;
}

static inline enum v7_err js_image_copy(struct v7* v7, v7_val_t* res) {
    js_return_image(v7, res, ImageCopy(js_get_image(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_image_from_image(struct v7* v7, v7_val_t* res) {
    js_return_image(v7, res, ImageFromImage(js_get_image(v7, 0), js_get_rect(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_image_text(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    js_return_image(v7, res, ImageText(v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 1)), js_get_color(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_image_text_ex(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    js_return_image(v7, res, ImageTextEx(js_get_font(v7, 0), v7_get_string(v7, &strarg, &lenstr), (float)v7_get_double(v7, v7_arg(v7, 2)), (float)v7_get_double(v7, v7_arg(v7, 3)), js_get_color(v7, 4)));
    return V7_OK;
}

static inline enum v7_err js_image_format(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageFormat(&image, v7_get_int(v7, v7_arg(v7, 1)));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_to_pot(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageToPOT(&image, js_get_color(v7, 1));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_crop(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageCrop(&image, js_get_rect(v7, 1));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_alpha_crop(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageAlphaCrop(&image, (float)v7_get_double(v7, v7_arg(v7, 1)));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_alpha_clear(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageAlphaClear(&image, js_get_color(v7, 1), (float)v7_get_double(v7, v7_arg(v7, 2)));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_alpha_mask(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    Image alphaMask = js_get_image(v7, 1);
    ImageAlphaMask(&image, alphaMask);
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_alpha_premultiply(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageAlphaPremultiply(&image);
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_resize(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageResize(&image, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_resize_nn(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageResizeNN(&image, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_resize_canvas(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageResizeCanvas(&image, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4)), js_get_color(v7, 5));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_mipmaps(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageMipmaps(&image);
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_dither(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDither(&image, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4)));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_flip_vertical(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageFlipVertical(&image);
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_flip_horizontal(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageFlipHorizontal(&image);
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_rotate_cw(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageRotateCW(&image);
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_rotate_ccw(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageRotateCCW(&image);
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_color_tint(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageColorTint(&image, js_get_color(v7, 1));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_color_invert(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageColorInvert(&image);
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_color_grayscale(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageColorGrayscale(&image);
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_color_contrast(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageColorContrast(&image, (float)v7_get_double(v7, v7_arg(v7, 1)));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_color_brightness(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageColorBrightness(&image, v7_get_int(v7, v7_arg(v7, 1)));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_color_replace(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageColorReplace(&image, js_get_color(v7, 1), js_get_color(v7, 2));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_load_image_colors(struct v7* v7, v7_val_t* res) {
    Image image = js_get_image(v7, 0);
    Color* colors = LoadImageColors(image);
    *res = v7_mk_array(v7);
    for (int i = 0; i < image.width * image.height; i++) {
        v7_val_t color = v7_mk_object(v7);
        js_push_val(v7, color, "r", colors[i].r);
        js_push_val(v7, color, "g", colors[i].g);
        js_push_val(v7, color, "b", colors[i].b);
        js_push_val(v7, color, "a", colors[i].a);
        v7_array_push(v7, *res, color);
    }
    return V7_OK;
}

static inline enum v7_err js_load_image_palette(struct v7* v7, v7_val_t* res) {
    Image image = js_get_image(v7, 0);
    int colorCount = v7_get_int(v7, v7_arg(v7, 2));
    Color* colors = LoadImagePalette(image, v7_get_int(v7, v7_arg(v7, 1)), &colorCount);
    *res = v7_mk_array(v7);
    for (int i = 0; i < colorCount; i++) {
        v7_val_t color = v7_mk_object(v7);
        js_push_val(v7, color, "r", colors[i].r);
        js_push_val(v7, color, "g", colors[i].g);
        js_push_val(v7, color, "b", colors[i].b);
        js_push_val(v7, color, "a", colors[i].a);
        v7_array_push(v7, *res, color);
    }
    return V7_OK;
}

static inline enum v7_err js_unload_image_colors(struct v7* v7) {
    UnloadImageColors((Color*)v7_arg(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_unload_image_palette(struct v7* v7) {
    UnloadImagePalette((Color*)v7_arg(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_get_image_alpha_border(struct v7* v7, v7_val_t* res) {
    js_return_rect(v7, res, GetImageAlphaBorder(js_get_image(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_image_clear_background(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageClearBackground(&image, js_get_color(v7, 1));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_pixel(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDrawPixel(&image, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), js_get_color(v7, 3));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_pixel_v(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDrawPixelV(&image, js_get_vec2(v7, 1), js_get_color(v7, 2));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_line(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDrawLine(&image, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4)), js_get_color(v7, 5));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_line_v(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDrawLineV(&image, js_get_vec2(v7, 1), js_get_vec2(v7, 2), js_get_color(v7, 3));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_circle(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDrawCircle(&image, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), js_get_color(v7, 4));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_circle_v(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDrawCircleV(&image, js_get_vec2(v7, 1), v7_get_int(v7, v7_arg(v7, 2)), js_get_color(v7, 3));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_rectangle(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDrawRectangle(&image, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4)), js_get_color(v7, 5));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_rectangle_v(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDrawRectangleV(&image, js_get_vec2(v7, 1), js_get_vec2(v7, 2), js_get_color(v7, 3));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_rectangle_rec(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDrawRectangleRec(&image, js_get_rect(v7, 1), js_get_color(v7, 2));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_rectangle_lines(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDrawRectangleLines(&image, js_get_rect(v7, 1), v7_get_int(v7, v7_arg(v7, 2)), js_get_color(v7, 3));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    ImageDraw(&image, js_get_image(v7, 1), js_get_rect(v7, 2), js_get_rect(v7, 3), js_get_color(v7, 4));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_text(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    v7_val_t strarg = v7_arg(v7, 1);
    size_t lenstr;
    ImageDrawText(&image, v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4)), js_get_color(v7, 5));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_image_draw_text_ex(struct v7* v7) {
    Image image = js_get_image(v7, 0);
    v7_val_t strarg = v7_arg(v7, 2);
    size_t lenstr;
    ImageDrawTextEx(&image, js_get_font(v7, 1), v7_get_string(v7, &strarg, &lenstr), js_get_vec2(v7, 3), (float)v7_get_double(v7, v7_arg(v7, 4)), (float)v7_get_double(v7, v7_arg(v7, 5)), js_get_color(v7, 6));
    js_update_image(v7, 0, image);
    return V7_OK;
}

static inline enum v7_err js_load_texture(struct v7* v7, v7_val_t* res) {
    char* lenstr;
    v7_val_t filename = v7_arg(v7, 0);
    Texture texture = LoadTexture(v7_get_string(v7, &filename, &lenstr));
    js_return_tex2d(v7, res, texture);
    return V7_OK;
}

static inline enum v7_err js_load_texture_from_image(struct v7* v7, v7_val_t* res) {
    js_return_tex2d(v7, res, LoadTextureFromImage(js_get_image(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_load_texture_cubemap(struct v7* v7, v7_val_t* res) {
    js_return_tex2d(v7, res, LoadTextureCubemap(js_get_image(v7, 0), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_load_render_texture(struct v7* v7, v7_val_t* res) {
    js_return_render_texture_2d(v7, res, LoadRenderTexture(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_unload_texture(struct v7* v7) {
    UnloadTexture(js_get_tex2d(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_unload_render_texture(struct v7* v7) {
    UnloadRenderTexture(js_get_render_texture_2d(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_update_texture(struct v7* v7) {
    UpdateTexture(js_get_tex2d(v7, 0), v7_get_ptr(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_update_texture_rec(struct v7* v7) {
    UpdateTextureRec(js_get_tex2d(v7, 0), js_get_rect(v7, 1), v7_get_ptr(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_get_texture_data(struct v7* v7, v7_val_t* res) {
    js_return_image(v7, res, GetTextureData(js_get_tex2d(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_get_screen_data(struct v7* v7, v7_val_t* res) {
    js_return_image(v7, res, GetScreenData());
    return V7_OK;
}

static inline enum v7_err js_gen_texture_mipmaps(struct v7* v7) {
    Texture texture = js_get_tex2d(v7, 0);
    GenTextureMipmaps(&texture);
    js_update_tex2d(v7, 0, texture);
    return V7_OK;
}

static inline enum v7_err js_set_texture_filter(struct v7* v7) {
    SetTextureFilter(js_get_tex2d(v7, 0), v7_get_int(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_set_texture_wrap(struct v7* v7) {
    SetTextureWrap(js_get_tex2d(v7, 0), v7_get_int(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_draw_texture(struct v7* v7) {
    Texture texture = js_get_tex2d(v7, 0);
    Color color = js_get_color(v7, 3);
    DrawTexture(texture, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), color);
    return V7_OK;
}

static inline enum v7_err js_draw_texture_v(struct v7* v7) {
    DrawTextureV(js_get_tex2d(v7, 0), js_get_vec2(v7, 1), js_get_color(v7, 2));
    return V7_OK;
}

static inline enum v7_err js_draw_texture_ex(struct v7* v7) {
    DrawTextureEx(js_get_tex2d(v7, 0), js_get_vec2(v7, 1), (float)v7_get_double(v7, v7_arg(v7, 2)), (float)v7_get_double(v7, v7_arg(v7, 3)), js_get_color(v7, 4));
    return V7_OK;
}

static inline enum v7_err js_draw_texture_rec(struct v7* v7) {
    DrawTextureRec(js_get_tex2d(v7, 0), js_get_rect(v7, 1), js_get_vec2(v7, 2), js_get_color(v7, 3));
    return V7_OK;
}

static inline enum v7_err js_draw_texture_quad(struct v7* v7) {
    DrawTextureQuad(js_get_tex2d(v7, 0), js_get_vec2(v7, 1), js_get_vec2(v7, 2), js_get_rect(v7, 3), js_get_color(v7, 4));
    return V7_OK;
}

static inline enum v7_err js_draw_texture_tiled(struct v7* v7) {
    DrawTextureTiled(js_get_tex2d(v7, 0), js_get_rect(v7, 1), js_get_rect(v7, 2), js_get_vec2(v7, 3), (float)v7_get_double(v7, v7_arg(v7, 4)), (float)v7_get_double(v7, v7_arg(v7, 5)), js_get_color(v7, 6));
    return V7_OK;
}

static inline enum v7_err js_draw_texture_pro(struct v7* v7) {
    DrawTexturePro(js_get_tex2d(v7, 0), js_get_rect(v7, 1), js_get_rect(v7, 2), js_get_vec2(v7, 3), (float)v7_get_double(v7, v7_arg(v7, 4)), js_get_color(v7, 5));
    return V7_OK;
}

static inline enum v7_err js_draw_texture_npatch(struct v7* v7) {
    DrawTextureNPatch(js_get_tex2d(v7, 0), js_get_npatch_info(v7, 1), js_get_rect(v7, 2), js_get_vec2(v7, 3), (float)v7_get_double(v7, v7_arg(v7, 4)), js_get_color(v7, 5));
    return V7_OK;
}

static inline enum v7_err js_fade(struct v7* v7, v7_val_t* res) {
    js_return_color(v7, res, Fade(js_get_color(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_color_to_int(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (int)ColorToInt(js_get_color(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_color_normalize(struct v7* v7, v7_val_t* res) {
    js_return_vec4(v7, res, ColorNormalize(js_get_color(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_color_from_normalized(struct v7* v7, v7_val_t* res) {
    js_return_color(v7, res, ColorFromNormalized(js_get_vec4(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_color_to_hsv(struct v7* v7, v7_val_t* res) {
    js_return_vec3(v7, res, ColorToHSV(js_get_color(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_color_from_hsv(struct v7* v7, v7_val_t* res) {
    js_return_color(v7, res, ColorFromHSV((float)v7_get_double(v7, v7_arg(v7, 0)), (float)v7_get_double(v7, v7_arg(v7, 1)), (float)v7_get_double(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_color_alpha(struct v7* v7, v7_val_t* res) {
    js_return_color(v7, res, ColorAlpha(js_get_color(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_color_alpha_blend(struct v7* v7, v7_val_t* res) {
    js_return_color(v7, res, ColorAlphaBlend(js_get_color(v7, 0), js_get_color(v7, 1), js_get_color(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_color_get_color(struct v7* v7, v7_val_t* res) {
    js_return_color(v7, res, GetColor(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_get_pixel_color(struct v7* v7, v7_val_t* res) {
    js_return_color(v7, res, GetPixelColor(v7_get_ptr(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_set_pixel_color(struct v7* v7) {
    SetPixelColor(v7_get_ptr(v7, v7_arg(v7, 0)), js_get_color(v7, 1), v7_get_int(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_get_pixel_data_size(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (int)GetPixelDataSize(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

void raylib_v7_load_textures(struct v7* v7) {
    v7_set_method(v7, v7_get_global(v7), "LoadImage", &js_load_image);
    v7_set_method(v7, v7_get_global(v7), "LoadImageRaw", &js_load_image_raw);
    v7_set_method(v7, v7_get_global(v7), "LoadImageAnim", &js_load_image_anim);
    v7_set_method(v7, v7_get_global(v7), "LoadImageFromMemory", &js_load_image_from_memory);
    v7_set_method(v7, v7_get_global(v7), "UnloadImage", &js_unload_image);
    v7_set_method(v7, v7_get_global(v7), "ExportImage", &js_export_image);
    v7_set_method(v7, v7_get_global(v7), "ExportImageAsCode", &js_export_image_as_code);

    v7_set_method(v7, v7_get_global(v7), "GenImageColor", &js_gen_image_color);
    v7_set_method(v7, v7_get_global(v7), "GenImageGradientV", &js_gen_image_gradient_v);
    v7_set_method(v7, v7_get_global(v7), "GenImageGradientH", &js_gen_image_gradient_h);
    v7_set_method(v7, v7_get_global(v7), "GenImageGradientRadial", &js_gen_image_gradient_radial);
    v7_set_method(v7, v7_get_global(v7), "GenImageChecked", &js_gen_image_checked);
    v7_set_method(v7, v7_get_global(v7), "GenImageWhiteNoise", &js_gen_image_white_noise);
    v7_set_method(v7, v7_get_global(v7), "GenImagePerlinNoise", &js_gen_image_perlin_noise);
    v7_set_method(v7, v7_get_global(v7), "GenImageCellular", &js_gen_image_cellular);

    v7_set_method(v7, v7_get_global(v7), "ImageCopy", &js_image_copy);
    v7_set_method(v7, v7_get_global(v7), "ImageFromImage", &js_image_from_image);
    v7_set_method(v7, v7_get_global(v7), "ImageText", &js_image_text);
    v7_set_method(v7, v7_get_global(v7), "ImageTextEx", &js_image_text_ex);
    v7_set_method(v7, v7_get_global(v7), "ImageFormat", &js_image_format);
    v7_set_method(v7, v7_get_global(v7), "ImageToPOT", &js_image_to_pot);
    v7_set_method(v7, v7_get_global(v7), "ImageCrop", &js_image_crop);
    v7_set_method(v7, v7_get_global(v7), "ImageAlphaCrop", &js_image_alpha_crop);
    v7_set_method(v7, v7_get_global(v7), "ImageAlphaClear", &js_image_alpha_clear);
    v7_set_method(v7, v7_get_global(v7), "ImageAlphaMask", &js_image_alpha_mask);
    v7_set_method(v7, v7_get_global(v7), "ImageAlphaPremultiply", &js_image_alpha_premultiply);
    v7_set_method(v7, v7_get_global(v7), "ImageResize", &js_image_resize);
    v7_set_method(v7, v7_get_global(v7), "ImageResizeNN", &js_image_resize_nn);
    v7_set_method(v7, v7_get_global(v7), "ImageResizeCanvas", &js_image_resize_canvas);
    v7_set_method(v7, v7_get_global(v7), "ImageMipmaps", &js_image_mipmaps);
    v7_set_method(v7, v7_get_global(v7), "ImageDither", &js_image_dither);
    v7_set_method(v7, v7_get_global(v7), "ImageFlipVertical", &js_image_flip_vertical);
    v7_set_method(v7, v7_get_global(v7), "ImageFlipHorizontal", &js_image_flip_horizontal);
    v7_set_method(v7, v7_get_global(v7), "ImageRotateCW", &js_image_rotate_cw);
    v7_set_method(v7, v7_get_global(v7), "ImageRotateCCW", &js_image_rotate_ccw);
    v7_set_method(v7, v7_get_global(v7), "ImageColorTint", &js_image_color_tint);
    v7_set_method(v7, v7_get_global(v7), "ImageColorInvert", &js_image_color_invert);
    v7_set_method(v7, v7_get_global(v7), "ImageColorGrayscale", &js_image_color_grayscale);
    v7_set_method(v7, v7_get_global(v7), "ImageColorContrast", &js_image_color_contrast);
    v7_set_method(v7, v7_get_global(v7), "ImageColorBrightness", &js_image_color_brightness);
    v7_set_method(v7, v7_get_global(v7), "ImageColorReplace", &js_image_color_replace);
    v7_set_method(v7, v7_get_global(v7), "LoadImageColors", &js_load_image_colors);
    v7_set_method(v7, v7_get_global(v7), "GetImageData", &js_load_image_colors);
    v7_set_method(v7, v7_get_global(v7), "LoadImagePalette", &js_load_image_palette);
    v7_set_method(v7, v7_get_global(v7), "UnloadImageColors", &js_unload_image_colors);
    v7_set_method(v7, v7_get_global(v7), "UnloadImagePalette", &js_unload_image_palette);
    v7_set_method(v7, v7_get_global(v7), "GetImageAlphaBorder", &js_get_image_alpha_border);

    v7_set_method(v7, v7_get_global(v7), "ImageClearBackground", &js_image_clear_background);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawPixel", &js_image_draw_pixel);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawPixelV", &js_image_draw_pixel_v);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawLine", &js_image_draw_line);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawLineV", &js_image_draw_line_v);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawCircle", &js_image_draw_circle);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawCircleV", &js_image_draw_circle_v);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawRectangle", &js_image_draw_rectangle);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawRectangleV", &js_image_draw_rectangle_v);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawRectangleRec", &js_image_draw_rectangle_rec);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawRectangleLines", &js_image_draw_rectangle_lines);
    v7_set_method(v7, v7_get_global(v7), "ImageDraw", &js_image_draw);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawText", &js_image_draw_text);
    v7_set_method(v7, v7_get_global(v7), "ImageDrawTextEx", &js_image_draw_text_ex);

    v7_set_method(v7, v7_get_global(v7), "LoadTexture", &js_load_texture);
    v7_set_method(v7, v7_get_global(v7), "LoadTextureFromImage", &js_load_texture_from_image);
    v7_set_method(v7, v7_get_global(v7), "LoadTextureCubemap", &js_load_texture_cubemap);
    v7_set_method(v7, v7_get_global(v7), "LoadRenderTexture", &js_load_render_texture);
    v7_set_method(v7, v7_get_global(v7), "UnloadTexture", &js_unload_texture);
    v7_set_method(v7, v7_get_global(v7), "UnloadRenderTexture", &js_unload_render_texture);
    v7_set_method(v7, v7_get_global(v7), "UpdateTexture", &js_update_texture);
    v7_set_method(v7, v7_get_global(v7), "UpdateTextureRec", &js_update_texture_rec);
    v7_set_method(v7, v7_get_global(v7), "GetTextureData", &js_get_texture_data);
    v7_set_method(v7, v7_get_global(v7), "GetScreenData", &js_get_screen_data);

    v7_set_method(v7, v7_get_global(v7), "GenTextureMipmaps", &js_gen_texture_mipmaps);
    v7_set_method(v7, v7_get_global(v7), "SetTextureFilter", &js_set_texture_filter);
    v7_set_method(v7, v7_get_global(v7), "SetTextureWrap", &js_set_texture_wrap);

    v7_set_method(v7, v7_get_global(v7), "DrawTexture", &js_draw_texture);
    v7_set_method(v7, v7_get_global(v7), "DrawTextureV", &js_draw_texture_v);
    v7_set_method(v7, v7_get_global(v7), "DrawTextureEx", &js_draw_texture_ex);
    v7_set_method(v7, v7_get_global(v7), "DrawTextureRec", &js_draw_texture_rec);
    v7_set_method(v7, v7_get_global(v7), "DrawTextureQuad", &js_draw_texture_quad);
    v7_set_method(v7, v7_get_global(v7), "DrawTextureTiled", &js_draw_texture_tiled);
    v7_set_method(v7, v7_get_global(v7), "DrawTexturePro", &js_draw_texture_pro);
    v7_set_method(v7, v7_get_global(v7), "DrawTextureNPatch", &js_draw_texture_npatch);

    v7_set_method(v7, v7_get_global(v7), "Fade", &js_fade);
    v7_set_method(v7, v7_get_global(v7), "ColorToInt", &js_color_to_int);
    v7_set_method(v7, v7_get_global(v7), "ColorNormalize", &js_color_normalize);
    v7_set_method(v7, v7_get_global(v7), "ColorFromNormalized", &js_color_from_normalized);
    v7_set_method(v7, v7_get_global(v7), "ColorToHSV", &js_color_to_hsv);
    v7_set_method(v7, v7_get_global(v7), "ColorFromHSV", &js_color_from_hsv);
    v7_set_method(v7, v7_get_global(v7), "ColorAlpha", &js_color_alpha);
    v7_set_method(v7, v7_get_global(v7), "ColorAlphaBlend", &js_color_alpha_blend);
    v7_set_method(v7, v7_get_global(v7), "GetColor", &js_color_get_color);
    v7_set_method(v7, v7_get_global(v7), "GetPixelColor", &js_get_pixel_color);
    v7_set_method(v7, v7_get_global(v7), "SetPixelColor", &js_set_pixel_color);
    v7_set_method(v7, v7_get_global(v7), "GetPixelDataSize", &js_get_pixel_data_size);
}
