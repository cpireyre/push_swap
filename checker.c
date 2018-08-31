/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:22:12 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/31 13:55:35 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	toggle_visu(char ***argv, t_bool *visu_on, int *argc)
{
	if (ft_strequ((*argv)[1], VISUAL_MODE) == true)
	{
		*visu_on = true;
		(*argv)++;
		(*argc)--;
	}
	else
		*visu_on = false;
}

int		main(int argc, char **argv)
{
	t_bool	visu_on;
	t_ps	*ps;

	toggle_visu(&argv, &visu_on, &argc);
	ps = parse(argc, argv);
	if (!ps)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
