#include "header.h"

t_pattern	find_winning_pattern(t_ps *ps)
{
	if (try_action(ps, &rra, &is_sorted))
		return (&rra);
	else if (try_action(ps, &ra, &is_sorted))
		return (&ra);
	else if (try_action(ps, &swap_second_third, &is_sorted))
		return (&swap_second_third);
	else if (try_action(ps, &swap_first_last, &is_sorted))
		return (&swap_first_last);
	else if (try_action(ps, &sa, &is_sorted))
		return (&sa);
	else
		return (NULL);
}
