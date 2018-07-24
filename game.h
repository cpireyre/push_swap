/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:59:51 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/24 09:01:07 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GAME_H
# define GAME_H

# include <ncurses.h>

/*
** frame rate of the visualizer, in microsecond:
*/

# define SLEEP_DELAY	50000

void	wrap_ncurses(t_wheel **a, t_wheel **b);
void	curse_print_wheel(t_wheel *wheel, int x, int y, t_bool left);

#endif
