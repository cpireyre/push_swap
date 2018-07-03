/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 13:19:04 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/01 14:06:47 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "wheel.h"

int		main(int argc, char **argv)
{
	t_wheel	*spoke;

	spoke = NULL;
	if (argc < 2)
		return (1);
	while (*(++argv))
		spoke = wheel_add_head(&spoke, ft_atoi(*argv));
	spoke = wheel_delete_spoke(wheel_retrieve_spoke(spoke, 4));
	wheel_print_wheel(wheel_go_to_head(spoke));
	wheel_free_all(spoke);
	return (0);
}
