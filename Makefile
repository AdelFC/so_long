CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

FT_PRINTF_DIR = lib/ftprintf
GNL_DIR = lib/get_next_line
LIBFT_DIR = lib/libft
MLX_DIR = lib/mlx
UTILS_DIR = utils
SRC_DIR = src
OBJ_DIR = obj
INCS = -I includes
MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 

SRC = so_long.c

UTILS = 

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o) $(UTILS:.c=.o))

LIBS = -L$(FT_PRINTF_DIR) -lftprintf \
       -L$(GNL_DIR) -lftgnl \
       -L$(LIBFT_DIR) -lft	\
	   -L$(MLX_DIR) -lmlx

GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
YELLOW = \033[0;93m

all: $(FT_PRINTF_DIR)/libftprintf.a $(GNL_DIR)/libgnl.a $(MLX_DIR)/libmlx.a $(LIBFT_DIR)/libft.a $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN) Compilation of $(NAME) completed!$(BLUE)"

$(FT_PRINTF_DIR)/libftprintf.a:
	@make -C $(FT_PRINTF_DIR) --no-print-directory

$(GNL_DIR)/libgnl.a:
	@make -C $(GNL_DIR) --no-print-directory

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR) --no-print-directory

$(MLX_DIR)/libmlx.a:
	@make -C $(MLX_DIR) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@echo "$(CYAN)Compiled: $< $(BLUE)"

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@echo "$(CYAN)Compiled: $< $(BLUE)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW) Created directory: $(OBJ_DIR)$(BLUE)"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(FT_PRINTF_DIR) clean --no-print-directory
	@make -C $(GNL_DIR) clean --no-print-directory
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(MLX_DIR) clean --no-print-directory
	@echo "$(YELLOW) Cleaned object files.$(BLUE)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean --no-print-directory
	@make -C $(GNL_DIR) fclean --no-print-directory
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@make -C $(MLX_DIR) fclean --no-print-directory
	@echo "$(YELLOW) Removed $(NAME) and compiled files.$(BLUE)"

re: fclean all

.PHONY: all clean fclean re
