#pragma once
#include <chrono> 


namespace Intrinsics
{
    class Timer
    {
    public: 
        Timer(float startTime = 0.0f) noexcept : m_StartTime(startTime)
        {
            Reset();
        }

        ~Timer() = default; 

        void Reset() noexcept
        {
            m_Clock = std::chrono::high_resolution_clock::now();
        }

        float Elapsed() const noexcept
        {
            std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
            float duration = (std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - m_Clock).count() * 0.000000001f) + m_StartTime;

            return duration;
        }

        float ElapsedMilliSeconds() const noexcept
        {
            return Elapsed() * 1000.0f;
        }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Clock;
        float m_StartTime = 0.0f;
    };
}
