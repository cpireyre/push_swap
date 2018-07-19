/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:32:32 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/19 09:31:22 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "header.h"

void	push_swap(t_wheel **to_sort, t_wheel **reserve)
{
	while (check_wheel_sortedness(*to_sort) == false)
	{
		place_min_first(to_sort);
		do_and_print(to_sort, reserve, "pb");
	}
	while (*reserve)
		do_and_print(to_sort, reserve, "pa");
}

int		main(int argc, char **argv)
{
	t_wheel	*to_sort;
	t_wheel *reserve;

	reserve = NULL;
	if (!(to_sort = (init_wheel(argc, argv))))
		return (1);
	push_swap(&to_sort, &reserve);
	wheel_free_all(to_sort);
	return (0);
}
