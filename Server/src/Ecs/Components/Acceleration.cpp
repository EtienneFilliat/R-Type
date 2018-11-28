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
