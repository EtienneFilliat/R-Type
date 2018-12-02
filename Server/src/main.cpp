/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Server main
*/

#include "GameLoop.hpp"
#include "EntityManager.hpp"
#include "Components/Position.hpp"

int main(int ac, char **av)
{
	Ecs::EntityManager entityManager;
	entityManager.createPlayer();
	entityManager.createMonster();
	GameLoop gameLoop(entityManager.getEntsByComp<Ecs::Position>());
	gameLoop.run();
	return 0;
}
