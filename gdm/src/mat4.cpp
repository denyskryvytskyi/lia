#include "mat4.h"

namespace gdm
{
    mat4::mat4()
    {
        m[0][0] = 1.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[0][3] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 1.0f;
        m[1][2] = 0.0f;
        m[1][3] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.0f;
        m[2][3] = 0.0f;
        m[3][0] = 0.0f;
        m[3][1] = 0.0f;
        m[3][2] = 0.0f;
        m[3][3] = 1.0f;
    }
    
    mat4::mat4(float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33)
    {
        m[0][0] = m00;
        m[0][1] = m01;
        m[0][2] = m02;
        m[0][3] = m03;
        m[1][0] = m10;
        m[1][1] = m11;
        m[1][2] = m12;
        m[1][3] = m13;
        m[2][0] = m20;
        m[2][1] = m21;
        m[2][2] = m22;
        m[2][3] = m23;
        m[3][0] = m30;
        m[3][1] = m31;
        m[3][2] = m32;
        m[3][3] = m33;
    }

    mat4::mat4(vec4 row1, vec4 row2, vec4 row3, vec4 row4)
    {
        m[0][0] = row1.x;
        m[0][1] = row1.y;
        m[0][2] = row1.z;
        m[0][3] = row1.w;
        m[1][0] = row2.x;
        m[1][1] = row2.y;
        m[1][2] = row2.z;
        m[1][3] = row2.w;
        m[2][0] = row3.x;
        m[2][1] = row3.y;
        m[2][2] = row3.z;
        m[2][3] = row3.w;
        m[3][0] = row4.x;
        m[3][1] = row4.y;
        m[3][2] = row4.z;
        m[3][3] = row4.w;
    }

    mat4::mat4(float scalar)
    {
        m[0][0] = scalar;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[0][3] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = scalar;
        m[1][2] = 0.0f;
        m[1][3] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = scalar;
        m[2][3] = 0.0f;
        m[3][0] = 0.0f;
        m[3][1] = 0.0f;
        m[3][2] = 0.0f;
        m[3][3] = scalar;
    }
}