/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** TextField
*/

#ifndef TEXTFIELD_HPP_
	#define TEXTFIELD_HPP_

    #include <string>
    #include <iostream>
    #include <SFML/Graphics.hpp>
    #include "Image.hpp"

namespace Menu {

class TextField {

	public:
		TextField(const std::string backPath, int posX = 0, int posY = 0);
		~TextField();
        inline sf::String &getData() { return _data; };
        inline sf::Text getSfText() { return _item; };
        inline void clearText() { _data.clear(); };
        inline void setFont(sf::Font &font) { _font = font; _item.setFont(_font); };
        inline void setPos(float posX, float posY) { _item.setPosition(posX + 10, posY + 35); _background.setPos(posX, posY); };
        inline void setMaxCharacters(int maxChar) { _maxEntry = maxChar; };
        void draw(sf::RenderWindow &window);
        void setText(sf::Uint32 entry);
        bool isSelected(sf::Vector2f mousePosF);

	private:
        inline sf::FloatRect getBounds() { return _background.get_sprite().getGlobalBounds(); };
        unsigned int _maxEntry;
        sf::Font _font;
        sf::Text _item;
        sf::String _data;
        Image _background;
};

}

#endif /* !TEXTFIELD_HPP_ */
