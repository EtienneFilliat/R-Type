/*
** EPITECH PROJECT, 2018
** R-type
** File description:
** r-type weapon system
*/

#ifndef WEAPONSYSTEM_HPP_
	#define WEAPONSYSTEM_HPP_
	#include "ASystem.hpp"


namespace Ecs {

	class WeaponSystem : public ASystem {
		public:
			WeaponSystem(std::list<std::shared_ptr<Entity>> &entities);
			void run() final;
		private:
			void moveMissile(std::shared_ptr<Entity> entity);
	};

}

#endif /* !WEAPONSYSTEM_HPP_ */
