# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 14:18:45 by cpireyre          #+#    #+#              #
#    Updated: 2018/08/12 09:44:09 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
RM		:=	rm -f
CFLAGS	:=	-Wall -Wextra -Werror
BFLAGS	:=	-Ilibft/
DEBUG	:=	-g
INCLUDE	:=	-lncurses -lft -Llibft/
LIB		:=	libft/libft.a

PROGRAMS	=	push_swap checker game test

C_FILES		:=	wheel.c wheel2.c wheel3.c wheel_math.c \
	print.c actions.c check.c compound_actions.c \
	game.c quicksort.c error.c
H_FILES		:=	actions.h check.h header.h print.h wheel.h game.h quicksort.h \
	error.h
OBJ			:=	$(C_FILES:.c=.o)

DEPS		=	$(H_FILES) Makefile $(LIB) $(OBJ) 

all: $(DEPS) push_swap checker

%.o: %.c
	$(CC) $(CFLAGS) $(BFLAGS) $< -c -o $@ $(DEBUG)

$(PROGRAMS): %: %_main.o $(DEPS)
	$(CC) $(CFLAGS) $(BFLAGS) $(C_FILES) $< $(NAME) $(INCLUDE) $(DEBUG) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PROGRAMS)
	rm -rf *.dSYM

.PHONY: all, run
