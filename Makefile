# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 14:18:45 by cpireyre          #+#    #+#              #
#    Updated: 2018/07/01 13:21:40 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
DEBUG	:=	-fsanitize=address -fsanitize=undefined -g3
INCLUDE	:=	-Ilibft/ -Llibft/ -lft

CHECKER	:=	checker
C_FILES	:=	wheel.c main.c
H_FILES	:=	wheel.h

all: $(CHECKER)

$(CHECKER): $(H_FILES) Makefile
	@$(CC) $(CFLAGS) $(C_FILES) $(NAME) $(INCLUDE) $(DEBUG) -o $(CHECKER)

run: all
	./a.out

.PHONY: all, run
