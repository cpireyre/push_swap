/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:17:03 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/23 14:03:49 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		main(int argc, char **argv)
{
	t_wheel	*to_sort;
	t_wheel *reserve;
	t_bool	visual;
	char	*line;
	int		size;

	reserve = NULL;
	line = NULL;
	visual = false;
	if (ft_strequ(argv[1], VISUAL_MODE) == true)
	{
		visual = true;
		argv++;
	}
	if (!(to_sort = (init_wheel(argc, argv))))
		return (1);
	initcurse();
	if (visual == false)
		wrap_ncurses(&to_sort, &reserve);
	else
	{
		size = wheel_count_spokes(to_sort) + 10;
		while (ft_gnl(0, &line))
		{
			clear();
			mvprintw(5, 30, "%s", line);
			do_from_stdin(&to_sort, &reserve, &line);
			free(line);
			curse_print_wheel(to_sort, 5, size);
			curse_print_wheel(reserve, 20, size);
			usleep(SPEED);
		}
		getch();
		endwin();
	}
	if (to_sort)
		wheel_free_all(to_sort);
	if (reserve)
		wheel_free_all(reserve);
	return (0);
}
