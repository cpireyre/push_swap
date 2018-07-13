/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 13:19:04 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/13 08:24:05 by cpireyre         ###   ########.fr       */
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

	spoke = NULL;
	b = NULL;
	line = NULL;
	if (argc < 2)
		return (1);
	while (*(++argv))
		spoke = wheel_add_tail(&spoke, ft_atoi(*argv));
/* later:
** extract this loop into a function returns the sortedness?
*/
	while (ft_gnl(0, &line))
	{
		do_action(&spoke, &b, line);
		free(line);
		spoke = wheel_go_to_head(spoke);
		b = wheel_go_to_head(b);
		print_game_state(spoke, b);
	}
	if (check_wheel_sortedness(spoke) == true)
		ft_putendl("OK");
	else	
		ft_putendl("Wrong!");
	wheel_free_all(spoke);
	if (b)
		wheel_free_all(b);
	return (0);
}
