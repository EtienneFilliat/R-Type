/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Damages component source code
*/

#include "Components/Damages.hpp"

Damages::Damages(int dmg)
	: _damage(dmg)
{ _type = Constants::DAMAGES; }

Damages::~Damages()
{}

inline void Damages::setDamage(int newDamage) noexcept
{
	_damage = newDamage;
}

inline int Damages::getDamage() noexcept
{
	return _damage;
}