/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Game
*/

#ifndef GAME_HPP_
	#define GAME_HPP_

    #include <SFML/Graphics.hpp>
	#include "Image.hpp"

	#define PLAYER_SPRITE	"Client/res/spacecraft.png"
	#define MONSTER1_SPRITE	"Client/res/ovni.png"
	#define MONSTER2_SPRITE	"Client/res/ufo.png"
	#define SPRITE_SIZE		64

class Game {
	public:
		Game(sf::RenderWindow &window);
		~Game();
		void GameEvents();
		void GameDisplay();

    private:
        sf::RenderWindow &_window;
		Image *_palyer;
		Image *_monster1;
		Image *_monster2;
};

#endif /* !GAME_HPP_ */
