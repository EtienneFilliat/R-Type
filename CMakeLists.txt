cmake_minimum_required(VERSION 3.5)
set(WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#	------------------- CLIENT -------------------

set(CLIENT r-type_client)
project(${CLIENT} LANGUAGES CXX)
set(CLIENT_SRC_PATH "Client/src")
set(CLIENT_INCLUDE_PATH "Client/include")

#	------------- CLIENT_RESSOURCES --------------

set(SRC_CLIENT Client/src/main.cpp
		Client/src/Image.cpp
		Client/src/Button.cpp
		Client/src/Window.cpp
		Client/src/Game.cpp
		Client/src/Timer.cpp
		Client/src/TextField.cpp
		Client/src/Network/UDPClient.cpp
		Client/src/Network/StreamBuffer/AStreamBuffer.cpp
		Client/src/Network/StreamBuffer/UDPClientStreamBuffer.cpp
		Client/src/Network/StreamBuffer/UDPServerStreamBuffer.cpp
	)

set(HPP_CLIENT Client/include/Window.hpp
		Client/include/Button.hpp
		Client/include/Image.hpp
		Client/include/Game.hpp
		Client/include/TextField.hpp
		Client/include/Timer.hpp
		Client/include/Constants/constants.hpp
		Client/include/Network/UDPClient.hpp
		Client/include/Network/StreamBuffer/AStreamBuffer.hpp
		Client/include/Network/StreamBuffer/UDPClientStreamBuffer.hpp
		Client/include/Network/StreamBuffer/UDPServerStreamBuffer.hpp
		Client/include/IoServiceWork.hpp
		Client/include/SafeQueue.hpp
	)

#	--------------- CLIENT_LINKING ---------------
add_executable(${CLIENT} ${SRC_CLIENT} ${HPP_CLIENT})

target_link_libraries(${CLIENT}
			CONAN_PKG::boost
			CONAN_PKG::sfml
			)

target_include_directories(${CLIENT} PUBLIC
			${CONAN_INCLUDE_DIRS_BOOST}
			${CONAN_INCLUDE_DIRS_SFML}
			${CLIENT_INCLUDE_PATH}
			)

#	------------------- SERVER -------------------

set(SERVER r-type_server)
project(${SERVER} LANGUAGES CXX)
set(SERVER_SRC_PATH "Server/src")
set(SERVER_INCLUDE_PATH "Server/include")

#	------------- SERVER_RESSOURCES --------------

set(SRC_SERVER Server/src/main.cpp
		Server/src/GameLoop.cpp
		Server/src/Timer.cpp
		Server/src/Ecs/Entity.cpp
		Server/src/Ecs/EntityManager.cpp
		Server/src/Ecs/HitboxSystem.cpp
		Server/src/Ecs/FrameSendingSystem.cpp
		Server/src/Ecs/AISystem.cpp
		Server/src/Ecs/PlayerSystem.cpp
		Server/src/Ecs/Components/Health.cpp
		Server/src/Ecs/Components/Position.cpp
		Server/src/Ecs/Components/Acceleration.cpp
		Server/src/Ecs/Components/Damages.cpp
		Server/src/Ecs/Components/HitBox.cpp
		Server/src/Ecs/Components/Drawable.cpp
		Server/src/Network/AServer.cpp
		Server/src/Network/TCPServer.cpp
		Server/src/Network/TCPServerRoutine.cpp
		Server/src/Network/UDPServer.cpp
		Server/src/Network/Components/AServerComponent.cpp
		Server/src/Network/Components/ConnectComponent.cpp
		Server/src/Network/Components/MoveComponent.cpp
		Server/src/Network/StreamBuffer/AStreamBuffer.cpp
		Server/src/Network/StreamBuffer/TCPStreamBuffer.cpp
		Server/src/Network/StreamBuffer/UDPServerStreamBuffer.cpp
		Server/src/Network/StreamBuffer/UDPClientStreamBuffer.cpp
	)

set(HPP_SERVER Server/include/Constants.hpp
		Server/include/GameLoop.hpp
		Server/include/Entity.hpp
		Server/include/EntityManager.hpp
		Server/include/ISystem.hpp
		Server/include/ASystem.hpp
		Server/include/HitboxSystem.hpp
		Server/include/FrameSendingSystem.hpp
		Server/include/AISystem.hpp
		Server/include/PlayerSystem.hpp
		Server/include/IoServiceWork.hpp
		Server/include/SafeQueue.hpp
		Server/include/Timer.hpp
		Server/include/Components/IComponent.hpp
		Server/include/Components/AComponent.hpp
		Server/include/Components/Health.hpp
		Server/include/Components/Position.hpp
		Server/include/Components/Acceleration.hpp
		Server/include/Components/Damages.hpp
		Server/include/Components/HitBox.hpp
		Server/include/Components/AI.hpp
		Server/include/Components/Weapon.hpp
		Server/include/Components/Drawable.hpp
		Server/include/Network/AServer.hpp
		Server/include/Network/TCPServer.hpp
		Server/include/Network/TCPServerRoutine.hpp
		Server/include/Network/UDPServer.hpp
		Server/include/Network/Components/IServerComponent.hpp
		Server/include/Network/Components/AServerComponent.hpp
		Server/include/Network/Components/ConnectComponent.hpp
		Server/include/Network/Components/MoveComponent.hpp
		Server/include/Network/Components/ConnectComponent.hpp
		Server/include/Network/Components/Actions.hpp
		Server/include/Network/Components/Directions.hpp
		Server/include/Network/Components/Events.hpp
		Server/include/Network/DataStruct/Lobby.hpp
		Server/include/Network/DataStruct/Player.hpp
		Server/include/Network/StreamBuffer/AStreamBuffer.hpp
		Server/include/Network/StreamBuffer/TCPStreamBuffer.hpp
		Server/include/Network/StreamBuffer/UDPServerStreamBuffer.hpp
		Server/include/Network/StreamBuffer/UDPClientStreamBuffer.hpp
	)

#	--------------- SERVER_LINKING ---------------

add_executable(${SERVER} ${SRC_SERVER} ${HPP_SERVER})
target_link_libraries(${SERVER}
			CONAN_PKG::boost
			)
target_include_directories(${SERVER} PUBLIC
			${CONAN_INCLUDE_DIRS_BOOST}
			${SERVER_INCLUDE_PATH}
			)
#	------------------- CONNAN -------------------

include(build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

#	----------------- UNIT_TEST ------------------

add_subdirectory(Server/tests)

#	-------------------- MISC --------------------

# Set default compile flags for GCC
if(CMAKE_COMPILER_IS_GNUCXX)
	message(STATUS "GCC detected, adding compile flags")
	list(APPEND CLIENT_COMPILE_OPTIONS "-std=c++14 -W -Wall -Wextra")
	list(APPEND SERVER_COMPILE_OPTIONS "-std=c++14 -W -Wall -Wextra")
	foreach(ITEM ${SERVER_COMPILE_OPTIONS})
		message("    ---> SERVER FLAGS  ${ITEM}")
		set_source_files_properties(${SRC_SERVER} PROPERTIES COMPILE_FLAGS ${ITEM})
	endforeach(ITEM in SERVER_COMPILE_OPTIONS)
	foreach(ITEM ${CLIENT_COMPILE_OPTIONS})
		message("    ---> CLIENT FLAGS  ${ITEM}")
		set_source_files_properties(${SRC_CLIENT} PROPERTIES COMPILE_FLAGS ${ITEM})
	endforeach(ITEM in CLIENT_COMPILE_OPTIONS)
endif(CMAKE_COMPILER_IS_GNUCXX)

# Set default compile flags for MSVC
# MSVC FLAGS DOC -> https://msdn.microsoft.com/fr-fr/library/fwkeyyhe.aspx
if(MSVC)
	message(STATUS "MSVC detected, adding compile flags")
	list(APPEND SERVER_COMPILE_OPTIONS "/std:c++14 -D_WIN32_WINNT=0x0A00")
	list(APPEND CLIENT_COMPILE_OPTIONS "/std:c++14")
	foreach(ITEM ${SERVER_COMPILE_OPTIONS})
		message("    ---> SERVER FLAGS  ${ITEM}")
		set_source_files_properties(${SRC_SERVER} PROPERTIES COMPILE_FLAGS ${ITEM})
	endforeach(ITEM in SERVER_COMPILE_OPTIONS)
	foreach(ITEM ${CLIENT_COMPILE_OPTIONS})
		message("    ---> CLIENT FLAGS  ${ITEM}")
		set_source_files_properties(${SRC_CLIENT} PROPERTIES COMPILE_FLAGS ${ITEM})
	endforeach(ITEM in CLIENT_COMPILE_OPTIONS)
endif(MSVC)
