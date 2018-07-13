/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:49 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/13 13:57:29 by cpireyre         ###   ########.fr       */
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
}				t_wheel;

/*
** wheel.c
*/

void			wheel_free_all(t_wheel *spoke);
void			wheel_swap_spokes(t_wheel *a, t_wheel *b);
t_wheel			*wheel_delete_spoke(t_wheel *to_delete);
t_wheel 		*wheel_go_to_max(t_wheel *spoke);

/*
** wheel2.c
*/

t_wheel			*wheel_retrieve_spoke(t_wheel *wheel, int to_find);
t_wheel			*wheel_go_to_head(t_wheel *ptr);
t_wheel			*wheel_go_to_tail(t_wheel *ptr);
t_wheel			*wheel_add_tail(t_wheel **oldtail, int input);
t_wheel			*wheel_add_head(t_wheel **oldhead, int input);

/*
**	check.c
*/

t_bool			check_wheel_sortedness(t_wheel *wheel);
#endif
