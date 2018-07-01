/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 13:19:04 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/01 13:19:19 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wheel.h"

int		main(int argc, char **argv)
{
	t_wheel	*spoke;

	spoke = NULL;
	if (argc < 2)
		return (1);
	while (*(++argv))
		spoke = wheel_add_spoke(&spoke, ft_atoi(*argv));
	spoke = wheel_get_head(spoke);
	wheel_print_wheel(spoke);
	return (0);
}
