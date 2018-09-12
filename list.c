/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:49:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/11 19:59:39 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ops	*ops_add_tail(t_ops **oldtail, char *input)
{
	t_ops	*new;

	if (!input || !*input)
		return (NULL);
	new = ft_memalloc(sizeof(t_ops));
	new->op = ft_strdup(input);
	if (*oldtail)
	{
		new->prev = *oldtail;
		new->next = NULL;
		(*oldtail)->next = new;
	}
	else
	{
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}
