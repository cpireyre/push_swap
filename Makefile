# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 14:18:45 by cpireyre          #+#    #+#              #
#    Updated: 2018/07/13 14:09:05 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
DEBUG	:=	-fsanitize=address -fsanitize=undefined -g3
INCLUDE	:=	-Ift_printf/ -Lft_printf/ -lftprintf -Ift_printf/ \
	-Ift_printf/libft/

CHECKER		:=	checker
PUSH_SWAP	:=	push_swap
C_FILES		:=	wheel.c wheel2.c print.c actions.c check.c push_swap_main.c 
H_FILES		:=	wheel.h actions.h check.h print.h

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(H_FILES) Makefile $(C_FILES)
	$(CC) $(CFLAGS) $(C_FILES) $(NAME) $(INCLUDE) $(DEBUG) -o $(PUSH_SWAP)

$(CHECKER): $(H_FILES) Makefile $(C_FILES)
	@$(CC) $(CFLAGS) $(C_FILES) $(NAME) $(INCLUDE) $(DEBUG) -o $(CHECKER)

run: all
	./$(PUSH_SWAP) 9 8 7 6 5 4 3 2 1 0

.PHONY: all, run
