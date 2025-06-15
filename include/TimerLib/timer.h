#pragma once
#include <chrono>
#include <thread>


namespace Timers {

    // timer that can check elapsed time at any moment. less precise
    struct Timer {
    public:
        Timer();

        void reset();

        double elapsedSeconds() const;

        double elapsedMilliseconds() const;

        double elapsedMicroseconds() const;
    private:
        std::chrono::high_resolution_clock::time_point m_start;
    };


    // scope based timer that calculates based on the lifetime of the object. more precise
    struct ScopedTimer {
        ScopedTimer(const char* label, double* outDuration = nullptr);
        ~ScopedTimer();

    private:
        double* m_durationRef{nullptr};
        std::chrono::high_resolution_clock::time_point m_start;
        const char* m_label{""};
    };
}