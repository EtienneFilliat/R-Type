/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** AISystem system class for R-Type
*/

#ifndef AISYSTEM_HPP_
	#define AISYSTEM_HPP_
	#include "ASystem.hpp"

namespace Ecs {

	class AISystem : public ASystem {
		public:
			AISystem(std::list<std::shared_ptr<Entity>> &entities);
			void run() final;
		private:
			void moveAI(std::shared_ptr<Entity> entity);
			void AIPattern1(std::shared_ptr<Entity> entity);
			void AIPattern2(std::shared_ptr<Entity> entity);
	};

}

#endif /* !AISYSTEM_HPP_ */
