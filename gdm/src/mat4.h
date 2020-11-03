#pragma once

#include "vec4.h"

namespace gdm
{
    /**
     * Vectors are treated as row, resulting in a matrix that is represented as follows,
     * where tx, ty and tz are the translation components of the matrix:
     *
     * 1   0   0   0
     * 0   1   0   0
     * 0   0   0   1
     * tx  ty  tz  1
     */
    struct mat4
    {
    protected:
        float m[16];

    public:
        mat4() = default;

        /**
        * Constructs a matrix initialized to the specified value.
        *
        * @param m00 The first element of the first row.
        * @param m01 The second element of the first row.
        * @param m02 The third element of the first row.
        * @param m03 The fourth element of the first row.
        * @param m10 The first element of the second row.
        * @param m11 The second element of the second row.
        * @param m12 The third element of the second row.
        * @param m13 The fourth element of the second row.
        * @param m20 The first element of the third row.
        * @param m21 The second element of the third row.
        * @param m22 The third element of the third row.
        * @param m23 The fourth element of the third row.
        * @param m30 The first element of the fourth row.
        * @param m31 The second element of the fourth row.
        * @param m32 The third element of the fourth row.
        * @param m33 The fourth element of the fourth row.
        */
        mat4(float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33);

        /**
        * Constructs a matrix initialized by the vectors.
        *
        * @param row1 The x unit basis vector
        * @param row2 The y unit basis vector
        * @param row3 The z unit basis vector
        * @param row4 The translation vector
        */
        mat4(vec4 row1, vec4 row2, vec4 row3, vec4 row4);

        /**
         * Constructs an identity matrix.
         *
         * @param scalar Diagonal scalar value
         */
        mat4(float scalar);

        float& operator()(int i, int j)
        {
            return m[j + i * 4];
        }

        const float& operator()(int i, int j) const
        {
            return m[j + i * 4];
        }
    };

    inline mat4 operator*(const mat4& mat1, const mat4& mat2)
    {
        float p[16];

        for (int16_t col = 0; col < 4; col++)
        {
            for (int16_t row = 0; row < 4; row++)
            {
                float sum = 0.0f;
                for (int16_t i = 0; i < 4; i++)
                {
                    sum += mat1(row, i) * mat2(i, col);
                }
                p[col + row * 4] = sum;
            }
        }

        return mat4(p[0], p[1], p[2], p[3],
            p[4], p[5], p[6], p[7],
            p[8], p[9], p[10], p[11],
            p[12], p[13], p[14], p[15]);
    }

    inline vec4 operator*(const mat4& mat, const vec4& vec)
    {
        return vec4(mat(0, 0) * vec.x + mat(0, 1) * vec.y + mat(0, 2) * vec.z + mat(0, 3) * vec.w,
            mat(1, 0) * vec.x + mat(1, 1) * vec.y + mat(1, 2) * vec.z + mat(1, 3) * vec.w,
            mat(2, 0) * vec.x + mat(2, 1) * vec.y + mat(2, 2) * vec.z + mat(2, 3) * vec.w,
            mat(3, 0) * vec.x + mat(3, 1) * vec.y + mat(3, 2) * vec.z + mat(3, 3) * vec.w);
    }

    inline std::ostream& operator<<(std::ostream& stream, const mat4& mat)
    {
        stream << "mat4 {\n";
        stream << mat(0, 0) << " " << mat(0, 1) << " " << mat(0, 2) << " " << mat(0, 3) << "\n";
        stream << mat(1, 0) << " " << mat(1, 1) << " " << mat(1, 2) << " " << mat(1, 3) << "\n";
        stream << mat(2, 0) << " " << mat(2, 1) << " " << mat(2, 2) << " " << mat(2, 3) << "\n";
        stream << mat(3, 0) << " " << mat(3, 1) << " " << mat(3, 2) << " " << mat(3, 3) << "\n";
        stream << "}\n";

        return stream;
    }
}
