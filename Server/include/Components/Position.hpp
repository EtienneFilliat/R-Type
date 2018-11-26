/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Position Component Header
*/

#ifndef POSITION_HPP_
	#define POSITION_HPP_

	#include <utility>
	#include "AComponent.hpp"

namespace Ecs {

	class Position : public AComponent {
		public:
			Position(int X, int Y);
			~Position(void);
			inline void setXPos(int X) noexcept;
			inline void setYPos(int Y) noexcept;
			std::pair<int, int> getPosition() noexcept;

		private:
			int _x;
			int _y;
	};

}
#endif /* !POSITION_HPP_ */
