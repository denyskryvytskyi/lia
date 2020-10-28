#pragma once

#include <cmath>
#include <ostream>

namespace gdm
{
    struct vec2
    {
        float x, y;

        vec2() = default;

        vec2(float xx, float yy)
            : x(xx), y(yy)
        {}

        vec2(float scalar)
            : x(scalar), y(scalar)
        {}

        vec2& operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;

            return (*this);
        }

        vec2& operator/=(float scalar)
        {
            scalar = 1.0f / scalar;
            x *= scalar;
            y *= scalar;

            return (*this);
        }

        vec2& operator+=(const vec2& v)
        {
            x += v.x;
            y += v.y;

            return (*this);
        }

        vec2& operator-=(const vec2& v)
        {
            x -= v.x;
            y -= v.y;

            return (*this);
        }
    };

    vec2 operator*(const vec2& v, float scalar)
    {
        return vec2(v.x * scalar, v.y * scalar);
    }

    vec2 operator/(const vec2& v, float scalar)
    {
        scalar = 1.0f / scalar;
        return vec2(v.x * scalar, v.y * scalar);
    }

    vec2 operator-(const vec2& v)
    {
        return vec2(-v.x, -v.y);
    }

    float magnitude(const vec2& v)
    {
        return sqrt(v.x * v.x + v.y * v.y);
    }

    vec2 normalize(const vec2& v)
    {
        return v / magnitude(v);
    }

    vec2 operator+(const vec2& first, const vec2& second)
    {
        return (vec2(first.x + second.x, first.y + second.y));
    }

    vec2 operator-(const vec2& first, const vec2& second)
    {
        return (vec2(first.x - second.x, first.y - second.y));
    }

    std::ostream& operator<<(std::ostream& stream, const vec2& vector)
    {
        stream << "vec3(" << vector.x << ", " << vector.y << ")";

        return stream;
    }
}