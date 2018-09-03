/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:09:54 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/03 13:04:11 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	quit_push_swap(t_ps **ps, const char *errmsg)
{
	free_ps(ps);
	ft_exit(errmsg);
}

void	free_ps(t_ps **ps)
{
	free((*ps)->sorted);
	free((*ps)->b);
	free((*ps)->a);
	free((*ps));
}
