/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:42 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 18:00:08 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

t_bool	check_wheel_sortedness(t_wheel *wheel);
void	do_action(t_wheel **a, t_wheel **b, char *action);
void	do_and_print(t_wheel **a, t_wheel **b, char *action);
t_bool	is_valid_arg(const char *arg);
void	do_from_stdin(t_wheel **to_sort, t_wheel **reserve, char **line);

#endif
