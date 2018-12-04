/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** frame sending system
*/

#include <iostream>
#include "FrameSendingSystem.hpp"
#include "Components/Drawable.hpp"
#include "Components/Position.hpp"

Ecs::FrameSendingSystem::FrameSendingSystem(
	std::list<std::shared_ptr<Entity>> &entities,
	UDPServer &server,
	boost::asio::ip::udp::endpoint	_endpoint)
	: ASystem(entities),
	_endpoint(_endpoint),
	_server(server)
{
}

void Ecs::FrameSendingSystem::run()
{
	std::shared_ptr<Entity> toRemove;
	bool removeAnEntity = false;

	for (auto &entity : _Entities) {
		if (entity->hasComps<Drawable, Position>()) {
			std::pair<int, int> pos =
				entity.get()->getComp<Position>()->getPosition();
			std::pair<int, int> size =
				entity.get()->getComp<Drawable>()->getSpriteSize();
			if (pos.first < size.first * -1) {
				toRemove = entity;
				removeAnEntity = true;
			}
			else
				drawThisEntity(entity);
		}
	}
	if (removeAnEntity)
		_Entities.remove(toRemove);
}

void Ecs::FrameSendingSystem::drawThisEntity(std::shared_ptr<Entity> entity)
{
	std::shared_ptr<Drawable> drawComp = entity.get()->getComp<Drawable>();
	std::shared_ptr<Position> posComp = entity.get()->getComp<Position>();
	_server.send({drawComp.get()->getSpriteSheetIndex(),
			drawComp.get()->getSpriteOffset().first,
			drawComp.get()->getSpriteOffset().second,
			drawComp.get()->getSpriteSize().first,
			drawComp.get()->getSpriteSize().second,
			posComp.get()->getPosition().first,
			posComp.get()->getPosition().second
			}, _endpoint);
}
