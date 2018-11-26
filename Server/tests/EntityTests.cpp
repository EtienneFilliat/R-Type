/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** EntityTests
*/

#include <criterion/criterion.h>
#include "Entity.hpp"
#include "Components/Health.hpp"
#include "Components/Position.hpp"
#include "Components/Damages.hpp"
#include "Constants.hpp"

Test(Entity, setId) {
	Ecs::Entity entity(0);

	unsigned int id = entity.getEntityId();
	cr_assert_eq(id, 0);
}

void addHealthComp(Ecs::Entity &entity)
{
	std::shared_ptr<Ecs::Health> healthComponent(new Ecs::Health(10));
	entity.addComp<Ecs::Health>(healthComponent);
}

void addAndChangeHealthComp(Ecs::Entity &entity)
{
	std::shared_ptr<Ecs::Health> healthComponent(new Ecs::Health(10));
	healthComponent.get()->setHp(42);
	entity.addComp<Ecs::Health>(healthComponent);
}

Test(Entity, addComponent) {
	Ecs::Entity entity(0);
	bool has;

	addHealthComp(entity);
	has = entity.hasComp<Ecs::Health>();
	cr_assert(has);
}

Test(Entity, getComp) {
	Ecs::Entity entity(0);

	std::shared_ptr<Ecs::Health> healthComponent(new Ecs::Health(10));
	entity.addComp<Ecs::Health>(healthComponent);
	auto comp = entity.getComp<Ecs::Health>();
	cr_assert_eq(comp.get(), healthComponent.get());
}

Test(Entity, ReadEntityValue)
{
	Ecs::Entity entity(0);

	addAndChangeHealthComp(entity);
	auto comp = entity.getComp<Ecs::Health>();
	cr_assert_eq(comp.get()->getHp(), 42);
}