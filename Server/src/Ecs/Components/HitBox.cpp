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