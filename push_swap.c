/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:05:08 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/16 19:12:41 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_swap(t_ps *ps)
{
	t_pattern	solve;
	int			i;
	int			size;

	i = -1;
	size = tablen(A) + tablen(B);
	solve = find_pattern(ps, &is_done);
	if (solve)
		solve(ps, PRINT);
	else
	{
		while (++i < NBR_PATTERNS)
			if ((solve = deep_run(ps, size, g_all_patterns[i], &is_done)))
			{
				g_all_patterns[i](ps, PRINT);
				solve(ps, PRINT);
				return ;
			}
		size < 250 ? splitsort(ps, PRINT) : two_tapes_quicksort(ps);
	}
}

int		main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (1);
	argc--;
	argv++;
	ps = parse(argv);
	if (!is_done(ps))
		push_swap(ps);
	free_ps(&ps);
	return (0);
}
