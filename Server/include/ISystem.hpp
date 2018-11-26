/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** R-Type Interface for Systems
*/

#ifndef ISYSTEM_HPP_
	#define ISYSTEM_HPP_

namespace Ecs {
	class ISystem {
	public:
		virtual ~ISystem() = default;
		virtual void run() = 0;

	protected:
	};
}

#endif /* !ISYSTEM_HPP_ */
