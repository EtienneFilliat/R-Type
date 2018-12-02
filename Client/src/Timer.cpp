/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Timer
*/

#include "Timer.hpp"

Timer::Timer()
{}

Timer::~Timer()
{}

void Timer::waitFrame() noexcept
{
    std::chrono::microseconds time_span(_end - _start);
    while (time_span.count() < 41667) {
        end();
        time_span = _end - _start;
    }
}
