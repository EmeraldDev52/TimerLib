#include <iostream>
#include <chrono>
#include <thread>
#include "TimerLib/timer.h"

namespace Timers {

    // timer that can check elapsed time at any moment. less precise
    Timer::Timer() {
        m_start = std::chrono::high_resolution_clock::now();
    }

    void Timer::reset() {
        m_start = std::chrono::high_resolution_clock::now();
    }

    double Timer::elapsedSeconds() const {
        return std::chrono::duration<double>(std::chrono::steady_clock::now() - m_start).count();
    }
    
    double Timer::elapsedMilliseconds() const {
        return std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - m_start).count();
    }

    double Timer::elapsedMicroseconds() const {
        return std::chrono::duration<double, std::micro>(std::chrono::steady_clock::now() - m_start).count();
    }



    // scope based timer that calculates based on the lifetime of the object. more precise
    ScopedTimer::ScopedTimer(double* outDuration = nullptr)
        : m_start(std::chrono::steady_clock::now()), m_durationRef(outDuration) {}

    ScopedTimer::~ScopedTimer() {
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> duration = end - m_start;
        std::cout << duration.count() << "\n";
        if (m_durationRef != nullptr) {
            *m_durationRef = duration.count();
        }
    }
}
