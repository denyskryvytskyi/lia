#include "doctest.h"

#include <lia/vec2.h>
#include <lia/vec3.h>
#include <lia/vec4.h>

namespace test {
TEST_CASE("Vectors")
{
    SUBCASE("Vec2")
    {
        lia::vec2 v2;

        REQUIRE_EQ(v2.x, 0.0f);
        REQUIRE_EQ(v2.y, 0.0f);

        v2 += 10.0f;
        v2.x += 5.0f;

        REQUIRE_EQ(v2.x, 15.0f);
        REQUIRE_EQ(v2.y, 10.0f);

        const float magCalc = sqrt(v2.x * v2.x + v2.y * v2.y);

        REQUIRE_EQ(magCalc, lia::magnitude(v2));
    }

    SUBCASE("Vec3")
    {
        lia::vec3 v3_0;

        REQUIRE_EQ(v3_0.x, 0.0f);
        REQUIRE_EQ(v3_0.y, 0.0f);
        REQUIRE_EQ(v3_0.z, 0.0f);

        v3_0 += 10.0f;
        v3_0.x += 5.0f;
        v3_0.z -= 3.0f;

        REQUIRE_EQ(v3_0.x, 15.0f);
        REQUIRE_EQ(v3_0.y, 10.0f);
        REQUIRE_EQ(v3_0.z, 7.0f);

        const lia::vec3 v3_1(7.0f, 5.0f, 3.0f);

        const float dotProduct = v3_0.x * v3_1.x + v3_0.y * v3_1.y + v3_0.z * v3_1.z;

        REQUIRE_EQ(dotProduct, lia::dot(v3_0, v3_1));

        const lia::vec3 crossProduct = lia::cross(v3_0, v3_1);

        REQUIRE_EQ(crossProduct.x, -5.0f);
        REQUIRE_EQ(crossProduct.y, 4.0f);
        REQUIRE_EQ(crossProduct.z, 5.0f);

        const lia::vec3 v3_0_normalized = lia::normalize(v3_0);

        REQUIRE_EQ(lia::magnitude(v3_0_normalized), 1.0f);
    }
}
} // namespace test
