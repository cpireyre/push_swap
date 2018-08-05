/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:41:04 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/05 10:32:28 by cpireyre         ###   ########.fr       */
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
	t_wheel		*wheel;

	wheel = NULL;
	if (argc < 2 || !argv || !*argv)
		return (NULL);
	while (*(++argv))
	{
		if (!is_valid_arg(*argv))
			free_and_quit(wheel, 0);
		wheel = wheel_add_tail(&wheel, ft_atoi(*argv));
		if (!wheel)
			free_and_quit(wheel, 0);
	}
	if (wheel_has_no_dupes(wheel) == false)
		free_and_quit(wheel, 0);
	return (wheel);
}
