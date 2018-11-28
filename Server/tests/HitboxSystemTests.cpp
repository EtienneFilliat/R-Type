/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Hitbox unit tests
*/

#include <criterion/criterion.h>
#include <memory>
#include <utility>
#include <list>
#include "HitboxSystem.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Components/Weapon.hpp"
#include "Components/Health.hpp"
#include "Components/Damages.hpp"
#include "Components/Position.hpp"
#include "Components/HitBox.hpp"

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

Test(HitboxSystem, checkForDamages)
{
	Ecs::EntityManager entityManager;

	entityManager.createPlayer();
	entityManager.createPlayer();
	std::list<std::shared_ptr<Ecs::Entity>> entityList =
		entityManager.getEntsByComp<Ecs::Weapon>();
	Ecs::HitboxSystem hitboxSystem(entityList);
	std::shared_ptr<Ecs::Entity> player1 = entityList.front();
	std::shared_ptr<Ecs::Entity> player2 = entityList.front();
	player1.get()->getComp<Ecs::Position>()->setXPos(800);
	player1.get()->getComp<Ecs::Position>()->setYPos(400);
	player1.get()->getComp<Ecs::HitBox>()->setHitBoxSize(
		std::make_pair<int, int>(100, 100));
	player2.get()->getComp<Ecs::Position>()->setXPos(690);
	player2.get()->getComp<Ecs::Position>()->setYPos(400);
	player2.get()->getComp<Ecs::HitBox>()->setHitBoxSize(
		std::make_pair<int, int>(100, 100));
	hitboxSystem.checkForDamages(player1, player2);
	cr_assert_eq(player1.get()->getComp<Ecs::Health>()->getHp(),
		player2.get()->getComp<Ecs::Health>()->getHp());
}

Test(HitboxSystem, checkForDamages2)
{
	Ecs::EntityManager entityManager;

	entityManager.createPlayer();
	entityManager.createPlayer();
	std::list<std::shared_ptr<Ecs::Entity>> entityList =
		entityManager.getEntsByComp<Ecs::Weapon>();
	Ecs::HitboxSystem hitboxSystem(entityList);
	std::shared_ptr<Ecs::Entity> player1 = entityList.front();
	std::shared_ptr<Ecs::Entity> player2 = entityList.front();
	player1.get()->getComp<Ecs::Position>()->setXPos(800);
	player1.get()->getComp<Ecs::Position>()->setYPos(400);
	player1.get()->getComp<Ecs::HitBox>()->setHitBoxSize(
		std::make_pair<int, int>(100, 100));
	player2.get()->getComp<Ecs::Position>()->setXPos(710);
	player2.get()->getComp<Ecs::Position>()->setYPos(400);
	player2.get()->getComp<Ecs::HitBox>()->setHitBoxSize(
		std::make_pair<int, int>(100, 100));
	hitboxSystem.checkForDamages(player1, player2);
	cr_assert_eq(player1.get()->getComp<Ecs::Health>()->getHp(),
		Constants::DefaultPlayerHealth -
		player2.get()->getComp<Ecs::Damages>()->getDamage());
}

Test(HitboxSystem, checkForDamages3)
{
	Ecs::EntityManager entityManager;

	entityManager.createPlayer();
	entityManager.createPlayer();
	std::list<std::shared_ptr<Ecs::Entity>> entityList =
		entityManager.getEntsByComp<Ecs::Weapon>();
	Ecs::HitboxSystem hitboxSystem(entityList);
	std::shared_ptr<Ecs::Entity> player1 = entityList.front();
	std::shared_ptr<Ecs::Entity> player2 = entityList.front();
	player1.get()->getComp<Ecs::Position>()->setXPos(800);
	player1.get()->getComp<Ecs::Position>()->setYPos(400);
	player1.get()->getComp<Ecs::HitBox>()->setHitBoxSize(
		std::make_pair<int, int>(100, 100));
	player2.get()->getComp<Ecs::Position>()->setXPos(901);
	player2.get()->getComp<Ecs::Position>()->setYPos(400);
	player2.get()->getComp<Ecs::HitBox>()->setHitBoxSize(
		std::make_pair<int, int>(100, 100));
	hitboxSystem.checkForDamages(player1, player2);
	cr_assert_eq(player1.get()->getComp<Ecs::Health>()->getHp(),
		player2.get()->getComp<Ecs::Health>()->getHp());
}