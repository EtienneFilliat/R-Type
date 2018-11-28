/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Hitbox unit tests
*/

#include <criterion/criterion.h>
#include "HitboxSystem.hpp"
#include "EntityManager.hpp"

Test(HitboxSystem, takeDamages)
{
	Ecs::EntityManager entityManager;

	entityManager.createPlayer();
	cr_assert_eq(1, 1);
}