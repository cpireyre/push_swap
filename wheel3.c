/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:41:04 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/13 14:43:28 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wheel.h"

t_wheel *wheel_go_to_min(t_wheel *spoke)
{
	t_wheel *tmp;
	t_wheel	*min_spoke;

	tmp = spoke;
	min_spoke = spoke;
	spoke = spoke->next;
	while (spoke != tmp)
	{
		if (min_spoke->number > spoke->number)
			min_spoke = spoke;
		spoke = spoke->next;
	}
	return (min_spoke);
}
