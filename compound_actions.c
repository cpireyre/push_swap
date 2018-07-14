/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:06:57 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/14 09:25:13 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	place_min_first(t_wheel **to_sort)
{
	*to_sort = wheel_go_to_min(*to_sort);
	while ((*to_sort)->is_head == false)
	{
		do_rotate(*to_sort);
		*to_sort = (*to_sort)->next;
		ft_putendl("ra");
	}
}
