/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:17:03 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/16 12:19:45 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	t_wheel	*spoke;
	t_wheel *b;

	spoke = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	while (*(++argv))
		spoke = wheel_add_tail(&spoke, ft_atoi(*argv));
	wrap_ncurses(&spoke, &b);
	return (0);
}
