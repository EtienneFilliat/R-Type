/*
** EPITECH PROJECT, 2018
** R-Type
** File description: r-type frame sending system
**
*/

#ifndef FRAMESENDINGSYSTEM_HPP_
	#define FRAMESENDINGSYSTEM_HPP_
	#include "ASystem.hpp"


namespace Ecs {

	class FrameSendingSystem : public ASystem {
		public:
			FrameSendingSystem(
				std::list<std::shared_ptr<Entity>> &entities);
			void run() final;
		private:
			void drawThisEntity(std::shared_ptr<Entity> entity);
	};

}

#endif /* !FRAMESENDINGSYSTEM_HPP_ */
