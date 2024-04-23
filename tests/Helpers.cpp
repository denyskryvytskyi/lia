#include "Helpers.h"
#include "doctest.h"

void test::CompareVectors(const lia::vec4& v1, const lia::vec4& v2)
{
    REQUIRE(v1.x == doctest::Approx(v2.x));
    REQUIRE(v1.y == doctest::Approx(v2.y));
    REQUIRE(v1.z == doctest::Approx(v2.z));
    REQUIRE(v1.w == doctest::Approx(v2.w));
}

void test::CompareMatrices(const lia::mat4& m1, const lia::mat4& m2)
{
    CompareVectors(m1[0], m2[0]);
    CompareVectors(m1[1], m2[1]);
    CompareVectors(m1[2], m2[2]);
    CompareVectors(m1[3], m2[3]);
}
