/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Acceleration Source code
*/

#include "Components/Acceleration.hpp"

Ecs::Acceleration::Acceleration(int Acc)
	: _acceleration(Acc)
{ _type = Constants::ACCELERATION; }

Ecs::Acceleration::~Acceleration()
{}

inline int Ecs::Acceleration::getAcceleration() noexcept
{
	return _acceleration;
}

inline void Ecs::Acceleration::setAcceleration(int Acc) noexcept
{
	_acceleration = Acc;
}
