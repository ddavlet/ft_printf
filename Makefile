CC = cc
AR = ar rcs
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft
UTILS_DIR = utils
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS = ft_printf.h libft/libft.h
RM = rm -f
RANNAME = ranlib $(NAME)
SRC = ft_printf.c ./utils/itoa_utils.c ./utils/bonus_utils.c ./utils/logic_utils.c ./utils/params_utils.c
OBJ := $(SRC:%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) $(HEADERS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

bonus: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -I $(LIBFT_DIR) -I $(UTILS_DIR) -I . -c $< -o $@

clean:
		$(RM) $(OBJ)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
