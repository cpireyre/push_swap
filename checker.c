/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:22:12 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/16 19:13:22 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

static void		init_visu(void)
{
	initscr();
	if (has_colors() == false)
	{
		endwin();
		ft_exit("Error: colors unsupported by terminal.");
	}
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	use_default_colors();
	start_color();
	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_BLUE, -1);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
}

static void		toggle_visu(char ***argv, t_bool *visu_on, int *argc)
{
	if (ft_strequ((*argv)[1], VISUAL_MODE) == true)
	{
		*visu_on = true;
		(*argv)++;
		(*argc)--;
		init_visu();
	}
	else
		*visu_on = false;
	(*argv)++;
	(*argc)--;
}

int				main(int argc, char **argv)
{
	t_bool	visu_on;
	t_ps	*ps;
	char	*line;
	int		*sorted;

	if (argc < 2)
		return (1);
	toggle_visu(&argv, &visu_on, &argc);
	ps = visu_on ? parse_visu(argv, &sorted) : parse(argv);
	line = NULL;
	while (ft_gnl(0, &line))
	{
		if (visu_on)
			visu_wrapper(ps, &line, sorted);
		else
			do_action(ps, &line, NO_PRINT);
	}
	endwin();
	ft_assert(is_done(ps), MSG_OK, MSG_NOT_OK);
	if (visu_on)
		free(sorted);
	free_ps(&ps);
	return (0);
}
