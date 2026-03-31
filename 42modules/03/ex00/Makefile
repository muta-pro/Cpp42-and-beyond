CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
NAME = 
SRC = main.cpp
all: $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: all fclean
.PHONY: all re fclean clean
