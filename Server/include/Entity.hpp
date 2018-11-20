/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Entity Headers
*/

#ifndef ENTITY_HPP_
	#define ENTITY_HPP_

	#include <memory>
	#include <list>

	#include "IComponent.hpp"

namespace Ecs {
	class Entity {
		public:
			Entity(unsigned int = 0);
			~Entity();
			unsigned int getEntityId() noexcept;
			template <class T> bool hasComp() noexcept;
			template <class T> bool removeComp() noexcept;
			template <class T> bool addComp(T &Comp) noexcept;
			template <class T> std::shared_ptr<T> getComp() noexcept;
			template <class T1, class T2, class... Other> bool hasComps();
		private:
			std::list<std::shared_ptr<IComponent>> _Comps;
			unsigned int _id;
	};
}

#endif /* !ENTITY_HPP_ */
