/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:32:32 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/13 14:50:26 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "header.h"

void	push_swap(t_ps *ps)
{
	while (check_wheel_sortedness(*(ps->a)) == false)
	{
		place_min_first(ps->a);
		do_and_print(ps->a, ps->b, "pb");
	}
	while (*(ps->b))
		do_and_print(ps->a, ps->b, "pa");
}

static void	swap_pair(t_ps *ps)
{
	if ((*ps->a)->number > (*ps->a)->next->number)
		do_and_print(ps->a, ps->b, "sa");
}

int		main(int argc, char **argv)
{
	t_wheel	*a;
	t_wheel	*b;
	t_ps	*ps;

	a = init_wheel(argc, argv);
	b = NULL;
	ps = init_ps(&a, &b);
	if (!ps)
		free_and_quit(a, b);
	if (ps->total_size == 2)
		swap_pair(ps);
	else
		push_swap(ps);
	wheel_free_all(a);
	return (0);
}
