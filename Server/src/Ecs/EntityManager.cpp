/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** EntityManager
*/

#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "Components/Health.hpp"
#include "Components/Position.hpp"
#include "Components/Damages.hpp"
#include "Components/HitBox.hpp"
#include "Components/Weapon.hpp"
#include "Components/Acceleration.hpp"
#include "Components/AI.hpp"
#include "Constants.hpp"
#include "EntityManager.hpp"

Ecs::EntityManager::EntityManager()
{}

Ecs::EntityManager::~EntityManager()
{}

unsigned int Ecs::EntityManager::createPlayer() noexcept
{
	unsigned int id = _entityList.size() + 1;
	std::shared_ptr<Entity> playerEntity(new Entity(id));

	// Create Player Components
	std::shared_ptr<Acceleration> accComponent(new Acceleration(Constants::DefaultPlayerAccel));
	std::shared_ptr<Health> healthComponent(new Health(Constants::DefaultPlayerHealth));
	std::shared_ptr<Damages> damagesComponent(new Damages(Constants::DefaultPlayerDamages));
	std::shared_ptr<Position> posComponent(new Position(Constants::DefaultPlayerPosX, Constants::DefaultPlayerPosY));
	std::shared_ptr<Weapon> weaponComponent(new Weapon());
	std::shared_ptr<HitBox> hitboxComponent(new HitBox(Constants::DefaultHitboxSizeX, Constants::DefaultHitboxSizeX));
	// Add Player Compoenent to the Entity
	playerEntity.get()->addComp<Acceleration>(accComponent);
	playerEntity.get()->addComp<Health>(healthComponent);
	playerEntity.get()->addComp<Damages>(damagesComponent);
	playerEntity.get()->addComp<Position>(posComponent);
	playerEntity.get()->addComp<Weapon>(weaponComponent);
	playerEntity.get()->addComp<HitBox>(hitboxComponent);
	_entityList.push_back(playerEntity);
	return id;
}

unsigned int Ecs::EntityManager::createMonster() noexcept
{
	std::srand(std::time(nullptr));
	int random = 1 + std::rand() % 2;

	unsigned int id = _entityList.size() + 1;
	std::shared_ptr<Entity> monsterEntity(new Entity(id));

	std::shared_ptr<Acceleration> accComponent(new Acceleration(Constants::DefaultMonsterAccel));
	std::shared_ptr<Health> healthComponent(new Health(Constants::DefaultMonsterHealth));
	std::shared_ptr<Damages> damagesComponent(new Damages(Constants::DefaultMonsterDamages));
	std::shared_ptr<Position> posComponent(new Position(Constants::DefaultMonsterPosX, Constants::DefaultMonsterPosY));
	std::shared_ptr<HitBox> hitboxComponent(new HitBox(Constants::DefaultHitboxSizeX, Constants::DefaultHitboxSizeX));
	std::shared_ptr<AI> aiComponent(new AI(random));

	monsterEntity.get()->addComp<Acceleration>(accComponent);
	monsterEntity.get()->addComp<Health>(healthComponent);
	monsterEntity.get()->addComp<Damages>(damagesComponent);
	monsterEntity.get()->addComp<Position>(posComponent);
	monsterEntity.get()->addComp<HitBox>(hitboxComponent);
	monsterEntity.get()->addComp<AI>(aiComponent);
	_entityList.push_back(monsterEntity);
	return id;
}

std::shared_ptr<Ecs::Entity> Ecs::EntityManager::getEntityById(unsigned int id)
{
	for (auto &y : _entityList) {
		if (y->getEntityId() == id)
			return y;
	}
	throw std::runtime_error("EventManager: getEntityById: id not found");
}
