/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:33 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/13 09:36:34 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

void	do_swap(t_wheel *wheel);
void	do_push(t_wheel **a, t_wheel **b);
void	do_rotate(t_wheel *wheel);
void	do_reverse_rotate(t_wheel *wheel);

#endif
