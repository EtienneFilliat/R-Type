cmake_minimum_required(VERSION 3.5)

include_directories(
	../include/
)

set(OUTPUT ServerUnitTests)
project(${CLIENT} LANGUAGES CXX)

set(SRC
	../src/Ecs/Entity.cpp
)

set(TESTS
	EntityTests.cpp
)

add_executable(${OUTPUT} ${SRC} ${TESTS})

target_link_libraries(${OUTPUT}
	criterion
)