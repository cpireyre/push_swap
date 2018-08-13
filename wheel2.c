/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:31 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/13 12:04:31 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

t_wheel	*wheel_retrieve_spoke(t_wheel *wheel, int to_find)
{
	t_wheel	*mark;

	mark = wheel;
	if (wheel->number == to_find)
		return (wheel);
	wheel = wheel->next;
	while (wheel->number != to_find && wheel != mark)
		wheel = wheel->next;
	if (wheel->number == to_find)
		return (wheel);
	else
		return (NULL);
}

t_wheel	*wheel_go_to_head(t_wheel *ptr)
{
	while (ptr && ptr->is_head == false)
		ptr = ptr->prev;
	return (ptr);
}

t_wheel	*wheel_go_to_tail(t_wheel *ptr)
{
	while (ptr && ptr->is_tail == false)
		ptr = ptr->next;
	return (ptr);
}
