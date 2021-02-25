#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#define GUI_TEXTBOX_EXTENDED_IMPLEMENTATION

#include <raylib.h>
#include <raygui/raygui.h>
#include <raygui/gui_textbox_extended.h>
#include <v7/v7.h>
#include <get_set.h>
#include <raygui_js.h>

static inline enum v7_err js_gui_enable(void) {
    GuiEnable();
    return V7_OK;
}

static inline enum v7_err js_gui_disable(void) {
    GuiDisable();
    return V7_OK;
}

static inline enum v7_err js_gui_lock(void) {
    GuiLock();
    return V7_OK;
}

static inline enum v7_err js_gui_unlock(void) {
    GuiUnlock();
    return V7_OK;
}

static inline enum v7_err js_gui_fade(struct v7* v7) {
    GuiFade((float)v7_get_double(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_gui_set_state(struct v7* v7) {
    GuiSetState(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_gui_get_state(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (int)GuiGetState());
    return V7_OK;
}

static inline enum v7_err js_gui_set_font(struct v7* v7) {
    GuiSetFont(js_get_font(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_gui_get_font(struct v7* v7, v7_val_t* res) {
    js_return_font(v7, res, GuiGetFont());
    return V7_OK;
}

static inline enum v7_err js_gui_set_style(struct v7* v7) {
    GuiSetStyle(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_gui_get_style(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (int)GuiGetStyle(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_gui_enable_tooltip(void) {
    GuiEnableTooltip();
    return V7_OK;
}

static inline enum v7_err js_gui_disable_tooltip(void) {
    GuiDisableTooltip();
    return V7_OK;
}

static inline enum v7_err js_gui_set_tooltip(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    GuiSetTooltip(v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_gui_clear_tooltip(void) {
    GuiClearTooltip();
    return V7_OK;
}

static inline enum v7_err js_gui_window_box(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)GuiWindowBox(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_gui_group_box(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    GuiGroupBox(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_gui_line(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    GuiLine(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_gui_panel(struct v7* v7) {
    GuiPanel(js_get_rect(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_gui_scroll_panel(struct v7* v7, v7_val_t* res) {
    Vector2 scroll = js_get_vec2(v7, 2);
    js_return_rect(v7, res, GuiScrollPanel(js_get_rect(v7, 0), js_get_rect(v7, 1), &scroll));
    return V7_OK;
}

static inline enum v7_err js_gui_label(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    GuiLabel(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_gui_button(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)GuiButton(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_gui_label_button(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)GuiLabelButton(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_gui_image_button(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)GuiImageButton(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), js_get_tex2d(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_gui_image_button_ex(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)GuiImageButtonEx(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), js_get_tex2d(v7, 2), js_get_rect(v7, 3)));
    return V7_OK;
}

static inline enum v7_err js_gui_toggle(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)GuiToggle(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), (bool)v7_get_bool(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gui_toggle_group(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_number(v7, (int)GuiToggleGroup(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gui_check_box(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)GuiCheckBox(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), (bool)v7_get_bool(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gui_combo_box(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_number(v7, (int)GuiComboBox(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gui_dropdown_box(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    int active = v7_get_int(v7, v7_arg(v7, 2));
    *res = v7_mk_boolean(v7, (int)GuiDropdownBox(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), &active, (bool)v7_get_bool(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gui_spinner(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    int value = v7_get_int(v7, v7_arg(v7, 2));
    int minValue = v7_get_int(v7, v7_arg(v7, 3));
    int maxValue = v7_get_int(v7, v7_arg(v7, 4));
    *res = v7_mk_boolean(v7, (int)GuiSpinner(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), &value, minValue, maxValue, (bool)v7_get_bool(v7, v7_arg(v7, 5))));
    return V7_OK;
}

static inline enum v7_err js_gui_value_box(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    int value = v7_get_int(v7, v7_arg(v7, 2));
    int minValue = v7_get_int(v7, v7_arg(v7, 3));
    int maxValue = v7_get_int(v7, v7_arg(v7, 4));
    *res = v7_mk_boolean(v7, (int)GuiValueBox(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), &value, minValue, maxValue, (bool)v7_get_bool(v7, v7_arg(v7, 5))));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)GuiTextBox(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 2)), (bool)v7_get_bool(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_multi(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)GuiTextBoxMulti(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 2)), (bool)v7_get_bool(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gui_slider(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 1);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 2);
    *res = v7_mk_number(v7, (float)GuiSlider(js_get_rect(v7, 0), v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1), (float)v7_get_double(v7, v7_arg(v7, 3)), (float)v7_get_double(v7, v7_arg(v7, 4)), (float)v7_get_double(v7, v7_arg(v7, 5))));
    return V7_OK;
}

static inline enum v7_err js_gui_slider_bar(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 1);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 2);
    *res = v7_mk_number(v7, (float)GuiSliderBar(js_get_rect(v7, 0), v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1), (float)v7_get_double(v7, v7_arg(v7, 3)), (float)v7_get_double(v7, v7_arg(v7, 4)), (float)v7_get_double(v7, v7_arg(v7, 5))));
    return V7_OK;
}

static inline enum v7_err js_gui_progress_bar(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 1);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 2);
    *res = v7_mk_number(v7, (float)GuiProgressBar(js_get_rect(v7, 0), v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1), (float)v7_get_double(v7, v7_arg(v7, 3)), (float)v7_get_double(v7, v7_arg(v7, 4)), (float)v7_get_double(v7, v7_arg(v7, 5))));
    return V7_OK;
}

static inline enum v7_err js_gui_status_bar(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    GuiStatusBar(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_gui_dummy_rec(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    GuiDummyRec(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_gui_scroll_bar(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (int)GuiScrollBar(js_get_rect(v7, 0), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gui_grid(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, GuiGrid(js_get_rect(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gui_list_view(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    int scrollIndex = v7_get_int(v7, v7_arg(v7, 2));
    *res = v7_mk_number(v7, (int)GuiListView(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), &scrollIndex, v7_get_int(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gui_list_view_ex(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    int focus = v7_get_int(v7, v7_arg(v7, 3));
    int scrollIndex = v7_get_int(v7, v7_arg(v7, 4));
    char* str = v7_get_string(v7, &strarg, &lenstr);
    *res = v7_mk_number(v7, (int)GuiListViewEx(js_get_rect(v7, 0), &str, v7_get_int(v7, v7_arg(v7, 2)), &focus, &scrollIndex, v7_get_int(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gui_message_box(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 1);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 2);
    size_t lenstr2;
    v7_val_t strarg2 = v7_arg(v7, 3);
    *res = v7_mk_number(v7, (int)GuiMessageBox(js_get_rect(v7, 0), v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1), v7_get_string(v7, &strarg2, &lenstr2)));
    return V7_OK;
}

static inline enum v7_err js_gui_text_input_box(struct v7* v7, v7_val_t* res) {
    size_t lenstr0;
    v7_val_t strarg0 = v7_arg(v7, 1);
    size_t lenstr1;
    v7_val_t strarg1 = v7_arg(v7, 2);
    size_t lenstr2;
    v7_val_t strarg2 = v7_arg(v7, 3);
    size_t lenstr3;
    v7_val_t strarg3 = v7_arg(v7, 4);
    *res = v7_mk_number(v7, (int)GuiTextInputBox(js_get_rect(v7, 0), v7_get_string(v7, &strarg0, &lenstr0), v7_get_string(v7, &strarg1, &lenstr1), v7_get_string(v7, &strarg2, &lenstr2), v7_get_string(v7, &strarg3, &lenstr3)));
    return V7_OK;
}

static inline enum v7_err js_gui_color_picker(struct v7* v7, v7_val_t* res) {
    js_return_color(v7, res, GuiColorPicker(js_get_rect(v7, 0), js_get_color(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_gui_color_panel(struct v7* v7, v7_val_t* res) {
    js_return_color(v7, res, GuiColorPanel(js_get_rect(v7, 0), js_get_color(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_gui_color_bar_alpha(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (float)GuiColorBarAlpha(js_get_rect(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_gui_color_bar_hue(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (float)GuiColorBarHue(js_get_rect(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1))));
    return V7_OK;
}

static inline enum v7_err js_gui_load_style(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    GuiLoadStyle(v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_gui_load_style_default(void) {
    GuiLoadStyleDefault();
    return V7_OK;
}

static inline enum v7_err js_gui_icon_text(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_string(v7, GuiIconText(v7_get_int(v7, v7_arg(v7, 0)), v7_get_string(v7, &strarg, &lenstr)), ~0, 0);
    return V7_OK;
}

static inline enum v7_err js_gui_draw_icon(struct v7* v7) {
    GuiDrawIcon(v7_get_int(v7, v7_arg(v7, 0)), js_get_vec2(v7, 1), v7_get_int(v7, v7_arg(v7, 2)), js_get_color(v7, 3));
    return V7_OK;
}

static inline enum v7_err js_gui_get_icons(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_foreign(v7, GuiGetIcons());
    return V7_OK;
}

static inline enum v7_err js_gui_get_icon_data(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_foreign(v7, GuiGetIconData(v7_get_int(v7, v7_arg(v7, 0))));
    return V7_OK;
}

static inline enum v7_err js_gui_set_icon_data(struct v7* v7) {
    int iconId = v7_get_int(v7, v7_arg(v7, 0));
    unsigned int* icon_data = v7_get_int(v7, v7_arg(v7, 1));
    GuiSetIconData(iconId, icon_data);
    return V7_OK;
}

static inline enum v7_err js_gui_set_icon_pixel(struct v7* v7) {
    int iconId = v7_get_int(v7, v7_arg(v7, 0));
    int x = v7_get_int(v7, v7_arg(v7, 1));
    int y = v7_get_int(v7, v7_arg(v7, 2));
    GuiSetIconPixel(iconId, x, y);
    return V7_OK;
}

static inline enum v7_err js_gui_clear_icon_pixel(struct v7* v7) {
    int iconId = v7_get_int(v7, v7_arg(v7, 0));
    int x = v7_get_int(v7, v7_arg(v7, 1));
    int y = v7_get_int(v7, v7_arg(v7, 2));
    GuiClearIconPixel(iconId, x, y);
    return V7_OK;
}

static inline enum v7_err js_gui_check_icon_pixel(struct v7* v7, v7_val_t* res) {
    int iconId = v7_get_int(v7, v7_arg(v7, 0));
    int x = v7_get_int(v7, v7_arg(v7, 1));
    int y = v7_get_int(v7, v7_arg(v7, 2));
    *res = v7_mk_boolean(v7, (int)GuiCheckIconPixel(iconId, x, y));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_set_active(struct v7* v7) {
    GuiTextBoxSetActive(js_get_rect(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_get_active(struct v7* v7, v7_val_t* res) {
    js_return_rect(v7, res, GuiTextBoxGetActive());
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_set_cursor(struct v7* v7) {
    GuiTextBoxSetCursor(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_get_cursor(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, (int)GuiTextBoxGetCursor());
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_set_selection(struct v7* v7) {
    GuiTextBoxSetSelection(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_get_selection(struct v7* v7, v7_val_t* res) {
    js_return_vec2(v7, res, GuiTextBoxGetSelection());
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_is_active(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)GuiTextBoxIsActive(js_get_rect(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_get_state(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_object(v7);
    GuiTextBoxState state = GuiTextBoxGetState();
    v7_set(v7, *res, "cursor", ~0, v7_mk_number(v7, (int)state.cursor));
    v7_set(v7, *res, "start", ~0, v7_mk_number(v7, (int)state.start));
    v7_set(v7, *res, "index", ~0, v7_mk_number(v7, (int)state.index));
    v7_set(v7, *res, "select", ~0, v7_mk_number(v7, (int)state.select));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_set_state(struct v7* v7) {
    GuiTextBoxState state = (GuiTextBoxState){
        v7_get(v7, v7_arg(v7, 0), "cursor", ~0),
        v7_get(v7, v7_arg(v7, 0), "start", ~0),
        v7_get(v7, v7_arg(v7, 0), "index", ~0),
        v7_get(v7, v7_arg(v7, 0), "select", ~0),
    };
    GuiTextBoxSetState(state);
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_select_all(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    GuiTextBoxSelectAll(v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_copy(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    GuiTextBoxCopy(v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_paste(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    GuiTextBoxPaste(v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_cut(struct v7* v7) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    GuiTextBoxCut(v7_get_string(v7, &strarg, &lenstr));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_delete(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    *res = v7_mk_number(v7, (int)GuiTextBoxDelete(v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 1)), (bool)v7_get_bool(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_get_byte_index(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 0);
    *res = v7_mk_number(v7, (int)GuiTextBoxGetByteIndex(v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3))));
    return V7_OK;
}

static inline enum v7_err js_gui_text_box_ex(struct v7* v7, v7_val_t* res) {
    size_t lenstr;
    v7_val_t strarg = v7_arg(v7, 1);
    *res = v7_mk_boolean(v7, (int)GuiTextBoxEx(js_get_rect(v7, 0), v7_get_string(v7, &strarg, &lenstr), v7_get_int(v7, v7_arg(v7, 2)), (bool)v7_get_bool(v7, v7_arg(v7, 3))));
    return V7_OK;
}

void raylib_v7_load_raygui(struct v7* v7) {
    js_push_val(v7, v7_get_global(v7), "RAYGUI_VERSION", v7_mk_string(v7, RAYGUI_VERSION, ~0, 0));
    js_push_key(v7, v7_get_global(v7), "GUI_STATE_NORMAL", GUI_STATE_NORMAL);
    js_push_key(v7, v7_get_global(v7), "GUI_STATE_FOCUSED", GUI_STATE_FOCUSED);
    js_push_key(v7, v7_get_global(v7), "GUI_STATE_PRESSED", GUI_STATE_PRESSED);
    js_push_key(v7, v7_get_global(v7), "GUI_STATE_DISABLED", GUI_STATE_DISABLED);
    js_push_key(v7, v7_get_global(v7), "GUI_TEXT_ALIGN_LEFT", GUI_TEXT_ALIGN_LEFT);
    js_push_key(v7, v7_get_global(v7), "GUI_TEXT_ALIGN_CENTER", GUI_TEXT_ALIGN_CENTER);
    js_push_key(v7, v7_get_global(v7), "GUI_TEXT_ALIGN_RIGHT", GUI_TEXT_ALIGN_RIGHT);
    js_push_key(v7, v7_get_global(v7), "DEFAULT", DEFAULT);
    js_push_key(v7, v7_get_global(v7), "LABEL", LABEL);
    js_push_key(v7, v7_get_global(v7), "BUTTON", BUTTON);
    js_push_key(v7, v7_get_global(v7), "TOGGLE", TOGGLE);
    js_push_key(v7, v7_get_global(v7), "SLIDER", SLIDER);
    js_push_key(v7, v7_get_global(v7), "PROGRESSBAR", PROGRESSBAR);
    js_push_key(v7, v7_get_global(v7), "CHECKBOX", CHECKBOX);
    js_push_key(v7, v7_get_global(v7), "COMBOBOX", COMBOBOX);
    js_push_key(v7, v7_get_global(v7), "DROPDOWNBOX", DROPDOWNBOX);
    js_push_key(v7, v7_get_global(v7), "TEXTBOX", TEXTBOX);
    js_push_key(v7, v7_get_global(v7), "VALUEBOX", VALUEBOX);
    js_push_key(v7, v7_get_global(v7), "SPINNER", SPINNER);
    js_push_key(v7, v7_get_global(v7), "LISTVIEW", LISTVIEW);
    js_push_key(v7, v7_get_global(v7), "COLORPICKER", COLORPICKER);
    js_push_key(v7, v7_get_global(v7), "SCROLLBAR", SCROLLBAR);
    js_push_key(v7, v7_get_global(v7), "STATUSBAR", STATUSBAR);
    js_push_key(v7, v7_get_global(v7), "BORDER_COLOR_NORMAL", BORDER_COLOR_NORMAL);
    js_push_key(v7, v7_get_global(v7), "BASE_COLOR_NORMAL", BASE_COLOR_NORMAL);
    js_push_key(v7, v7_get_global(v7), "TEXT_COLOR_NORMAL", TEXT_COLOR_NORMAL);
    js_push_key(v7, v7_get_global(v7), "BORDER_COLOR_FOCUSED", BORDER_COLOR_FOCUSED);
    js_push_key(v7, v7_get_global(v7), "BASE_COLOR_FOCUSED", BASE_COLOR_FOCUSED);
    js_push_key(v7, v7_get_global(v7), "TEXT_COLOR_FOCUSED", TEXT_COLOR_FOCUSED);
    js_push_key(v7, v7_get_global(v7), "BORDER_COLOR_PRESSED", BORDER_COLOR_PRESSED);
    js_push_key(v7, v7_get_global(v7), "BASE_COLOR_PRESSED", BASE_COLOR_PRESSED);
    js_push_key(v7, v7_get_global(v7), "TEXT_COLOR_PRESSED", TEXT_COLOR_PRESSED);
    js_push_key(v7, v7_get_global(v7), "BORDER_COLOR_DISABLED", BORDER_COLOR_DISABLED);
    js_push_key(v7, v7_get_global(v7), "BASE_COLOR_DISABLED", BASE_COLOR_DISABLED);
    js_push_key(v7, v7_get_global(v7), "TEXT_COLOR_DISABLED", TEXT_COLOR_DISABLED);
    js_push_key(v7, v7_get_global(v7), "BORDER_WIDTH", BORDER_WIDTH);
    js_push_key(v7, v7_get_global(v7), "TEXT_PADDING", TEXT_PADDING);
    js_push_key(v7, v7_get_global(v7), "TEXT_ALIGNMENT", TEXT_ALIGNMENT);
    js_push_key(v7, v7_get_global(v7), "RESERVED", RESERVED);
    js_push_key(v7, v7_get_global(v7), "TEXT_SIZE", TEXT_SIZE);
    js_push_key(v7, v7_get_global(v7), "TEXT_SPACING", TEXT_SPACING);
    js_push_key(v7, v7_get_global(v7), "LINE_COLOR", LINE_COLOR);
    js_push_key(v7, v7_get_global(v7), "BACKGROUND_COLOR", BACKGROUND_COLOR);
    js_push_key(v7, v7_get_global(v7), "GROUP_PADDING", GROUP_PADDING);
    js_push_key(v7, v7_get_global(v7), "SLIDER_WIDTH", SLIDER_WIDTH);
    js_push_key(v7, v7_get_global(v7), "SLIDER_PADDING", SLIDER_PADDING);
    js_push_key(v7, v7_get_global(v7), "PROGRESS_PADDING", PROGRESS_PADDING);
    js_push_key(v7, v7_get_global(v7), "CHECK_PADDING", CHECK_PADDING);
    js_push_key(v7, v7_get_global(v7), "COMBO_BUTTON_WIDTH", COMBO_BUTTON_WIDTH);
    js_push_key(v7, v7_get_global(v7), "COMBO_BUTTON_PADDING", COMBO_BUTTON_PADDING);
    js_push_key(v7, v7_get_global(v7), "ARROW_PADDING", ARROW_PADDING);
    js_push_key(v7, v7_get_global(v7), "DROPDOWN_ITEMS_PADDING", DROPDOWN_ITEMS_PADDING);
    js_push_key(v7, v7_get_global(v7), "TEXT_INNER_PADDING", TEXT_INNER_PADDING);
    js_push_key(v7, v7_get_global(v7), "TEXT_LINES_PADDING", TEXT_LINES_PADDING);
    js_push_key(v7, v7_get_global(v7), "COLOR_SELECTED_FG", COLOR_SELECTED_FG);
    js_push_key(v7, v7_get_global(v7), "COLOR_SELECTED_BG", COLOR_SELECTED_BG);
    js_push_key(v7, v7_get_global(v7), "SPIN_BUTTON_WIDTH", SPIN_BUTTON_WIDTH);
    js_push_key(v7, v7_get_global(v7), "SPIN_BUTTON_PADDING", SPIN_BUTTON_PADDING);
    js_push_key(v7, v7_get_global(v7), "ARROWS_SIZE", ARROWS_SIZE);
    js_push_key(v7, v7_get_global(v7), "ARROWS_VISIBLE", ARROWS_VISIBLE);
    js_push_key(v7, v7_get_global(v7), "SCROLL_SLIDER_PADDING", SCROLL_SLIDER_PADDING);
    js_push_key(v7, v7_get_global(v7), "SCROLL_SLIDER_SIZE", SCROLL_SLIDER_SIZE);
    js_push_key(v7, v7_get_global(v7), "SCROLL_PADDING", SCROLL_PADDING);
    js_push_key(v7, v7_get_global(v7), "SCROLL_SPEED", SCROLL_SPEED);
    js_push_key(v7, v7_get_global(v7), "SCROLLBAR_LEFT_SIDE", SCROLLBAR_LEFT_SIDE);
    js_push_key(v7, v7_get_global(v7), "SCROLLBAR_RIGHT_SIDE", SCROLLBAR_RIGHT_SIDE);
    js_push_key(v7, v7_get_global(v7), "LIST_ITEMS_HEIGHT", LIST_ITEMS_HEIGHT);
    js_push_key(v7, v7_get_global(v7), "LIST_ITEMS_PADDING", LIST_ITEMS_PADDING);
    js_push_key(v7, v7_get_global(v7), "SCROLLBAR_WIDTH", SCROLLBAR_WIDTH);
    js_push_key(v7, v7_get_global(v7), "SCROLLBAR_SIDE", SCROLLBAR_SIDE);
    js_push_key(v7, v7_get_global(v7), "COLOR_SELECTOR_SIZE", COLOR_SELECTOR_SIZE);
    js_push_key(v7, v7_get_global(v7), "HUEBAR_WIDTH", HUEBAR_WIDTH);
    js_push_key(v7, v7_get_global(v7), "HUEBAR_PADDING", HUEBAR_PADDING);
    js_push_key(v7, v7_get_global(v7), "HUEBAR_SELECTOR_HEIGHT", HUEBAR_SELECTOR_HEIGHT);
    js_push_key(v7, v7_get_global(v7), "HUEBAR_SELECTOR_OVERFLOW", HUEBAR_SELECTOR_OVERFLOW);

    js_push_key(v7, v7_get_global(v7), "RICON_NONE", RICON_NONE);
    js_push_key(v7, v7_get_global(v7), "RICON_FOLDER_FILE_OPEN", RICON_FOLDER_FILE_OPEN);
    js_push_key(v7, v7_get_global(v7), "RICON_FILE_SAVE_CLASSIC", RICON_FILE_SAVE_CLASSIC);
    js_push_key(v7, v7_get_global(v7), "RICON_FOLDER_OPEN", RICON_FOLDER_OPEN);
    js_push_key(v7, v7_get_global(v7), "RICON_FOLDER_SAVE", RICON_FOLDER_SAVE);
    js_push_key(v7, v7_get_global(v7), "RICON_FILE_OPEN", RICON_FILE_OPEN);
    js_push_key(v7, v7_get_global(v7), "RICON_FILE_SAVE", RICON_FILE_SAVE);
    js_push_key(v7, v7_get_global(v7), "RICON_FILE_EXPORT", RICON_FILE_EXPORT);
    js_push_key(v7, v7_get_global(v7), "RICON_FILE_NEW", RICON_FILE_NEW);
    js_push_key(v7, v7_get_global(v7), "RICON_FILE_DELETE", RICON_FILE_DELETE);
    js_push_key(v7, v7_get_global(v7), "RICON_FILETYPE_TEXT", RICON_FILETYPE_TEXT);
    js_push_key(v7, v7_get_global(v7), "RICON_FILETYPE_AUDIO", RICON_FILETYPE_AUDIO);
    js_push_key(v7, v7_get_global(v7), "RICON_FILETYPE_IMAGE", RICON_FILETYPE_IMAGE);
    js_push_key(v7, v7_get_global(v7), "RICON_FILETYPE_PLAY", RICON_FILETYPE_PLAY);
    js_push_key(v7, v7_get_global(v7), "RICON_FILETYPE_VIDEO", RICON_FILETYPE_VIDEO);
    js_push_key(v7, v7_get_global(v7), "RICON_FILETYPE_INFO", RICON_FILETYPE_INFO);
    js_push_key(v7, v7_get_global(v7), "RICON_FILE_COPY", RICON_FILE_COPY);
    js_push_key(v7, v7_get_global(v7), "RICON_FILE_CUT", RICON_FILE_CUT);
    js_push_key(v7, v7_get_global(v7), "RICON_FILE_PASTE", RICON_FILE_PASTE);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_HAND", RICON_CURSOR_HAND);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_POINTER", RICON_CURSOR_POINTER);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_CLASSIC", RICON_CURSOR_CLASSIC);
    js_push_key(v7, v7_get_global(v7), "RICON_PENCIL", RICON_PENCIL);
    js_push_key(v7, v7_get_global(v7), "RICON_PENCIL_BIG", RICON_PENCIL_BIG);
    js_push_key(v7, v7_get_global(v7), "RICON_BRUSH_CLASSIC", RICON_BRUSH_CLASSIC);
    js_push_key(v7, v7_get_global(v7), "RICON_BRUSH_PAINTER", RICON_BRUSH_PAINTER);
    js_push_key(v7, v7_get_global(v7), "RICON_WATER_DROP", RICON_WATER_DROP);
    js_push_key(v7, v7_get_global(v7), "RICON_COLOR_PICKER", RICON_COLOR_PICKER);
    js_push_key(v7, v7_get_global(v7), "RICON_RUBBER", RICON_RUBBER);
    js_push_key(v7, v7_get_global(v7), "RICON_COLOR_BUCKET", RICON_COLOR_BUCKET);
    js_push_key(v7, v7_get_global(v7), "RICON_TEXT_T", RICON_TEXT_T);
    js_push_key(v7, v7_get_global(v7), "RICON_TEXT_A", RICON_TEXT_A);
    js_push_key(v7, v7_get_global(v7), "RICON_SCALE", RICON_SCALE);
    js_push_key(v7, v7_get_global(v7), "RICON_RESIZE", RICON_RESIZE);
    js_push_key(v7, v7_get_global(v7), "RICON_FILTER_POINT", RICON_FILTER_POINT);
    js_push_key(v7, v7_get_global(v7), "RICON_FILTER_BILINEAR", RICON_FILTER_BILINEAR);
    js_push_key(v7, v7_get_global(v7), "RICON_CROP", RICON_CROP);
    js_push_key(v7, v7_get_global(v7), "RICON_CROP_ALPHA", RICON_CROP_ALPHA);
    js_push_key(v7, v7_get_global(v7), "RICON_SQUARE_TOGGLE", RICON_SQUARE_TOGGLE);
    js_push_key(v7, v7_get_global(v7), "RICON_SYMMETRY", RICON_SYMMETRY);
    js_push_key(v7, v7_get_global(v7), "RICON_SYMMETRY_HORIZONTAL", RICON_SYMMETRY_HORIZONTAL);
    js_push_key(v7, v7_get_global(v7), "RICON_SYMMETRY_VERTICAL", RICON_SYMMETRY_VERTICAL);
    js_push_key(v7, v7_get_global(v7), "RICON_LENS", RICON_LENS);
    js_push_key(v7, v7_get_global(v7), "RICON_LENS_BIG", RICON_LENS_BIG);
    js_push_key(v7, v7_get_global(v7), "RICON_EYE_ON", RICON_EYE_ON);
    js_push_key(v7, v7_get_global(v7), "RICON_EYE_OFF", RICON_EYE_OFF);
    js_push_key(v7, v7_get_global(v7), "RICON_FILTER_TOP", RICON_FILTER_TOP);
    js_push_key(v7, v7_get_global(v7), "RICON_FILTER", RICON_FILTER);
    js_push_key(v7, v7_get_global(v7), "RICON_TARGET_POINT", RICON_TARGET_POINT);
    js_push_key(v7, v7_get_global(v7), "RICON_TARGET_SMALL", RICON_TARGET_SMALL);
    js_push_key(v7, v7_get_global(v7), "RICON_TARGET_BIG", RICON_TARGET_BIG);
    js_push_key(v7, v7_get_global(v7), "RICON_TARGET_MOVE", RICON_TARGET_MOVE);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_MOVE", RICON_CURSOR_MOVE);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_SCALE", RICON_CURSOR_SCALE);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_SCALE_RIGHT", RICON_CURSOR_SCALE_RIGHT);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_SCALE_LEFT", RICON_CURSOR_SCALE_LEFT);
    js_push_key(v7, v7_get_global(v7), "RICON_UNDO", RICON_UNDO);
    js_push_key(v7, v7_get_global(v7), "RICON_REREDO", RICON_REREDO);
    js_push_key(v7, v7_get_global(v7), "RICON_MUTATE", RICON_MUTATE);
    js_push_key(v7, v7_get_global(v7), "RICON_ROTATE", RICON_ROTATE);
    js_push_key(v7, v7_get_global(v7), "RICON_REPEAT", RICON_REPEAT);
    js_push_key(v7, v7_get_global(v7), "RICON_SHUFFLE", RICON_SHUFFLE);
    js_push_key(v7, v7_get_global(v7), "RICON_EMPTYBOX", RICON_EMPTYBOX);
    js_push_key(v7, v7_get_global(v7), "RICON_TARGET", RICON_TARGET);
    js_push_key(v7, v7_get_global(v7), "RICON_TARGET_SMALL_FILL", RICON_TARGET_SMALL_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_TARGET_BIG_FILL", RICON_TARGET_BIG_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_TARGET_MOVE_FILL", RICON_TARGET_MOVE_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_MOVE_FILL", RICON_CURSOR_MOVE_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_SCALE_FILL", RICON_CURSOR_SCALE_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_SCALE_RIGHT_FILL", RICON_CURSOR_SCALE_RIGHT_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_CURSOR_SCALE_LEFT_FILL", RICON_CURSOR_SCALE_LEFT_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_UNDO_FILL", RICON_UNDO_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_REDO_FILL", RICON_REDO_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_REREDO_FILL", RICON_REREDO_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_MUTATE_FILL", RICON_MUTATE_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_ROTATE_FILL", RICON_ROTATE_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_REPEAT_FILL", RICON_REPEAT_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_SHUFFLE_FILL", RICON_SHUFFLE_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_EMPTYBOX_SMALL", RICON_EMPTYBOX_SMALL);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX", RICON_BOX);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_TOP", RICON_BOX_TOP);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_TOP_RIGHT", RICON_BOX_TOP_RIGHT);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_RIGHT", RICON_BOX_RIGHT);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_BOTTOM_RIGHT", RICON_BOX_BOTTOM_RIGHT);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_BOTTOM", RICON_BOX_BOTTOM);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_BOTTOM_LEFT", RICON_BOX_BOTTOM_LEFT);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_LEFT", RICON_BOX_LEFT);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_TOP_LEFT", RICON_BOX_TOP_LEFT);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_CENTER", RICON_BOX_CENTER);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_CIRCLE_MASK", RICON_BOX_CIRCLE_MASK);
    js_push_key(v7, v7_get_global(v7), "RICON_POT", RICON_POT);
    js_push_key(v7, v7_get_global(v7), "RICON_ALPHA_MULTIPLY", RICON_ALPHA_MULTIPLY);
    js_push_key(v7, v7_get_global(v7), "RICON_ALPHA_CLEAR", RICON_ALPHA_CLEAR);
    js_push_key(v7, v7_get_global(v7), "RICON_DITHERING", RICON_DITHERING);
    js_push_key(v7, v7_get_global(v7), "RICON_MIPMAPS", RICON_MIPMAPS);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_GRID", RICON_BOX_GRID);
    js_push_key(v7, v7_get_global(v7), "RICON_GRID", RICON_GRID);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_CORNERS_SMALL", RICON_BOX_CORNERS_SMALL);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_CORNERS_BIG", RICON_BOX_CORNERS_BIG);
    js_push_key(v7, v7_get_global(v7), "RICON_FOUR_BOXES", RICON_FOUR_BOXES);
    js_push_key(v7, v7_get_global(v7), "RICON_GRID_FILL", RICON_GRID_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_MULTISIZE", RICON_BOX_MULTISIZE);
    js_push_key(v7, v7_get_global(v7), "RICON_ZOOM_SMALL", RICON_ZOOM_SMALL);
    js_push_key(v7, v7_get_global(v7), "RICON_ZOOM_MEDIUM", RICON_ZOOM_MEDIUM);
    js_push_key(v7, v7_get_global(v7), "RICON_ZOOM_BIG", RICON_ZOOM_BIG);
    js_push_key(v7, v7_get_global(v7), "RICON_ZOOM_ALL", RICON_ZOOM_ALL);
    js_push_key(v7, v7_get_global(v7), "RICON_ZOOM_CENTER", RICON_ZOOM_CENTER);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_DOTS_SMALL", RICON_BOX_DOTS_SMALL);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_DOTS_BIG", RICON_BOX_DOTS_BIG);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_CONCENTRIC", RICON_BOX_CONCENTRIC);
    js_push_key(v7, v7_get_global(v7), "RICON_BOX_GRID_BIG", RICON_BOX_GRID_BIG);
    js_push_key(v7, v7_get_global(v7), "RICON_OK_TICK", RICON_OK_TICK);
    js_push_key(v7, v7_get_global(v7), "RICON_CROSS", RICON_CROSS);
    js_push_key(v7, v7_get_global(v7), "RICON_ARROW_LEFT", RICON_ARROW_LEFT);
    js_push_key(v7, v7_get_global(v7), "RICON_ARROW_RIGHT", RICON_ARROW_RIGHT);
    js_push_key(v7, v7_get_global(v7), "RICON_ARROW_BOTTOM", RICON_ARROW_BOTTOM);
    js_push_key(v7, v7_get_global(v7), "RICON_ARROW_TOP", RICON_ARROW_TOP);
    js_push_key(v7, v7_get_global(v7), "RICON_ARROW_LEFT_FILL", RICON_ARROW_LEFT_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_ARROW_RIGHT_FILL", RICON_ARROW_RIGHT_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_ARROW_BOTTOM_FILL", RICON_ARROW_BOTTOM_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_ARROW_TOP_FILL", RICON_ARROW_TOP_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_AUDIO", RICON_AUDIO);
    js_push_key(v7, v7_get_global(v7), "RICON_FX", RICON_FX);
    js_push_key(v7, v7_get_global(v7), "RICON_WAVE", RICON_WAVE);
    js_push_key(v7, v7_get_global(v7), "RICON_WAVE_SINUS", RICON_WAVE_SINUS);
    js_push_key(v7, v7_get_global(v7), "RICON_WAVE_SQUARE", RICON_WAVE_SQUARE);
    js_push_key(v7, v7_get_global(v7), "RICON_WAVE_TRIANGULAR", RICON_WAVE_TRIANGULAR);
    js_push_key(v7, v7_get_global(v7), "RICON_CROSS_SMALL", RICON_CROSS_SMALL);
    js_push_key(v7, v7_get_global(v7), "RICON_PLAYER_PREVIOUS", RICON_PLAYER_PREVIOUS);
    js_push_key(v7, v7_get_global(v7), "RICON_PLAYER_PLAY_BACK", RICON_PLAYER_PLAY_BACK);
    js_push_key(v7, v7_get_global(v7), "RICON_PLAYER_PLAY", RICON_PLAYER_PLAY);
    js_push_key(v7, v7_get_global(v7), "RICON_PLAYER_PAUSE", RICON_PLAYER_PAUSE);
    js_push_key(v7, v7_get_global(v7), "RICON_PLAYER_STOP", RICON_PLAYER_STOP);
    js_push_key(v7, v7_get_global(v7), "RICON_PLAYER_NEXT", RICON_PLAYER_NEXT);
    js_push_key(v7, v7_get_global(v7), "RICON_PLAYER_RECORD", RICON_PLAYER_RECORD);
    js_push_key(v7, v7_get_global(v7), "RICON_MAGNET", RICON_MAGNET);
    js_push_key(v7, v7_get_global(v7), "RICON_LOCK_CLOSE", RICON_LOCK_CLOSE);
    js_push_key(v7, v7_get_global(v7), "RICON_LOCK_OPEN", RICON_LOCK_OPEN);
    js_push_key(v7, v7_get_global(v7), "RICON_CLOCK", RICON_CLOCK);
    js_push_key(v7, v7_get_global(v7), "RICON_TOOLS", RICON_TOOLS);
    js_push_key(v7, v7_get_global(v7), "RICON_GEAR", RICON_GEAR);
    js_push_key(v7, v7_get_global(v7), "RICON_GEAR_BIG", RICON_GEAR_BIG);
    js_push_key(v7, v7_get_global(v7), "RICON_BIN", RICON_BIN);
    js_push_key(v7, v7_get_global(v7), "RICON_HAND_POINTER", RICON_HAND_POINTER);
    js_push_key(v7, v7_get_global(v7), "RICON_LASER", RICON_LASER);
    js_push_key(v7, v7_get_global(v7), "RICON_COIN", RICON_COIN);
    js_push_key(v7, v7_get_global(v7), "RICON_EXPLOSION", RICON_EXPLOSION);
    js_push_key(v7, v7_get_global(v7), "RICON_1UP", RICON_1UP);
    js_push_key(v7, v7_get_global(v7), "RICON_PLAYER", RICON_PLAYER);
    js_push_key(v7, v7_get_global(v7), "RICON_PLAYER_JUMP", RICON_PLAYER_JUMP);
    js_push_key(v7, v7_get_global(v7), "RICON_KEY", RICON_KEY);
    js_push_key(v7, v7_get_global(v7), "RICON_DEMON", RICON_DEMON);
    js_push_key(v7, v7_get_global(v7), "RICON_TEXT_POPUP", RICON_TEXT_POPUP);
    js_push_key(v7, v7_get_global(v7), "RICON_GEAR_EX", RICON_GEAR_EX);
    js_push_key(v7, v7_get_global(v7), "RICON_CRACK", RICON_CRACK);
    js_push_key(v7, v7_get_global(v7), "RICON_CRACK_POINTS", RICON_CRACK_POINTS);
    js_push_key(v7, v7_get_global(v7), "RICON_STAR", RICON_STAR);
    js_push_key(v7, v7_get_global(v7), "RICON_DOOR", RICON_DOOR);
    js_push_key(v7, v7_get_global(v7), "RICON_EXIT", RICON_EXIT);
    js_push_key(v7, v7_get_global(v7), "RICON_MODE_2D", RICON_MODE_2D);
    js_push_key(v7, v7_get_global(v7), "RICON_MODE_3D", RICON_MODE_3D);
    js_push_key(v7, v7_get_global(v7), "RICON_CUBE", RICON_CUBE);
    js_push_key(v7, v7_get_global(v7), "RICON_CUBE_FACE_TOP", RICON_CUBE_FACE_TOP);
    js_push_key(v7, v7_get_global(v7), "RICON_CUBE_FACE_LEFT", RICON_CUBE_FACE_LEFT);
    js_push_key(v7, v7_get_global(v7), "RICON_CUBE_FACE_FRONT", RICON_CUBE_FACE_FRONT);
    js_push_key(v7, v7_get_global(v7), "RICON_CUBE_FACE_BOTTOM", RICON_CUBE_FACE_BOTTOM);
    js_push_key(v7, v7_get_global(v7), "RICON_CUBE_FACE_RIGHT", RICON_CUBE_FACE_RIGHT);
    js_push_key(v7, v7_get_global(v7), "RICON_CUBE_FACE_BACK", RICON_CUBE_FACE_BACK);
    js_push_key(v7, v7_get_global(v7), "RICON_CAMERA", RICON_CAMERA);
    js_push_key(v7, v7_get_global(v7), "RICON_SPECIAL", RICON_SPECIAL);
    js_push_key(v7, v7_get_global(v7), "RICON_LINK_NET", RICON_LINK_NET);
    js_push_key(v7, v7_get_global(v7), "RICON_LINK_BOXES", RICON_LINK_BOXES);
    js_push_key(v7, v7_get_global(v7), "RICON_LINK_MULTI", RICON_LINK_MULTI);
    js_push_key(v7, v7_get_global(v7), "RICON_LINK", RICON_LINK);
    js_push_key(v7, v7_get_global(v7), "RICON_LINK_BROKE", RICON_LINK_BROKE);
    js_push_key(v7, v7_get_global(v7), "RICON_TEXT_NOTES", RICON_TEXT_NOTES);
    js_push_key(v7, v7_get_global(v7), "RICON_NOTEBOOK", RICON_NOTEBOOK);
    js_push_key(v7, v7_get_global(v7), "RICON_SUITCASE", RICON_SUITCASE);
    js_push_key(v7, v7_get_global(v7), "RICON_SUITCASE_ZIP", RICON_SUITCASE_ZIP);
    js_push_key(v7, v7_get_global(v7), "RICON_MAILBOX", RICON_MAILBOX);
    js_push_key(v7, v7_get_global(v7), "RICON_MONITOR", RICON_MONITOR);
    js_push_key(v7, v7_get_global(v7), "RICON_PRINTER", RICON_PRINTER);
    js_push_key(v7, v7_get_global(v7), "RICON_PHOTO_CAMERA", RICON_PHOTO_CAMERA);
    js_push_key(v7, v7_get_global(v7), "RICON_PHOTO_CAMERA_FLASH", RICON_PHOTO_CAMERA_FLASH);
    js_push_key(v7, v7_get_global(v7), "RICON_HOUSE", RICON_HOUSE);
    js_push_key(v7, v7_get_global(v7), "RICON_HEART", RICON_HEART);
    js_push_key(v7, v7_get_global(v7), "RICON_CORNER", RICON_CORNER);
    js_push_key(v7, v7_get_global(v7), "RICON_VERTICAL_BARS", RICON_VERTICAL_BARS);
    js_push_key(v7, v7_get_global(v7), "RICON_VERTICAL_BARS_FILL", RICON_VERTICAL_BARS_FILL);
    js_push_key(v7, v7_get_global(v7), "RICON_LIFE_BARS", RICON_LIFE_BARS);
    js_push_key(v7, v7_get_global(v7), "RICON_INFO", RICON_INFO);
    js_push_key(v7, v7_get_global(v7), "RICON_HELP", RICON_HELP);
    js_push_key(v7, v7_get_global(v7), "RICON_FILETYPE_ALPHA", RICON_FILETYPE_ALPHA);
    js_push_key(v7, v7_get_global(v7), "RICON_FILETYPE_HOME", RICON_FILETYPE_HOME);
    js_push_key(v7, v7_get_global(v7), "RICON_LAYERS_VISIBLE", RICON_LAYERS_VISIBLE);
    js_push_key(v7, v7_get_global(v7), "RICON_LAYERS", RICON_LAYERS);
    js_push_key(v7, v7_get_global(v7), "RICON_WINDOW", RICON_WINDOW);
    js_push_key(v7, v7_get_global(v7), "RICON_HIDPI", RICON_HIDPI);
    js_push_key(v7, v7_get_global(v7), "RICON_200", RICON_200);
    js_push_key(v7, v7_get_global(v7), "RICON_201", RICON_201);
    js_push_key(v7, v7_get_global(v7), "RICON_202", RICON_202);
    js_push_key(v7, v7_get_global(v7), "RICON_203", RICON_203);
    js_push_key(v7, v7_get_global(v7), "RICON_204", RICON_204);
    js_push_key(v7, v7_get_global(v7), "RICON_205", RICON_205);
    js_push_key(v7, v7_get_global(v7), "RICON_206", RICON_206);
    js_push_key(v7, v7_get_global(v7), "RICON_207", RICON_207);
    js_push_key(v7, v7_get_global(v7), "RICON_208", RICON_208);
    js_push_key(v7, v7_get_global(v7), "RICON_209", RICON_209);
    js_push_key(v7, v7_get_global(v7), "RICON_210", RICON_210);
    js_push_key(v7, v7_get_global(v7), "RICON_211", RICON_211);
    js_push_key(v7, v7_get_global(v7), "RICON_212", RICON_212);
    js_push_key(v7, v7_get_global(v7), "RICON_213", RICON_213);
    js_push_key(v7, v7_get_global(v7), "RICON_214", RICON_214);
    js_push_key(v7, v7_get_global(v7), "RICON_215", RICON_215);
    js_push_key(v7, v7_get_global(v7), "RICON_216", RICON_216);
    js_push_key(v7, v7_get_global(v7), "RICON_217", RICON_217);
    js_push_key(v7, v7_get_global(v7), "RICON_218", RICON_218);
    js_push_key(v7, v7_get_global(v7), "RICON_219", RICON_219);
    js_push_key(v7, v7_get_global(v7), "RICON_220", RICON_220);
    js_push_key(v7, v7_get_global(v7), "RICON_221", RICON_221);
    js_push_key(v7, v7_get_global(v7), "RICON_222", RICON_222);
    js_push_key(v7, v7_get_global(v7), "RICON_223", RICON_223);
    js_push_key(v7, v7_get_global(v7), "RICON_224", RICON_224);
    js_push_key(v7, v7_get_global(v7), "RICON_225", RICON_225);
    js_push_key(v7, v7_get_global(v7), "RICON_226", RICON_226);
    js_push_key(v7, v7_get_global(v7), "RICON_227", RICON_227);
    js_push_key(v7, v7_get_global(v7), "RICON_228", RICON_228);
    js_push_key(v7, v7_get_global(v7), "RICON_229", RICON_229);
    js_push_key(v7, v7_get_global(v7), "RICON_230", RICON_230);
    js_push_key(v7, v7_get_global(v7), "RICON_231", RICON_231);
    js_push_key(v7, v7_get_global(v7), "RICON_232", RICON_232);
    js_push_key(v7, v7_get_global(v7), "RICON_233", RICON_233);
    js_push_key(v7, v7_get_global(v7), "RICON_234", RICON_234);
    js_push_key(v7, v7_get_global(v7), "RICON_235", RICON_235);
    js_push_key(v7, v7_get_global(v7), "RICON_236", RICON_236);
    js_push_key(v7, v7_get_global(v7), "RICON_237", RICON_237);
    js_push_key(v7, v7_get_global(v7), "RICON_238", RICON_238);
    js_push_key(v7, v7_get_global(v7), "RICON_239", RICON_239);
    js_push_key(v7, v7_get_global(v7), "RICON_240", RICON_240);
    js_push_key(v7, v7_get_global(v7), "RICON_241", RICON_241);
    js_push_key(v7, v7_get_global(v7), "RICON_242", RICON_242);
    js_push_key(v7, v7_get_global(v7), "RICON_243", RICON_243);
    js_push_key(v7, v7_get_global(v7), "RICON_244", RICON_244);
    js_push_key(v7, v7_get_global(v7), "RICON_245", RICON_245);
    js_push_key(v7, v7_get_global(v7), "RICON_246", RICON_246);
    js_push_key(v7, v7_get_global(v7), "RICON_247", RICON_247);
    js_push_key(v7, v7_get_global(v7), "RICON_248", RICON_248);
    js_push_key(v7, v7_get_global(v7), "RICON_249", RICON_249);
    js_push_key(v7, v7_get_global(v7), "RICON_250", RICON_250);
    js_push_key(v7, v7_get_global(v7), "RICON_251", RICON_251);
    js_push_key(v7, v7_get_global(v7), "RICON_252", RICON_252);
    js_push_key(v7, v7_get_global(v7), "RICON_253", RICON_253);
    js_push_key(v7, v7_get_global(v7), "RICON_254", RICON_254);
    js_push_key(v7, v7_get_global(v7), "RICON_255", RICON_255);

    v7_set_method(v7, v7_get_global(v7), "GuiEnable", &js_gui_enable);
    v7_set_method(v7, v7_get_global(v7), "GuiDisable", &js_gui_disable);
    v7_set_method(v7, v7_get_global(v7), "GuiLock", &js_gui_lock);
    v7_set_method(v7, v7_get_global(v7), "GuiUnlock", &js_gui_unlock);
    v7_set_method(v7, v7_get_global(v7), "GuiFade", &js_gui_fade);
    v7_set_method(v7, v7_get_global(v7), "GuiSetState", &js_gui_set_state);
    v7_set_method(v7, v7_get_global(v7), "GuiGetState", &js_gui_get_state);

    v7_set_method(v7, v7_get_global(v7), "GuiSetFont", &js_gui_set_font);
    v7_set_method(v7, v7_get_global(v7), "GuiGetFont", &js_gui_get_font);

    v7_set_method(v7, v7_get_global(v7), "GuiSetStyle", &js_gui_set_style);
    v7_set_method(v7, v7_get_global(v7), "GuiGetStyle", &js_gui_get_style);

    v7_set_method(v7, v7_get_global(v7), "GuiEnableTooltip", &js_gui_enable_tooltip);
    v7_set_method(v7, v7_get_global(v7), "GuiDisableTooltip", &js_gui_disable_tooltip);
    v7_set_method(v7, v7_get_global(v7), "GuiSetTooltip", &js_gui_set_tooltip);
    v7_set_method(v7, v7_get_global(v7), "GuiClearTooltip", &js_gui_clear_tooltip);

    v7_set_method(v7, v7_get_global(v7), "GuiWindowBox", &js_gui_window_box);
    v7_set_method(v7, v7_get_global(v7), "GuiGroupBox", &js_gui_group_box);
    v7_set_method(v7, v7_get_global(v7), "GuiLine", &js_gui_line);
    v7_set_method(v7, v7_get_global(v7), "GuiPanel", &js_gui_panel);
    v7_set_method(v7, v7_get_global(v7), "GuiScrollPanel", &js_gui_scroll_panel);

    v7_set_method(v7, v7_get_global(v7), "GuiLabel", &js_gui_label);
    v7_set_method(v7, v7_get_global(v7), "GuiButton", &js_gui_button);
    v7_set_method(v7, v7_get_global(v7), "GuiLabelButton", &js_gui_label_button);
    v7_set_method(v7, v7_get_global(v7), "GuiImageButton", &js_gui_image_button);
    v7_set_method(v7, v7_get_global(v7), "GuiImageButtonEx", &js_gui_image_button_ex);
    v7_set_method(v7, v7_get_global(v7), "GuiToggle", &js_gui_toggle);
    v7_set_method(v7, v7_get_global(v7), "GuiToggleGroup", &js_gui_toggle_group);
    v7_set_method(v7, v7_get_global(v7), "GuiCheckBox", &js_gui_check_box);
    v7_set_method(v7, v7_get_global(v7), "GuiComboBox", &js_gui_combo_box);
    v7_set_method(v7, v7_get_global(v7), "GuiDropdownBox", &js_gui_dropdown_box);
    v7_set_method(v7, v7_get_global(v7), "GuiSpinner", &js_gui_spinner);
    v7_set_method(v7, v7_get_global(v7), "GuiValueBox", &js_gui_value_box);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBox", &js_gui_text_box);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxMulti", &js_gui_text_box_multi);
    v7_set_method(v7, v7_get_global(v7), "GuiSlider", &js_gui_slider);
    v7_set_method(v7, v7_get_global(v7), "GuiSliderBar", &js_gui_slider_bar);
    v7_set_method(v7, v7_get_global(v7), "GuiProgressBar", &js_gui_progress_bar);
    v7_set_method(v7, v7_get_global(v7), "GuiStatusBar", &js_gui_status_bar);
    v7_set_method(v7, v7_get_global(v7), "GuiDummyRec", &js_gui_dummy_rec);
    v7_set_method(v7, v7_get_global(v7), "GuiScollBar", &js_gui_scroll_bar);
    v7_set_method(v7, v7_get_global(v7), "GuiGrid", &js_gui_grid);

    v7_set_method(v7, v7_get_global(v7), "GuiListView", &js_gui_list_view);
    v7_set_method(v7, v7_get_global(v7), "GuiListViewEx", &js_gui_list_view_ex);
    v7_set_method(v7, v7_get_global(v7), "GuiMessageBox", &js_gui_message_box);
    v7_set_method(v7, v7_get_global(v7), "GuiTextInputBox", &js_gui_text_input_box);
    v7_set_method(v7, v7_get_global(v7), "GuiColorPicker", &js_gui_color_picker);
    v7_set_method(v7, v7_get_global(v7), "GuiColorPanel", &js_gui_color_panel);
    v7_set_method(v7, v7_get_global(v7), "GuiColorBarAlpha", &js_gui_color_bar_alpha);
    v7_set_method(v7, v7_get_global(v7), "GuiColorBarHue", &js_gui_color_bar_hue);

    v7_set_method(v7, v7_get_global(v7), "GuiLoadStyle", &js_gui_load_style);
    v7_set_method(v7, v7_get_global(v7), "GuiLoadStyleDefault", &js_gui_load_style_default);

    v7_set_method(v7, v7_get_global(v7), "GuiIconText", &js_gui_icon_text);

    v7_set_method(v7, v7_get_global(v7), "GuiDrawIcon", &js_gui_draw_icon);

    v7_set_method(v7, v7_get_global(v7), "GuiGetIcons", &js_gui_get_icons);
    v7_set_method(v7, v7_get_global(v7), "GuiGetIconData", &js_gui_get_icon_data);
    v7_set_method(v7, v7_get_global(v7), "GuiSetIconData", &js_gui_set_icon_data);

    v7_set_method(v7, v7_get_global(v7), "GuiSetIconPixel", &js_gui_set_icon_pixel);
    v7_set_method(v7, v7_get_global(v7), "GuiClearIconPixel", &js_gui_clear_icon_pixel);
    v7_set_method(v7, v7_get_global(v7), "GuiCheckIconPixel", &js_gui_check_icon_pixel);

    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxSetActive", &js_gui_text_box_set_active);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxGetActive", &js_gui_text_box_get_active);

    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxSetCursor", &js_gui_text_box_set_cursor);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxGetCursor", &js_gui_text_box_get_cursor);

    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxSetSelection", &js_gui_text_box_set_selection);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxGetSelection", &js_gui_text_box_get_selection);

    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxIsActive", &js_gui_text_box_is_active);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxGetState", &js_gui_text_box_get_state);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxSetState", &js_gui_text_box_set_state);

    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxSelectAll", &js_gui_text_box_select_all);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxCopy", &js_gui_text_box_copy);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxPaste", &js_gui_text_box_paste);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxCut", &js_gui_text_box_cut);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxDelete", &js_gui_text_box_delete);
    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxGetByteIndex", &js_gui_text_box_get_byte_index);

    v7_set_method(v7, v7_get_global(v7), "GuiTextBoxEx", &js_gui_text_box_ex);
}
