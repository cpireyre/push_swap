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

void	ncurses_print_tab(int *tab, int *sorted, int size, size_t leftshift, int total)
{
	int		i;

	i = -1;
	while (++i < size)
		mvprintw(total - i, leftshift, "%d", sorted[tab[size - i - 1] - 1]);
}

void	visu_wrapper(t_ps *ps, char **line, int *sorted)
{
	int	height;
	int	size_a;
	int	size_b;

	size_a = tablen(A);
	size_b = tablen(B);
	height = size_a + size_b;
	clear();
	mvprintw(height + 2, 1, "-------------------||-------------------");
	if (size_a)
		ncurses_print_tab(A, sorted, size_a, 1, height);
	mvprintw(height + 3, 9, "a");
	if (size_b)
		ncurses_print_tab(B, sorted, size_b, 30, height);
	mvprintw(height + 3, 30, "b");
	refresh();
	do_action(ps, line, NO_PRINT);
	size_a = 900000000;
	while (size_a--)
		;
}
