/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** PlayerSystem
*/

#include "PlayerSystem.hpp"
#include "Components/HitBox.hpp"
#include "Components/Damages.hpp"
#include "Components/Health.hpp"
#include "Components/AI.hpp"
#include "Components/Position.hpp"
#include "Components/Weapon.hpp"
#include "Components/Acceleration.hpp"

Ecs::PlayerSystem::PlayerSystem(std::list<std::shared_ptr<Entity>> &entities, std::shared_ptr<SafeQueue<struct UDPClientStreamBufferData>> queue)
    : ASystem(entities),
    _actionQueue(queue)
{}

void Ecs::PlayerSystem::run()
{
    for (auto &entity : _Entities) {
		if (entity.get()->hasComps<Position, Acceleration, Weapon>()) {
			handlePlayerAction(entity);
		}
	}
}

void Ecs::PlayerSystem::handlePlayerAction(std::shared_ptr<Entity> entity)
{
    while (!_actionQueue->empty()) {
        auto action = _actionQueue->pop();
        switch (action.event) {
            case Constants::EVENT::MOVE :
                movePlayer(entity, action.direction);
                break;
            case Constants::EVENT::SHOOT :
                break;
            default :
                break;
        }
    }
}

void Ecs::PlayerSystem::movePlayer(std::shared_ptr<Entity> entity, int dir)
{
    auto accel = entity->getComp<Acceleration>();
    auto pos = entity->getComp<Position>();
    auto posXY = pos->getPosition();
    switch (dir) {
        case Constants::DIRECTION::DOWN :
            pos->setYPos(posXY.second + accel->getAcceleration());
            break;
        case Constants::DIRECTION::UP :
            pos->setYPos(posXY.second - accel->getAcceleration());
            break;
        case Constants::DIRECTION::RIGHT :
            pos->setXPos(posXY.first + accel->getAcceleration());
            break;
        case Constants::DIRECTION::LEFT :
            pos->setXPos(posXY.first - accel->getAcceleration());
            break;
        default:
            break;
    }
}