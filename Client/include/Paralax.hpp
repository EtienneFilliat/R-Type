/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Paralax
*/

#ifndef PARALAX_HPP_
	#define PARALAX_HPP_

    #include <list>
    #include <memory>
    #include "Background.hpp"

class Paralax {
	public:
		Paralax();
		~Paralax();
        void addbck(const std::string &path);
        void moveBackground(sf::RenderWindow &window);

	private:
        std::list<std::shared_ptr<Background>> _backgrounds;
};

#endif /* !PARALAX_HPP_ */
