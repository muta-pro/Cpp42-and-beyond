CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20 -g -fsanitize=address,undefined -fno-sanitize-recover=undefined -MMD -MP
NAME = span
SRC = main.cpp Span.cpp
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
