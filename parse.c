/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:21:21 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/16 19:13:51 by cpireyre         ###   ########.fr       */
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

	tab = ft_memalloc(sizeof(int) * argc);
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
	int		args;
	int		*sorted;
	t_bool	dupes;

	ps = ft_memalloc(sizeof(t_ps));
	args = argc - 1;
	A = create_tab(argc, argv);
	B = ft_memalloc(sizeof(int) * (args + 1));
	sorted = create_sorted_copy(A, args);
	normalize_tab(&A, sorted, args);
	dupes = has_dupes(sorted, args);
	free(sorted);
	if (dupes)
		quit_push_swap(&ps, MSG_DUPES);
	return (ps);
}
