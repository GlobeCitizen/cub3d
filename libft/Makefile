# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahnich <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 22:48:45 by mahnich           #+#    #+#              #
#    Updated: 2019/11/29 05:22:17 by mahnich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

SRC = ft_isdigit.c ft_memmove.c	ft_split.c	ft_strmapi.c ft_toupper.c \
ft_atoi.c ft_isprint.c ft_memset.c ft_strchr.c	ft_strncmp.c \
ft_bzero.c ft_itoa.c ft_strdup.c	ft_strnstr.c ft_calloc.c \
ft_memccpy.c ft_putchar_fd.c ft_strjoin.c ft_strrchr.c ft_isalnum.c \
ft_memchr.c ft_putendl_fd.c ft_strlcat.c ft_strtrim.c ft_isalpha.c \
ft_memcmp.c ft_putnbr_fd.c	ft_strlcpy.c ft_substr.c ft_isascii.c \
ft_memcpy.c ft_putstr_fd.c ft_strlen.c ft_tolower.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME)

$(OBJ) :
	$(CC) $(CCFLAGS) -c $(SRC)

$(OBJ_BONUS) :
	$(CC) $(CCFLAGS) -c $(SRC) $(SRC_BONUS)

bonus: $(OBJ_BONUS)
	ar cr $(NAME) $(OBJ) $(OBJ_BONUS)
	ranlib $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
