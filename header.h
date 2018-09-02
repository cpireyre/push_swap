/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:32:30 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/02 15:24:41 by cpireyre         ###   ########.fr       */
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
**	tab.c
*/

void			tab_erase_first(int **tab, int *size);
void			tab_add_first(int **tab, int *size, int value);
void			tab_rotate_down(int **tab, int *size);

/*
**	push.c
*/

void			pb(t_ps *ps);
void			pa(t_ps *ps);

/*
** swap.c
*/

void			sa(t_ps *ps);
void			sb(t_ps *ps);

/*
**	rotate.c
*/

void			ra(t_ps *ps);
void			rb(t_ps *ps);
void			rr(t_ps *ps);

#endif
