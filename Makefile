# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 14:18:45 by cpireyre          #+#    #+#              #
#    Updated: 2018/08/10 12:50:08 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
DEBUG	:=	-fsanitize=address -fsanitize=undefined -g3
INCLUDE	:=	-lncurses -Ilibft/ -lft -Llibft/
LIB		:=	libft/libft.a

PROGRAMS	=	push_swap checker game test

C_FILES		:=	wheel.c wheel2.c wheel3.c wheel_math.c \
	print.c actions.c check.c compound_actions.c \
	game.c quicksort.c error.c
H_FILES		:=	actions.h check.h header.h print.h wheel.h game.h quicksort.h \
	error.h

DEPS		=	$(H_FILES) Makefile $(C_FILES) $(LIB)

all: $(DEPS)
	$(PROGRAMS)

# to do: change this so the dep is a .o and not a .c and generate the .o iff necessary
$(PROGRAMS): %: %_main.c
	$(CC) $(CFLAGS) $(C_FILES) $< $(NAME) $(INCLUDE) $(DEBUG) -o $@

.PHONY: all, run
