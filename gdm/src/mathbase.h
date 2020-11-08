#pragma once

namespace gdm
{
    #define TOLERANCE 2e-37f

    // Conversion from degrees to radians
    float degreesToRadians(float degrees)
    {
        return degrees * 0.0174532925f;
    }

    // Macro for conversion from radians to degrees
    float radiansToDegrees(float radians)
    {
        return radians * 57.29577951f;
    }
}
