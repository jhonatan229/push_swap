NAME = push_swap
FILES = ./utils.c ./main.c ./utils_order_list.c

CC = clang
CFLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(FILES) -o $(NAME) 

fclean:
	rm -rf $(NAME)

re: fclean all