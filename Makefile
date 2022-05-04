# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 12:24:16 by ksadiku           #+#    #+#              #
#    Updated: 2022/05/04 12:56:36 by ksadiku          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
SRC = main.c save.c solve.c valid.c create_and_clean.c shifter.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME)

$(NAME):
	@echo "fillit is created. Do --> Make clean to remove *.o files."
	@make -C libft
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
	
clean:
	@echo "all object (*.o) files are removed"
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@echo "and an executable file fillit has been removed."
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re