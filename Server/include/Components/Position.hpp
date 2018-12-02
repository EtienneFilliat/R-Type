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
			Position(int X = 0, int Y = 0);
			~Position(void);
			inline void setXPos(int X) noexcept { _x = X; };
			inline void setYPos(int Y) noexcept { _y = Y; };
			std::pair<int, int> getPosition() noexcept { return (std::make_pair(_x, _y)); };

		private:
			int _x;
			int _y;
	};

}
#endif /* !POSITION_HPP_ */
