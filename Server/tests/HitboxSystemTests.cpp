/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Hitbox unit tests
*/

#include <criterion/criterion.h>
#include <memory>
#include <list>
#include "HitboxSystem.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Components/Weapon.hpp"
#include "Components/Health.hpp"
#include "Components/Damages.hpp"

Test(HitboxSystem, takeDamages)
{
	Ecs::EntityManager entityManager;

	entityManager.createPlayer();
	entityManager.createPlayer();
	std::list<std::shared_ptr<Ecs::Entity>> entityList =
		entityManager.getEntsByComp<Ecs::Weapon>();
	Ecs::HitboxSystem hitboxSystem(entityList);
	std::shared_ptr<Ecs::Entity> player1 = entityList.front();
	std::shared_ptr<Ecs::Entity> player2 = entityList.front();
	hitboxSystem.takeDamages(player1, player2);
	cr_assert_eq(player1.get()->getComp<Ecs::Health>()->getHp(),
	 	Constants::DefaultPlayerHealth -
	 	player2.get()->getComp<Ecs::Damages>()->getDamage());
}