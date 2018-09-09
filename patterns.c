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

t_pattern	deep_run(t_ps *ps, t_pattern to_try, t_checker check)
{
	t_ps	copy;
	int	a_copy[ps->size_total];
	int	b_copy[ps->size_total];
	int	i;

	ft_memcpy(&copy, ps, sizeof(t_ps));
	ft_memcpy(a_copy, ps->a, sizeof(a_copy));
	copy.a = a_copy;
	ft_memcpy(b_copy, ps->b, sizeof(b_copy));
	copy.b = b_copy;
	to_try(&copy, NO_PRINT);
	if (check(&copy))
		return (to_try);
	i = -1;
	while (++i < NBR_PATTERNS)
		if (dry_run(&copy, g_all_patterns[i], check))
			return (g_all_patterns[i]);
	return (NULL);
}

t_pattern	find_pattern(t_ps *ps, t_checker to_pass)
{
	int	i;
	
	i = -1;
	while (++i < NBR_PATTERNS)
		if (dry_run(ps, g_all_patterns[i], to_pass))
			return (g_all_patterns[i]);
	return (NULL);
}

void	print_pattern(t_ps *ps, char *instruction)
{
	(void)ps;
	ft_putendl(instruction);
}
