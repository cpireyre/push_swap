/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:05 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 17:27:38 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	do_swap(t_wheel *wheel)
{
	if (!wheel || wheel->prev == wheel)
		return ;
	wheel = wheel_go_to_head(wheel);
	wheel_swap_spokes(wheel, wheel->next);
}

void	do_push(t_wheel **from, t_wheel **to)
{
	if (!*from)
		return ;
	*from = wheel_go_to_head(*from);
	*to = wheel_add_head(to, (*from)->number);
	if (!*to)
	{
		wheel_free_all(*from);
		exit(1);
	}
	*from = wheel_delete_spoke(*from);
}

void	do_rotate(t_wheel *wheel)
{
	t_wheel	*mark;
	int		tmp;

	if (!wheel)
		return ;
	mark = wheel;
	tmp = wheel->number;
	wheel->number = wheel->prev->number;
	while ((wheel = wheel->prev) != mark)
		wheel->number = wheel->prev->number;
	wheel->next->number = tmp;
}

void	do_reverse_rotate(t_wheel *wheel)
{
	t_wheel	*mark;
	int		tmp;

	if (!wheel)
		return ;
	mark = wheel;
	tmp = wheel->number;
	wheel->number = wheel->next->number;
	while ((wheel = wheel->next) != mark)
		wheel->number = wheel->next->number;
	wheel->prev->number = tmp;
}
