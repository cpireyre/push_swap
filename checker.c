/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:22:12 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/01 13:50:15 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		toggle_visu(char ***argv, t_bool *visu_on, int *argc)
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

/*
**	ft_memcmp returns 0 if the memory areas contain equal values.
**	more or less.
*/

static t_bool	is_sorted(t_ps *ps)
{
	if (ps->size_b || (ps->size_a != ps->size_total))
		return (false);
	return (!(ft_memcmp((void*)(ps->a), (void*)(ps->sorted),
				sizeof(int) * ps->size_total)));
}

int				main(int argc, char **argv)
{
	t_bool	visu_on;
	t_ps	*ps;

	if (argc > 1)
	{
		toggle_visu(&argv, &visu_on, &argc);
		ps = parse(argc, argv);
		ft_print_int_tab(ps->a, ps->size_a);
		tab_add_first(&(ps->a), &(ps->size_a), 1337);
		ft_printf("Adding 1337...\n");
		ft_print_int_tab(ps->a, ps->size_a);
		ft_assert(is_sorted(ps), MSG_OK, MSG_NOT_OK);
		free_ps(ps);
	}
	while (1)
		;
	return (0);
}
