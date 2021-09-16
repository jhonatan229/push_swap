NAME = push_swap
FILES = ./utils.c ./main.c ./utils_order_list.c ./sort_large_list.c ./sort_small_list.c
OBJ = $(FILES:.c=.o)

CC = clang
CFLAGS = -Wextra -Werror -Wall -fsanitize=leak

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

$(OBJ): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re: fclean all