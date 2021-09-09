NAME = push_swap
FILES = ./utils.c ./main.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(FILES) -o $(NAME) 

fclean:
	rm -rf $(NAME)

re: fclean all