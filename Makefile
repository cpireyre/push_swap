# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 14:18:45 by cpireyre          #+#    #+#              #
#    Updated: 2018/10/07 10:31:10 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
RM		:=	rm -f
CFLAGS	:=	-Wall -Wextra -Werror -O0
LIBDIR	:=	./libft
LIBFT	:=	$(LIBDIR)/libft.a
BFLAGS	:=	-I$(LIBDIR)/
#DEBUG	:=	-g3 -fsanitize=address -fsanitize=undefined 
INCLUDE	:=	-lncurses -lft -L$(LIBDIR)/

PROGRAMS	=	push_swap checker

PAT_SRC		:=	swaps.c doubles.c spin.c bswaps.c smart_pushes.c
PATTERNS	:=	$(addprefix ./patterns/, $(PAT_SRC))
C_FILES		:=	parse.c mem.c actions.c normalize.c multifd.c \
	push.c swap.c rotate.c reverse.c \
	tab.c math.c \
	draw.c visu.c  \
	$(PATTERNS) patterns.c \
	twotapes.c splitsort.c intelligentsort.c \
	is_ordered.c \
	sorcery.c
H_FILES		:=	header.h
OBJ			:=	$(C_FILES:.c=.o)

DEPS		=	$(H_FILES) Makefile 

all: push_swap checker
	ctags -R

$(LIBFT): force
	@$(MAKE) -C $(LIBDIR) 2> /dev/null

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(BFLAGS) $< -c -o $@ $(DEBUG)

$(PROGRAMS): %: %.o $(DEPS) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(BFLAGS) $(OBJ) $< $(NAME) $(INCLUDE) $(DEBUG) -o $@

clean:
	$(RM) checker_main.o push_swap.o
	$(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft/
	$(RM) $(PROGRAMS)
	$(RM) tags

re: fclean all

force:
	@true

run: push_swap
	sh run.sh

urn: run

.PHONY: all, re, clean, fclean, force, run, urn
