/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Game
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

Game::Game(sf::RenderWindow &window)
    : _window(window),
    _palyer(new Image(PLAYER_SPRITE)),
    _monster1(new Image(MONSTER1_SPRITE)),
    _monster2(new Image(MONSTER2_SPRITE))
{}

Game::~Game()
{}

void Game::GameEvents()
{
	sf::Event event;
	while (_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			_window.close();
	}
}

void Game::GameDisplay()
{
	_window.clear();
    _window.draw(_palyer->get_sprite());
	_window.display();
}
