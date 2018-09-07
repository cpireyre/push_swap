/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:32:30 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/05 15:03:40 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include <ncurses.h>

# define VISUAL_MODE	"-v"
# define MSG_ERROR		"Error\n"
# define MSG_INVALID	"Error: invalid argument.\n"
# define MSG_OK			"OK\n"
# define MSG_NOT_OK		"KO\n"
# define MSG_DUPES		"Error: duplicate entries.\n"
# define MSG_BAD_ACTION	"Error: invalid instruction.\n"

# define A_FIRST	(ps->a[0])
# define A_SECOND	(ps->a[1])
# define A_LAST		(ps->a[ps->size_a - 1])

# define PA	do_print(ps, "pa")
# define PB	do_print(ps, "pb")
# define SA	do_print(ps, "sa")
# define SB	do_print(ps, "sb")
# define SS	do_print(ps, "ss")
# define RA	do_print(ps, "ra")
# define RB	do_print(ps, "rb")
# define RR	do_print(ps, "rr")
# define RRA	do_print(ps, "rra")
# define RRB	do_print(ps, "rrb")
# define RRR	do_print(ps, "rrr")

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
void			do_print(t_ps *ps, char *action);

/*
**	draw.c
*/

void			visu_wrapper(t_ps *ps, char **line);

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
t_bool			is_sorted(t_ps *ps);

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

/*
**	math.c
*/

int	tab_get_min(int *tab, int size);
int	tab_get_max(int *tab, int size);

/*
** --- A Pattern Language:
*/

typedef void	(*t_pattern)(t_ps *ps);
typedef t_bool	(*t_checker)(t_ps *ps);

/*
**	patterns.c
*/

t_pattern	find_winning_pattern(t_ps *ps);
t_bool		dry_run(t_ps *ps, t_pattern to_try, t_checker check);
/*
**	./patterns/swaps.c
*/

void	swap_second_third(t_ps *ps);
void	swap_first_last(t_ps *ps);

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
