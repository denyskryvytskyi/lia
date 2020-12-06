#pragma once

namespace gdm
{
    #define TOLERANCE 2e-37f

    // Conversion from degrees to radians
    inline float radians(float degrees)
    {
        return degrees * 0.0174532925f;
    }

    // Macro for conversion from radians to degrees
    inline float degrees(float radians)
    {
        return radians * 57.29577951f;
    }

    inline float clamp(float value, float min, float max)
    {
        return std::max(min, std::min(max, value));
    }
}
