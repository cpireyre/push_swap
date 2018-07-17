/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 14:46:40 by cpireyre         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_wheel	*to_sort;
	t_wheel *b;
	char	*line;

	b = NULL;
	line = NULL;
	to_sort = (init_wheel(argc, argv));
	/* later:
	 ** extract this loop into a function returns the sortedness?
	 */
	while (ft_gnl(0, &line))
	{
		do_action(&to_sort, &b, line);
		to_sort = wheel_go_to_head(to_sort);
		b = wheel_go_to_head(b);
		free(line);
	}
	if (to_sort && check_wheel_sortedness(to_sort) == true)
		ft_putendl("OK");
	else	
		ft_putendl("KO");
	wheel_free_all(to_sort);
	if (b)
		wheel_free_all(b);
	return (0);
}
