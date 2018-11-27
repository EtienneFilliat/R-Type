/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Position Component source code
*/

#include "Components/Position.hpp"

Ecs::Position::Position(int X, int Y)
	: _x(X), _y(Y)
{ _type = Constants::POSITION; }

Ecs::Position::~Position(void)
{}