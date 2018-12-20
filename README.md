# R-Type

This project aims to recreate the [R-Type](https://fr.wikipedia.org/wiki/R-Type) game and add a multiplayer mode to it. we had to implement a multi-threaded server using [Boost::asio](https://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio.html) and a graphical client in [SFML](https://www.sfml-dev.org/).

Final Grade : **A**

## Server

- [X] The server must be multi-threaded
- [X] The server must be able to handle more than one game at a time
- [ ] The server must be able to handle multiple
games in a row
- [X] The server must be the referee of all games it manages.

## Client

> The client is the display terminal of the game.

- [X] The client must contain anything necessary to display the game and handle player input.
- [X] The client must use the SFML.

## Requirements

### Platforms

- [ ] The project must be OS independent. (Only Linux compliant at delivery)
- [X] The project must be built using a [CMake](https://github.com/EtienneFilliat/R-Type/blob/master/CMakeLists.txt) and dependencies must be handled using [conan](https://github.com/EtienneFilliat/R-Type/blob/master/conanfile.txt).

### Protocol

- [X] You must **design** a binary protocol for client/server communications. (Cf [rfc9999.txt](https://github.com/EtienneFilliat/R-Type/blob/master/rfc9999.txt))
- [X] You must use _UDP_ for communications between the server and the clients. 
- [X] A second connection using _TCP_ can be tolerated but **you must provide a strong justification**.
- [X] You must document your protocol and the documentation must be an RFC as discribed in [RFC 2223](https://www.ietf.org/rfc/rfc2223.txt).
- [X] Your RFC must be formatted like an official RFC.
- [X] You must write the RFC in ASCII format.
- [X] You must respect standard RFC keywords as described in [RFC 2119](https://www.ietf.org/rfc/rfc2119.txt).

### Libraries

- [X] You must use the SFML on the client side and any rendering must be done using the SFML.
- [X] You are allowed to use **Boost::ASIO** for your server.

### Game Engine

> The game engine is the core foundation of any video game: it determines how you represent an object in-game, how the coordinate system works, and how the various systems of your game (graphics, physics, network... ) communicate.

- [ ] Ability to add systems to a game through the form of dynamic libraries, scripts...
- [X] Your engine must provides type-safety at compile-time.

We choosed to use an [ECS architecture](https://en.wikipedia.org/wiki/Entity%E2%80%93component%E2%80%93system) for our engine.


This is our architecture :
![ecs model](https://user-images.githubusercontent.com/26181710/50279537-3c767d00-044a-11e9-85b9-da4f513ff149.png)
