/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:09:54 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/01 11:09:56 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_exit(const char *errmsg)
{
	ft_putendl_fd(errmsg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_ps(t_ps *ps)
{
	if (ps->a)
		free(ps->a);
	if (ps->b)
		free(ps->b);
	if (ps->sorted)
		free(ps->sorted);
	if (ps)
		free(ps);
}
