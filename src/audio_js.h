#ifndef RAYLIB_V7_AUDIO
#define RAYLIB_V7_AUDIO

#include <v7/v7.h>

static inline enum v7_err js_init_audio_device(void);
static inline enum v7_err js_close_audio_device(void);
static inline enum v7_err js_audio_device_ready(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_master_volume(struct v7* v7);

static inline enum v7_err js_load_wave(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_wave_from_memory(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_sound(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_load_sound_from_wave(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_update_sound(struct v7* v7);
static inline enum v7_err js_unload_sound(struct v7* v7);
static inline enum v7_err js_unload_wave(struct v7* v7);
static inline enum v7_err js_export_wave(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_export_wave_as_code(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_play_sound(struct v7* v7);
static inline enum v7_err js_stop_sound(struct v7* v7);
static inline enum v7_err js_pause_sound(struct v7* v7);
static inline enum v7_err js_resume_sound(struct v7* v7);
static inline enum v7_err js_play_sound_multi(struct v7* v7);
static inline enum v7_err js_stop_sound_multi(void);
static inline enum v7_err js_get_sounds_playing(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_sound_playing(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_sound_volume(struct v7* v7);
static inline enum v7_err js_set_sound_pitch(struct v7* v7);
static inline enum v7_err js_wave_format(struct v7* v7);
static inline enum v7_err js_wave_copy(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_wave_crop(struct v7* v7);
static inline enum v7_err js_load_wave_samples(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_wave_samples(struct v7* v7);

static inline enum v7_err js_load_music_stream(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_unload_music_stream(struct v7* v7);
static inline enum v7_err js_play_music_stream(struct v7* v7);
static inline enum v7_err js_update_music_stream(struct v7* v7);
static inline enum v7_err js_stop_music_stream(struct v7* v7);
static inline enum v7_err js_pause_music_stream(struct v7* v7);
static inline enum v7_err js_resume_music_stream(struct v7* v7);
static inline enum v7_err js_music_playing(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_set_music_volume(struct v7* v7);
static inline enum v7_err js_set_music_pitch(struct v7* v7);
static inline enum v7_err js_get_music_time_length(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_get_music_time_played(struct v7* v7, v7_val_t* res);

static inline enum v7_err js_init_audio_stream(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_update_audio_stream(struct v7* v7);
static inline enum v7_err js_close_audio_stream(struct v7* v7);
static inline enum v7_err js_audio_stream_processed(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_play_audio_stream(struct v7* v7);
static inline enum v7_err js_pause_audio_stream(struct v7* v7);
static inline enum v7_err js_resume_audio_stream(struct v7* v7);
static inline enum v7_err js_audio_stream_playing(struct v7* v7, v7_val_t* res);
static inline enum v7_err js_stop_audio_stream(struct v7* v7);
static inline enum v7_err js_set_audio_stream_volume(struct v7* v7);
static inline enum v7_err js_set_audio_stream_pitch(struct v7* v7);
static inline enum v7_err js_set_audio_stream_buffer_size_default(struct v7* v7);

void raylib_v7_load_audio(struct v7* v7);

#endif
