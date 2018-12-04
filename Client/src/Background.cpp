/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Background
*/

#include "Background.hpp"

Background::Background(const std::string &path)
{
    _bgTex.loadFromFile(path);
    _bgSize = (sf::Vector2f) _bgTex.getSize();
    _bgShape.setTexture(&_bgTex);
    _bgShape.setSize(_bgSize);
    _bgSprite.setTexture(_bgTex);
    _bgSprite2.setTexture(_bgTex);
    _bgX = 0;
    _bgX2 = _bgSize.x;

}

Background::~Background()
{}


void Background::Update(float offset)
{
    float outBorder = (_bgSize.x * - 1);
    if (_bgX > outBorder)
        _bgX -= offset;
    else
        _bgX = _bgSize.x;
    if (_bgX2 > outBorder)
        _bgX2 -= offset;
    else
        _bgX2 = _bgSize.x;
    _bgSprite.setPosition(_bgX, 0);
    _bgSprite2.setPosition(_bgX2, 0);
}

void Background::Render(sf::RenderWindow &window)
{
    window.draw(_bgSprite);
    window.draw(_bgSprite2);
}