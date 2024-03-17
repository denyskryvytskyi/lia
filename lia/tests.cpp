#include <iostream>
#include <ostream>

#include "lia.h"
#include "tests.h"

namespace lia {
void tests()
{
    std::cout << "Sandbox" << std::endl;

    std::cout << "-----------------Test----------------\n";

    std::cout << isEqual(10.0f, 10.0f) << std::endl;
    std::cout << isEqual(10.0f, 11.0f) << std::endl;
    std::cout << isEqual(10.0, 10.0) << std::endl;
    std::cout << isEqual(10.0, 11.0) << std::endl;

    lia::vec4 vec(2.0f);
    std::cout << vec << std::endl;
    vec += 4.0f;
    vec /= 2.0f;
    std::cout << "Vector operation result (sum and devided): " << vec << std::endl;
    vec = lia::vec4(1, 2, 3, 4);
    std::cout << "Vector operation result (indexing): vec4(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ", " << vec[3] << ");" << std::endl;

    {
        lia::mat4 mat(
            { 0, 1, 2, 3 },
            { 4, 5, 6, 7 },
            { 8, 9, 10, 11 },
            { 12, 13, 14, 15 });

        std::cout << "Matrix operation result (row indexing): " << std::endl;
        std::cout << mat << std::endl;
    }

    std::cout << "\n------------------------------\n"
              << std::endl;

    {
        lia::mat4 mat;
        std::cout << "Default matrix: " << std::endl;
        std::cout << mat << std::endl;

        mat = lia::scale(mat, { 5, 6, 7 }) * lia::translate(mat, { 2, 3, 4 });
        std::cout << "Matrix operation result (scale * translate): " << std::endl;
        std::cout << mat << std::endl;

        lia::mat4 matT;
        matT = lia::transpose(lia::translate(matT, { 2, 3, 4 })) * lia::transpose(lia::scale(matT, { 5, 6, 7 }));
        std::cout << "Matrix operation result (transpose translate * transpose scale): " << std::endl;
        std::cout << matT << std::endl;
    }

    {
        lia::vec4 vec(1.0f);
        lia::mat4 mat;
        mat = lia::translate(mat, { 2, 3, 4 });

        std::cout << "-----------------------" << std::endl;
        std::cout << "Vector: " << vec << std::endl;
        std::cout << "Matrix: " << mat << std::endl;
        std::cout << "Vector * Matrix: " << std::endl;
        std::cout << vec * mat << std::endl;
    }

    {
        lia::mat4 mat({ 1, 2, 3, 0 },
                      { 0, 1, 0, 7 },
                      { 6, 4, 1, 0 },
                      { 0, 0, 0, 1 });

        std::cout << "------------ Determinant of matrix ---------" << std::endl;
        std::cout << "Matrix: " << mat << std::endl;
        std::cout << "Determinant: " << mat.determinant() << std::endl;
        std::cout << "Inverse matrix: " << lia::inverse(mat) << std::endl;
    }

    {
        std::cout << "------------- Transforamtion of matrix -------------" << std::endl;
        lia::vec4 vec(1.0f); // position vector
        lia::mat4 mat;       // identity matrix
        std::cout << "Position vector: " << vec << std::endl;
        std::cout << "Matrix: " << mat << std::endl;

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
        std::cout << "Matrix1: " << mat1 << std::endl;
        std::cout << "Matrix2: " << mat2 << std::endl;
        std::cout << "--- Matrix multiplication --- " << std::endl;
        std::cout << "Matrix1 * Matrix2: " << mat1 * mat2 << std::endl;

        std::cout << "--- Matrix rotation ---" << std::endl;
        float angleDegrees = 30.0f;
        float angleRadians = lia::radians(angleDegrees);
        lia::vec3 axis = { 1, 0, 0 };

        std::cout << "RotateX: " << lia::rotateX(mat, angleRadians) << std::endl;
        std::cout << "RotateY: " << lia::rotateY(mat, angleRadians) << std::endl;
        std::cout << "RotateZ: " << lia::rotateZ(mat, angleRadians) << std::endl;

        mat = lia::rotate(mat, angleRadians, axis);
        std::cout << "Rotated matrix by angle " << angleRadians << " degrees around axis: " << axis << std::endl;
        std::cout << mat << std::endl;
        std::cout << vec << std::endl;
        std::cout << "Rotated position vector: " << vec * mat << std::endl;
    }

    {
        std::cout << "--------------------- Model View Projection Matrices ------------------------------" << std::endl;

        lia::mat4 model;
        model = lia::scale(model, lia::vec3(5.0f, 6.0f, 7.0f));
        model = lia::rotate(model, lia::radians(-55.0f), lia::vec3(0.0f, 0.0f, 1.0f));

        lia::mat4 view;
        view = lia::translate(view, lia::vec3(2.0f, 3.0f, 4.0f));

        lia::mat4 proj = lia::orthographic(-4.0f, 4.0f, -3.0f, 3.0f, -1.0f, 1.0f);

        lia::mat4 mvp = model * view * proj;

        std::cout << "MVP matrix: " << mvp << std::endl;
    }
}
} // namespace lia
