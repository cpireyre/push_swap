/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:05:08 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/30 18:20:11 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define TEST_INSERT 0

void	push_swap(t_ps *ps)
{
	t_pattern	solve;
	int			i;
	int			size;

	i = -1;
	size = tablen(A) + tablen(B);
	solve = find_pattern(ps, &is_done);
	if (TEST_INSERT)
	{
		while (A[0])
			pb(ps, PRINT);
		insertionsort(ps, PRINT);
	}
	else
	{
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
			(size < 1) ? splitsort(ps, PRINT) : subfilesort(ps, PRINT);
			selectionsort(ps, PRINT);
		}
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
	flush_buf(&(ps->buf));
	free_ps(&ps);
	return (0);
}
