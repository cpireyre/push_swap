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

#include "libft.h"
#include "wheel.h"

int		main(int argc, char **argv)
{
	t_wheel	*spoke;
	char	*line;

	spoke = NULL;
	line = NULL;
	if (argc < 2)
		return (1);
	while (*(++argv))
		spoke = wheel_add_tail(&spoke, ft_atoi(*argv));
	while (ft_gnl(0, &line))
		ft_printf("%s\n", line);
	return (0);
}
