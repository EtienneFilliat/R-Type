/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
	#define ACOMPONENT_HPP_

	#include "IComponent.hpp"

namespace Ecs {

	class AComponent : public IComponent {
		public:
			virtual ~AComponent() = default;
			inline Constants::Comps getType() final { return _type; };
			inline void setType(Constants::Comps newType) final { _type = newType; };
		protected:
			Constants::Comps _type;
	};

}

#endif /* !ACOMPONENT_HPP_ */
