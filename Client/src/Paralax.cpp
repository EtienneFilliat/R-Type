/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Paralax
*/

#include <iostream>
#include "Paralax.hpp"

Paralax::Paralax()
{
}

Paralax::~Paralax()
{
}

void Paralax::addbck(const std::string &path)
{
    try {
        std::shared_ptr<Background> bck(new Background(path));
        _backgrounds.push_back(bck);
    } catch (std::exception &e) {
        std::cout << "Unable to create background from : " << path << std::endl;
    }
}

void Paralax::moveBackground(sf::RenderWindow &window)
{
    if (_backgrounds.empty())
        return ;
    int offset = 1;
    for (auto &bck : _backgrounds) {
        bck->Update(offset);
        bck->Render(window);
        offset++;
    }
}