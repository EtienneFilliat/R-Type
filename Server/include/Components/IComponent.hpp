/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

	#include "Constants.hpp"

namespace Ecs {

	class IComponent {
		public:
			virtual ~IComponent() = default;
			virtual Constants::Comps getType() = 0;
			virtual void setType(Constants::Comps newType) = 0;

		protected:
			Constants::Comps _type;

	};

}

#endif /* !ICOMPONENT_HPP_ */
