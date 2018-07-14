/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:16 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/14 09:13:52 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	wheel_print_spoke(t_wheel *spoke)
{
	if (!spoke)
		return ;
//	ft_putstr("Current spoke: ");
//	if (spoke->is_head == true)
//		ft_putendl("Head.");
//	if (spoke->is_tail == true)
//		ft_putendl("Tail.");
	ft_putnbr(spoke->number);
	ft_putchar(' ');
	//ft_putstr("--------\n");
}

void	wheel_print_wheel(t_wheel *spoke)
{
	if (!spoke)
		return ;
	if (spoke->is_head == true)
	{
		wheel_print_spoke(spoke);
		spoke = spoke->next;
	}
	while (spoke->is_head == false)
	{
		wheel_print_spoke(spoke);
		spoke = spoke->next;
	}
}

void	print_game_state(t_wheel *a, t_wheel *b)
{
	a = wheel_go_to_head(a);
	b = wheel_go_to_head(b);
	ft_printf("-----\n");
	ft_putstr("a: ");
	wheel_print_wheel(a);
	ft_putstr("\nb: ");
	wheel_print_wheel(b);
	ft_printf("\n-----");
}
