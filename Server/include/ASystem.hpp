/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** R-Typr Systems abstract class
*/

#ifndef ASYSTEM_HPP_
	#define ASYSTEM_HPP_
	#include <list>
	#include <memory>
	#include "ISystem.hpp"
	#include "Entity.hpp"


namespace Ecs {

	class ASystem : public ISystem {
	public:
		ASystem(std::list<std::shared_ptr<Entity>> &entities)
			: _Entities(entities) {};
	protected:
		std::list<std::shared_ptr<Entity>> &_Entities;

	};
}

#endif /* !ASYSTEM_HPP_ */
