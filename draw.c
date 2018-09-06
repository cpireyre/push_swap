/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:52:54 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/05 15:47:20 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void	ncurses_print_tab(int *tab, int size, size_t leftshift, int	total)
{
	int		i;

	i = -1;
	while (++i < size)
		mvprintw(total - i, leftshift, "%d", tab[size - 1 - i]);
}

void	visu_wrapper(t_ps *ps, char **line)
{
	clear();
	do_action(ps, line);
	mvprintw(ps->size_total + 2, 1, "----------------------------------------");
	ncurses_print_tab(ps->a, ps->size_a, 1, ps->size_total);
	mvprintw(ps->size_total + 3, 9, "a");
	ncurses_print_tab(ps->b, ps->size_b, 30, ps->size_total);
	mvprintw(ps->size_total + 3, 30, "b");
	refresh();
	sleep(1);
}
