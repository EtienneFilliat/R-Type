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
	#include <algorithm>
	#include <type_traits>

	#include "Components/AComponent.hpp"

namespace Ecs {
	class Entity {

	private:
		std::list<std::shared_ptr<AComponent>> _Comps;
		unsigned int _id;
	public:
		Entity(unsigned int = 0);
		~Entity();
		unsigned int getEntityId() noexcept;

		template <class T>
		bool hasComp() noexcept
		{
			static_assert(std::is_base_of<AComponent, T>::value, "T must inherit from AComponent");
			T Comp;

			for (auto &y : _Comps) {
				if (y.get()->getType() == Comp.getType())
					return true;
			}
			return false;
		}

		template <class T>
		bool removeComp() noexcept
		{
			static_assert(std::is_base_of<AComponent, T>::value, "T must inherit from AComponent");
			T Comp;

			for (auto it = _Comps.begin(); it != _Comps.end(); it++)
			{
				if ((*it).get()->getType() == Comp.getType()) {
					_Comps.erase(it);
					return true;
				}
			}
			return false;
		}

		template <class T>
		bool addComp(std::shared_ptr<T> &Comp) noexcept
		{
			static_assert(std::is_base_of<AComponent, T>::value, "T must inherit from AComponent");
			if (hasComp<T>())
				return false;
			try
			{
				_Comps.push_back(Comp);
			}
			catch (std::exception &e)
			{
				(void) e;
				return false;
			}
			return true;
		}

		template <class T>
		std::shared_ptr<T> getComp() noexcept
		{
			static_assert(std::is_base_of<AComponent, T>::value, "T must inherit from AComponent");
			T Comp;

			if (!hasComp<T>())
				return nullptr;
			for (auto it = _Comps.begin(); it != _Comps.end(); it++)
			{
				if ((*it).get()->getType() == Comp.getType())
					return std::static_pointer_cast<T>(*it);
			}
			return nullptr;
		}

		template <class T1, class T2, class... Other>
		bool hasComps()
		{
			static_assert(std::is_base_of<AComponent, T1>::value, "T must inherit from AComponent");
			T1 _Comps;

			if (hasComp<T1>())
				return (true && hasComps<T2, Other...>());
			return false;
		}
	};
}

#endif /* !ENTITY_HPP_ */
