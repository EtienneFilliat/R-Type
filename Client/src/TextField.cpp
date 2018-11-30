/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** TextField
*/

#include "TextField.hpp"

Menu::TextField::TextField(const std::string backPath, int posX, int posY)
    : _background(backPath, posX, posY)
{
    _item.setPosition(posX + 10, posY + 35);
    _item.setFillColor(sf::Color::White);
    _item.setCharacterSize(20);
    _item.setOutlineThickness(0.3);
    _item.setOutlineColor(sf::Color::Black);
    _maxEntry = 32;
}

Menu::TextField::~TextField()
{
}

bool Menu::TextField::isSelected(sf::Vector2f mousePosF)
{
    if (getBounds().contains(mousePosF)) {
        _background.toggleFocus(true);
        return true;
    }
    _background.toggleFocus(false);
    return false;
}

void Menu::TextField::setText(sf::Uint32 entry)
{
    if (entry == '\b') {
        if (_data.getSize() > 0) {
            _data.erase(_data.getSize() - 1);
            _item.setString(_data);
        }
        return;    
    }
    if (_data.getSize() <= _maxEntry)
        _data += entry;
    _item.setString(_data);
};

void Menu::TextField::draw(sf::RenderWindow &window)
{
    window.draw(_background.get_sprite());
    window.draw(_item);
}