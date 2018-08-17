/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:32:32 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/17 15:00:28 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "header.h"

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
//	if (ps->total_size == 2) TBD
//		swap_pair(ps);
//	else
//		push_swap(ps);
	wheel_free_all(*ps->a);
	wheel_free_all(*ps->b);
	return (0);
}
