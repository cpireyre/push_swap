/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:21:21 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/01 11:37:55 by cpireyre         ###   ########.fr       */
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

static int		*create_array(int argc, char **argv)
{
	int		*array;
	int		i;

	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		if (is_valid_arg(argv[i]))
			array[i - 1] = ft_atoi(argv[i]);
		else
		{
			free(array);
			return (NULL);
		}
	}
	return (array);
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
	ps->a = create_array(argc, argv);
	if (!(ps->a))
		ft_exit(MSG_ERROR);
	ps->b = NULL;
	ps->size_total = argc - 1;
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
