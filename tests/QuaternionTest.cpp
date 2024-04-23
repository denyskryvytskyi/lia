#include "doctest.h"

#include "Helpers.h"

#include <lia/quaternion.h>

namespace test {

TEST_CASE("Quaternions")
{
    const lia::vec3 eulerAngles(30.0f, 45.0f, 60.0f);

    const lia::mat4 rotationMatrix = lia::quaternion(eulerAngles).getRotationMatrix();

    const lia::mat4 checkQuatRotationMat = {
        { -0.500324f, 0.84773f, 0.176155f, 0 },
        { -0.160124f, 0.109349f, -0.981022f, 0 },
        { -0.850904f, -0.519035f, 0.0810316f, 0 },
        { 0, 0, 0, 1 }
    };

    CompareMatrices(rotationMatrix, checkQuatRotationMat);
}

} // namespace test
