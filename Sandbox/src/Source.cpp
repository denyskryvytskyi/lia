#include "iostream"

#include "vec4.h"
#include "vec3.h"
#include "vec2.h"

int main()
{
    std::cout << "Sandbox" << std::endl;

    gdm::vec4 vec(1.0f);
    std::cout << vec << std::endl;
    vec += 4.0f;
    vec /= 2.0f;
    std::cout << vec << std::endl;

    return 0;
}