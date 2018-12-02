/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Server main
*/

#include "GameLoop.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "IoServiceWork.hpp"
#include "Components/Position.hpp"

int main(int ac, char **av)
{
	Ecs::EntityManager entityManager;
	entityManager.createPlayer();
	entityManager.createMonster();
	IoServiceWork s;
	std::list<std::shared_ptr<Ecs::Entity>> entityList =
		entityManager.getEntsByComp<Ecs::Position>();
	GameLoop gameLoop(entityList, s.ioService(), "127.0.0.1");
	gameLoop.run();
	return 0;
}
