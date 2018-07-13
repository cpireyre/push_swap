/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:42 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/13 09:36:43 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

t_bool	check_wheel_sortedness(t_wheel *wheel);
void	do_action(t_wheel **a, t_wheel **b, char *action);

#endif
