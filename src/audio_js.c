#include <raylib.h>
#include <v7/v7.h>
#include <get_set.h>
#include <audio_js.h>

static inline enum v7_err js_init_audio_device(void) {
    InitAudioDevice();
    return V7_OK;
}

static inline enum v7_err js_close_audio_device(void) {
    CloseAudioDevice();
    return V7_OK;
}

static inline enum v7_err js_audio_device_ready(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsAudioDeviceReady());
    return V7_OK;
}

static inline enum v7_err js_set_master_volume(struct v7* v7) {
    SetMasterVolume((float)v7_get_double(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_load_wave(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    js_return_wave(v7, res, LoadWave(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_load_wave_from_memory(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    js_return_wave(v7, res, LoadWaveFromMemory(v7_get_string(v7, &strarg, &lenstr), v7_get_ptr(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_load_sound(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    js_return_sound(v7, res, LoadSound(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_load_sound_from_wave(struct v7* v7, v7_val_t* res) {
    js_return_sound(v7, res, LoadSoundFromWave(js_get_wave(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_update_sound(struct v7* v7) {
    UpdateSound(js_get_sound(v7, 0), v7_get_ptr(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_unload_sound(struct v7* v7) {
    UnloadSound(js_get_sound(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_unload_wave(struct v7* v7) {
    UnloadWave(js_get_wave(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_export_wave(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 1);
    size_t lenstr;
    *res = v7_mk_boolean(v7, (int)ExportWave(js_get_wave(v7, 0), v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_export_wave_as_code(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 1);
    size_t lenstr;
    *res = v7_mk_boolean(v7, (int)ExportWaveAsCode(js_get_wave(v7, 0), v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_play_sound(struct v7* v7) {
    PlaySound(js_get_sound(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_stop_sound(struct v7* v7) {
    StopSound(js_get_sound(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_pause_sound(struct v7* v7) {
    PauseSound(js_get_sound(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_resume_sound(struct v7* v7) {
    ResumeSound(js_get_sound(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_play_sound_multi(struct v7* v7) {
    PlaySoundMulti(js_get_sound(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_stop_sound_multi(void) {
    StopSoundMulti();
    return V7_OK;
}

enum v7_err js_get_sounds_playing(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetSoundsPlaying());
    return V7_OK;
}

static inline enum v7_err js_sound_playing(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsSoundPlaying(js_get_sound(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_set_sound_volume(struct v7* v7) {
    SetSoundVolume(js_get_sound(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_set_sound_pitch(struct v7* v7) {
    SetSoundPitch(js_get_sound(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_wave_format(struct v7* v7) {
    Wave wave = js_get_wave(v7, 0);
    WaveFormat(&wave, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)), v7_get_int(v7, v7_arg(v7, 3)));
    v7_set(v7, v7_arg(v7, 0), "sampleCount", ~0, v7_mk_number(v7, wave.sampleCount));
    v7_set(v7, v7_arg(v7, 0), "sampleRate", ~0, v7_mk_number(v7, wave.sampleRate));
    v7_set(v7, v7_arg(v7, 0), "sampleSize", ~0, v7_mk_number(v7, wave.sampleSize));
    v7_set(v7, v7_arg(v7, 0), "channels", ~0, v7_mk_number(v7, wave.channels));
    v7_set(v7, v7_arg(v7, 0), "data", ~0, v7_mk_foreign(v7, wave.data));
    return V7_OK;
}

static inline enum v7_err js_wave_copy(struct v7* v7, v7_val_t* res) {
    js_return_wave(v7, res, WaveCopy(js_get_wave(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_wave_crop(struct v7* v7) {
    Wave wave = js_get_wave(v7, 0);
    WaveCrop(&wave, v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    v7_set(v7, v7_arg(v7, 0), "sampleCount", ~0, v7_mk_number(v7, wave.sampleCount));
    v7_set(v7, v7_arg(v7, 0), "sampleRate", ~0, v7_mk_number(v7, wave.sampleRate));
    v7_set(v7, v7_arg(v7, 0), "sampleSize", ~0, v7_mk_number(v7, wave.sampleSize));
    v7_set(v7, v7_arg(v7, 0), "channels", ~0, v7_mk_number(v7, wave.channels));
    v7_set(v7, v7_arg(v7, 0), "data", ~0, v7_mk_foreign(v7, wave.data));
    return V7_OK;
}

static inline enum v7_err js_load_wave_samples(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_foreign(v7, LoadWaveSamples(js_get_wave(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_unload_wave_samples(struct v7* v7) {
    UnloadWaveSamples(v7_get_ptr(v7, v7_arg(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_load_music_stream(struct v7* v7, v7_val_t* res) {
    v7_val_t strarg = v7_arg(v7, 0);
    size_t lenstr;
    js_return_music(v7, res, LoadMusicStream(v7_get_string(v7, &strarg, &lenstr)));
    return V7_OK;
}

static inline enum v7_err js_unload_music_stream(struct v7* v7) {
    UnloadMusicStream(js_get_music(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_play_music_stream(struct v7* v7) {
    PlayMusicStream(js_get_music(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_update_music_stream(struct v7* v7) {
    UpdateMusicStream(js_get_music(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_stop_music_stream(struct v7* v7) {
    StopMusicStream(js_get_music(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_pause_music_stream(struct v7* v7) {
    PauseMusicStream(js_get_music(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_resume_music_stream(struct v7* v7) {
    ResumeMusicStream(js_get_music(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_music_playing(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsMusicPlaying(js_get_music(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_set_music_volume(struct v7* v7) {
    SetMusicVolume(js_get_music(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_set_music_pitch(struct v7* v7) {
    SetMusicPitch(js_get_music(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_get_music_time_length(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMusicTimeLength(js_get_music(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_get_music_time_played(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_number(v7, GetMusicTimePlayed(js_get_music(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_init_audio_stream(struct v7* v7, v7_val_t* res) {
    js_return_audio_stream(v7, res, InitAudioStream(v7_get_int(v7, v7_arg(v7, 0)), v7_get_int(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2))));
    return V7_OK;
}

static inline enum v7_err js_update_audio_stream(struct v7* v7) {
    UpdateAudioStream(js_get_audio_stream(v7, 0), v7_get_ptr(v7, v7_arg(v7, 1)), v7_get_int(v7, v7_arg(v7, 2)));
    return V7_OK;
}

static inline enum v7_err js_close_audio_stream(struct v7* v7) {
    CloseAudioStream(js_get_audio_stream(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_audio_stream_processed(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsAudioStreamProcessed(js_get_audio_stream(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_play_audio_stream(struct v7* v7) {
    PlayAudioStream(js_get_audio_stream(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_pause_audio_stream(struct v7* v7) {
    PauseAudioStream(js_get_audio_stream(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_resume_audio_stream(struct v7* v7) {
    ResumeAudioStream(js_get_audio_stream(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_audio_stream_playing(struct v7* v7, v7_val_t* res) {
    *res = v7_mk_boolean(v7, (int)IsAudioStreamPlaying(js_get_audio_stream(v7, 0)));
    return V7_OK;
}

static inline enum v7_err js_stop_audio_stream(struct v7* v7) {
    StopAudioStream(js_get_audio_stream(v7, 0));
    return V7_OK;
}

static inline enum v7_err js_set_audio_stream_volume(struct v7* v7) {
    SetAudioStreamVolume(js_get_audio_stream(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_set_audio_stream_pitch(struct v7* v7) {
    SetAudioStreamPitch(js_get_audio_stream(v7, 0), (float)v7_get_double(v7, v7_arg(v7, 1)));
    return V7_OK;
}

static inline enum v7_err js_set_audio_stream_buffer_size_default(struct v7* v7) {
    SetAudioStreamBufferSizeDefault(v7_get_int(v7, v7_arg(v7, 0)));
    return V7_OK;
}

void raylib_v7_load_audio(struct v7* v7) {
    v7_set_method(v7, v7_get_global(v7), "InitAudioDevice", &js_init_audio_device);
    v7_set_method(v7, v7_get_global(v7), "CloseAudioDevice", &js_close_audio_device);
    v7_set_method(v7, v7_get_global(v7), "IsAudioDeviceReady", &js_audio_device_ready);
    v7_set_method(v7, v7_get_global(v7), "SetMasterVolume", &js_set_master_volume);

    v7_set_method(v7, v7_get_global(v7), "LoadWave", &js_load_wave);
    v7_set_method(v7, v7_get_global(v7), "LoadWaveFromMemory", &js_load_wave_from_memory);
    v7_set_method(v7, v7_get_global(v7), "LoadSound", &js_load_sound);
    v7_set_method(v7, v7_get_global(v7), "LoadSoundFromWave", &js_load_sound_from_wave);
    v7_set_method(v7, v7_get_global(v7), "UpdateSound", &js_update_sound);
    v7_set_method(v7, v7_get_global(v7), "UnloadWave", &js_unload_wave);
    v7_set_method(v7, v7_get_global(v7), "UnloadSound", &js_unload_sound);
    v7_set_method(v7, v7_get_global(v7), "ExportWave", &js_export_wave);
    v7_set_method(v7, v7_get_global(v7), "ExportWaveAsCode", &js_export_wave_as_code);

    v7_set_method(v7, v7_get_global(v7), "PlaySound", &js_play_sound);
    v7_set_method(v7, v7_get_global(v7), "StopSound", &js_stop_sound);
    v7_set_method(v7, v7_get_global(v7), "PauseSound", &js_pause_sound);
    v7_set_method(v7, v7_get_global(v7), "ResumeSound", &js_resume_sound);
    v7_set_method(v7, v7_get_global(v7), "PlaySoundMulti", &js_play_sound_multi);
    v7_set_method(v7, v7_get_global(v7), "StopSoundMulti", &js_stop_sound_multi);
    v7_set_method(v7, v7_get_global(v7), "GetSoundsPlaying", &js_get_sounds_playing);
    v7_set_method(v7, v7_get_global(v7), "IsSoundPlaying", &js_sound_playing);
    v7_set_method(v7, v7_get_global(v7), "SetSoundVolume", &js_set_sound_volume);
    v7_set_method(v7, v7_get_global(v7), "SetSoundPitch", &js_set_sound_pitch);
    v7_set_method(v7, v7_get_global(v7), "WaveFormat", &js_wave_format);
    v7_set_method(v7, v7_get_global(v7), "WaveCopy", &js_wave_copy);
    v7_set_method(v7, v7_get_global(v7), "WaveCrop", &js_wave_crop);
    v7_set_method(v7, v7_get_global(v7), "LoadWaveSamples", &js_load_wave_samples);
    v7_set_method(v7, v7_get_global(v7), "UnloadWaveSamples", &js_unload_wave_samples);

    v7_set_method(v7, v7_get_global(v7), "LoadMusicStream", &js_load_music_stream);
    v7_set_method(v7, v7_get_global(v7), "UnloadMusicStream", &js_unload_music_stream);
    v7_set_method(v7, v7_get_global(v7), "PlayMusicStream", &js_play_music_stream);
    v7_set_method(v7, v7_get_global(v7), "UpdateMusicStream", &js_update_music_stream);
    v7_set_method(v7, v7_get_global(v7), "StopMusicStream", &js_stop_music_stream);
    v7_set_method(v7, v7_get_global(v7), "PauseMusicStream", &js_pause_music_stream);
    v7_set_method(v7, v7_get_global(v7), "ResumeMusicStream", &js_resume_music_stream);
    v7_set_method(v7, v7_get_global(v7), "IsMusicPlaying", &js_music_playing);
    v7_set_method(v7, v7_get_global(v7), "SetMusicVolume", &js_set_music_volume);
    v7_set_method(v7, v7_get_global(v7), "SetMusicPitch", &js_set_music_pitch);
    v7_set_method(v7, v7_get_global(v7), "GetMusicTimeLength", &js_get_music_time_length);
    v7_set_method(v7, v7_get_global(v7), "GetMusicTimePlayed", &js_get_music_time_played);

    v7_set_method(v7, v7_get_global(v7), "InitAudioStream", &js_init_audio_stream);
    v7_set_method(v7, v7_get_global(v7), "UpdateAudioStream", &js_update_audio_stream);
    v7_set_method(v7, v7_get_global(v7), "CloseAudioStream", &js_close_audio_stream);
    v7_set_method(v7, v7_get_global(v7), "IsAudioStreamProcessed", &js_audio_stream_processed);
    v7_set_method(v7, v7_get_global(v7), "PlayAudioStream", &js_play_audio_stream);
    v7_set_method(v7, v7_get_global(v7), "PauseAudioStream", &js_pause_audio_stream);
    v7_set_method(v7, v7_get_global(v7), "ResumeAudioStream", &js_resume_audio_stream);
    v7_set_method(v7, v7_get_global(v7), "IsAudioStreamPlaying", &js_audio_stream_playing);
    v7_set_method(v7, v7_get_global(v7), "StopAudioStream", &js_stop_audio_stream);
    v7_set_method(v7, v7_get_global(v7), "SetAudioStreamVolume", &js_set_audio_stream_volume);
    v7_set_method(v7, v7_get_global(v7), "SetAudioStreamPitch", &js_set_audio_stream_pitch);
    v7_set_method(v7, v7_get_global(v7), "SetAudioStreamBufferSizeDefault", &js_set_audio_stream_buffer_size_default);
}
