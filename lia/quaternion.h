#pragma once

#include "mat4.h"
#include "vec3.h"

namespace lia {
struct quaternion {
    float x { 0.0f };
    float y { 0.0f };
    float z { 0.0f };
    float w { 1.0f };

    quaternion() = default;

    quaternion(const float xx, const float yy, const float zz, const float s)
        : x(xx)
        , y(yy)
        , z(zz)
        , w(s)
    { }

    quaternion(const vec3& v, const float s)
        : x(v.x)
        , y(v.y)
        , z(v.z)
        , w(s)
    { }

    quaternion(const vec3& eulerAngles)
    {
        const vec3 halfAngles = eulerAngles * 0.5f;

        const float cy = cos(halfAngles.z);
        const float sy = sin(halfAngles.z);
        const float cp = cos(halfAngles.y);
        const float sp = sin(halfAngles.y);
        const float cr = cos(halfAngles.x);
        const float sr = sin(halfAngles.x);

        x = sr * cp * cy - cr * sp * sy;
        y = cr * sp * cy + sr * cp * sy;
        z = cr * cp * sy - sr * sp * cy;
        w = cr * cp * cy + sr * sp * sy;
    }

    vec3& GetVectorPart()
    {
        return reinterpret_cast<vec3&>(x);
    }

    const vec3& GetVectorPart() const
    {
        return reinterpret_cast<const vec3&>(x);
    }

    quaternion& operator+=(const quaternion& q)
    {
        x += q.x;
        y += q.y;
        z += q.z;
        w += q.w;
        return *this;
    }

    quaternion& operator-=(const quaternion& q)
    {
        x -= q.x;
        y -= q.y;
        z -= q.z;
        w -= q.w;
        return *this;
    }

    quaternion& operator*=(const quaternion& q)
    {
        x *= q.x;
        y *= q.y;
        z *= q.z;
        w *= q.w;
        return *this;
    }

    quaternion& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    quaternion& operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }

    float& operator[](int index)
    {
        return ((&x)[index]);
    }

    const float& operator[](int index) const
    {
        return ((&x)[index]);
    }

    /**
     * Convert matrix to quaternion
     */
    void setRotationMatrix(const mat4& m)
    {
        const float m00 = m(0, 0);
        const float m11 = m(1, 1);
        const float m22 = m(2, 2);
        const float sum = m00 + m11 + m22;

        if (sum > 0.0f) {
            w = sqrt(sum + 1.0f) * 0.5f;
            float f = 0.25f / w;

            x = (m(2, 1) - m(1, 2)) * f;
            y = (m(0, 2) - m(2, 0)) * f;
            z = (m(1, 0) - m(0, 1)) * f;
        } else if ((m00 > m11) && (m00 > m22)) {
            x = sqrt(m00 - m11 - m22 + 1.0f) * 0.5f;
            float f = 0.25f / x;

            y = (m(1, 0) + m(0, 1)) * f;
            z = (m(0, 2) + m(2, 0)) * f;
            w = (m(2, 1) - m(1, 2)) * f;
        } else if (m11 > m22) {
            y = sqrt(m11 - m00 - m22 + 1.0f) * 0.5f;
            float f = 0.25f / y;

            x = (m(1, 0) + m(0, 1)) * f;
            z = (m(2, 1) + m(1, 2)) * f;
            w = (m(0, 2) - m(2, 0)) * f;
        } else {
            w = sqrt(m22 - m00 - m11 + 1.0f) * 0.5f;
            float f = 0.25f / w;

            x = (m(0, 2) + m(2, 0)) * f;
            y = (m(2, 1) + m(1, 2)) * f;
            z = (m(1, 0) - m(0, 1)) * f;
        }
    }

    /**
     * Convert quaternion to matrix
     */
    mat4 getRotationMatrix()
    {
        const float x2 = x * x;
        const float y2 = y * y;
        const float z2 = z * z;
        const float xy = x * y;
        const float xz = x * z;
        const float yz = y * z;
        const float wx = w * x;
        const float wy = w * y;
        const float wz = w * z;

        return mat4(1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy), 0,
                    2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx), 0,
                    2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2), 0,
                    0, 0, 0, 1);
    }
};

inline const quaternion operator+(const quaternion& q1, const quaternion& q2)
{
    return quaternion(q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w);
}

inline const quaternion operator-(const quaternion& q1, const quaternion& q2)
{
    return quaternion(q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w);
}

inline quaternion operator*(const quaternion& q1, const quaternion& q2)
{
    return quaternion(q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
                      q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
                      q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
                      q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z);
}

inline const quaternion operator*(const quaternion& q, float scalar)
{
    return quaternion(q.x * scalar, q.y * scalar, q.z * scalar, q.w * scalar);
}

inline const quaternion operator/(const quaternion& q, float scalar)
{
    return quaternion(q.x / scalar, q.y / scalar, q.z / scalar, q.w / scalar);
}

inline quaternion Conjugate(const quaternion& q)
{
    return quaternion(-q.x, -q.y, -q.z, q.w);
}

inline vec3 rotate(const vec3& v, const quaternion& q)
{
    const vec3& b = q.GetVectorPart();
    const float b2 = b.x * b.x + b.y * b.y + b.z * b.z;
    return (v * (q.w * q.w - b2) + b * (dot(v, b) * 2.0f)
            + cross(b, v) * (q.w * 2.0f));
}

/**
 * @param angle Angle in radians
 */
inline quaternion rotationX(float angle)
{
    const float halfAngle = angle * 0.5f;
    return quaternion(sin(halfAngle), 0, 0, cos(halfAngle));
}

/**
 * @param angle Angle in radians
 */
inline quaternion rotationY(float angle)
{
    const float halfAngle = angle * 0.5f;
    return quaternion(0, sin(halfAngle), 0, cos(halfAngle));
}

/**
 * @param angle Angle in radians
 */
inline quaternion rotationZ(float angle)
{
    const float halfAngle = angle * 0.5f;
    return quaternion(0, 0, sin(halfAngle), cos(halfAngle));
}
} // namespace lia
