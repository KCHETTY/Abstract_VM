CLANG =	clang++

NAME = AbstractVM

CFLAGS = -Wall -Werror -Wextra

C++_TYPE = -std=c++11

HEADER = ./Inc/

SRC_PATH = ./Src/

SRC = $(SRC_PATH)main.cpp $(SRC_PATH)virtual_machine.cpp $(SRC_PATH)factory.cpp $(SRC_PATH)lexer_parser.cpp $(SRC_PATH)Exceptions.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CLANG) -c $(CFLAGS) $(C++_TYPE) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CLANG) $(CFLAGS) $(C++_TYPE) -Qunused-arguments -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
