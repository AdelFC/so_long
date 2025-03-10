CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_DIR = .
OBJ_DIR = obj

SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
YELLOW = \033[0;93m

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN) ft_printf compiled successfully!$(BLUE)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiled: $< $(BLUE)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW) Created directory: $(OBJ_DIR)$(BLUE)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW) ft_printf object files cleaned!$(BLUE)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN) ft_printf executable files removed!$(BLUE)"

re: fclean all

.PHONY: clean fclean re all
