/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:32:32 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/10 14:00:21 by cpireyre         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_wheel	*a;
	t_ps	*ps;

	a = init_wheel(argc, argv);
	ps = init_ps(a);
	wheel_add_tail((ps->b), 214);
	ft_printf("%d", (*(ps->b))->number);
	wheel_print_spoke(*(ps->b));
	//push_swap(ps);
	wheel_free_all(a);
	return (0);
}
