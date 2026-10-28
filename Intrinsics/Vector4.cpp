#include "Vector4.hpp"
#include <intrin.h>


namespace Intrinsics
{
    float Vector4::Dot(const Vector4& a, const Vector4& b) noexcept
    {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
    }

    float Vector4::IntrinDot(const Vector4& a, const Vector4& b) noexcept
    {
        __m128 va = _mm_loadu_ps(&a.x);
        __m128 vb = _mm_loadu_ps(&b.x);
        __m128 dp = _mm_dp_ps(va, vb, 0xFF); // dot x,y,z,w

        return _mm_cvtss_f32(dp);
    }
}
