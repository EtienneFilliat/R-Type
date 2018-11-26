/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Server main
*/

#include "Entity.hpp"
#include "Components/Health.hpp"
#include "Components/Position.hpp"
#include "Components/Damages.hpp"

void subFct(Ecs::Entity &entity)
{
	std::shared_ptr<Ecs::Health> healthComponent(new Ecs::Health(10));
	entity.addComp<Ecs::Health>(healthComponent);
}

int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	Ecs::Entity entity(0);
	Ecs::Position posComponent(50, 40);

	subFct(entity);
	bool ret = entity.hasComp<Ecs::Health>();
	return 0;
}
