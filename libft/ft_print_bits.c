/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 07:58:41 by cpireyre          #+#    #+#             */
/*   Updated: 2018/05/19 07:59:36 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(t_byte octet)
{
	t_byte i;

	i = 0;
	while (i < 8)
	{
		(octet & 128 >> i) ? ft_putchar('1') : ft_putchar('0');
		i++;
	}
}
