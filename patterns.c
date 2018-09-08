#include "header.h"

t_bool		dry_run(t_ps *ps, t_pattern to_try, t_checker check)
{
	t_ps	copy;
	int	a_copy[ps->size_total];
	int	b_copy[ps->size_total];

	ft_memcpy(&copy, ps, sizeof(t_ps));
	ft_memcpy(a_copy, ps->a, sizeof(a_copy));
	copy.a = a_copy;
	ft_memcpy(b_copy, ps->b, sizeof(b_copy));
	copy.b = b_copy;
	to_try(&copy, NO_PRINT);
	return (check(&copy));
}

t_pattern	find_winning_pattern(t_ps *ps)
{
	if (dry_run(ps, &rra, &is_sorted))
		return (&rra);
	else if (dry_run(ps, &ra, &is_sorted))
		return (&ra);
	else if (dry_run(ps, &sa, &is_sorted))
		return (&sa);
	else if (dry_run(ps, &swap_and_down, &is_sorted))
		return (&swap_and_down);
	else if (dry_run(ps, &swap_second_third, &is_sorted))
		return (&swap_second_third);
	else if (dry_run(ps, &swap_first_last, &is_sorted))
		return (&swap_first_last);
	else
		return (NULL);
}

void	print_pattern(t_ps *ps, char *instruction)
{
	(void)ps;
	ft_putendl(instruction);
}
