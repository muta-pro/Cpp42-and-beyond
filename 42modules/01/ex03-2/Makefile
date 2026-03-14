CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

NAME = weapon

SRC = main.cpp Document.cpp EditorA.cpp EditorB.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
