/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:32:14 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/13 15:01:05 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ps	*parse_visu(int argc, char **argv, int **sorted)
{
	t_ps	*ps;
	int	args;
	t_bool	dupes;

	ps = ft_memalloc(sizeof(t_ps));
	args = argc - 1;
	A = create_tab(argc, argv);
	B = ft_memalloc(sizeof(int) * (args + 1));
	*sorted = create_sorted_copy(A, args);
	normalize_tab(&A, *sorted, args);
	dupes = has_dupes(*sorted, args);
	if (dupes)
	{
		free(*sorted);
		quit_push_swap(&ps, MSG_DUPES);
	}
	return (ps);
}
