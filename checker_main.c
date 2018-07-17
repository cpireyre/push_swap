/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 08:58:44 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int		main(int argc, char **argv)
{
	t_wheel	*spoke;
	t_wheel *b;
	char	*line;

	spoke = NULL;
	b = NULL;
	line = NULL;
	if (argc < 2)
		return (1);
	/*	later
	 **	protect this malloc (if !wheel_add_tail then wheel_free_all and exit)
	 */
	while (*(++argv))
		spoke = wheel_add_tail(&spoke, ft_atoi(*argv));
	if (wheel_has_no_dupes(spoke) == false)
	{
		ft_putendl("Error: duplicate entries");
		return (1);
	}
	/* later:
	 ** extract this loop into a function returns the sortedness?
	 */
	while (ft_gnl(0, &line))
	{
		do_action(&spoke, &b, line);
		spoke = wheel_go_to_head(spoke);
		b = wheel_go_to_head(b);
		free(line);
	}
	if (check_wheel_sortedness(spoke) == true)
		ft_putendl("OK");
	else	
		ft_putendl("KO");
	wheel_free_all(spoke);
	if (b)
		wheel_free_all(b);
	return (0);
}
