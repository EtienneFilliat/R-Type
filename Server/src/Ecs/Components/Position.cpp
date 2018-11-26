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

inline void Ecs::Position::setXPos(int X) noexcept
{
	_x = X;
}

inline void Ecs::Position::setYPos(int Y) noexcept
{
	_y = Y;
}

std::pair<int, int> Ecs::Position::getPosition() noexcept
{
	return (std::make_pair(_x, _y));
}
