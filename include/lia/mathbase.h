#pragma once

#include "vec3.h"

#include <algorithm>
#include <ostream>

namespace lia {
constexpr float TOLERANCE = 2e-37f;
constexpr double PI = 3.1415926535897931;
constexpr double TAU = 6.28318530717;

inline float radians(const float degrees)
{
    return degrees * 0.0174532925f;
}

inline vec3 radians(const vec3& degrees)
{
    return vec3(radians(degrees.x), radians(degrees.y), radians(degrees.z));
}

inline float degrees(const float radians)
{
    return radians * 57.29577951f;
}

inline vec3 degrees(const vec3& radians)
{
    return vec3(degrees(radians.x), degrees(radians.y), degrees(radians.z));
}

inline float clamp(const float value, const float min, const float max)
{
    return std::max(min, std::min(max, value));
}

inline bool isEqual(const double a, const double b)
{
    return std::abs(a - b) < TOLERANCE;
}

inline bool isEqual(const float a, const float b)
{
    return std::abs(a - b) < TOLERANCE;
}
} // namespace lia
