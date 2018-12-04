/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** HitboxSystem for R-Type
*/

#include "HitboxSystem.hpp"
#include "Components/HitBox.hpp"
#include "Components/Damages.hpp"
#include "Components/Health.hpp"
#include "Components/AI.hpp"
#include "Components/Position.hpp"
#include "Components/Weapon.hpp"

Ecs::HitboxSystem::HitboxSystem(std::list<std::shared_ptr<Entity>> &entities)
	: ASystem(entities)
{}

void Ecs::HitboxSystem::run()
{
	std::shared_ptr<Entity> toRemove;
	bool removeAnEntity = false;

	for (auto &entity : _Entities) {
		if (entity.get()->hasComps<HitBox, Position, Health>())
			selectHitType(entity);
		if (entity.get()->getComp<Health>()->getHp() < 1) {
			toRemove = entity;
			removeAnEntity = true;
		}
	}
	if (removeAnEntity)
		_Entities.remove(toRemove);
}

void Ecs::HitboxSystem::selectHitType(std::shared_ptr<Entity> entity)
{
	if (entity.get()->hasComp<AI>())
		AIHit(entity);
	else
		nonAIHit(entity);
}

void Ecs::HitboxSystem::AIHit(std::shared_ptr<Entity> entity) {
	for (auto &otherEntity : _Entities) {
		if (otherEntity.get()->hasComps<HitBox, Position, Damages, Weapon>())
			checkForDamages(entity, otherEntity);
	}
}

void Ecs::HitboxSystem::nonAIHit(std::shared_ptr<Entity> entity) {
	for (auto &otherEntity : _Entities) {
		if (otherEntity.get()->hasComps<HitBox, Position, Damages, AI>())
			checkForDamages(entity, otherEntity);
	}
}

void Ecs::HitboxSystem::checkForDamages(std::shared_ptr<Entity> entity,
			std::shared_ptr<Entity> otherEntity)
{
	std::pair<int, int> entityPos =
		entity.get()->getComp<Position>()->getPosition();
	std::pair<int, int> entityHitbox =
		entity.get()->getComp<HitBox>()->getHitBoxSize();
	std::pair<int, int> otherPos =
		otherEntity.get()->getComp<Position>()->getPosition();
	std::pair<int, int> otherHitbox =
		otherEntity.get()->getComp<HitBox>()->getHitBoxSize();

	if (entityPos.first + entityHitbox.first > otherPos.first &&
		entityPos.first < otherPos.first + otherHitbox.first &&
		entityPos.second + entityHitbox.second > otherHitbox.second &&
		entityPos.second < otherPos.second + otherHitbox.second) {
		takeDamages(entity, otherEntity);
	}
}

void Ecs::HitboxSystem::takeDamages(std::shared_ptr<Entity> entity,
			std::shared_ptr<Entity> otherEntity)
{
	int currentEntityHealth = entity.get()->getComp<Health>()->getHp();

	currentEntityHealth -= otherEntity.get()->getComp<Damages>()->getDamage();
	entity.get()->getComp<Health>()->setHp(currentEntityHealth);
}