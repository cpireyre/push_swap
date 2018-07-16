/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:32:32 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/15 11:54:27 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "header.h"

void	push_swap(t_wheel *to_sort, t_wheel *reserve)
{
	int		wheel_size[2];

	wheel_size[0] = wheel_init_ranks(&to_sort);
	wheel_size[1] = wheel_init_ranks(&reserve);
	while (!(check_wheel_sortedness(to_sort) == true && !reserve))
	{
		while (to_sort)
		{
			place_min_first(&to_sort);
			do_and_print(&to_sort, &reserve, "pb");
		}
		while (reserve)
			do_and_print(&to_sort, &reserve, "pa");
	}
}

int		main(int argc, char **argv)
{
	t_wheel *to_sort;
	t_wheel	*reserve;

	to_sort = NULL;
	reserve = NULL;
	if (argc < 2)
		return (1);
	while (*(++argv))
		to_sort = wheel_add_tail(&to_sort, ft_atoi(*argv));
	to_sort = wheel_go_to_head(to_sort);
	push_swap(to_sort, reserve);
	if (reserve)
		wheel_free_all(reserve);
	return (0);
}
