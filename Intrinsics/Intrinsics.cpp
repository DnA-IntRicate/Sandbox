#include <iostream>

#include "Timer.hpp"
#include "Vector4.hpp"
using namespace Intrinsics;

static constexpr size_t MAX_TESTS = 1'000'000'000;
static constexpr Vector4 VEC_A = Vector4(800.1f, 22.7f, 9.8f, 1.0f);
static constexpr Vector4 VEC_B = Vector4(42.0f, 627.98f, 9e-9f, 1.0f);

int main()
{
    std::cout << "Validating SIMD implementation...\n";

    float normalDot = Vector4::Dot(VEC_A, VEC_B);
    float simdDot = Vector4::IntrinDot(VEC_A, VEC_B);

    if (normalDot == simdDot)
        std::cout << "SIMD implementation is valid!\n\n";
    else
    {
        std::cout << "SIMD implementation is invalid!\n";
        return 0;
    }

    float normalTimeMS = 0.0f;
    std::cout << "Running normal dot product...\n";
    {
        Timer t;

        float sum = 0.0f;
        for (size_t i = 0; i < MAX_TESTS; ++i)
            sum += Vector4::Dot(VEC_A, VEC_B);

        normalTimeMS = t.ElapsedMilliSeconds();
        std::cout << "Dot sum: " << sum << '\n';
        std::cout << "Took " << normalTimeMS << " ms.\n\n";
    }

    float simdTimeMS = 0.0f;
    std::cout << "Running SIMD dot product...\n";
    {
        Timer t;

        float sum = 0.0f;
        for (size_t i = 0; i < MAX_TESTS; ++i)
            sum += Vector4::IntrinDot(VEC_A, VEC_B);

        simdTimeMS = t.ElapsedMilliSeconds();
        std::cout << "Dot sum: " << sum << '\n';
        std::cout << "took " << simdTimeMS << " ms.\n\n";
    }

    float simdSpeedup = normalTimeMS / simdTimeMS;
    std::cout << "SIMD Speedup: " << simdSpeedup << '\n';

    std::cout << "Press Enter to continue...\n";
    (void)std::cin.get();
    return 0;
}
