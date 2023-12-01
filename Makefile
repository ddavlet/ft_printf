CC = cc
AR = ar rcs
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft
UTILS_DIR = utils
LIBFT = $(LIBFT_DIR)/libft.a
RM = rm -f
RANNAME = ranlib $(NAME)
SRC = ft_printf.c ./utils/itoa_utils.c ./utils/bonus_utils.c ./utils/logic_utils.c ./params_utils.c
OBJ := $(SRC:%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -I $(LIBFT_DIR) $(UTILS_DIR) . $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
