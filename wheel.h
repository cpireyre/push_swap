/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:59:47 by cpireyre          #+#    #+#             */
/*   Updated: 2018/06/29 15:00:14 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_wheel
{
	int				nbr;
	struct s_wheel	*prev;
	struct s_wheel	*next;
}				t_wheel;

void	printwheel(t_wheel *wheel);
