#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>
#include <text_js.h>

static inline enum v7_err js_get_font_default(struct v7* v7, v7_val_t* res) {
    js_return_font(v7, res, GetFontDefault());
    return V7_OK;
}

static inline enum v7_err js_load_font(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    js_return_font(v7, res, LoadFont(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_load_font_ex(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    int fontChars = v7_get_int(v7, v7_arg(v7, 2));
    js_return_font(v7, res, LoadFontEx(v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 1)), &fontChars, v7_get_int(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_load_font_from_image(struct v7* v7, v7_val_t* res) {
    js_return_font(v7, res, LoadFontFromImage(js_get_image(v7, 0), js_get_color(v7, 1), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_load_font_from_memory(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr0;
    v7_val_t strarg1 = v7_arg(v7, 1);
    size_t lenstr1;
    const char* fileType = v7_get_string(v7, &strarg0, &lenstr0);
    const unsigned char* fileData = v7_get_string(v7, &strarg1, &lenstr1);
    int dataSize = v7_get_int(v7, v7_arg(v7, 2));
    int fontSize = v7_get_int(v7, v7_arg(v7, 3));
    int fontChars = v7_get_int(v7, v7_arg(v7, 4));
    int charsCount = v7_get_int(v7, v7_arg(v7, 5));
    js_return_font(v7, res, LoadFontFromMemory(fileType, fileData, dataSize, fontSize, &fontChars, charsCount));
    return V7_OK;
}

static inline enum v7_err js_load_font_data(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr0;
    v7_val_t strarg1 = v7_arg(v7, 1);
    size_t lenstr1;
    const char* fileType = v7_get_string(v7, &strarg0, &lenstr0);
    const unsigned char* fileData = v7_get_string(v7, &strarg1, &lenstr1);
    int dataSize = v7_get_int(v7, v7_arg(v7, 2));
    int fontSize = v7_get_int(v7, v7_arg(v7, 3));
    int fontChars = v7_get_int(v7, v7_arg(v7, 4));
    int charsCount = v7_get_int(v7, v7_arg(v7, 5));
    CharInfo* result = LoadFontData(&fileData, dataSize, fontSize, &fontChars, charsCount, fileType);
    *res = result;
    return V7_OK;
}

static inline enum v7_err js_gen_image_font_atlas(struct v7* v7, v7_val_t* res) {
    CharInfo chars_info = js_get_char_info(v7, 0);
    Rectangle recs = js_get_rect(v7, 1);
    js_return_image(v7, res, GenImageFontAtlas(&chars_info, &recs, v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)), v7_get_int(v7, v7_arg(v7, 4)), v7_get_int(v7, v7_arg(v7, 5))));
    return V7_OK;
}

static inline enum v7_err js_unload_font_data(struct v7* v7) {
    CharInfo chars_info = js_get_char_info(v7, 0);
    UnloadFontData(&chars_info, v7_get_int(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_unload_font(struct v7* v7) {
    UnloadFont(js_get_font(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_draw_fps(struct v7* v7) {
    DrawFPS(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_draw_text(struct v7* v7) {
    size_t lenstr;
    v7_val_t text_str = v7_arg(v7, 0);
    char* text = v7_get_string(v7, &text_str, &lenstr);
    int x = v7_get_int(v7, v7_arg(v7, 1));
    int y = v7_get_int(v7, v7_arg(v7, 2));
    int font_size = v7_get_int(v7, v7_arg(v7, 3));
    Color color = js_get_color(v7, 4);
    DrawText(text, x, y, font_size, color);
    return V7_OK;
}

static inline enum v7_err js_draw_text_ex(struct v7* v7) {
    size_t lenstr;
    Font font = js_get_font(v7, 0);
    v7_val_t text_str = v7_arg(v7, 1);
    char* text = v7_get_string(v7, &text_str, &lenstr);
    Vector2 position = js_get_vec2(v7, 2);
    float font_size = (float)v7_get_double(v7, v7_arg(v7, 3));
    float spacing = (float)v7_get_double(v7, v7_arg(v7, 4));
    Color tint = js_get_color(v7, 5);
    DrawTextEx(font, text, position, font_size, spacing, tint);
    return V7_OK;
}

static inline enum v7_err js_draw_text_rec(struct v7* v7) {
    size_t lenstr;
    Font font = js_get_font(v7, 0);
    v7_val_t text_str = v7_arg(v7, 1);
    char* text = v7_get_string(v7, &text_str, &lenstr);
    Rectangle rec = js_get_rect(v7, 2);
    float font_size = (float)v7_get_double(v7, v7_arg(v7, 3));
    float spacing = (float)v7_get_double(v7, v7_arg(v7, 4));
    bool wordWrap = (bool)v7_get_bool(v7, v7_arg(v7, 5));
    Color tint = js_get_color(v7, 6);
    DrawTextRec(font, text, rec, font_size, spacing, wordWrap, tint);
    return V7_OK;
}

static inline enum v7_err js_draw_text_rec_ex(struct v7* v7) {
    size_t lenstr;
    Font font = js_get_font(v7, 0);
    v7_val_t text_str = v7_arg(v7, 1);
    char* text = v7_get_string(v7, &text_str, &lenstr);
    Rectangle rec = js_get_rect(v7, 2);
    float font_size = (float)v7_get_double(v7, v7_arg(v7, 3));
    float spacing = (float)v7_get_double(v7, v7_arg(v7, 4));
    bool wordWrap = (bool)v7_get_bool(v7, v7_arg(v7, 5));
    Color tint = js_get_color(v7, 6);
    int selectStart = v7_get_int(v7, v7_arg(v7, 7));
    int selectLength = v7_get_int(v7, v7_arg(v7, 8));
    Color selectTint = js_get_color(v7, 9);
    Color selectBackTint = js_get_color(v7, 10);
    DrawTextRecEx(font, text, rec, font_size, spacing, wordWrap, tint, selectStart, selectLength, selectTint, selectBackTint);
    return V7_OK;
}

static inline enum v7_err js_draw_text_codepoint(struct v7* v7) {
    DrawTextCodepoint(js_get_font(v7, 0), v7_get_int(v7, v7_arg(v7, 1)), js_get_vec2(v7, 2), (float)v7_get_double(v7, v7_arg(v7, 3)), js_get_color(v7, 4));
    return V7_OK;
}

static inline enum v7_err js_measure_text(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t text_str = v7_arg(v7, 0);
    *res = v7_mk_number(v7, (int)MeasureText(v7_get_string(v7, &text_str, &lenstr), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_measure_text_ex(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t text_str = v7_arg(v7, 1);
    js_return_vec2(v7, res, MeasureTextEx(js_get_font(v7, 0), v7_get_string(v7, &text_str, &lenstr), (float)v7_get_double(v7, v7_arg(v7, 2)), (float)v7_get_double(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_get_glyph_index(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t text_str = v7_arg(v7, 1);
    *res = v7_mk_number(v7, (int)GetGlyphIndex(js_get_font(v7, 0), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_text_copy(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 1);
    *res = v7_mk_number(v7, (int)TextCopy(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1)));
    return V7_OK;
}

static inline enum v7_err js_text_is_equal(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (bool)TextIsEqual(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1)));
    return V7_OK;
}

static inline enum v7_err js_text_length(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    *res = v7_mk_number(v7, (int)TextLength(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_text_format(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 1);
    *res = v7_mk_string(v7, TextFormat(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_text_subtext(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    *res = v7_mk_string(v7, TextSubtext(v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_text_replace(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 1);
    size_t lenstr2;
    v7_val_t strarg2 = v7_arg(v7, 2);
    *res = v7_mk_string(v7, TextReplace(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1), v7_get_string(v7, &strarg2, &lenstr2)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_text_insert(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 1);
    *res = v7_mk_string(v7, TextInsert(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1), v7_get_int(v7, v7_arg(v7, 2))), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_text_join(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 2);
    char** textList = v7_get_string(v7, &strarg0, &lenstr0);
    *res = v7_mk_string(v7, TextJoin(textList, v7_get_int(v7, v7_arg(v7, 1)), v7_get_string(v7, &strarg1, &lenstr1)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_text_split(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    char** textList = v7_get_string(v7, &strarg0, &lenstr0);
    int count = v7_get_int(v7, v7_arg(v7, 2));
    *res = (char**)v7_mk_string(v7, TextSplit(textList, v7_get_int(v7, v7_arg(v7, 1)), &count), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_text_append(struct v7* v7) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 1);
    int position = v7_get_int(v7, v7_arg(v7, 2));
    TextAppend(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1), &position);
    return V7_OK;
}

static inline enum v7_err js_text_find_index(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 0);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 1);
    *res = v7_mk_number(v7, (int)TextFindIndex(v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1)));
    return V7_OK;
}

static inline enum v7_err js_text_to_upper(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    *res = v7_mk_string(v7, TextToUpper(v7_get_string(v7, &strarg, &lenstr)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_text_to_lower(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    *res = v7_mk_string(v7, TextToLower(v7_get_string(v7, &strarg, &lenstr)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_text_to_pascal(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    *res = v7_mk_string(v7, TextToPascal(v7_get_string(v7, &strarg, &lenstr)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_text_to_integer(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    *res = v7_mk_number(v7, (int)TextToInteger(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_text_to_utf8(struct v7* v7, v7_val_t* res) {
    int* codepoints = v7_get_int(v7, v7_arg(v7, 1));
    *res = v7_mk_string(v7, TextToUtf8(&codepoints, v7_get_int(v7, v7_arg(v7, 1))), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_get_codepoints(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    int count = v7_get_int(v7, v7_arg(v7, 1));
    *res = GetCodepoints(v7_get_string(v7, &strarg, &lenstr), &count);
    return V7_OK;
}

static inline enum v7_err js_get_codepoints_count(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    *res = v7_mk_number(v7, (int)GetCodepointsCount(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_get_next_codepoint(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    int bytesProcessed = v7_get_int(v7, v7_arg(v7, 1));
    *res = v7_mk_number(v7, (int)GetNextCodepoint(v7_get_string(v7, &strarg, &lenstr), &bytesProcessed));
    return V7_OK;
}

static inline enum v7_err js_codepoint_to_utf8(struct v7* v7, v7_val_t* res) {
    int codepoint = v7_get_int(v7, v7_arg(v7, 0));
    int byteLength = v7_get_int(v7, v7_arg(v7, 1));
    *res = v7_mk_string(v7, CodepointToUtf8(codepoint, &byteLength), ~0, 0);
    return V7_OK;
}

void raylib_v7_load_text(struct v7* v7) {
    v7_set_method(v7, v7_get_global(v7), "GetFontDefault", &js_get_font_default);
    v7_set_method(v7, v7_get_global(v7), "LoadFont", &js_load_font);
    v7_set_method(v7, v7_get_global(v7), "LoadFontEx", &js_load_font_ex);
    v7_set_method(v7, v7_get_global(v7), "LoadFontFromImage", &js_load_font_from_image);
    v7_set_method(v7, v7_get_global(v7), "LoadFontFromMemory", &js_load_font_from_memory);
    v7_set_method(v7, v7_get_global(v7), "LoadFontData", &js_load_font_data);
    v7_set_method(v7, v7_get_global(v7), "GenImageFontAtlas", &js_gen_image_font_atlas);
    v7_set_method(v7, v7_get_global(v7), "UnloadFontData", &js_unload_font_data);
    v7_set_method(v7, v7_get_global(v7), "UnloadFont", &js_unload_font);

    v7_set_method(v7, v7_get_global(v7), "DrawFPS", &js_draw_fps);
    v7_set_method(v7, v7_get_global(v7), "DrawText", &js_draw_text);
    v7_set_method(v7, v7_get_global(v7), "DrawTextEx", &js_draw_text_ex);
    v7_set_method(v7, v7_get_global(v7), "DrawTextRec", &js_draw_text_rec);
    v7_set_method(v7, v7_get_global(v7), "DrawTextRecEx", &js_draw_text_rec_ex);
    v7_set_method(v7, v7_get_global(v7), "DrawTextCodepoint", &js_draw_text_codepoint);

    v7_set_method(v7, v7_get_global(v7), "MeasureText", &js_measure_text);
    v7_set_method(v7, v7_get_global(v7), "MeasureTextEx", &js_measure_text_ex);
    v7_set_method(v7, v7_get_global(v7), "GetGlyphIndex", &js_get_glyph_index);

    v7_set_method(v7, v7_get_global(v7), "TextCopy", &js_text_copy);
    v7_set_method(v7, v7_get_global(v7), "TextIsEqual", &js_text_is_equal);
    v7_set_method(v7, v7_get_global(v7), "TextLength", &js_text_length);
    v7_set_method(v7, v7_get_global(v7), "TextFormat", &js_text_format);
    v7_set_method(v7, v7_get_global(v7), "FormatText", &js_text_format);
    v7_set_method(v7, v7_get_global(v7), "TextSubtext", &js_text_subtext);
    v7_set_method(v7, v7_get_global(v7), "TextReplace", &js_text_replace);
    v7_set_method(v7, v7_get_global(v7), "TextInsert", &js_text_insert);
    v7_set_method(v7, v7_get_global(v7), "TextJoin", &js_text_join);
    v7_set_method(v7, v7_get_global(v7), "TextSplit", &js_text_split);
    v7_set_method(v7, v7_get_global(v7), "TextAppend", &js_text_append);
    v7_set_method(v7, v7_get_global(v7), "TextFindIndex", &js_text_find_index);
    v7_set_method(v7, v7_get_global(v7), "TextToUpper", &js_text_to_upper);
    v7_set_method(v7, v7_get_global(v7), "TextToLower", &js_text_to_lower);
    v7_set_method(v7, v7_get_global(v7), "TextToPascal", &js_text_to_pascal);
    v7_set_method(v7, v7_get_global(v7), "TextToInteger", &js_text_to_integer);
    v7_set_method(v7, v7_get_global(v7), "TextToUtf8", &js_text_to_utf8);

    v7_set_method(v7, v7_get_global(v7), "GetCodepoints", &js_get_codepoints);
    v7_set_method(v7, v7_get_global(v7), "GetCodepointsCount", &js_get_codepoints_count);
    v7_set_method(v7, v7_get_global(v7), "GetNextCodepoint", &js_get_next_codepoint);
    v7_set_method(v7, v7_get_global(v7), "CodepointToUtf8", &js_codepoint_to_utf8);
}
