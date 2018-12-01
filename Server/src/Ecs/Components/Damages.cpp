/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Damages component source code
*/

#include "Components/Damages.hpp"

Ecs::Damages::Damages(int dmg)
	: _damage(dmg)
{ _type = Constants::DAMAGES; }

Ecs::Damages::~Damages()
{}