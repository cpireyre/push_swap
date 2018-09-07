/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:05:08 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/05 15:45:01 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_next_int(int *sorted, int size, int previous)
{
	int	i;

	i = 0;
	while (i < size - 1 && sorted[i] != previous)
		i++;
	return ((i < size - 1) ? sorted[i + 1] : previous);
}

int	get_prev_int(int *sorted, int size, int next)
{
	int	i;

	i = 1;
	while (i < size && sorted[i] != next)
		i++;
	return ((i < size) ? sorted[i - 1] : next);
}

void	push_swap(t_ps *ps)
{
	t_pattern	solve;

	solve = find_winning_pattern(ps);
	if (solve)
		solve(ps, PRINT);
}

int		main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (1);
	ps = parse(argc, argv);
	push_swap(ps);
	free_ps(&ps);
	return (0);
}
