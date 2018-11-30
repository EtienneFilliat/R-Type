/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Image
*/

#ifndef IMAGE_HPP_
	#define IMAGE_HPP_

    #include <string>
    #include <SFML/Graphics.hpp>

class Image {
	public:
		Image(std::string _path, float posX=0, float posY=0);
		inline std::string &get_path() { return path; }
		inline void set_path(std::string &_path) { path = _path; }
		inline sf::Sprite &get_sprite() { return sprite; }
		inline void setPos(int posX = 0, int posY = 0) { sprite.setPosition(posX, posY); };
		void toggleFocus(bool focus);
		
	private:
		std::string path;
		sf::Texture texture;
		sf::Sprite sprite;
};

#endif /* !IMAGE_HPP_ */
