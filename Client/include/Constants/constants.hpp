/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** constants
*/

#ifndef CONSTANTS_HPP_
	#define CONSTANTS_HPP_


namespace Constants {

    enum TcpActions {
        OK,
        KO,
        CONNECT,
        CREATE,
        LIST,
        JOIN,
        JOINED,
        READY,
        START
    };

    enum EVENT {
        MOVE,
        SHOOT,
        QUIT,    
    };

    enum DIRECTION {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    enum TYPE {
        UNKNOW,
        PLAYER,
        MONSTER_1,
        MONSTER_2,
        MISSILE
    };

    const std::size_t MaxPayloadSize = 1024;
    const int WindowHeight = 859;
    const int WindowWidth = 1200;
}

#endif /* !CONSTANTS_HPP_ */