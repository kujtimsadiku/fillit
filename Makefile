NAME = fillit
CC = gcc
SRC = main.c save.c solve.c utilits.c valid.c create_and_clean.c shifter.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME) -g
	
clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re