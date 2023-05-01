NAME	= megaphone
CFLAGS	= -Wall -Wextra -Werror -std=c++98
CC		= c++
SRC		= megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	@echo "$(YELLOW)Compiling...$(COLOR_END)"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC)
	@echo "$(GREEN)Megaphone is compiled and ready to make a call!$(COLOR_END)"

clean:
	@echo "$(YELLOW)Cleaning...$(COLOR_END)"
	@rm -f $(NAME)
	@echo "$(GREEN)Cleaning done.$(COLOR_END)"


fclean: clean
	@echo "$(YELLOW)Cleaning everything...$(COLOR_END)"
	@rm -f $(NAME)
	@echo "$(GREEN)Cleaning done.$(COLOR_END)"

re:
	@echo "$(YELLOW)Recompiling...$(COLOR_END)"
	@make fclean
	@make all
	@echo "$(GREEN)The project has been recompiled.$(COLOR_END)"

.PHONY: all clean fclean re

COLOR_END = \033[0;39m
CYAN3 = \033[1;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m
RED = \033[1;91m
GREEN = \033[1;92m
CYAN2 = \x1B[1;36m
CYAN = \033[1;96m
