# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 14:18:45 by cpireyre          #+#    #+#              #
#    Updated: 2018/06/29 14:59:05 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
INCLUDE	:=	-Ilibft/ -Llibft/ -lft

C_FILES	:= wheel.c

all:
	@$(CC) $(CFLAGS) $(C_FILES) $(NAME) $(INCLUDE)

run: all
	./a.out

.PHONY: all, run
