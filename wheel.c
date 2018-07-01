/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 09:24:05 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/01 10:16:17 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

typedef struct	s_wheel
{
	struct s_wheel	*prev;
	struct s_wheel	*next;
	t_bool			head;
	t_bool			tail;
	int				number;
}				t_wheel;

t_wheel	*wheel_get_head(t_wheel *ptr)
{
	while (ptr->head == false)
		ptr = ptr->prev;
	return (ptr);
}

t_wheel	*wheel_add_spoke(t_wheel **oldtail, int input)
{
	t_wheel	*new;

	new = malloc(sizeof(t_wheel));
	if (!new)
		exit(1);
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

int		main(int argc, char **argv)
{
	t_wheel	*spoke;

	spoke = NULL;
	if (argc < 2)
		return (1);
	while (*(++argv))
		spoke = wheel_add_spoke(&spoke, ft_atoi(*argv));
	while (spoke->prev->tail == false)
	{
		wheel_print_spoke(spoke);
		spoke = spoke->prev;
	}
		wheel_print_spoke(spoke);
	return (0);
}
