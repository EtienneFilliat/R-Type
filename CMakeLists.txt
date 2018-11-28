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
	)

set(HPP_CLIENT Client/include/Window.hpp
		Client/include/Button.hpp
		Client/include/Image.hpp
		Client/include/Game.hpp
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
	)

set(HPP_SERVER
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

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

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
