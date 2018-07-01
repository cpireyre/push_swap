/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 13:17:36 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/01 14:00:19 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_wheel
{
	struct s_wheel	*prev;
	struct s_wheel	*next;
	t_bool			head;
	t_bool			tail;
	int				number;
}				t_wheel;

t_wheel	*wheel_get_head(t_wheel *ptr);
t_wheel	*wheel_add_tail(t_wheel **oldtail, int input);
void	wheel_print_spoke(t_wheel *spoke);
void	wheel_print_wheel(t_wheel *spoke);
int		ft_printf(const char *format, ...);
