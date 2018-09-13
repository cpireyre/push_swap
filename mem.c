/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:09:54 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/13 11:43:50 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	note: i am allowed this because my int arrays are ft_memalloc'd,
**	therefore ft_bzero'd, therefore NULL-termination is guaranteed,
**	as in strings.
**	the recursion is probably fine and gets TCO'd with -O1.
*/

int	tablen(int *tab)
{
	return (*tab ? 1 + tablen(++tab) : 0);
}
void	quit_push_swap(t_ps **ps, const char *errmsg)
{
	endwin();
	free_ps(ps);
	ft_exit(errmsg);
}

void	free_ps(t_ps **ps)
{
	free((*ps)->b);
	free((*ps)->a);
	free((*ps));
}
