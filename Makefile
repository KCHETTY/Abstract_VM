CLANG =	clang++

NAME = Abstract_VM

CFLAGS = -Wall -Werror -Wextra

C++_TYPE = -std=c++11

HEADER = ./Inc/

SRC_PATH = ./Src/

SRC = $(SRC_PATH)main.cpp $(SRC_PATH)parser.cpp $(SRC_PATH)virtual_machine.cpp $(SRC_PATH)type_factory.cpp $(SRC_PATH)Operand.cpp

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
