/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 09:53:21 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 17:47:33 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_bigger(t_wheel **to_sort, t_wheel **reserve, int pivot)
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

	pivot = wheel_get_median(*to_sort);
	push_bigger(to_sort, reserve, pivot);
}

int		main(int argc, char **argv)
{
	t_wheel	*to_sort;
	t_wheel *reserve;

	reserve = NULL;
	if (!(to_sort = (init_wheel(argc, argv))))
		return (1);
	wh_quicksort(&to_sort, &reserve);
	print_game_state(to_sort, reserve);
	if (to_sort)
		wheel_free_all(to_sort);
	return (0);
}
