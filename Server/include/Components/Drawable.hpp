/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** drawable component
*/

#ifndef DRAWABLE_HPP_
	#define DRAWABLE_HPP_
	#include "AComponent.hpp"

namespace Ecs {

	class Drawable : public AComponent {
		public:
			Drawable(int spriteSheetIndex = 1,
				std::pair<int, int> spriteOffset = {0, 0},
				std::pair<int, int> spriteSize = {50, 50});
			~Drawable();
			void setSpriteSheetIndex(int spriteSheetIndex);
			void setSpriteOffset(std::pair<int, int> spriteOffset);
			void setSpriteSize(std::pair<int, int> spriteSize);
			int getSpriteSheetIndex();
			std::pair<int, int> &getSpriteOffset();
			std::pair<int, int> &getSpriteSize();

		private:
			int 			_spriteSheetIndex;
			std::pair<int, int>	_spriteOffset;
			std::pair<int, int>	_spriteSize;
	};

}

#endif /* !DRAWABLE_HPP_ */
