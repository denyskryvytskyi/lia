#include "mat4.h"

namespace gdm
{
    mat4::mat4(float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33)
    {
        m[0] = m00;
        m[1] = m01;
        m[2] = m02;
        m[3] = m03;
        m[4] = m10;
        m[5] = m11;
        m[6] = m12;
        m[7] = m13;
        m[8] = m20;
        m[9] = m21;
        m[10] = m22;
        m[11] = m23;
        m[12] = m30;
        m[13] = m31;
        m[14] = m32;
        m[15] = m33;
    }

    mat4::mat4(vec4 row1, vec4 row2, vec4 row3, vec4 row4)
    {
        m[0] = row1.x;
        m[1] = row1.y;
        m[2] = row1.z;
        m[3] = row1.w;
        m[4] = row2.x;
        m[5] = row2.y;
        m[6] = row2.z;
        m[7] = row2.w;
        m[8] = row3.x;
        m[9] = row3.y;
        m[10] = row3.z;
        m[11] = row3.w;
        m[12] = row4.x;
        m[13] = row4.y;
        m[14] = row4.z;
        m[15] = row4.w;
    }

    mat4::mat4(float scalar)
    {
        m[0 + 0 * 4] = scalar;
        m[1 + 1 * 4] = scalar;
        m[2 + 2 * 4] = scalar;
        m[3 + 3 * 4] = scalar;
    }
}