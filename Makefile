NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = includes/

all:
	 $(CC) $(FLAGS) libft/libft.a main.c valid.c save.c create_and_clean.c shifter.c solve.c utilits.c -g -o $(NAME)
# clean:
# 	rm fillit
re: clean all