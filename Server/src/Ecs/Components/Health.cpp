/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Health Component source code
*/

#include "Components/Health.hpp"

Ecs::Health::Health(int hp)
	: _hp(hp)
{ _type = Constants::HEALTH; }

Ecs::Health::~Health()
{}