##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC =	./src/main.cpp \
	./src/Image.cpp \
	./src/Button.cpp \
	./src/Menu.cpp

CXX = g++

CXXFLAGS += -I./include/ -W -Wextra -Wall -Werror

NAME = R-type_menu_test

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
