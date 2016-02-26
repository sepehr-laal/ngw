#include "ngw.h"
#include "ngw.hpp"

struct _Player      final : public ngw::Player { };
struct _Discoverer  final : public ngw::Discoverer { };

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

NGWAPI(void) ngw_add_plugin_path(const char* path) {
    ngw::addPluginPath(path);
}

NGWAPI(void) ngw_add_binary_path(const char* path) {
    ngw::addBinaryPath(path);
}

NGWAPI(Player*) ngw_player_make(void) {
    return new Player();
}

NGWAPI(void) ngw_player_free(Player* player) {
    delete player;
}

NGWAPI(Discoverer*) ngw_discoverer_make(void) {
    return new Discoverer();
}

NGWAPI(void) ngw_discoverer_free(Discoverer* discoverer) {
    delete discoverer;
}

NGWAPI(int) ngw_discoverer_get_width(Discoverer* discoverer) {
    return discoverer->getWidth();
}

NGWAPI(int) ngw_discoverer_get_height(Discoverer* discoverer) {
    return discoverer->getHeight();
}

NGWAPI(float) ngw_discoverer_get_framerate(Discoverer* discoverer) {
    return discoverer->getFramerate();
}

NGWAPI(NgwBool) ngw_discoverer_get_has_video(Discoverer* discoverer) {
    return discoverer->getHasVideo() != NGW_BOOL_FALSE;
}

NGWAPI(NgwBool) ngw_discoverer_get_has_audio(Discoverer* discoverer) {
    return discoverer->getHasAudio() != NGW_BOOL_FALSE;
}

NGWAPI(NgwBool) ngw_discoverer_get_seekable(Discoverer* discoverer) {
    return discoverer->getSeekable() != NGW_BOOL_FALSE;
}

NGWAPI(double) ngw_discoverer_get_duration(Discoverer* discoverer) {
    return discoverer->getDuration();
}

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
