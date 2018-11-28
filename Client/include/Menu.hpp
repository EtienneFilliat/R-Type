//
// EPITECH PROJECT, 2018
// Button
// File description:
// Button class for SFML R-Type

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

//to adjust
#define MENU_DEFAULT_WIDTH 1200
#define MENU_DEFAULT_HEIGHT 859

#define MENU_TITLE "R-Type"
#define MENU_DEFAULT_BG "res/background.jpg"
#define MENU_BG_WIDTH 1200
#define MENU_BG_HEIGHT 859


#define NEWGAME_IMG "res/newgameImg.png"
// to adjust
#define NEWGAME_PX 200
#define NEWGAME_PY 700

#define JOINGAME_IMG "res/joingameImg.png"
// to adjust
#define JOINGAME_PX 500
#define JOINGAME_PY 700

namespace Menu {

	class Image {
		public:
			Image(std::string _path, float posX=0, float posY=0);
			std::string &get_path() { return path; }
			void set_path(std::string &_path) { path = _path; }
			sf::Sprite &get_sprite() { return sprite; }
		private:
			std::string path;
			sf::Texture texture;
			sf::Sprite sprite;
	};

	class Button : public Image {
		public:
			Button(std::string _path, int posX=0, int posY=0);
			bool IsPressed(sf::Vector2f mousePosF);
			bool IsHovered(sf::Vector2f mousePosF);
	};

	class Window {
		public:
			Window(sf::VideoMode mode, const sf::String &title);
			void Loop();
		private:
			void Display();
			void Events();
			bool JoinGameEvents();
			void JoinGameDisplay();
			void StartGame();
		
			sf::RenderWindow window;
			Image background;
			Button newgameBtn;
			Button joingameBtn;
	};

	class JoinGame {
		public:
			JoinGame(sf::VideoMode mode, const sf::String &title);
			void Loop();
		private:
			void Display();
			void Events();
			sf::RenderWindow window;
			Image background;
	};
}

#endif /* !MENU_HPP_ */
