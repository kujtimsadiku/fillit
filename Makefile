# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 12:24:16 by ksadiku           #+#    #+#              #
#    Updated: 2022/05/11 12:21:15 by ksadiku          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
SRC = main.c save.c solve.c valid.c create_and_clean.c shifter.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "executable fillit is been created"
	
clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@echo "all object (*.o) files are removed"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "and an executable file fillit has been removed."

re: fclean all

.PHONY: all clean fclean re