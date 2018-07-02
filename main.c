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
		spoke = wheel_add_tail(&spoke, ft_atoi(*argv));
	wheel_free_all(spoke);
	return (0);
}
