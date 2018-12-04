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

int main()
{
	Ecs::EntityManager entityManager;
	entityManager.createPlayer();
	entityManager.createMonster();
	IoServiceWork sUDP;
	IoServiceWork sTCP;
	std::list<std::shared_ptr<Ecs::Entity>> entityList =
		entityManager.getEntsByComp<Ecs::Position>();
	GameLoop gameLoop(entityList, sUDP.ioService(), sTCP.ioService(), "127.0.0.1");
	gameLoop.run();
	return 0;
}
