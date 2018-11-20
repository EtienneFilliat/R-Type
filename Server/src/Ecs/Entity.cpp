/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Entity source code
*/

#include <memory>
#include <algorithm>
#include "Entity.hpp"

Ecs::Entity::Entity(unsigned int id)
	: _id(id)
{};

Ecs::Entity::~Entity()
{}


unsigned int Ecs::Entity::getEntityId() noexcept
{
	return _id;
}

template <class T>
bool Ecs::Entity::hasComp() noexcept
{
	T Comp;

	try {
		auto it = std::find(_Comps.begin(), _Comps.end(), Comp);
		if (it == _Comps.end())
			return false;
		return true;
	} catch(std::exception &e) {
		(void) e;
	}
	return false;
}

template <class T>
bool Ecs::Entity::removeComp() noexcept
{
	T Comp;

	try {
		auto it = std::find(_Comps.begin(), _Comps.end(), Comp);
		_Comps.erase(it);
	}
	catch (std::exception &e)
	{
		(void) e;
		return false;
	}
	return true;
}

template <class T>
bool Ecs::Entity::addComp(T &Comp) noexcept
{
	if (hasComp<T>())
		return false;
	try {
		_Comps.push_back(Comp);
	} catch (std::exception &e) {
		(void) e;
		return false;
	}
	return true;
}

template <class T>
std::shared_ptr<T> Ecs::Entity::getComp() noexcept
{
	T Comp;

	if (!hasComp<T>())
		return nullptr;
	try {
		auto it = std::find(_Comps.begin(), _Comps.end(), Comp);
		return std::static_pointer_cast<T>(*it);
	} catch (std::exception &e) {
		(void) e;
	}
	return nullptr;
}

template <class T1, class T2, class... Other>
bool Ecs::Entity::hasComps()
{
	T1 _Comps;

	if (hasComp<T1>())
		return (true && hasComps<T2, Other...>());
	return false;
}