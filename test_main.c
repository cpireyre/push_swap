/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 09:53:21 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/10 11:41:40 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_smaller(t_wheel **to_sort, t_wheel **reserve, int pivot)
{
	size_t	size;
	size_t	i;

	(*to_sort) = wheel_go_to_head(*to_sort);
	size = wheel_count_spokes(*to_sort);
	if (!size)
		return ;
	i = 0;
	while (i <= size)
	{
		if ((*to_sort)->number <= pivot)
			do_and_print(to_sort, reserve, "pb");
		else
			do_and_print(to_sort, reserve, "rra");
		i++;
		if (!to_sort || !*to_sort)
			return ;
	}
}

void	wh_quicksort(t_wheel **to_sort, t_wheel **reserve)
{
	int	pivot;

	while (*to_sort)
	{
		pivot = wheel_get_quant(*to_sort, 50);
		push_smaller(to_sort, reserve, pivot);
	}
}

void	pushmax(t_wheel **from, t_wheel **to)
{
	int		max;

	while (*from)
	{
		max = wheel_go_to_max(*from)->number;
		if ((*from)->number == max)
			do_and_print(from, to, "pa");
		else
			do_and_print(from, to, "ra");
	}
}

int		main(int argc, char **argv)
{
	t_wheel	*to_sort;
	t_wheel *reserve;

	reserve = NULL;
	if (!(to_sort = (init_wheel(argc, argv))))
		return (1);
	to_sort = wheel_go_to_head(to_sort);
	wh_quick_step(&to_sort, &reserve, wheel_get_quant(to_sort, 50));
	wheel_free_all(to_sort);
	return (0);
}
