/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:22:12 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/13 17:04:34 by cpireyre         ###   ########.fr       */
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
	t_ops	*list;
	t_ops	*tmp;
	int		*sorted;

	if (argc < 2)
		return (1);
	toggle_visu(&argv, &visu_on, &argc);
	ps = visu_on ? parse_visu(argc, argv, &sorted) : parse(argc, argv);
	list = make_list(0);
	tmp = list;
	while (list)
	{
		if (visu_on)
			visu_wrapper(ps, list->op, sorted);
		else
			do_action(ps, list->op, NO_PRINT);
		list = list->next;
	}
	endwin();
	ft_assert(is_done(ps), MSG_OK, MSG_NOT_OK);
	if (visu_on)
		free(sorted);
	free_all_ops(&tmp);
	free_ps(&ps);
	return (0);
}
