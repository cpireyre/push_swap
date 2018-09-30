/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:32:30 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/30 18:14:39 by cpireyre         ###   ########.fr       */
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

# define A		(ps->a)
# define B		(ps->b)

# define PA			pa(ps, will_print)
# define PB			pb(ps, will_print)
# define SA			sa(ps, will_print)
# define SB			sb(ps, will_print)
# define SS			ss(ps, will_print)
# define RA			ra(ps, will_print)
# define RB			rb(ps, will_print)
# define RR			rr(ps, will_print)
# define RRA		rra(ps, will_print)
# define RRB		rrb(ps, will_print)
# define RRR		rrr(ps, will_print)

typedef struct	s_ps
{
	int		*a;
	int		*b;
}				t_ps;

/*
**	multifd.c
*/

int				get_number_entries(char **argv);

/*
**	parse.c
*/

t_ps			*parse(char **argv);
int				*create_sorted_copy(int	*tab, int size);
t_bool			is_valid_arg(const char *arg);
t_bool			has_dupes(int *sorted, int size);
int				*create_tab(int argc, char **argv);
void			ps_fill_tab(int **tab, char **argv);

/*
**	normalize.c
*/

int				*calculate_splits(int *sorted, int size, int *nbr_splits);
void			normalize_tab(int **tab, int *sorted, int size);

/*
**	actions.c
*/

void			do_action(t_ps *ps, char **line, t_bool will_print);

/*
**	visu.c
*/

t_ps			*parse_visu(char **argv, int **sorted);

/*
**	draw.c
*/

typedef struct	s_draw
{
	int	*tape;
	int	size;
	int	color;
}				t_draw;

void			visu_wrapper(t_ps *ps, char **line, int *sorted);

/*
**	mem.c
*/

int				tablen(int *tab);
void			free_ps(t_ps **ps);
void			ft_exit(const char *errmsg);
void			quit_push_swap(t_ps **ps, const char *errmsg);

/*
**	tab.c
*/

void			tab_erase_first(int **tab);
void			tab_add_first(int **tab, int value);
void			tab_rotate_down(int **tab);
void			tab_rotate_up(int **tab);

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

int				tab_get_min(int *tab);
int				tab_get_max(int *tab);
void			tab_get_median(int *tab, int size, int *median);

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

t_pattern		find_pattern(t_ps *ps, t_checker to_pass);
t_bool			dry_run(t_ps *ps, int size, t_pattern to_try, t_checker check);
t_pattern		deep_run(t_ps *ps, int size, t_pattern to_try, t_checker check);
void			print_pattern(t_ps *ps, char *instruction);

void			leader(t_ps *ps, t_bool will_print);

/*
**	./patterns/doubles.c
*/

void			dra(t_ps *ps, t_bool will_print);
void			drra(t_ps *ps, t_bool will_print);
void			drb(t_ps *ps, t_bool will_print);
void			drrb(t_ps *ps, t_bool will_print);

/*
**	./patterns/swaps.c
*/

void			swap_second_third(t_ps *ps, t_bool will_print);
void			swap_first_last(t_ps *ps, t_bool will_print);
void			b_swap_second_third(t_ps *ps, t_bool will_print);
void			b_swap_first_last(t_ps *ps, t_bool will_print);
void			swap_and_down(t_ps *ps, t_bool will_print);
void			b_swap_and_down(t_ps *ps, t_bool will_print);

/*
**	./patterns/smart_pushes.c
*/

void			smart_push(t_ps *ps, t_bool will_print, int cutoff);
void			push_all_below_cutoff(t_ps *ps, t_bool will_print, int cutoff);

/*
**	spin.c
*/

int				distance(int *tab, int to_find);
t_pattern		spin_til(t_ps *ps, int to_find);
t_pattern		b_spin_til(t_ps *ps, int to_find);
void			b_actually_spin(t_ps *ps, t_bool will_print, int to_find);

/*
**	crapsort.c
*/

void			place_min_first(t_ps *ps, t_bool will_print);
void			crapsort(t_ps *ps, t_bool will_print);

/*
**	splitsort.c
*/

void			push_all_below_cutoff(t_ps *ps, t_bool will_print, int cutoff);
void			splitsort(t_ps *ps, t_bool will_print);
void			push_half(t_ps *ps, t_bool willprint);
void			selectionsort(t_ps *ps, t_bool will_print);

/*
**	twotapes.c
*/

void			two_tapes_quicksort(t_ps *ps);
t_bool			entries_in_range(int *tape, int a, int b);
t_pattern		find_closest_below(t_ps *ps, int a, int b, t_bool atob);

/*
**	intelligentsort.c
*/

void			subfilesort(t_ps *ps, t_bool will_print);

/*
**	a few checkers to start with.
**	todo: move them to their own files
*/

t_bool			is_done(t_ps *ps);

/*
**	is_ordered.c
*/

t_bool			first_three_ok(t_ps *ps);
t_bool			a_is_ordered(t_ps *ps);
t_bool			b_is_ordered(t_ps *ps);
t_bool			b_is_decreasing(t_ps *ps);
t_bool			a_is_increasing(t_ps *ps);

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

# define NBR_PATTERNS	18

/*
**	this array should be split up.
**	all the a patterns, all the cheap a patterns,
**	all the b patterns, etc.
**	so as to prevent useless checks.
*/

static const	t_pattern g_all_patterns[NBR_PATTERNS] = {
	&ra,
	&rra,
	&sa,
	&dra,
	&drra,
	&rb,
	&rrb,
	&sb,
	&drb,
	&drrb,
	&swap_and_down,
	&b_swap_and_down,
	&swap_second_third,
	&swap_first_last,
	&b_swap_and_down,
	&b_swap_second_third,
	&b_swap_first_last,
	&leader
};

/*
**	eldritch knowledge
**	sorcery.c
*/

t_pattern		*composition(t_pattern f, t_pattern g);
void			run_sequence(t_ps **ps, t_pattern *composite, t_bool print);
t_bool			autosolve(t_ps **ps, t_bool will_print, t_checker check);

#endif
