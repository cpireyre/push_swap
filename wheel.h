/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:49 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/10 13:58:31 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHEEL_H
# define WHEEL_H

typedef struct	s_wheel
{
	struct s_wheel	*prev;
	struct s_wheel	*next;
	t_bool			is_head;
	t_bool			is_tail;
	int				number;
	int				rank;
}				t_wheel;

typedef struct	s_ps
{
	t_wheel **a;
	t_wheel **b;
	size_t	total_size;
	int		*sorted_cpy;
}				t_ps;

/*
** wheel.c
*/

void			wheel_free_all(t_wheel *spoke);
void			wheel_swap_spokes(t_wheel *a, t_wheel *b);
t_wheel			*wheel_delete_spoke(t_wheel *to_delete);
t_wheel 		*wheel_go_to_max(t_wheel *spoke);
size_t			wheel_count_spokes(t_wheel *spoke);

/*
** wheel2.c
*/

t_wheel			*wheel_retrieve_spoke(t_wheel *wheel, int to_find);
t_wheel			*wheel_go_to_head(t_wheel *ptr);
t_wheel			*wheel_go_to_tail(t_wheel *ptr);
t_wheel			*wheel_add_tail(t_wheel **oldtail, int input);
t_wheel			*wheel_add_head(t_wheel **oldhead, int input);

/*
** wheel3.c
*/

int				wheel_init_ranks(t_wheel **wheel);
t_wheel			*init_wheel(int argc, char **argv);
t_ps			*init_ps(t_wheel *a);

/*
**	wheel_math.c
*/

t_wheel 		*wheel_go_to_min(t_wheel *spoke);
int				wheel_get_avg(t_wheel *wheel);
int				*wheel_to_array(t_wheel *wheel);
int				wheel_get_quant(t_wheel *wheel, int cutoff_percent);
t_bool			wheel_has_no_dupes(t_wheel *wheel);

/*
**	check.c
*/

t_bool			check_wheel_sortedness(t_wheel *wheel);

#endif
