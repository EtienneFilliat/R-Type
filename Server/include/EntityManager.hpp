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
	#include <iostream>
	#include "Entity.hpp"

namespace Ecs {

	class EntityManager {
	private:
		std::list<std::shared_ptr<Entity>> _entityList;

	public:
		EntityManager();
		~EntityManager();
		unsigned int createPlayer() noexcept;
		unsigned int createMonster() noexcept;
		unsigned int createMissile() noexcept;
		unsigned int addEntity(Entity &entity) noexcept;
		std::shared_ptr<Entity> getEntityById(unsigned int id);
		bool deleteEntity(unsigned int id) noexcept;
		template <class T>
		std::list<std::shared_ptr<Entity>> getEntsByComp()
		{
			static_assert(std::is_base_of<AComponent, T>::value, "T must inherit from AComponent");
			std::list<std::shared_ptr<Entity>> entities;
			for (auto &y : _entityList)
			{
				if (y.get()->hasComp<T>())
					entities.push_back(y);
			}
			return entities;
		};
		template <class ...Other>
		std::list<std::shared_ptr<Entity>> &getEntsByComps()
		{
			std::list<std::shared_ptr<Entity>> entities;
			for (auto &y : _entityList)
			{
				if (y.get()->hasComps<Other ...>())
					entities.push_back(y);
			}
			return entities;
		};
	};

}

#endif /* !ENTITYMANAGER_HPP_ */
