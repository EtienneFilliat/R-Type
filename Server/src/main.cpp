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
	// boost::asio::io_service ioService;
	// boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234);
	// UDPServer server(ioService, 1488);
	// std::list<struct UDPPlayer> players;
	// std::unique_ptr<IServerComponent> move = std::make_unique<MoveComponent>(MoveComponent(players));

	// server.addComponent(move);
	// server.send({1, 1, 1, 1, 1, 500, 700}, endpoint);
	// ioService.run();
	Ecs::EntityManager entityManager;
	entityManager.createPlayer();
	entityManager.createMonster();
	std::list<std::shared_ptr<Ecs::Entity>> entityList =
		entityManager.getEntsByComp<Ecs::Position>();
	GameLoop gameLoop(entityList);
	gameLoop.run();
	return 0;
}
