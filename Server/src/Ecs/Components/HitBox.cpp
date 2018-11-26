/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** HitBox Component source code
*/

#include "Components/HitBox.hpp"

Ecs::HitBox::HitBox(int height, int width)
	: _height(height), _width(width)
{ _type = Constants::HITBOX; }

Ecs::HitBox::~HitBox()
{}

inline void Ecs::HitBox::setHitBoxSize(int height, int width) noexcept
{
	_height = height;
	_width = width;
}

inline void Ecs::HitBox::setHitBoxSize(std::pair<int, int> size) noexcept
{
	_height = size.first;
	_height = size.second;
}

inline std::pair<int, int> Ecs::HitBox::getHitBoxSize()
{
	return std::pair<int, int>(_height, _width);
}