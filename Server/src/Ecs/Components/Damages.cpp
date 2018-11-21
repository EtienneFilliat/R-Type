/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Damages component source code
*/

#include "Components/Damages.hpp"

Ecs::Damages::Damages(int dmg)
	: _damage(dmg)
{}

Ecs::Damages::~Damages()
{}

inline void Ecs::Damages::setDamage(int newDamage) noexcept
{
	_damage = newDamage;
}

inline int Ecs::Damages::getDamage() noexcept
{
	return _damage;
}