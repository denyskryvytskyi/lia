#include "doctest.h"

#include "Helpers.h"

#include <lia/mat4.h>

namespace test {

TEST_CASE("Matrix")
{
    lia::mat4 mat(5.0f);

    SUBCASE("Init")
    {
        const lia::vec4 r1(5.0f, 0.0, 0.0f, 0.0f);
        const lia::vec4 r2(0.0f, 5.0, 0.0f, 0.0f);
        const lia::vec4 r3(0.0f, 0.0, 5.0f, 0.0f);
        const lia::vec4 r4(0.0f, 0.0, 0.0f, 5.0f);

        CompareVectors(mat[0], r1);
        CompareVectors(mat[1], r2);
        CompareVectors(mat[2], r3);
        CompareVectors(mat[3], r4);
    }

    SUBCASE("Determinant")
    {
        REQUIRE_EQ(mat.determinant(), 625.0f);
    }

    SUBCASE("Transformation: scale")
    {
        const lia::vec3 scale(3.0f, 2.0f, 3.4f);
        const lia::mat4 scaled = lia::scale(mat, scale);
        REQUIRE_EQ(scaled(0, 0), 15.0f);
        REQUIRE_EQ(scaled(1, 1), 10.0f);
        REQUIRE_EQ(scaled(2, 2), 17.0f);
    }

    SUBCASE("Transformation: rotation")
    {
        const float angleRadians = lia::radians(10.0f);
        const lia::vec3 axis = { 1, 0, 0 };
        const lia::mat4 rotated = lia::rotate(mat, angleRadians, axis);
        const lia::mat4 checkRotationMat = {
            { 5.0f, 0.0f, 0.0f, 0.0f },
            { 0.0f, 4.92404f, 0.868241f, 0.0f },
            { 0.0f, -0.868241f, 4.92404f, 0.0f },
            { 0.0f, 0.0f, 0.0f, 5.0f }
        };

        CompareMatrices(rotated, checkRotationMat);
    }

    SUBCASE("Transformation: translation")
    {
        lia::mat4 mat(1.0f);
        const lia::vec3 translation(3.0f, 5.0f, 3.5f);
        const lia::mat4 matTranslated = lia::translate(mat, translation);

        CompareVectors(matTranslated[3], { 3.0f, 5.0f, 3.5, 1.0f });
    }

    SUBCASE("Multiplication")
    {
        lia::mat4 mat1 = {
            { 1, 2, 3, 4 },
            { 5, 6, 7, 8 },
            { 9, 10, 11, 12 },
            { 13, 14, 15, 16 }
        };

        lia::mat4 mat2 = {
            { 4, 2, 0, 0 },
            { 2, 0, 2, 0 },
            { 9, 7, 4, 0 },
            { 0, 0, 0, 1 }
        };

        const lia::mat4 matMultresult = mat1 * mat2;

        const lia::mat4 checkMatMult = {
            { 35, 23, 16, 4 },
            { 95, 59, 40, 8 },
            { 155, 95, 64, 12 },
            { 215, 131, 88, 16 }
        };

        CompareMatrices(matMultresult, checkMatMult);
    }
}
} // namespace test
