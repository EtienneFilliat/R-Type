/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Health Component header
*/

#ifndef HEALTH_HPP_
	#define HEALTH_HPP_

	#include "AComponent.hpp"

namespace Ecs {

	class Health : public AComponent {
		public:
			Health(int hp = 100);
			~Health();
			inline int getHp() noexcept;
			inline void setHp(int newHp) noexcept;
		private:
			int _hp;
	};

}

#endif /* !HEALTH_HPP_ */
