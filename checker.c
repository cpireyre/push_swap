/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:22:12 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/02 16:35:59 by cpireyre         ###   ########.fr       */
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

void			do_action(t_ps *ps, const char *action)
{
	if (ft_strequ(action, "sa"))
		sa(ps);
	else if (ft_strequ(action, "pa"))
		pa(ps);
	else if (ft_strequ(action, "ra"))
		ra(ps);
	else if (ft_strequ(action, "rra"))
		rra(ps);
	else if (ft_strequ(action, "sb"))
		sb(ps);
	else if (ft_strequ(action, "pb"))
		pb(ps);
	else if (ft_strequ(action, "rb"))
		rb(ps);
	else if (ft_strequ(action, "rrb"))
		rrb(ps);
	else if (ft_strequ(action, "ss"))
		ss(ps);
	else if (ft_strequ(action, "rr"))
		rr(ps);
	else if (ft_strequ(action, "rrr"))
		rrr(ps);
}

int				main(int argc, char **argv)
{
	t_bool	visu_on;
	t_ps	*ps;
	char	*line;

	line = NULL;
	if (argc > 1)
	{
		toggle_visu(&argv, &visu_on, &argc);
		ps = parse(argc, argv);
		/*
		** test stuff. throw out later:
		*/
		while (ft_gnl(0, &line))
		{
			if (!line)
				ft_exit(MSG_ERROR);
			do_action(ps, line);
			free(line);
			ft_printf("\n--------\n");
			ft_printf("a:\n");
			ft_print_int_tab(ps->a, ps->size_a);
			ft_printf("b:\n");
			ft_print_int_tab(ps->b, ps->size_b);
			ft_printf("\n--------\n");
		}
		/*
		** end of test stuff. keep what follows.
		*/
		ft_assert(is_sorted(ps), MSG_OK, MSG_NOT_OK);
		free_ps(ps);
	}
	return (0);
}
