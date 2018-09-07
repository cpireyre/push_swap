/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:22:12 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/05 13:36:04 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

static void			init_visu(void)
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
}

int				main(int argc, char **argv)
{
	t_bool	visu_on;
	t_ps	*ps;
	char	*line;
	int	count;

	if (argc < 2)
		return (1);
	toggle_visu(&argv, &visu_on, &argc);
	ps = parse(argc, argv);
	line = NULL;
	count = 0;
	while (ft_gnl(0, &line))
	{
		if (visu_on)
			visu_wrapper(ps, &line);
		else
			do_action(ps, &line, NO_PRINT);
		ft_strdel(&line);
		count++;
	}
	endwin();
	ft_assert(is_sorted(ps), MSG_OK, MSG_NOT_OK);
	ft_printf("%d moves.\n", count);
	free_ps(&ps);
	return (0);
}
