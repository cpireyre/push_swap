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

# define PA	pa(ps, will_print)
# define PB	pb(ps, will_print)
# define SA	sa(ps, will_print)
# define SB	sb(ps, will_print)
# define SS	ss(ps, will_print)
# define RA	ra(ps, will_print)
# define RB	rb(ps, will_print)
# define RR	rr(ps, will_print)
# define RRA	rra(ps, will_print)
# define RRB	rrb(ps, will_print)
# define RRR	rrr(ps, will_print)

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
**	actions.c
*/

void			do_action(t_ps *ps, char **line, t_bool will_print);

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

void			pb(t_ps *ps, t_bool will_print);
void			pa(t_ps *ps, t_bool will_print);

/*
** swap.c
*/

void			sa(t_ps *ps, t_bool will_print);
void			sb(t_ps *ps, t_bool will_print);
void			ss(t_ps *ps, t_bool will_print);

/*
**	rotate.c
*/

void			ra(t_ps *ps, t_bool will_print);
void			rb(t_ps *ps, t_bool will_print);
void			rr(t_ps *ps, t_bool will_print);

/*
**	reverse.c
*/

void			rra(t_ps *ps, t_bool will_print);
void			rrb(t_ps *ps, t_bool will_print);
void			rrr(t_ps *ps, t_bool will_print);

/*
**	math.c
*/

int	tab_get_min(int *tab, int size);
int	tab_get_max(int *tab, int size);

/*
** --- A Pattern Language:
*/

# define PRINT		1
# define NO_PRINT	0

typedef void	(*t_pattern)(t_ps *ps, t_bool will_print);
typedef t_bool	(*t_checker)(t_ps *ps);

typedef struct	s_action
{
	char		*instruction;
	t_pattern	operation;
}				t_action;

/*
**	patterns.c
*/

t_pattern	find_winning_pattern(t_ps *ps);
t_bool		dry_run(t_ps *ps, t_pattern to_try, t_checker check);
void	print_pattern(t_ps *ps, char *instruction);
/*
**	./patterns/swaps.c
*/

void	swap_second_third(t_ps *ps, t_bool will_print);
void	swap_first_last(t_ps *ps, t_bool will_print);

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
