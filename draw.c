/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:52:54 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/18 12:11:43 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void	visu_wrapper(t_ps *ps, char **line, int *sorted)
{
	int	i;
	int	height;
	int	size_a;
	int	size_b;

	size_a = tablen(A);
	size_b = tablen(B);
	height = size_a + size_b;
	clear();
	mvprintw(height + 2, 1, "-------------------||-------------------");
	i = -1;
	if (size_a)
		while (++i < size_a)
			mvprintw(height - i, 3, "%d", sorted[A[size_a - i - 1] - 1]);
	mvprintw(height + 3, 9, "a");
	i = -1;
	if (size_b)
		while (++i < size_b)
			mvprintw(height - i, 32, "%d", sorted[B[size_b - i - 1] - 1]);
	mvprintw(height + 3, 30, "b");
	refresh();
	do_action(ps, line, NO_PRINT);
	size_a = 100000000;
	while (size_a--)
		;
}
