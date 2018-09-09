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

void	push_swap(t_ps *ps)
{
/*
	t_pattern	solve;
	int		i;

	i = -1;
	while (++i < NBR_PATTERNS)
		if ((solve = deep_run(ps, g_all_patterns[i], &is_done)))
		{
			g_all_patterns[i](ps, PRINT);
			solve(ps, PRINT);
			return ;
		}
	crapsort(ps, PRINT);
*/
	t_pattern	*identity;

	identity = composition(&rra, &swap_and_down);
	run_sequence(&ps, identity, PRINT);
	free(identity);
}

int		main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (1);
	ps = parse(argc, argv);
	if (!is_done(ps))
		push_swap(ps);
	free_ps(&ps);
	return (0);
}
