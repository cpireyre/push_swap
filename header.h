/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:32:30 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/01 12:45:57 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"

# define VISUAL_MODE	"-v"
# define MSG_ERROR		"Error\n"
# define MSG_OK			"OK\n"
# define MSG_NOT_OK		"KO\n"

typedef struct	s_ps
{
	int		*a;
	int		*b;
	int		size_total;
	int		size_a;
	int		size_b;
	int		*sorted;
}				t_ps;

/*
**	parse.c
*/

t_ps			*parse(int argc, char **argv);

/*
**	mem.c
*/

void			free_ps(t_ps *ps);
void			ft_exit(const char *errmsg);

/*
**	actions.c
*/

void			tab_erase_first(int **tab, int *size);
void			tab_add_first(int **tab, int *size, int value);

#endif
