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

	class HitBox : public AComponent {
		public:
			HitBox(int height = 50, int width = 50);
			~HitBox();
			inline std::pair<int, int> getHitBoxSize()
			{
				return std::pair<int, int>(_height, _width);
			}
			inline void setHitBoxSize(int height, int width) noexcept
			{
				_height = height;
				_width = width;
			}
			inline void setHitBoxSize(std::pair<int, int> size) noexcept
			{
				_height = size.first;
				_height = size.second;
			}

		private:
			int _height;
			int _width;
	};

}

#endif /* !HITBOX_HPP_ */
