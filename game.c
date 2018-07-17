/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:59:19 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/16 13:07:43 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define POS_A	5
#define POS_B	10

void	curse_print_wheel(t_wheel *wheel, int x, int y)
{
	if (!wheel)
		return ;
	wheel = wheel_go_to_head(wheel);
	mvprintw(y, x, "%d", wheel->number);
	y++;
	wheel = wheel->next;
	while (wheel->is_head == false)
	{
		mvprintw(y, x, "%d", wheel->number);
		y++;
		wheel = wheel->next;
	}
	refresh();
}

void	wrap_ncurses(t_wheel **a, t_wheel **b)
{
	int		keypress;

	curse_print_wheel(*a, 5, 3);
	mvprintw(15, 1, "q to quit");
	while ((keypress = getch()) != 'q')
	{
		clear();
		mvprintw(15, 1, "q to quit");
		if (keypress == KEY_DOWN)
			do_rotate(*a);
		else if (keypress == KEY_UP)
			do_reverse_rotate(*a);
		else if (keypress == '+')
			do_rotate(*b);
		else if (keypress == '-')
			do_reverse_rotate(*b);
		else if (keypress == KEY_RIGHT)
			do_push(a, b);
		else if (keypress == KEY_LEFT)
			do_push(b, a);
		else
			printw("%c", keypress);
		curse_print_wheel(*a, POS_A, 3);
		curse_print_wheel(*b, POS_B, 3);
	}
	endwin();
}