/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 17:43:28 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

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
	return (!*reserve && check_wheel_sortedness(*to_sort));
}

int		main(int argc, char **argv)
{
	t_wheel	*to_sort;
	t_wheel *reserve;

	reserve = NULL;
	if (!(to_sort = (init_wheel(argc, argv))))
		return (1);
	if (checker(&to_sort, &reserve) == true)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	if (to_sort)
		wheel_free_all(to_sort);
	if (reserve)
		wheel_free_all(reserve);
	return (0);
}
