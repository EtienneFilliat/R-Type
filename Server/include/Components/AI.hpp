/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** AI
*/

#ifndef AI_HPP_
	#define AI_HPP_

	#include "AComponent.hpp"

namespace Ecs {

	class AI : public AComponent {
		public:
			AI() { _type = Constants::AI; };
			~AI() = default;
		private:
			const bool _isAI = true;
	};

}

#endif /* !AI_HPP_ */
