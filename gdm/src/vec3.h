#pragma once

#include <cmath>
#include <ostream>

namespace gdm
{
    struct vec3
    {
        float x, y, z;

        vec3() = default;

        vec3(float xx, float yy, float zz)
            : x(xx), y(yy), z(zz)
        {}

        vec3(float scalar)
            : x(scalar), y(scalar), z(scalar)
        {}

        vec3& operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;

            return (*this);
        }

        vec3& operator/=(float scalar)
        {
            scalar = 1.0f / scalar;
            x *= scalar;
            y *= scalar;
            z *= scalar;

            return (*this);
        }

        vec3& operator+=(const vec3& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;

            return (*this);
        } 
        
        vec3& operator-=(const vec3& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;

            return (*this);
        }
    };

    vec3 operator*(const vec3& v, float scalar)
    {
        return vec3(v.x * scalar, v.y * scalar, v.z * scalar);
    }
    
    vec3 operator/(const vec3& v, float scalar)
    {
        scalar = 1.0f / scalar;
        return vec3(v.x * scalar, v.y * scalar, v.z * scalar);
    }
    
    vec3 operator-(const vec3& v)
    {
        return vec3(-v.x, -v.y, -v.z);
    }

    float magnitude(const vec3& v)
    {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    vec3 normalize(const vec3& v)
    {
        return v / magnitude(v);
    }

    vec3 operator+(const vec3& first, const vec3& second)
    {
        return (vec3(first.x + second.x, first.y + second.y, first.z + second.z));
    }

    vec3 operator-(const vec3& first, const vec3& second)
    {
        return (vec3(first.x - second.x, first.y - second.y, first.z - second.z));
    }

    std::ostream& operator<<(std::ostream& stream, const vec3& vector)
    {
        stream << "vec3(" << vector.x << ", " << vector.y << ", " << vector.z << ")";

        return stream;
    }
}