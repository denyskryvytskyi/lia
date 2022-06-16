#pragma once

#include "mathbase.h"
#include "vec4.h"
#include "vec3.h"

namespace lia
{
    /**
     * Vectors are treated as rows, resulting in a matrix that is represented as follows,
     * where tx, ty and tz are the translation components of the matrix:
     *
     * 1   0   0   0
     * 0   1   0   0
     * 0   0   1   0
     * tx  ty  tz  1
     */
    struct mat4
    {
    protected:
        float m[4][4];

    public:
        /**
        * Constructs an identity matrix.
        */
        mat4()
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

        /**
        * Constructs a matrix initialized by the vectors.
        *
        * @param row1 The x unit basis vector
        * @param row2 The y unit basis vector
        * @param row3 The z unit basis vector
        * @param row4 The translation vector
        */
        mat4(vec4 row1, vec4 row2, vec4 row3, vec4 row4)
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

        /**
         * Constructs an matrix with scalar by diagonal.
         *
         * @param scalar Diagonal scalar value
         */
        mat4(float scalar)
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

        float& operator()(int i, int j)
        {
            return m[i][j];
        }

        const float& operator()(int i, int j) const
        {
            return m[i][j];
        }

        vec4& operator[](int row_index)
        {
            return (*reinterpret_cast<vec4*>(m[row_index]));
        }
        
        const vec4& operator[](int row_index) const
        {
            return (*reinterpret_cast<const vec4*>(m[row_index]));
        }

        const float* elementsPtr() const
        {
            return &(m[0][0]);
        }

