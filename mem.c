/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:09:54 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/01 13:51:54 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_ps(t_ps *ps)
{
	if (ps->sorted)
		free(ps->sorted);
	if (ps->b)
		free(ps->b);
	if (ps->a)
		free(ps->a);
	if (ps)
		free(ps);
}
