/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:15:00 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/29 15:03:24 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "wheel.h"

void	printwheel(t_wheel *wheel)
{
	while (wheel)
	{
		ft_putnbr(wheel->nbr);
		wheel = wheel->next;
	}
}

int		main(void)
{
	t_wheel		*a;
	t_wheel		*b;

	a = malloc(sizeof(t_wheel));
	b = malloc(sizeof(t_wheel));
	a->nbr = 3;
	a->next = b;
	a->prev = NULL;
	b->nbr = 6;
	b->next = NULL;
	b->prev = a;
	printwheel(a);
	return (0);
}
