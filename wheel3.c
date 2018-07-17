/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:41:04 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 17:43:24 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		wheel_init_ranks(t_wheel **wheel)
{
	int		current_rank;

	if (!wheel || !*wheel)
		return (0);
	current_rank = 1;
	*wheel = wheel_go_to_head(*wheel);
	(*wheel)->rank = current_rank;
	(*wheel) = (*wheel)->next;
	while ((*wheel)->is_head == false)
	{
		current_rank++;
		(*wheel)->rank = current_rank;
		(*wheel) = (*wheel)->next;
	}
	return (current_rank);
}

t_wheel		*init_wheel(int argc, char **argv)
{
	t_wheel	*wheel;

	if (argc < 2 || !argv || !*argv)
		return (NULL);
	while (*(++argv))
	{
		if (!is_valid_arg(*argv))
		{
			ft_putendl_fd("Error: invalid entry", STDERR_FILENO);
			return (NULL); // free everything, then exit
		}
		/*	later
		 **	protect this malloc (if !wheel_add_tail then wheel_free_all and exit)
		 */
		wheel = wheel_add_tail(&wheel, ft_atoi(*argv));
	}
	if (wheel_has_no_dupes(wheel) == false)
	{
		ft_putendl_fd("Error: duplicate entries", STDERR_FILENO);
		return (NULL); //free everything, then exit
	}
	return (wheel);
}
