/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Server main
*/

#include "GameLoop.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Components/Position.hpp"

int main(int ac, char **av)
{
	Ecs::EntityManager entityManager;
	entityManager.createPlayer();
	entityManager.createMonster();
	std::list<std::shared_ptr<Ecs::Entity>> entityList =
		entityManager.getEntsByComp<Ecs::Position>();
	GameLoop gameLoop(entityList);
	gameLoop.run();
	return 0;
}
