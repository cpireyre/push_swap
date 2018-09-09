#include "header.h"

t_pattern	*composition(t_pattern f, t_pattern g)
{
	t_pattern	*composite;

	composite = ft_memalloc(3 * sizeof(t_pattern));
	composite[0] = f;
	composite[1] = g;
	composite[2] = NULL;
	return (composite);
}

void		run_sequence(t_ps **ps, t_pattern *composite, t_bool will_print)
{
	while (*composite)
	{
		(*composite)(*ps, will_print);
		composite++;
	}
}
