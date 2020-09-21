# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harmida <harmida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 23:19:44 by harmida           #+#    #+#              #
#    Updated: 2020/09/20 23:19:45 by harmida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRC			= main.c
OBJ			= $(SRC:.c=.o)
HEAD		= cub3d.h

all	: $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@
#$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(HEAD)
	$(CC) -o $(NAME) $(OBJ) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz








