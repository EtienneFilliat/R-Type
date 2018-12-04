/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Background
*/

#ifndef BACKGROUND_HPP_
	#define BACKGROUND_HPP_

	#include <SFML/Graphics.hpp>
	#include "Constants/constants.hpp"

class Background {
	public:
		Background(const std::string &path);
		~Background();
		void Render(sf::RenderWindow &window);
		void Update(float offset);

	private:
		sf::Texture _bgTex;
		sf::Sprite _bgSprite;
		sf::Sprite _bgSprite2;
		sf::RectangleShape _bgShape;
		sf::Vector2f _bgSize;
		float _bgX;
		float _bgX2;
};

#endif /* !BACKGROUND_HPP_ */
