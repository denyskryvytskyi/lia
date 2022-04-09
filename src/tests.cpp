#include <iostream>

#include "tests.h"
#include "lia.h"

void tests()
{
    std::cout << "Sandbox" << std::endl;

    std::cout << "-----------------Test----------------\n";

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

    std::cout << "\n------------------------------\n" << std::endl;

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
        lia::mat4 mat; // identity matrix
        std::cout << "Position vector: " << vec << std::endl;
        std::cout << "Matrix: " << mat << std::endl;

        lia::mat4 mat1 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };
        
        lia::mat4 mat2 = {
            {4, 2, 0, 0},
            {2, 0, 2, 0},
            {9, 7, 4, 0},
            {0, 0, 0, 1}
        };
        std::cout << "Matrix1: " << mat1 << std::endl;
        std::cout << "Matrix2: " << mat2 << std::endl;
        std::cout << "--- Matrix multiplication --- " << std::endl;
        std::cout << "Matrix1 * Matrix2: " << mat1 * mat2 << std::endl;


        std::cout << "--- Matrix rotation ---" << std::endl;
        float angleDegrees = 30.0f;
        lia::vec3 axis = { 1, 1, 0 };

        std::cout << "RotateX: " << lia::rotateX(mat, angleDegrees) << std::endl;
        std::cout << "RotateY: " << lia::rotateY(mat, angleDegrees) << std::endl;
        std::cout << "RotateZ: " << lia::rotateZ(mat, angleDegrees) << std::endl;

        mat = lia::rotate(mat, angleDegrees, axis);
        std::cout << "Rotated matrix by angle " << angleDegrees << " degrees around axis: " << axis << std::endl;
        std::cout << mat << std::endl;
        std::cout << vec << std::endl;
        std::cout << "Rotated position vector: " << vec * mat << std::endl;
    }

    ///////

    //lia::mat4 projT = lia::orthographic(-4.0f, 4.0f, -3.0f, 3.0f, -1.0f, 1.0f);
    //lia::mat4 modelT;
    //modelT = lia::rotate(modelT, lia::radians(-55.0f), lia::vec3(0.0f, 0.0f, 1.0f));
    //lia::mat4 viewT;
    //viewT = lia::translate(viewT, lia::vec3(2.0f, 3.0f, 4.0f));
    //lia::mat4 modelT;
    //modelT = lia::scale(modelT, lia::vec3(5.0f, 6.0f, 7.0f));

    //lia::mat4 vm = modelT * viewT;

    //std::cout << lia::transpose(vm) << std::endl;

    //lia::mat4 pvT = projT * viewT;
    //lia::mat4 vpT = viewT * projT;
    //lia::mat4 mpT = projT * modelT;
    //lia::mat4 mvpT = projT * viewT * modelT;


    //std::cout << "-----------------Matrix----------------\n";

    //{
    //    lia::mat4 mat1(0, 2, 3, 1,
    //        2, 1, 5, 3,
    //        3, 4, 1, 6,
    //        1, 2, 3, 1);
    //    lia::mat4 mat2(1, 2, 3, 4,
    //        3, 2, 1, 3,
    //        2, 5, 2, 1,
    //        6, 3, 6, 1);

    //    lia::mat4 matT(0.25f, 0, 0, 0,
    //        0, 0.333f, 0, 0,
    //        0, 0, 1, 0,
    //        0, 0, 0, 1);
    //    
    //    lia::mat4 matT1(1, 0, 0, 0,
    //        0, 1, 0, 0,
    //        0, 0, 1, 0,
    //        0, 1, 0, 1);

    //    // mat 1
    //    std::cout << "First matrix: ";
    //    std::cout << mat1 << std::endl;
    //    // mat 2
    //    std::cout << "Second matrix: ";
    //    std::cout << mat2 << std::endl;
    //    // product
    //    std::cout << "Product of matrices: ";
    //    std::cout << mat1 * mat2 << std::endl; 
    //    
    //    
    //    // product Test
    //    std::cout << "Test Product of matrices: ";
    //    std::cout << matT * matT1 << std::endl;

    //    // inverse matrix of mat1
    //    if (lia::canBeInverse(mat1))
    //    {
    //        lia::mat4 inv1 = lia::inverse(mat1);
    //        std::cout << "Inverse of the first matrix: ";
    //        std::cout << inv1 << std::endl;
    //        // check, should be identity matrix
    //        std::cout << "Check inverse matrix. Product of first and inverse matrix (should be identity matrix): ";
    //        std::cout << mat1 * inv1 << std::endl;

    //        // determinant of first matrix
    //        std::cout << "Determinant = " << mat1.determinant() << " ." << std::endl;
    //    }
    //    else
    //    {
    //        std::cout << "Determinant = " << mat1.determinant() << ". Matrix can't be inversed!" << std::endl;
    //    }

    //    std::cout << std::endl;
    //    lia::mat4 mat4;
    //    std::cout << "Matrix four:\n" << mat4 << std::endl;
    //    mat4 = lia::translate(mat4, lia::vec3(1.0f, 1.0f, 2.0f));
    //    std::cout << "Translated fourth Matrix:\n" << mat4 << std::endl;
    //    std::cout << "Transposed fourth matrix:\n" << lia::transpose(mat4) << std::endl;

    //    lia::mat4 matRot;
    //    std::cout << "Rotation test:\n X axis:" << lia::rotate(matRot, lia::radians(90.0f), lia::vec3(1.0f, 0.0f, 0.0f)) << std::endl;
    //    std::cout << "Y axis:" << lia::rotate(matRot, lia::radians(90.0f), lia::vec3(0.0f, 1.0f, 0.0f)) << std::endl;
    //    std::cout << "Z axis:" << lia::rotate(matRot, lia::radians(90.0f), lia::vec3(0.0f, 0.0f, 1.0f)) << std::endl;
    //    std::cout << "All axis:" << lia::rotate(matRot, lia::radians(90.0f), lia::vec3(1.0f, 1.0f, 1.0f)) << std::endl;


    //    lia::mat4 matScale;
    //    std::cout << "Scale test:" << lia::scale(matScale, lia::vec3(1.5f, 3.0f, 2.0f));
    //}

    //std::cout << "===================================" << std::endl;

    //{
    //    lia::Matrix4D mat1(0, 2, 3, 1,
    //        2, 1, 5, 3,
    //        3, 4, 1, 6,
    //        1, 2, 3, 1);
    //    lia::Matrix4D mat2(1, 2, 3, 4,
    //        3, 2, 1, 3,
    //        2, 5, 2, 1,
    //        6, 3, 6, 1);

    //    // multiplication
    //    lia::Matrix4D mat3 = mat1 * mat2;

    //    // mat 1
    //    std::cout << mat1 << std::endl;
    //    // mat 2
    //    std::cout << mat2 << std::endl;
    //    // multi result
    //    std::cout << mat3 << std::endl;

    //    // inverse matrix of mat1
    //    lia::Matrix4D inv1 = lia::Inverse(mat1);
    //    std::cout << inv1 << std::endl;

    //    // check, should be identity matrix
    //    std::cout << mat1 * inv1 << std::endl;

        //lia::Matrix4D mat4D();
        //std::cout << "4D x:\n" << lia::MakeRotation(lia::radians(90.0f), lia::vec3(1.0f, 0.0f, 0.0f));
        //std::cout << "4D y:\n" << lia::MakeRotation(lia::radians(90.0f), lia::vec3(0.0f, 1.0f, 0.0f));
        //std::cout << "4D z:\n" << lia::MakeRotation(lia::radians(90.0f), lia::vec3(0.0f, 0.0f, 1.0f));
        //std::cout << "4D all:\n" << lia::MakeRotation(lia::radians(90.0f), lia::vec3(1.0f, 1.0f, 1.0f));

    //}
}