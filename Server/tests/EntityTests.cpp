/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** EntityTests
*/

#include <criterion/criterion.h>
#include "Entity.hpp"

Test(Entity, setId) {
	Ecs::Entity entity(0);

	unsigned int id = entity.getEntityId();
	cr_assert_eq(id, 0);
}