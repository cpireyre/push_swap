/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:36:55 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/05 15:17:08 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		(*get_operation(const char *arg))(t_ps *)
{
	int	i;

	i = -1;
	while (++i < 11)
		if (ft_strequ(arg, g_actions[i].instruction))
			return (g_actions[i].operation);
	return (NULL);
}

void			do_action(t_ps *ps, char **line)
{
	void	(*do_op)(t_ps *);

	do_op = get_operation(*line);
	ft_strdel(line);
	if (do_op)
		do_op(ps);
	else
		quit_push_swap(&ps, MSG_BAD_ACTION);
}

void		do_print(t_ps *ps, char *action)
{
	void	(*do_op)(t_ps *);

	ft_putendl(action);
	do_op = get_operation(action);
	do_op(ps);
}

t_bool		try_action(t_ps *ps, void (*to_try)(t_ps *), t_bool (*check)(t_ps *))
{
	t_ps	copy;
	int	a_copy[ps->size_total];
	int	b_copy[ps->size_total];

	ft_memcpy(&copy, ps, sizeof(t_ps));
	ft_memcpy(a_copy, ps->a, sizeof(a_copy));
	copy.a = a_copy;
	ft_memcpy(b_copy, ps->b, sizeof(b_copy));
	copy.b = b_copy;
	to_try(&copy);
	return (check(&copy));
}
