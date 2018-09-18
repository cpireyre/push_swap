/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:04:14 by cpireyre          #+#    #+#             */
/*   Updated: 2018/04/09 17:20:48 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **node, t_list *addend)
{
	if (addend)
	{
		if (*node)
		{
			ft_lstlast(*node)->next = addend;
			addend->next = NULL;
		}
		else
		{
			ft_lstadd(node, addend);
		}
	}
}
