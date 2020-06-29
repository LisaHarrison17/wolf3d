# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lharris <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 15:28:19 by lharris           #+#    #+#              #
#    Updated: 2018/08/13 12:22:18 by lharris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
HEADER	=	libft.h
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
SRC		=	ft_atoi.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncpy.c \
			ft_strsplit.c \
			get_next_line.c

all:		$(NAME)

$(NAME):	
			@$(CC) -c $(SRC) $(FLAGS)
			@ar rcs $(NAME) *.o
			@ranlib $(NAME)
			@echo "-- LIBFT COMPILED --"

%.o:		$(HEADER)

clean:
			@-rm -f *.o

fclean:		clean
			@-rm -f *.a
			@echo "-- LIBRARY CLEARED --"

re:			fclean all

.PHONY:		all, clean, fclean, re