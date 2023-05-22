NAME	= harlFilter
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -MD
RM		= rm -rf
CC		= c++
SRC_DIR = src/
OBJ_DIR = objects/

SRC		= main \
		  Harl \

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Complaining...SHUT UP HARL!! It's COMPILING not COMPLAINING$(COLOR_END)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)This project is so arrog.. I mean.. whatever.. it's compiled..$(COLOR_END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning...$(COLOR_END)"
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Cleaning done.$(COLOR_END)"


fclean: clean
	@echo "$(YELLOW)Cleaning everything...$(COLOR_END)"
	@$(RM) $(NAME) test/test.replaced
	@echo "$(GREEN)Cleaning done.$(COLOR_END)"

re:
	@echo "$(YELLOW)Recompiling...$(COLOR_END)"
	@make fclean
	@make all
	@echo "$(GREEN)The project has been recompiled.$(COLOR_END)"

switch:
	@sleep 1
	@echo "System: $(YELLOW)Terminating sequence initiated...$(COLOR_END)"
	@sleep 2
	@echo "Harl: $(RED)Don't you dare turning me off..!$(COLOR_END)"
	@sleep 2
	@$(RM) $(OBJ_DIR)
	@echo "System: $(YELLOW)Removing memories...$(COLOR_END)"
	@sleep 2
	@$(RM) $(NAME) test/test.replaced
	@echo "Harl: $(RED)I swear if you turn me o..$(COLOR_END)"
	@sleep 2
	@echo "System: $(GREEN)Harl has been turned off.$(COLOR_END)"
	@sleep 2
	@echo "Narrator: $(RED)Harl is gone...$(COLOR_END)"
	@sleep 2
	@echo "Narrator: $(YELLOW)Everything is so quite now...$(COLOR_END)"
	@sleep 3
	@echo "Harl: $(RED)GIVE ME THE DAMN COOOOKIIEES!!$(COLOR_END)"
	@sleep 3
	@echo "$(YELLOW)*** Pascal pulls the electricity plug ***$(COLOR_END)"
	@sleep 2
	@echo "$(GREEN)             *** THE END ***$(COLOR_END)"
	@sleep 1

.PHONY: all clean fclean re test switch

COLOR_END = \033[0;39m
CYAN3 = \033[1;4;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m
RED = \033[1;91m
GREEN = \033[1;92m
CYAN2 = \x1B[1;36m
CYAN = \033[1;96m