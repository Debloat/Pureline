/*
By Kaptan Yosun @ mmotutkunlari.com

This header is used to store various values for debugging purposes.
*/

#pragma once

#include "../EterBase/Singleton.h"

class YosunControlCenter : public CSingleton<YosunControlCenter>
{
    public:
        inline static constexpr float defaultWindStrength = 40.0f;
        float fWindStrength = defaultWindStrength;

        inline static constexpr float defaultWindOscillationSpeed = 20.0f;
        float windOscillationSpeed = defaultWindOscillationSpeed;

        inline static uint8_t anisotropyLevel = 0;
        inline static bool speedTreeAnisotropy  = false;
        inline static bool interfaceAnisotropy  = false;

        /* - SHADERS ------------------------------------------- */
        inline static bool waveShader           = false;
        inline static bool greyscaleShader      = false;
        inline static bool pixelateShader       = false;
        inline static bool invertColorsShader   = false;
        inline static bool atlasSpotlightShader = false;
        inline static bool uiBlurShader         = false;
        inline static bool waterShader          = false;
        /* ----------------------------------------------------- */
};
