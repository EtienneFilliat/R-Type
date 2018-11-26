/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** R-Type Interface for Systems
*/

#ifndef ISYSTEM_HPP_
	#define ISYSTEM_HPP_
	#include <list>
	#include <memory>
	#include "Entity.hpp"

namespace Ecs {
	class ISystem {
	public:
		virtual ~ISystem() = default;
		virtual void run() = 0;

	protected:
		std::list<std::shared_ptr<Entity>> &_Entities;
	};
}

#endif /* !ISYSTEM_HPP_ */
