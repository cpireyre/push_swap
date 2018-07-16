# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 14:18:45 by cpireyre          #+#    #+#              #
#    Updated: 2018/07/16 12:20:08 by cpireyre         ###   ########.fr        #
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

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(H_FILES) Makefile $(C_FILES) push_swap_main.c
	$(CC) $(CFLAGS) $(C_FILES) push_swap_main.c $(NAME) $(INCLUDE) $(DEBUG) -o $(PUSH_SWAP)

$(CHECKER): $(H_FILES) Makefile $(C_FILES) checker_main.c
	$(CC) $(CFLAGS) $(C_FILES) checker_main.c $(NAME) $(INCLUDE) $(DEBUG) -o $(CHECKER)

$(TEST): $(H_FILES) Makefile $(C_FILES) test_main.c
	$(CC) $(CFLAGS) $(C_FILES) test_main.c $(NAME) $(INCLUDE) $(DEBUG) -o $(TEST)

$(GAME): $(H_FILES) Makefile $(C_FILES) game_main.c
	$(CC) $(CFLAGS) $(C_FILES) game_main.c $(NAME) $(INCLUDE) $(DEBUG) -o $(GAME)

run: all
	./$(PUSH_SWAP) 9 8 7 6 5 4 3 2 1 0

.PHONY: all, run
