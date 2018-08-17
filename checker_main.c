/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/17 14:57:25 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool	checker(t_ps *ps)
{
	char	*line;

	line = NULL;
	while (ft_gnl(0, &line))
		do_from_stdin(ps, &line);
	return (!*ps->b && check_wheel_sortedness(*ps->a));
}

int		main(int argc, char **argv)
{
	t_wheel	*a;
	t_wheel	*b;
	t_ps	*ps;

	a = init_wheel(argc, argv);
	b = NULL;
	ps = init_ps(&a, &b);
	if (!ps)
		free_and_quit(a, b);
	if (checker(ps) == true)
		ft_printf("OK");
	else
		ft_printf("KO");
	wheel_free_all(*ps->a);
	wheel_free_all(*ps->b);
	return (0);
}
