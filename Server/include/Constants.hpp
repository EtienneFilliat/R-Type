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
		DRAWABLE,
		HITBOX,
		POSITION,
		DAMAGES,
		ACCELERATION,
		WEAPON,
		AI
	};

	enum EVENT {
        MOVE,
        SHOOT,
        QUIT,
    };

    enum DIRECTION {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

	// Player and Monsters defaults Stats
	const int DefaultPlayerAccel = 3;
	const int DefaultPlayerHealth = 200;
	const int DefaultPlayerDamages = 20;
	const int DefaultPlayerPosX = 100;
	const int DefaultPlayerPosY = 100;
	const int DefaultPlayerSpriteSheetIndex = 1;
	const int DefaultPlayerSpriteOffsetX = 0;
	const int DefaultPlayerSpriteOffsetY = 0;
	const int DefaultPlayerSpriteSizeX = 64;
	const int DefaultPlayerSpriteSizeY = 24;
	const int DefaultPlayerHitboxSizeX = 64;
	const int DefaultPlayerHitboxSizeY = 24;

	const int DefaultMonsterAccel = 2;
	const int DefaultMonsterHealth = 100;
	const int DefaultMonsterDamages = 10;
	const int DefaultMonsterPosX = 800;
	const int DefaultMonsterPosY = 300;
	const int DefaultMonsterSpriteSheetIndex = 2;
	const int DefaultMonsterSpriteOffsetX = 0;
	const int DefaultMonsterSpriteOffsetY = 0;
	const int DefaultMonsterSpriteSizeX = 64;
	const int DefaultMonsterSpriteSizeY = 56;
	const int DefaultMonsterHitboxSizeX = 64;
	const int DefaultMonsterHitboxSizeY = 56;

	const int DefaultMissileAccel = 10;
	const int DefaultMissileHealth = 1;
	const int DefaultMissileDamages = 100;
	const int DefaultMissilePosX = 800;
	const int DefaultMissilePosY = 300;
	const int DefaultMissileSpriteSheetIndex = 4;
	const int DefaultMissileSpriteOffsetX = 0;
	const int DefaultMissileSpriteOffsetY = 0;
	const int DefaultMissileSpriteSizeX = 12;
	const int DefaultMissileSpriteSizeY = 48;
	const int DefaultMissileHitboxSizeX = 12;
	const int DefaultMissileHitboxSizeY = 48;


} // namespace Constants

#endif /* !CONSTANTS_HPP_ */
