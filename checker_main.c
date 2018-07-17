/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 14:51:08 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

t_wheel		*init_wheel(int argc, char **argv)
{
	t_wheel	*wheel;

	if (argc < 2)
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

t_bool	checker(t_wheel **to_sort, t_wheel **reserve)
{
	char	*line;

	line = NULL;
	while (ft_gnl(0, &line))
	{
		do_action(to_sort, reserve, line);
		*to_sort = wheel_go_to_head(*to_sort);
		*reserve = wheel_go_to_head(*reserve);
		free(line);
	}
	return (check_wheel_sortedness(*to_sort));
}

int		main(int argc, char **argv)
{
	t_wheel	*to_sort;
	t_wheel *reserve;

	reserve = NULL;
	to_sort = (init_wheel(argc, argv));
	if (checker(&to_sort, &reserve) == true)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	wheel_free_all(to_sort);
	if (reserve)
		wheel_free_all(reserve);
	return (0);
}
