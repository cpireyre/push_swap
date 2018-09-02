/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:21:21 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/01 13:53:09 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <limits.h>

static t_bool	is_valid_arg(const char *arg)
{
	intmax_t	tmp;

	tmp = ft_atoi(arg);
	if ((intmax_t)INT_MAX < (intmax_t)tmp || (intmax_t)tmp < (intmax_t)INT_MIN)
		return (false);
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg) && !ft_isblank(*arg))
			return (false);
		arg++;
	}
	return (true);
}

static int		*create_tab(int argc, char **argv)
{
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		if (is_valid_arg(argv[i]))
			tab[i - 1] = ft_atoi(argv[i]);
		else
		{
			free(tab);
			return (NULL);
		}
	}
	return (tab);
}

t_bool			has_dupes(int *sorted, int size)
{
	int		i;

	i = -1;
	while (++i < (size - 1))
	{
		if (sorted[i] == sorted[i + 1])
			return (true);
	}
	return (false);
}

t_ps			*parse(int argc, char **argv)
{
	t_ps	*ps;
	int		*sorted;

	ps = malloc(sizeof(t_ps));
	if (!ps)
		ft_exit(MSG_ERROR);
	ps->a = create_tab(argc, argv);
	if (!(ps->a))
		ft_exit(MSG_ERROR);
	ps->size_total = argc - 1;
	ps->b = malloc(sizeof(int) * ps->size_total);
	ft_printf("%d size total", ps->size_total);
	ft_printf("%p\n", ps->b);
	if (!ps->b)
		ft_exit(MSG_ERROR);
	ps->size_a = ps->size_total;
	ps->size_b = 0;
	sorted = malloc(sizeof(int) * ps->size_a);
	if (!sorted)
		ft_exit(MSG_ERROR);
	ft_memcpy((void*)sorted, (void*)(ps->a), sizeof(int) * ps->size_a);
	ft_sort_tab(sorted, ps->size_a);
	ps->sorted = sorted;
	if (has_dupes(sorted, ps->size_a))
		ft_exit(MSG_ERROR);
	return (ps);
}
