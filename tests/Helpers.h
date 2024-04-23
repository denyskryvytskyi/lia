#pragma once

#include "doctest.h"
#include <lia/lia.h>

namespace test {
void CompareVectors(const lia::vec4& v1, const lia::vec4& v2);

void CompareMatrices(const lia::mat4& m1, const lia::mat4& m2);
} // namespace test
