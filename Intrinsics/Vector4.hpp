#pragma once

namespace Intrinsics
{
    class Vector4
    {
    public:
        constexpr Vector4(float x, float y, float z, float w) noexcept : x(x), y(y), z(z), w(w) { };
        constexpr explicit Vector4(float scalar) noexcept : x(scalar), y(scalar), z(scalar), w(scalar) { };
        constexpr Vector4(const Vector4& other) noexcept : x(other.x), y(other.y), z(other.z), w(other.w) { };
        ~Vector4() = default;

        constexpr Vector4& operator=(const Vector4&) noexcept = default;

    public:
        static float Dot(const Vector4& a, const Vector4& b) noexcept;
        static float IntrinDot(const Vector4& a, const Vector4& b) noexcept;

    public:
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float w = 0.0f;
    };
}
