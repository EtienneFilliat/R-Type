/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Health Component source code
*/

#include "Components/Health.hpp"

Ecs::Health::Health(int hp)
	: _hp(hp)
{}

Ecs::Health::~Health()
{}

inline int Ecs::Health::getHp() noexcept
{
	return _hp;
}

inline void Ecs::Health::setHp(int newHp) noexcept
{
	_hp = newHp;
}