/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:59:51 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 12:08:47 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GAME_H
# define GAME_H

# include <ncurses.h>

void	wrap_ncurses(t_wheel **a, t_wheel **b);
void	curse_print_wheel(t_wheel *wheel, int x, int y);

#endif
