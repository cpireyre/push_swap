/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:21:21 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/12 14:58:49 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <limits.h>

t_bool	is_valid_arg(const char *arg)
{
	intmax_t	tmp;

	if (ft_strlen(arg) > 11)
		return (false);
	tmp = ft_atoi(arg);
	if ((intmax_t)INT_MAX < (intmax_t)tmp || (intmax_t)tmp < (intmax_t)INT_MIN)
		return (false);
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		arg++;
	}
	return (true);
}

t_bool	has_dupes(int *sorted, int size)
{
	int		i;

	i = -1;
	while (++i < (size - 1))
		if (sorted[i] == sorted[i + 1])
			return (true);
	return (false);
}

int		*create_tab(int argc, char **argv)
{
	int		*tab;
	int		i;

	tab = ft_memalloc(sizeof(int) * (argc - 1));
	i = 0;
	while (++i < argc)
	{
		if (is_valid_arg(argv[i]))
			tab[i - 1] = ft_atoi(argv[i]);
		else
			ft_exit(MSG_INVALID);
	}
	return (tab);
}

t_ps	*parse(int argc, char **argv)
{
	t_ps	*ps;

	ps = ft_memalloc(sizeof(t_ps));
	ps->a = create_tab(argc, argv);
	ps->size_total = argc - 1;
	ps->b = ft_memalloc(sizeof(int) * ps->size_total);
	ps->size_a = ps->size_total;
	ps->size_b = 0;
	ps->sorted = create_sorted_copy(ps->a, ps->size_a);
	if (has_dupes(ps->sorted, ps->size_a))
		quit_push_swap(&ps, MSG_DUPES);
	ps->splits = calculate_splits(ps->sorted, ps->size_total, &ps->nbr_splits);
	ps->median = 0;
	normalize_tabs(&ps->a, &ps->sorted, ps->size_a);
	return (ps);
}
