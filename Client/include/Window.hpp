/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Window
*/

#ifndef WINDOW_HPP_
	#define WINDOW_HPP_

    #include <string>
    #include <utility>
    #include <SFML/Graphics.hpp>
    #include <SFML/Network.hpp>
    #include "Image.hpp"
    #include "Button.hpp"
    #include "TextField.hpp"
    #include "Constants/constants.hpp"

    //to adjust
    #define MENU_DEFAULT_WIDTH 1200
    #define MENU_DEFAULT_HEIGHT 859

    #define MENU_TITLE  "R-Type"
    #define FONT_PATH   "Client/res/Roboto-Bold.ttf"
    #define MENU_DEFAULT_BG "Client/res/background.jpg"
    #define MENU_BG_WIDTH 1200
    #define MENU_BG_HEIGHT 859


    #define NEWGAME_IMG "Client/res/newgameImg.png"
    // to adjust
    #define NEWGAME_PX 200
    #define NEWGAME_PY 700

    #define JOINGAME_IMG "Client/res/joingameImg.png"
    // to adjust
    #define JOINGAME_PX 500
    #define JOINGAME_PY 700

    #define IP_IMG_PATH "Client/res/ip.png"
    #define PORT_IMG_PATH "Client/res/port.png"

namespace Menu {

    class Window {
            public:
                Window(sf::VideoMode mode, const sf::String &title);
                void Loop();
            private:
                void Display();
                void Events();
                bool ConnectToServer(const std::string &ip, const std::string &port);
                std::string FormatTCPData(Constants::TcpActions action, std::string &payload);
                bool ProcessRes(std::size_t bytesRecived, char *res);
            
                sf::RenderWindow window;
                Image background;
                Button joingameBtn;
                bool inGame;
                bool isIp;
                TextField ipTextField;
                TextField portTextField;
                std::string _ip;
                sf::Font font;
    };

}

#endif /* !WINDOW_HPP_ */
