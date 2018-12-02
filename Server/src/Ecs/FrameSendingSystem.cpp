/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** frame sending system
*/

#include "FrameSendingSystem.hpp"
#include "Components/Drawable.hpp"
#include "Components/Position.hpp"

Ecs::FrameSendingSystem::FrameSendingSystem(
	std::list<std::shared_ptr<Entity>> &entities)
	: ASystem(entities),
	_endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234),
	_server(_ioService, 1488)
{
}

void Ecs::FrameSendingSystem::run()
{

	for (auto &entity : _Entities) {
		if (entity.get()->hasComps<Drawable, Position>())
			drawThisEntity(entity);
	}
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
	_ioService.run();
}
