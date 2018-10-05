/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:58:41 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/13 13:59:23 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool		dry_run(t_ps *ps, int size, t_pattern to_try, t_checker check)
{
	t_ps	copy;
	int		a_copy[size + 1];
	int		b_copy[size + 1];

	ft_memcpy(&copy, ps, sizeof(ps));
	ft_memcpy(a_copy, A, sizeof(a_copy));
	copy.a = a_copy;
	ft_memcpy(b_copy, B, sizeof(b_copy));
	copy.b = b_copy;
	to_try(&copy, NO_PRINT);
	return (check(&copy));
}

t_pattern	deep_run(t_ps *ps, int size, t_pattern to_try, t_checker check)
{
	t_ps	copy;
	int		a_copy[size + 1];
	int		b_copy[size + 1];
	int		i;

	ft_memcpy(&copy, ps, sizeof(t_ps));
	ft_memcpy(a_copy, A, sizeof(a_copy));
	copy.a = a_copy;
	ft_memcpy(b_copy, B, sizeof(b_copy));
	copy.b = b_copy;
	to_try(&copy, NO_PRINT);
	if (check(&copy))
		return (to_try);
	i = -1;
	while (++i < NBR_PATTERNS)
		if (dry_run(&copy, size, g_all_patterns[i], check))
			return (g_all_patterns[i]);
	return (NULL);
}

t_pattern	find_pattern(t_ps *ps, t_checker to_pass)
{
	int	i;
	int	size;

	i = -1;
	size = tablen(A) + tablen(B);
	while (++i < NBR_PATTERNS)
		if (dry_run(ps, size, g_all_patterns[i], to_pass))
			return (g_all_patterns[i]);
	return (NULL);
}

void		print_pattern(t_ps *ps, char *instruction)
{
	putstr_buf(&(ps->buf), instruction);
	putc_buf(&(ps->buf), '\n');
}
