/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** EntityManager header
*/

#ifndef ENTITYMANAGER_HPP_
	#define ENTITYMANAGER_HPP_

	#include <list>
	#include <memory>
	#include "Entity.hpp"

namespace Ecs {

	class EntityManager {
		public:
			EntityManager();
			~EntityManager();
		private:
			std::list<std::shared_ptr<Entity>> _entityList;
	};

}

#endif /* !ENTITYMANAGER_HPP_ */
