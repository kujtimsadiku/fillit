NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = includes/

all:
	 $(CC) $(FLAGS) libft/libft.a main.c check_map.c save_map.c create_and_clean.c shifter.c solve.c utilits.c symbol.c -g -o $(NAME)
clean:
	rm fillit
re: clean all