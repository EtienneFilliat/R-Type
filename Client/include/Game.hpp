/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Game
*/

#ifndef GAME_HPP_
	#define GAME_HPP_

    #include <SFML/Graphics.hpp>
	#include <boost/asio.hpp>
	#include <queue>
	#include "Network/UDPClient.hpp"
	#include "Image.hpp"
	#include "SafeQueue.hpp"
	#include "Paralax.hpp"
	#include "Constants/constants.hpp"
	#include "Network/StreamBuffer/UDPServerStreamBuffer.hpp"
	#include "Network/StreamBuffer/UDPClientStreamBuffer.hpp"

	#define PLAYER_SPRITE	"Client/res/spacecraft.png"
	#define MONSTER1_SPRITE	"Client/res/ovni.png"
	#define MONSTER2_SPRITE	"Client/res/ufo.png"
	#define SPRITE_SIZE		64
	#define STD_SERV_UPD_PORT	1488
	#define STD_CLI_UPD_PORT	1234

	class Game {
		public:
			Game(sf::RenderWindow &window, const std::string &ip, boost::asio::io_service &iso, const std::string &playername);
			~Game();
			void run();

		private:
			bool GameEvents();
			void GameDisplay();
			void CheckPlayerInput(sf::Event &event);
			void sendAction();
			void processFrame();

			sf::RenderWindow &_window;
			std::string _ip;
			Image *_player;
			Image *_monster1;
			Image *_monster2;
			std::string _playerName;
			std::shared_ptr<SafeQueue<struct UDPServerStreamBufferData>> _QClass;
			boost::asio::ip::udp::endpoint _endpoint;
			UDPClient *_client;
			Paralax _paralax;
			std::queue<struct UDPClientStreamBufferData> _actions;
	};

#endif /* !GAME_HPP_ */
