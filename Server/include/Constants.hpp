/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Constants
*/

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

#include <utility>

namespace Constants
{
	enum Comps
	{
		HEALTH,
		HITBOX,
		POSITION,
		DAMAGES,
		ACCELERATION,
		WEAPON,
		AI
	};

	// Player and Monsters defaults Stats
	const int DefaultPlayerAccel = 3;
	const int DefaultPlayerHealth = 200;
	const int DefaultPlayerDamages = 20;
	const int DefaultPlayerPosX = 100;
	const int DefaultPlayerPosY = 100;

} // namespace Constants

#endif /* !CONSTANTS_HPP_ */
