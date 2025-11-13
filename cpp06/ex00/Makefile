NAME    = convert
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRC     = main.cpp \
		ScalarConverter.cpp \

# Colors
GREEN   = \033[32m
YELLOW  = \033[33m
RESET   = \033[0m
RED     = \033[31m

all: $(NAME)

$(NAME): $(SRC)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	@echo "$(GREEN)Successfully compiled $(YELLOW)$(NAME)$(GREEN)!$(RESET)"

clean:
	@rm -f $(NAME)
	@echo "$(GREEN)Successfully deleted $(RED)$(NAME)$(GREEN)!$(RESET)"

fclean: clean

re: fclean all

.PHONY: all clean fclean re
