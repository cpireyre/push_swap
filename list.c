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

t_ops	*add_tail(t_ops **oldtail, char *input)
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

void	free_op(t_ops **to_free)
{
	ft_strdel(&((*to_free)->op));
	ft_memdel((void**)to_free);
}

void	free_all_ops(t_ops **head)
{
	t_ops	*tmp;
	t_ops	*list;

	list = *head;
	while (list->prev)
		list = list->prev;
	while (list)
	{
		tmp = list;
		list = list->next;
		free_op(&tmp);
	}
}

t_ops	*make_list(int fd)
{
	t_ops	*list;
	char	*line;

	line = NULL;
	list = NULL;
	while (ft_gnl(fd, &line))
	{
		list = add_tail(&list, line);
		ft_strdel(&line);
	}
	while (list->prev)
		list = list->prev;
	return (list);
}
