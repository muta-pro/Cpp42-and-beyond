CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
NAME = animal
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp
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
.PHONY: all re fclean clean
