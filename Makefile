# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 14:18:45 by cpireyre          #+#    #+#              #
#    Updated: 2018/08/17 14:59:01 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
RM		:=	rm -f
CFLAGS	:=	-Wall -Wextra -Werror
LIBDIR	:=	./libft
LIBFT	:=	$(LIBDIR)/libft.a
BFLAGS	:=	-I$(LIBDIR)/
DEBUG	:=	-g -fsanitize=address -fsanitize=undefined
INCLUDE	:=	-lncurses -lft -L$(LIBDIR)/

PROGRAMS	=	push_swap checker game test

C_FILES		:=	wheel.c wheel2.c wheel_math.c \
	print.c actions.c check.c \
	game.c error.c mem.c init.c
H_FILES		:=	actions.h check.h header.h print.h wheel.h game.h quicksort.h \
	error.h
OBJ			:=	$(C_FILES:.c=.o)

DEPS		=	$(H_FILES) Makefile 

all: push_swap checker
	ctags -R #remove later

$(LIBFT): force
	$(MAKE) -C $(LIBDIR)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(BFLAGS) $< -c -o $@ $(DEBUG)

$(PROGRAMS): %: %_main.o $(DEPS) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(BFLAGS) $(OBJ) $< $(NAME) $(INCLUDE) $(DEBUG) -o $@

clean:
	$(RM) checker_main.o push_swap.o
	$(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft/
	$(RM) $(PROGRAMS)
	rm -rf *.dSYM #comment out later?
	$(RM) tags

re: fclean all

force:
	@true

.PHONY: all, re, clean, fclean, force
