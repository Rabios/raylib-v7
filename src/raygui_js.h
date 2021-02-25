#ifndef RAYLIB_V7_RAYGUI
#define RAYLIB_V7_RAYGUI

#include <v7/v7.h>

static inline enum v7_err js_gui_enable(void);
static inline enum v7_err js_gui_disable(void);
static inline enum v7_err js_gui_lock(void);
static inline enum v7_err js_gui_unlock(void);
static inline enum v7_err js_gui_fade(struct v7* v7);
static inline enum v7_err js_gui_set_state(struct v7* v7);
static inline enum v7_err js_gui_get_state(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_set_font(struct v7* v7);
static inline enum v7_err js_gui_get_font(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_set_style(struct v7* v7);
static inline enum v7_err js_gui_get_style(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_enable_tooltip(void);
static inline enum v7_err js_gui_disable_tooltip(void);
static inline enum v7_err js_gui_set_tooltip(struct v7* v7);
static inline enum v7_err js_gui_clear_tooltip(void);

static inline enum v7_err js_gui_window_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_group_box(struct v7* v7);
static inline enum v7_err js_gui_line(struct v7* v7);
static inline enum v7_err js_gui_panel(struct v7* v7);
static inline enum v7_err js_gui_scroll_panel(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_label(struct v7* v7);
static inline enum v7_err js_gui_button(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_label_button(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_image_button(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_image_button_ex(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_toggle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_toggle_group(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_check_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_combo_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_dropdown_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_spinner(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_value_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_text_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_text_box_multi(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_slider(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_slider_bar(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_progress_bar(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_status_bar(struct v7* v7);
static inline enum v7_err js_gui_dummy_rec(struct v7* v7);
static inline enum v7_err js_gui_scroll_bar(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_grid(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_list_view(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_list_view_ex(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_message_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_text_input_box(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_color_picker(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_color_panel(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_color_bar_alpha(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_color_bar_hue(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_load_style(struct v7* v7);
static inline enum v7_err js_gui_load_style_default(void);

static inline enum v7_err js_gui_icon_text(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_draw_icon(struct v7* v7);

static inline enum v7_err js_gui_get_icons(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_get_icon_data(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_set_icon_data(struct v7* v7);

static inline enum v7_err js_gui_set_icon_pixel(struct v7* v7);
static inline enum v7_err js_gui_clear_icon_pixel(struct v7* v7);
static inline enum v7_err js_gui_check_icon_pixel(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_text_box_set_active(struct v7* v7);
static inline enum v7_err js_gui_text_box_get_active(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_text_box_set_cursor(struct v7* v7);
static inline enum v7_err js_gui_text_box_get_cursor(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_text_box_set_selection(struct v7* v7);
static inline enum v7_err js_gui_text_box_get_selection(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_text_box_is_active(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_text_box_get_state(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_text_box_set_state(struct v7* v7);

static inline enum v7_err js_gui_text_box_select_all(struct v7* v7);
static inline enum v7_err js_gui_text_box_copy(struct v7* v7);
static inline enum v7_err js_gui_text_box_paste(struct v7* v7);
static inline enum v7_err js_gui_text_box_cut(struct v7* v7);
static inline enum v7_err js_gui_text_box_delete(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gui_text_box_get_byte_index(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gui_text_box_ex(struct v7* v7, v7_val_t* res);

void raylib_v7_load_raygui(struct v7* v7);

#endif
