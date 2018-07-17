/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:17:03 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 14:46:40 by cpireyre         ###   ########.fr       */
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
	t_bool	visual;
	char	*line;

	spoke = NULL;
	b = NULL;
	line = NULL;
	initcurse();
	if (argc < 2)
		return (1);
	visual = false;
	if (ft_strequ(argv[1], VISUAL_MODE) == true)
	{
		visual = true;
		argv++;
	}
	while (*(++argv))
		spoke = wheel_add_tail(&spoke, ft_atoi(*argv));
	if (visual == false)
		wrap_ncurses(&spoke, &b);
	else
	{
		while (ft_gnl(0, &line))
		{
			clear();
			do_action(&spoke, &b, line);
			spoke = wheel_go_to_head(spoke);
			b = wheel_go_to_head(b);
			curse_print_wheel(spoke, 5, 3);
			curse_print_wheel(b, 20, 3);
			free(line);
			usleep(500000);
		}
		getch();
		endwin();
	}
	if (spoke)
		wheel_free_all(spoke);
	if (b)
		wheel_free_all(b);
	return (0);
}
