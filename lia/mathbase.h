#pragma once

#include <algorithm>
#include <ostream>

namespace lia {
const float TOLERANCE = 2e-37f;
const double PI = 3.1415926535897931;
const double TAU = 6.28318530717;

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

inline bool isEqual(double a, double b)
{
    return std::abs(a - b) < TOLERANCE;
}

inline bool isEqual(float a, float b)
{
    return std::abs(a - b) < TOLERANCE;
}
} // namespace lia
