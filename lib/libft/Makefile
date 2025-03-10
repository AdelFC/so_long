CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC_DIR = .
OBJ_DIR = obj

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_bzero.c ft_putendl_fd.c ft_strlcpy.c ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strdup.c ft_strchr.c ft_strrchr.c \
	  ft_strnstr.c ft_calloc.c ft_strncmp.c ft_memchr.c ft_memset.c \
	  ft_memcpy.c ft_memmove.c ft_memcmp.c ft_itoa.c ft_putnbr_fd.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_strtrim.c ft_substr.c \
	  ft_striteri.c ft_strjoin.c ft_split.c ft_strmapi.c ft_atoi.c \
	  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
YELLOW = \033[0;93m

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN) libft compiled successfully!$(BLUE)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiled: $< $(BLUE)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW) Created directory: $(OBJ_DIR)$(BLUE)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW) libft object files cleaned!$(BLUE)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN) libft executable files removed!$(BLUE)"

re: fclean all

.PHONY: all clean fclean re
