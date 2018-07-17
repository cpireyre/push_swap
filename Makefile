# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 14:18:45 by cpireyre          #+#    #+#              #
#    Updated: 2018/07/17 15:05:27 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
DEBUG	:=	-fsanitize=address -fsanitize=undefined -g3
INCLUDE	:=	-Ift_printf/ -Lft_printf/ -lftprintf -Ift_printf/ \
	-Ift_printf/libft/ -lncurses

CHECKER		:=	checker
PUSH_SWAP	:=	push_swap
TEST		:=	test
GAME		:=	game

C_FILES		:=	wheel.c wheel2.c wheel3.c wheel_math.c \
	print.c actions.c check.c compound_actions.c \
	game.c
H_FILES		:=	actions.h check.h header.h print.h wheel.h game.h

DEPS		=	$(H_FILES) Makefile $(C_FILES)

all: $(PUSH_SWAP) $(CHECKER) $(TEST) $(GAME)

$(PUSH_SWAP): $(DEPS) push_swap_main.c
	$(CC) $(CFLAGS) $(C_FILES) push_swap_main.c $(NAME) $(INCLUDE) $(DEBUG) -o $(PUSH_SWAP)

$(CHECKER): $(DEPS) checker_main.c
	$(CC) $(CFLAGS) $(C_FILES) checker_main.c $(NAME) $(INCLUDE) $(DEBUG) -o $(CHECKER)

$(TEST): $(DEPS) test_main.c
	$(CC) $(CFLAGS) $(C_FILES) test_main.c $(NAME) $(INCLUDE) $(DEBUG) -o $(TEST)

$(GAME):  $(DEPS) game_main.c
	$(CC) $(CFLAGS) $(C_FILES) game_main.c $(NAME) $(INCLUDE) $(DEBUG) -o $(GAME)

.PHONY: all, run
