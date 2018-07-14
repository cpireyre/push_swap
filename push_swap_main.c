/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:32:32 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/14 09:18:12 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "header.h"

void	push_swap(t_wheel *to_sort, t_wheel *reserve)
{
	wheel_init_ranks(&to_sort);
	wheel_init_ranks(&reserve);
	while (to_sort)
	{
		place_min_first(&to_sort);
		do_push(&to_sort, &reserve);
		ft_putendl("pb");
	}
	while (reserve)
	{
		do_push(&reserve, &to_sort);
		ft_putendl("pa");
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
