/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:52:54 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/14 10:06:45 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

typedef struct	s_draw
{
	int	*tape;
	int	size;
	int	color;
}		t_draw;

t_draw	create_draw_struct(int *tape, int color)
{
	t_draw	ret;

	ret.tape = tape;
	ret.size = tablen(tape);
	ret.color = color;
	return (ret);
}

void	ncurses_print_tab(t_draw to_draw, int *sorted, size_t leftshift, int total)
{
	int		i;

	i = -1;
	attron(COLOR_PAIR(to_draw.color));
	while (++i < to_draw.size)
		mvprintw(total - i, leftshift, "%d", \
				sorted[to_draw.tape[to_draw.size - i - 1] - 1]);
	attroff(COLOR_PAIR(to_draw.color));
}

void	visu_wrapper(t_ps *ps, char **line, int *sorted)
{
	t_draw	tape_a;
	t_draw	tape_b;
	int	height;

	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_BLUE, -1);
	tape_a = create_draw_struct(A, 1);
	tape_b = create_draw_struct(B, 2);
	height = tape_a.size + tape_b.size;
	clear();
	mvprintw(height + 2, 1, "-------------------||-------------------");
	if (tape_a.size)
		ncurses_print_tab(tape_a, sorted, 1, height);
	mvprintw(height + 3, 9, "a");
	if (tape_b.size)
		ncurses_print_tab(tape_b, sorted, 30, height);
	mvprintw(height + 3, 30, "b");
	refresh();
	do_action(ps, line, NO_PRINT);
	height = 200000000;
	while (height--)
		;
}
