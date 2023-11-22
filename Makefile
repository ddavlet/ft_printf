CC = cc
AR = ar rcs
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
OPTION = -c -I
INC_DIR = .
RM = rm -f
RANNAME = ranlib $(NAME)
SRC = ft_printf.c hexidec_utils.c print_utils.c
OBJ := $(SRC:%.c=%.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RANNAME)

%.o: %.c
	$(CC) $(FLAGS) $(OPTION) $(INC_DIR) $< -o $@

$(LIBFT):
	make -C libft

clean:
		$(RM) $(OBJ)
		make -C libft clean

fclean: clean
		$(RM) $(NAME)
		make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
