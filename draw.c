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
	if (ret.size > LINES - 4)
	{
		endwin();
		ft_exit("Term window too small. Please try again.\n");
	}
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

void	print_action_string(char *line, int offset)
{
	attron(A_BOLD);
	if (ft_strchr(line, 'a'))
	{
		attron(COLOR_PAIR(3));
		mvprintw(1, offset + 9, "%s", line);
		attroff(COLOR_PAIR(3));
	}
	else if (ft_strchr(line, 'b'))
	{
		attron(COLOR_PAIR(4));
		mvprintw(1, offset + 30, "%s", line);
		attroff(COLOR_PAIR(4));
	}
	else
		mvprintw(1, offset + 18, "%s", line);
	attroff(A_BOLD);
	refresh();
}

void	visu_wrapper(t_ps *ps, char **line, int *sorted)
{
	t_draw	tape_a;
	t_draw	tape_b;
	int	height;
	int	horizontal_offset;

	horizontal_offset = 20;
	tape_a = create_draw_struct(A, 1);
	tape_b = create_draw_struct(B, 2);
	height = tape_a.size + tape_b.size + 2;
	clear();
	print_action_string(*line, horizontal_offset);
	mvprintw(height + 2, horizontal_offset + 1, "-------------------||-------------------");
	if (tape_a.size)
		ncurses_print_tab(tape_a, sorted, horizontal_offset + 8, height + 1);
	mvprintw(height + 3, horizontal_offset + 9, "a");
	if (tape_b.size)
		ncurses_print_tab(tape_b, sorted, horizontal_offset + 30, height + 1);
	mvprintw(height + 3, horizontal_offset + 30, "b");
	refresh();
	do_action(ps, line, NO_PRINT);
	height = 200000000;
	while (height--)
		;
}
