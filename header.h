/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:32:30 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/05 09:39:04 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"

# define VISUAL_MODE	"-v"
# define MSG_ERROR		"Error\n"
# define MSG_INVALID		"Error: invalid argument.\n"
# define MSG_OK			"OK\n"
# define MSG_NOT_OK		"KO\n"
# define MSG_DUPES		"Error: duplicate entries.\n"
# define MSG_BAD_ACTION	"Error: invalid instruction.\n"

typedef struct	s_ps
{
	int		*a;
	int		*b;
	int		size_total;
	int		size_a;
	int		size_b;
	int		*sorted;
}				t_ps;

typedef struct	s_action
{
	char		*instruction;
	void		(*operation)(t_ps *);
}				t_action;

/*
**	parse.c
*/

t_ps			*parse(int argc, char **argv);

/*
**	actions.c
*/

void			do_action(t_ps *ps, char **line);

/*
**	mem.c
*/

void			free_ps(t_ps **ps);
void			ft_exit(const char *errmsg);
void			quit_push_swap(t_ps **ps, const char *errmsg);

/*
**	tab.c
*/

void			tab_erase_first(int **tab, int *size);
void			tab_add_first(int **tab, int *size, int value);
void			tab_rotate_down(int **tab, int *size);
void			tab_rotate_up(int **tab, int *size);

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
void			ss(t_ps *ps);

/*
**	rotate.c
*/

void			ra(t_ps *ps);
void			rb(t_ps *ps);
void			rr(t_ps *ps);

/*
**	reverse.c
*/

void			rra(t_ps *ps);
void			rrb(t_ps *ps);
void			rrr(t_ps *ps);

static const	t_action g_actions[11] = {
	(t_action){"pa", &pa},
	(t_action){"pb", &pb},
	(t_action){"sa", &sa},
	(t_action){"sb", &sb},
	(t_action){"ss", &ss},
	(t_action){"ra", &ra},
	(t_action){"rb", &rb},
	(t_action){"rr", &rr},
	(t_action){"rra", &rra},
	(t_action){"rrb", &rrb},
	(t_action){"rrr", &rrr}
};

#endif
