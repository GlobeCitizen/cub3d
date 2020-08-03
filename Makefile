# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahnich <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 16:38:49 by mahnich           #+#    #+#              #
#    Updated: 2020/08/03 18:17:41 by mahnich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

SRC = ./config/config.c \
	  ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: libft minilibx $(NAME)

libft:
	make -C libft/

minilibx:
	make -C mlx/

$(OBJ):
	$(CC) -c $(SRC)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	make -C libft/ clean
	make -C mlx/ clean

fclean:
	rm -f $(NAME)
	make -C libft/ fclean
	make -C mlx/ fclean

re: fclean all
