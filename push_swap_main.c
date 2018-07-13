/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:32:32 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/13 14:10:19 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "wheel.h"
#include "print.h"
#include "actions.h"

void	push_swap(t_wheel *to_sort, t_wheel *reserve)
{
	(void)reserve;
	to_sort = wheel_go_to_max(to_sort);
	while (to_sort->is_head == false)
	{
		do_rotate(to_sort);
		to_sort = to_sort->next;
		ft_putendl("ra");
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
	wheel_free_all(to_sort);
	if (reserve)
		wheel_free_all(reserve);
	return (0);
}
