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

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) $(OPTION) $(INC_DIR) $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
