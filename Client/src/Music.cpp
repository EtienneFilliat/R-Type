/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Music
*/

#include <iostream>
#include "Music.hpp"

Music::Music(const std::string &path)
{
    if (!_music.openFromFile(path))
        std::cout << "Unable to open music file : " << path << std::endl;
    else {
        _music.setLoop(false);
    }
}

Music::~Music()
{
}
