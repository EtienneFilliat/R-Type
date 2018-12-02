/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** r-type game loop
*/

#ifndef GAMELOOP_HPP_
	#define GAMELOOP_HPP_
	#include "HitboxSystem.hpp"
	#include "AISystem.hpp"
	#include "FrameSendingSystem.hpp"

class GameLoop {
	public:
		GameLoop(std::list<std::shared_ptr<Ecs::Entity>> list);

	private:
		Ecs::HitboxSystem	_hitboxSystem;
		Ecs::FrameSendingSystem	_frameSendingSystem;
		Ecs::AISystem		_AISystem;
};

#endif /* !GAMELOOP_HPP_ */
