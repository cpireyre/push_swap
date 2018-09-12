/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:52:54 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/12 14:20:40 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void	ncurses_print_tab(int *tab, int size, size_t leftshift, int total)
{
	int		i;

	i = -1;
	while (++i < size)
		mvprintw(total - i, leftshift, "%d", tab[size - 1 - i]);
}

void	visu_wrapper(t_ps *ps, char **line)
{
	int	height;
	int	size_a;
	int	size_b;

	size_a = tablen(A);
	size_b = tablen(B);
	height = ft_max(size_a, size_b);
	clear();
	do_action(ps, line, NO_PRINT);
	mvprintw(height + 2, 1, "-------------------||-------------------");
	ncurses_print_tab(A, size_a, 1, height);
	mvprintw(height + 3, 9, "a");
	ncurses_print_tab(B, size_b, 30, height);
	mvprintw(height + 3, 30, "b");
	refresh();
	sleep(1);
}
