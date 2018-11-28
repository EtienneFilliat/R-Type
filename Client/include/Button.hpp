/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Button
*/

#ifndef BUTTON_HPP_
	#define BUTTON_HPP_

    #include <SFML/Graphics.hpp>
    #include "Image.hpp"

namespace Menu {

	class Button : public Image {
		public:
			Button(std::string _path, int posX=0, int posY=0);
			bool IsPressed(sf::Vector2f mousePosF);
			bool IsHovered(sf::Vector2f mousePosF);
	};

}

#endif /* !BUTTON_HPP_ */
