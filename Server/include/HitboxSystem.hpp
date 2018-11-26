/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** HitboxSystem system class for R-Type
*/

#ifndef HITBOXSYSTEM_HPP_
	#define HITBOXSYSTEM_HPP_
	#include "ASystem.hpp"

namespace Ecs {

	class HitboxSystem : public ASystem {
		public:
			HitboxSystem(std::list<std::shared_ptr<Entity>> &entities);
			void run() final;
		private:
	};

}

#endif /* !HITBOXSYSTEM_HPP_ */
