#ifndef RAYLIB_V7_CORE
#define RAYLIB_V7_CORE

#include <v7/v7.h>

static inline enum v7_err js_init_window(struct v7* v7);
static inline enum v7_err js_window_should_close(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_close_window(void);
static inline enum v7_err js_window_ready(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_window_fullscreen(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_window_maximized(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_window_minimized(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_window_focused(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_window_resized(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_window_state(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_window_state(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_clear_window_state(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_toggle_fullscreen(void);
static inline enum v7_err js_maximize_window(void);
static inline enum v7_err js_minimize_window(void);
static inline enum v7_err js_restore_window(void);
static inline enum v7_err js_set_window_icon(struct v7* v7);
static inline enum v7_err js_set_window_title(struct v7* v7);
static inline enum v7_err js_set_window_position(struct v7* v7);
static inline enum v7_err js_set_window_monitor(struct v7* v7);
static inline enum v7_err js_set_window_min_size(struct v7* v7);
static inline enum v7_err js_set_window_size(struct v7* v7);
static inline enum v7_err js_get_window_handle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_screen_width(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_screen_height(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_monitor_count(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_monitor_position(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_monitor_width(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_monitor_height(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_monitor_physical_width(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_monitor_physical_height(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_monitor_refresh_rate(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_window_position(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_window_scale_dpi(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_monitor_name(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_clipboard_text(struct v7* v7);
static inline enum v7_err js_get_clipboard_text(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_show_cursor(void);
static inline enum v7_err js_hide_cursor(void);
static inline enum v7_err js_cursor_hidden(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_enable_cursor(void);
static inline enum v7_err js_disable_cursor(void);
static inline enum v7_err js_cursor_onscreen(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_clear_background(struct v7* v7);
static inline enum v7_err js_begin_drawing(struct v7* v7);
static inline enum v7_err js_end_drawing(void);
static inline enum v7_err js_begin_mode2d(struct v7* v7);
static inline enum v7_err js_end_mode2d(void);
static inline enum v7_err js_begin_mode3d(struct v7* v7);
static inline enum v7_err js_end_mode3d(void);
static inline enum v7_err js_begin_texture_mode(struct v7* v7);
static inline enum v7_err js_end_texture_mode(void);
static inline enum v7_err js_begin_scissor_mode(struct v7* v7);
static inline enum v7_err js_end_scissor_mode(void);

static inline enum v7_err js_get_mouse_ray(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_camera_matrix(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_camera_matrix2d(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_world_to_screen(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_world_to_screen_ex(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_world_to_screen2d(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_screen_to_world2d(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_set_target_fps(struct v7* v7);
static inline enum v7_err js_get_fps(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_frame_time(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_time(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_set_config_flags(struct v7* v7);
static inline enum v7_err js_set_tracelog_level(struct v7* v7);
static inline enum v7_err js_set_tracelog_exit(struct v7* v7);
static inline enum v7_err js_set_tracelog_callback(struct v7* v7);
static inline enum v7_err js_tracelog(struct v7* v7);

static inline enum v7_err js_memalloc(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_memfree(struct v7* v7);
static inline enum v7_err js_take_screenshot(struct v7* v7);
static inline enum v7_err js_get_random_value(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_load_file_data(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_file_data(struct v7* v7);
static inline enum v7_err js_save_file_data(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_file_text(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_file_text(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_save_file_text(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_file_exists(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_directory_exists(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_is_file_extension(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_file_extension(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_filename(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_filename_without_ext(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_directory_path(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_prev_directory_path(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_working_directory(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_directory_files(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_clear_directory_files(void);
static inline enum v7_err js_change_directory(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_file_dropped(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_dropped_files(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_clear_dropped_files(void);
static inline enum v7_err js_get_file_mod_time(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_compress_data(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_decompress_data(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_save_storage_value(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_storage_value(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_open_url(struct v7* v7);

static inline enum v7_err js_key_pressed(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_key_down(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_key_released(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_key_up(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_exit_key(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_key_pressed(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_char_pressed(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_gamepad_available(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gamepad_name(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_gamepad_name(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gamepad_button_pressed(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gamepad_button_down(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gamepad_button_released(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_gamepad_button_up(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_gamepad_button_pressed(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_gamepad_axis_count(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_gamepad_axis_movement(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_mouse_button_pressed(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_mouse_button_down(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_mouse_button_released(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_mouse_button_up(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_mouse_x(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_mouse_y(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_mouse_position(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_mouse_position(struct v7* v7);
static inline enum v7_err js_set_mouse_offset(struct v7* v7);
static inline enum v7_err js_set_mouse_scale(struct v7* v7);
static inline enum v7_err js_get_mouse_wheel_move(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_mouse_cursor(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_mouse_cursor(struct v7* v7);

static inline enum v7_err js_get_touch_x(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_touch_y(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_touch_position(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_set_gestures_enabled(struct v7* v7);
static inline enum v7_err js_gesture_detected(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_gesture_detected(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_touch_points_count(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_gesture_hold_duration(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_gesture_drag_vector(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_gesture_drag_angle(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_gesture_pinch_vector(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_gesture_pinch_angle(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_set_camera_mode(struct v7* v7);
static inline enum v7_err js_update_camera(struct v7* v7);
static inline enum v7_err js_set_camera_pan_control(struct v7* v7);
static inline enum v7_err js_set_camera_alt_control(struct v7* v7);
static inline enum v7_err js_set_camera_smooth_zoom_control(struct v7* v7);
static inline enum v7_err js_set_camera_move_controls(struct v7* v7);

void raylib_v7_load_core(struct v7* v7);

#endif