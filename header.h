/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:32:30 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/31 13:34:30 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

# define VISUAL_MODE	"-v"

typedef struct	s_ps
{
	int		*a;
	int		*b;
	int		size_total;
	int		size_a;
	int		size_b;
	int		*sorted;
}				t_ps;

/*
**	parse.c
*/

t_ps	*parse(int argc, char **argv);

#endif
