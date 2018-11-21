/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** HitBox Header
*/

#ifndef HITBOX_HPP_
	#define HITBOX_HPP_

	#include <utility>
	#include "AComponent.hpp"

namespace Ecs {

	class HitBox {
		public:
			HitBox(int height, int width);
			~HitBox();
			inline std::pair<int, int> getHitBoxSize();
			inline void setHitBoxSize(int height, int width) noexcept;
			inline void setHitBoxSize(std::pair<int, int> size) noexcept;

		private:
			int _height;
			int _width;
	};

}

#endif /* !HITBOX_HPP_ */
