/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** R-Type weapon hpp file
*/

#ifndef WEAPON_HPP_
	#define WEAPON_HPP_
	#include "AComponent.hpp"

namespace Ecs {

	class Weapon : public AComponent {
		public:
			Weapon() = default;
			~Weapon() = default;
			bool isWeapon() {return true;};

		private:
			bool _isWeapon = true;
	};

}

#endif /* !WEAPON_HPP_ */
