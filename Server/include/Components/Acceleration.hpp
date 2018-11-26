/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Acceleration Header
*/

#ifndef ACCELERATION_HPP_
	#define ACCELERATION_HPP_

	#include "AComponent.hpp"

namespace Ecs {

	class Acceleration : public AComponent {
		public:
			Acceleration(int Acc = 2);
			~Acceleration();
			inline void setAcceleration(int Acc) noexcept;
			inline int getAcceleration() noexcept;
		private:
			int _acceleration;
	};

}
#endif /* !ACCELERATION_HPP_ */
