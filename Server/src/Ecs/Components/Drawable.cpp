/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** drawable component
*/

#include "Components/Drawable.hpp"

Ecs::Drawable::Drawable(int spriteSheetIndex,
		std::pair<int, int> spriteOffset,
		std::pair<int, int> spriteSize)
	:	_spriteSheetIndex(spriteSheetIndex),
		_spriteOffset(spriteOffset),
		_spriteSize(spriteSize)
{
	_type = Constants::DRAWABLE;
}

Ecs::Drawable::~Drawable()
{}

void Ecs::Drawable::setSpriteSheetIndex(int spriteSheetIndex) {
	_spriteSheetIndex = spriteSheetIndex;
}

void Ecs::Drawable::setSpriteOffset(std::pair<int, int> spriteOffset) {
	_spriteOffset.first = spriteOffset.first;
	_spriteOffset.second = spriteOffset.second;
}

void Ecs::Drawable::setSpriteSize(std::pair<int, int> spriteSize) {
	_spriteSize.first = spriteSize.first;
	_spriteSize.second = spriteSize.second;
}

int Ecs::Drawable::getSpriteSheetIndex()
{
	return _spriteSheetIndex;
}

std::pair<int, int> &Ecs::Drawable::getSpriteOffset()
{
	return _spriteOffset;
}

std::pair<int, int> &Ecs::Drawable::getSpriteSize()
{
	return _spriteSize;
}