/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** EntityManagerTests
*/

#include <criterion/criterion.h>
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "Components/Health.hpp"
#include "Constants.hpp"

Test(EntityManager, createPlayer) {
	Ecs::EntityManager manager;

	cr_assert_eq(manager.createPlayer(), 1);
}

Test(EntityManager, getEntityById) {
	Ecs::EntityManager manager;

	unsigned int id = manager.createPlayer();
	auto entity = manager.getEntityById(id);
	auto comp = entity.get()->getComp<Ecs::Health>();
	cr_assert_eq(comp.get()->getHp(), Constants::DefaultPlayerHealth);
}
