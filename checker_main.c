/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/14 08:39:16 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"
#include "wheel.h"
#include "actions.h"
#include "check.h"
#include "print.h"

int		main(int argc, char **argv)
{
	t_wheel	*spoke;
	t_wheel *b;
	char	*line;
	t_bool	visual;

	spoke = NULL;
	b = NULL;
	line = NULL;
	visual = false;
	if (argc < 2)
		return (1);
	if (ft_strequ(argv[1], "-v") == true)
	{
		visual = true;
		argv++;
	}
/*	later
 **	protect this malloc (if !wheel_add_tail then wheel_free_all and exit)
*/
	while (*(++argv))
		spoke = wheel_add_tail(&spoke, ft_atoi(*argv));
/* later:
** extract this loop into a function returns the sortedness?
*/
	while (ft_gnl(0, &line))
	{
		if (visual == true)
		{
			print_game_state(spoke, b);
			ft_putstr(line);
		}
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
