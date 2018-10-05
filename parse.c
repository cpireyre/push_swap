/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:21:21 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/30 18:03:34 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <fcntl.h>

t_bool		has_dupes(int *sorted, int size)
{
	int		i;

	i = -1;
	while (++i < (size - 1))
		if (sorted[i] == sorted[i + 1])
			return (true);
	return (false);
}

void		fill_tab_from_string(int **tab, int *index, char *str)
{
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str)
		{
			(*tab)[*index] = ft_atoi(str);
			(*index)++;
			str += ft_strsplen(str);
		}
	}
}

void		ps_fill_tab(int **tab, char **argv)
{
	int		fd;
	int		index;
	char	*line;

	index = 0;
	while (*argv)
	{
		fd = open(*argv, O_RDONLY);
		if (fd == -1)
			fill_tab_from_string(tab, &index, *argv);
		else
		{
			while (ft_gnl(fd, &line))
				fill_tab_from_string(tab, &index, line);
			if ((close(fd) == -1))
				ft_exit("Something went wrong while closing file descriptor.");
		}
		argv++;
	}
}

t_ps		*parse(char **argv)
{
	t_ps	*ps;
	int		args;
	int		*sorted;
	t_bool	dupes;

	ps = ft_memalloc(sizeof(t_ps));
	ps->buf.pos = 0;
	ps->buf.filedesc = 1;
	ps->buf.written = 0;
	args = get_number_entries(argv);
	A = ft_memalloc(sizeof(int) * (args + 1));
	ps_fill_tab(&A, argv);
	B = ft_memalloc(sizeof(int) * (args + 1));
	sorted = create_sorted_copy(A, args);
	normalize_tab(&A, sorted, args);
	dupes = has_dupes(sorted, args);
	free(sorted);
	if (dupes)
		quit_push_swap(&ps, MSG_DUPES);
	return (ps);
}
