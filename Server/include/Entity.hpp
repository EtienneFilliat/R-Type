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

	#include "IComponents.hpp"

namespace Ecs {
	class Entity {
		public:
			Entity(unsigned int = 0);
			~Entity();
			unsigned int getEntityId();
			template<class T> bool removeComp();
			template<class T> bool hasComp();
			template<class T> bool addComp(T &Comp);
			template<class T> std::shared_ptr<T> getComp();
			template<class T1, class T2, class... Other> bool hasComps();
		private:
			std::list<std::shared_ptr<IComponents>> _Comps;
			unsigned int _id;
	};
}

#endif /* !ENTITY_HPP_ */
