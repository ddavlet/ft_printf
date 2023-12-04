CC = cc
AR = ar rcs
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft
UTILS_DIR = utils
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS = ft_printf.h
HEADERS_BONUS = ft_printf_bonus.h libft/libft.h
RM = rm -f
RANNAME = ranlib $(NAME)
SRC = ft_printf.c print_utils.c hexidec_utils.c
SRC_BONUS = ft_printf_bonus.c ./utils/itoa_utils_bonus.c ./utils/bonus_utils_bonus.c ./utils/logic_utils_bonus.c ./utils/params_utils_bonus.c
OBJ := $(SRC:%.c=%.o)
OBJ_BONUS := $(SRC:%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(HEADERS)
	$(AR) $(NAME) $(OBJ)

# bonus: $(OBJ) $(OBJ_BONUS) $(LIBFT) $(HEADERS_BONUS)
# 	cp $(LIBFT) $(NAME)
# 	$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)


%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -I $(LIBFT_DIR) -I $(UTILS_DIR) -I . -c $< -o $@

clean:
		$(RM) $(OBJ) $(OBJ_BONUS)
		$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