        float determinant() const
        {
            float a0 = m[0][0] * m[1][1] - m[0][1] * m[1][0];
            float a1 = m[0][0] * m[1][2] - m[0][2] * m[1][0];
            float a2 = m[0][0] * m[1][3] - m[0][3] * m[1][0];
            float a3 = m[0][1] * m[1][2] - m[0][2] * m[1][1];
            float a4 = m[0][1] * m[1][3] - m[0][3] * m[1][1];
            float a5 = m[0][2] * m[1][3] - m[0][3] * m[1][2];
            float b0 = m[2][0] * m[3][1] - m[2][1] * m[3][0];
            float b1 = m[2][0] * m[3][2] - m[2][2] * m[3][0];
            float b2 = m[2][0] * m[3][3] - m[2][3] * m[3][0];
            float b3 = m[2][1] * m[3][2] - m[2][2] * m[3][1];
            float b4 = m[2][1] * m[3][3] - m[2][3] * m[3][1];
            float b5 = m[2][2] * m[3][3] - m[2][3] * m[3][2];

            return (a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0);
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

    inline vec4 operator*(const vec4& vec, const mat4& mat)
    {
        return vec4(mat(0, 0) * vec.x + mat(1, 0) * vec.y + mat(2, 0) * vec.z + mat(3, 0) * vec.w,
                    mat(0, 1) * vec.x + mat(1, 1) * vec.y + mat(2, 1) * vec.z + mat(3, 1) * vec.w,
                    mat(0, 2) * vec.x + mat(1, 2) * vec.y + mat(2, 2) * vec.z + mat(3, 2) * vec.w,
                    mat(0, 3) * vec.x + mat(1, 3) * vec.y + mat(2, 3) * vec.z + mat(3, 3) * vec.w);
    }

    inline std::ostream& operator<<(std::ostream& stream, const mat4& mat)
    {
        stream << "mat4 {\n";
        stream << mat[0] << "\n";
        stream << mat[1] << "\n";
        stream << mat[2] << "\n";
        stream << mat[3] << "\n";
        stream << "}\n";

        return stream;
    }

    inline bool canBeInverse(const mat4& mat)
    {
        // if determinant close to zero, can't convert
        return !(std::abs(mat.determinant()) <= TOLERANCE);
    }

    /**
    * Warning: return identity matrix if the matrix cannot be inversed (determinant <= 0)
    */
    inline mat4 inverse(const mat4& mat)
    {
        // if determinant close to zero, can't convert
        if (std::abs(mat.determinant()) <= TOLERANCE)
            return mat4();

        const vec3& a = vec3(mat(0, 0), mat(1, 0), mat(2, 0));
        const vec3& b = vec3(mat(0, 1), mat(1, 1), mat(2, 1));
        const vec3& c = vec3(mat(0, 2), mat(1, 2), mat(2, 2));
        const vec3& d = vec3(mat(0, 3), mat(1, 3), mat(2, 3));

        const float& x = mat(3, 0);
        const float& y = mat(3, 1);
        const float& z = mat(3, 2);
        const float& w = mat(3, 3);

        vec3 s = cross(a, b);
        vec3 t = cross(c, d);
        vec3 u = a * y - b * x;
        vec3 v = c * w - d * z;

        float invDet = 1.0F / (dot(s, v) + dot(t, u));
        s *= invDet;
        t *= invDet;
        u *= invDet;
        v *= invDet;

        vec3 r0 = cross(b, v) + t * y;
        vec3 r1 = cross(v, a) - t * x;
        vec3 r2 = cross(d, u) + s * w;
        vec3 r3 = cross(u, c) - s * z;

        return (mat4(r0.x, r0.y, r0.z, -dot(b, t),
                     r1.x, r1.y, r1.z, dot(a, t),
                     r2.x, r2.y, r2.z, -dot(d, s),
                     r3.x, r3.y, r3.z, dot(c, s)));
    }

    inline mat4 transpose(const mat4& mat)
    {
        return mat4(vec4(mat(0, 0), mat(1, 0), mat(2, 0), mat(3, 0)),
                    vec4(mat(0, 1), mat(1, 1), mat(2, 1), mat(3, 1)),
                    vec4(mat(0, 2), mat(1, 2), mat(2, 2), mat(3, 2)),
                    vec4(mat(0, 3), mat(1, 3), mat(2, 3), mat(3, 3)));
    }

    inline mat4 translate(const mat4& mat, const vec3& translation)
    {
        mat4 result;
        result(3, 0) = translation.x;
        result(3, 1) = translation.y;
        result(3, 2) = translation.z;

        return mat * result;
    }

    /**
    * @param angle The angle in radians
    * @param axis The unit vector
    */
    inline mat4 rotate(const mat4& mat, const float& angle, const vec3& vec)
    {
        float cos_ = std::cos(angle);
        float sin_ = std::sin(angle);
        float d = 1.0f - cos_;

        const vec3 axis = normalize(vec);

        float x = axis.x * d;
        float y = axis.y * d;
        float z = axis.z * d;
        float axay = x * axis.y;
        float axaz = x * axis.z;
        float ayaz = y * axis.z;

        return mat * mat4(cos_ + x * axis.x, axay + sin_ * axis.z, axaz - sin_ * axis.y, 0.0f,
                          axay - sin_ * axis.z, cos_ + y * axis.y, ayaz + sin_ * axis.x, 0.0f,
                          axaz + sin_ * axis.y, ayaz - sin_ * axis.x, cos_ + z * axis.z, 0.0f,
                          0.0f, 0.0f, 0.0f, 1.0f);
    }

    /**
    * @param angle The angle in radians
    */
    inline mat4 rotateX(const mat4& mat, const float& angle)
    {
        float cos_ = std::cos(angle);
        float sin_ = std::sin(angle);

        return mat * mat4(1, 0, 0, 0,
                          0, cos_, sin_, 0,
                          0, -sin_, cos_, 0,
                          0, 0, 0, 1);
    }
    
    /**
    * @param angle The angle in radians
    */
    inline mat4 rotateY(const mat4& mat, const float& angle)
    {
        float cos_ = std::cos(angle);
        float sin_ = std::sin(angle);

        return mat * mat4(cos_, 0, -sin_, 0,
                          0, 1, 0, 0,
                          sin_, 0, cos_, 0,
                          0, 0, 0, 1);
    }
    
    /**
    * @param angle The angle in radians
    */
    inline mat4 rotateZ(const mat4& mat, const float& angle)
    {
        float cos_ = std::cos(angle);
        float sin_ = std::sin(angle);

        return mat * mat4(cos_, sin_, 0, 0,
                          -sin_, cos_, 0, 0,
                          0, 0, 1, 0,
                          0, 0, 0, 1);
    }

    inline mat4 scale(const mat4& mat, const vec3& scale)
    {
        mat4 scaled;
        scaled(0, 0) = scale.x;
        scaled(1, 1) = scale.y;
        scaled(2, 2) = scale.z;

        return mat * scaled;
    }

    inline mat4 orthographic(float left, float right, float bottom, float top, float near_, float far_)
    {
        return mat4(2.0f / (right - left), 0.0f, 0.0f, 0.0f,
                    0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
                    0.0f, 0.0f, -2.0f / (far_ - near_), 0.0f,
                    -((right + left) / (right - left)), -((top + bottom) / (top - bottom)), -((far_ + near_) / (far_ - near_)), 1.0f);
    }

    /**
    * Creates a perspective projection matrix from the given parameters.
    * 
    * @param fov Field of View in radians that sets the width of the perspective frustum
    * @param aspect Specifies the aspect ratio of the scene
    * @param near Specifies the near plane of the perspective frustum
    * @param far Specifies the far plane of the perspective frustum
    */
    inline mat4 perspective(float fov, float aspect, float near_, float far_)
    {
        float top = near_ * std::tan((fov / 2.0f));
        float bottom = -top;
        float right = top * aspect;
        float left = -right;

        return mat4((2.0f * near_) / (right - left), 0.0f, 0.0f, 0.0f,
                    0.0f, (2.0f * near_) / (top - bottom), 0.0f, 0.0f,
                    (right + left) / (right - left), (top + bottom) / (top - bottom), -((far_ + near_) / (far_ - near_)), -1.0f,
                    0.0f, 0.0f, -((2.0f * near_ * far_) / (far_ - near_)), 0.0f);
    }

    inline mat4 lookAt(vec3 eyePosition, vec3 target, vec3 up)
    {
        const vec3 cameraDirection = normalize(eyePosition - target);
        const vec3 cameraRight = normalize(cross(up, cameraDirection));
        const vec3 cameraUp = cross(cameraDirection, cameraRight);

        return mat4(cameraRight.x, cameraUp.x, cameraDirection.x, 0.0f,
                    cameraRight.y, cameraUp.y, cameraDirection.y, 0.0f,
                    cameraRight.z, cameraUp.z, cameraDirection.z, 0.0f,
                    -dot(cameraRight, eyePosition), -dot(cameraUp, eyePosition), -dot(cameraDirection, eyePosition), 1.0f);
    }
}
