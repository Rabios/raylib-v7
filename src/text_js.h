#ifndef RAYLIB_V7_TEXT
#define RAYLIB_V7_TEXT

#include <v7/v7.h>

static inline enum v7_err js_get_font_default(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_font(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_font_ex(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_font_from_image(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_font_from_memory(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_font_data(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gen_image_font_atlas(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_font_data(struct v7* v7);
static inline enum v7_err js_unload_font(struct v7* v7);

static inline enum v7_err js_draw_fps(struct v7* v7);
static inline enum v7_err js_draw_text(struct v7* v7);
static inline enum v7_err js_draw_text_ex(struct v7* v7);
static inline enum v7_err js_draw_text_rec(struct v7* v7);
static inline enum v7_err js_draw_text_rec_ex(struct v7* v7);
static inline enum v7_err js_draw_text_codepoint(struct v7* v7);

static inline enum v7_err js_measure_text(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_measure_text_ex(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_glyph_index(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_text_copy(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_is_equal(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_length(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_format(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_subtext(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_replace(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_insert(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_join(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_split(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_append(struct v7* v7);
static inline enum v7_err js_text_find_index(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_to_upper(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_to_lower(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_to_pascal(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_to_integer(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_text_to_utf8(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_get_codepoints(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_codepoints_count(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_next_codepoint(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_codepoint_to_utf8(struct v7* v7, v7_val_t* res);

void raylib_v7_load_text(struct v7* v7);

#endif