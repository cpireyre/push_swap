/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:59:19 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/24 09:56:49 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define X_A	5
#define X_B	20

void	condcolor(t_bool cond)
{
	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_BLUE, -1);
	if (cond)
		attron(COLOR_PAIR(1));
	else
		attron(COLOR_PAIR(2));
}

void	curse_print_wheel(t_wheel *wheel, int x, int y, t_bool left)
{
	if (!wheel)
		return ;
	condcolor(left);
	if (y > 80)
		y /= 2;
	wheel = wheel_go_to_tail(wheel);
	mvprintw(y + 2, 5, "----------------------------------------------------");
	if (left)
		mvprintw(y + 4, 11, "a");
	else
		mvprintw(y + 4, 47, "b");
	mvprintw(y, x, "%d", wheel->number);
	y--;
	wheel = wheel->prev;
	while (wheel->is_tail == false)
	{
		if (y < 10)
		{
			x += 8;
			y = 50;
		}
		mvprintw(y, x, "%d", wheel->number);
		y--;
		wheel = wheel->prev;
	}
	refresh();
}

void	ncurses_do_action(int keypress, t_wheel **a, t_wheel **b)
{
	if (keypress == 's' || keypress == 'g')
		do_rotate(*a);
	if (keypress == 'w' || keypress == 't')
		do_reverse_rotate(*a);
	if (keypress == 'k' || keypress == 'g')
		do_rotate(*b);
	if (keypress == 'i' || keypress == 't')
		do_reverse_rotate(*b);
	if (keypress == 'd')
		do_push(a, b);
	if (keypress == 'j')
		do_push(b, a);
	if (keypress == 'a' || keypress == 'b')
		do_swap(*a);
	if (keypress == 'l' || keypress == 'b')
		do_swap(*b);
}

void	wrap_ncurses(t_wheel **a, t_wheel **b)
{
	int		keypress;
	int		moves;

	curse_print_wheel(*a, 5, 3, true);
	mvprintw(15, 1, "q to quit");
	moves = 0;
	while ((keypress = getch()) != 'q')
	{
		clear();
		mvprintw(15, 1, "q to quit");
		ncurses_do_action(keypress, a, b);
		curse_print_wheel(*a, X_A, 30, true);
		curse_print_wheel(*b, X_B, 30, false);
		moves++;
	}
	if (*a && check_wheel_sortedness(*a) == true && !*b)
	{
		mvprintw(10, 10, "Well done! %d moves.", moves);
		getch();
	}
	endwin();
}
