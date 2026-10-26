CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wconversion -std=c++17 -g -fsanitize=address,undefined -fno-sanitize-recover=undefined -MMD -MP
NAME = mutantstack
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)
all: $(NAME)
$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
-include $(DEP)
clean:
	$(RM) $(OBJ) $(DEP)
fclean: clean
	$(RM) $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY: all clean fclean re
