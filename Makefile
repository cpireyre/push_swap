# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 14:18:45 by cpireyre          #+#    #+#              #
#    Updated: 2018/07/13 08:11:14 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
DEBUG	:=	-fsanitize=address -fsanitize=undefined -g3
INCLUDE	:=	-Ilibft/ -Llibft/ -lft

CHECKER		:=	checker
PUSH_SWAP	:=	push_swap
C_FILES		:=	wheel.c wheel2.c checker_main.c print.c actions.c check.c
H_FILES		:=	wheel.h actions.h check.h print.h

all: $(CHECKER)

$(CHECKER): $(H_FILES) Makefile $(C_FILES)
	@$(CC) $(CFLAGS) $(C_FILES) $(NAME) $(INCLUDE) $(DEBUG) -o $(CHECKER)

run: all
	./$(CHECKER) 1 2 3 4 5 6


.PHONY: all, run
