#pragma once

#include <cmath>
#include <ostream>

namespace lia
{
    const float TOLERANCE = 2e-37f;
    const double PI = 3.1415926535897931;

    inline float radians(float degrees)
    {
        return degrees * 0.0174532925f;
    }

    inline float degrees(float radians)
    {
        return radians * 57.29577951f;
    }

    inline float clamp(float value, float min, float max)
    {
        return std::max(min, std::min(max, value));
    }
}
