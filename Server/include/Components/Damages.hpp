/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Damages header
*/

#ifndef DAMAGES_HPP_
	#define DAMAGES_HPP_

	#include "AComponent.hpp"

class Damages : public Ecs::AComponent {
	public:
		Damages(int dmg = 10);
		~Damages();
		inline void setDamage(int dmg) noexcept;
		inline int getDamage() noexcept;
	private:
		int _damage;
};

#endif /* !DAMAGES_HPP_ */
