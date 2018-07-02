/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 09:24:05 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/01 13:37:14 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "wheel.h"

t_wheel	*wheel_get_head(t_wheel *ptr)
{
	while (ptr->head == false)
		ptr = ptr->prev;
	return (ptr);
}

t_wheel	*wheel_add_tail(t_wheel **oldtail, int input)
{
	t_wheel	*new;

	if (!(new = malloc(sizeof(t_wheel))))
	{
		wheel_free_all(*oldtail);
		exit(1);
	}
	if (*oldtail)
	{
		(*oldtail)->tail = false;
		new->prev = *oldtail;
		new->next = wheel_get_head(*oldtail);
		new->head = false;
		(*oldtail)->next = new;
		new->next->prev = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
		new->head = true;
	}
	new->tail = true;
	new->number = input;
	return (new);
}

void	wheel_print_spoke(t_wheel *spoke)
{
	if (!spoke)
		return ;
	ft_putstr("Current spoke: ");
	if (spoke->head == true)
		ft_putendl("Head.");
	if (spoke->tail == true)
		ft_putendl("Tail.");
	ft_putnbr_endl(spoke->number);
	ft_putstr("--------\n");
}

void	wheel_print_wheel(t_wheel *spoke)
{
	if (spoke->head == true)
	{
		wheel_print_spoke(spoke);
		spoke = spoke->next;
	}
	while (spoke->head == false)
	{
		wheel_print_spoke(spoke);
		spoke = spoke->next;
	}
}

void	wheel_free_all(t_wheel *spoke)
{
	if (spoke->head == false)
		spoke = wheel_get_head(spoke);
	while (spoke->tail == false)
	{
		spoke = spoke->next;
		free(spoke->prev);
	}
	free(spoke)
}
