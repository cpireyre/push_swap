/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:17:03 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 09:56:59 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

static void	initcurse(void)
{
	initscr();
	if (has_colors() == false)
	{
		endwin();
		ft_putendl_fd("Error: colors not suppored by terminal.", STDERR_FILENO);
		exit(1);
	}
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	use_default_colors();
	start_color();
}

int			main(int argc, char **argv)
{
	t_wheel	*spoke;
	t_wheel *b;

	spoke = NULL;
	b = NULL;
	initcurse();
	if (argc < 2)
		return (1);
	while (*(++argv))
		spoke = wheel_add_tail(&spoke, ft_atoi(*argv));
	wrap_ncurses(&spoke, &b);
	if (spoke)
		wheel_free_all(spoke);
	if (b)
		wheel_free_all(b);
	return (0);
}
