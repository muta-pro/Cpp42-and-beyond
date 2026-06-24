CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g -fsanitize=address -MMD -MP
NAME = Form
SRC = main.cpp Bureaucrat.cpp Form.cpp
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
re: fclean all
.PHONY: all re fclean clean
