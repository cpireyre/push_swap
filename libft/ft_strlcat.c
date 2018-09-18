/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:07:44 by cpireyre          #+#    #+#             */
/*   Updated: 2018/04/15 12:39:53 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*pdst;
	size_t	lensrc;
	size_t	lendst;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	pdst = dst;
	pdst += lendst;
	if (lendst >= size)
		return (size + lensrc);
	size -= lendst;
	while (*src && size > 1)
	{
		*pdst = *src;
		size--;
		pdst++;
		src++;
	}
	*pdst = 0;
	return (lensrc + lendst);
}
