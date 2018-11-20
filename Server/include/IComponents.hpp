/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** IComponents
*/

#ifndef ICOMPONENTS_HPP_
	#define ICOMPONENTS_HPP_

	#include "Constants.hpp"

class IComponents {
	public:
		virtual ~IComponents() = 0;
		virtual Constants::Comps getType() = 0;
		virtual void setType(Constants::Comps type) = 0;

	protected:
		Constants::Comps _type;
};

#endif /* !ICOMPONENTS_HPP_ */
