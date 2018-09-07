#include "header.h"

int	tab_get_min(int *tab, int size)
{
	int	min;
	int	i;

	i = -1;
	min = tab[0];
	while (++i < size)
		min = (tab[i] <= min) ? tab[i] : min;
	return (min);
}

int	tab_get_max(int *tab, int size)
{
	int	max;
	int	i;

	i = -1;
	max = tab[0];
	while (++i < size)
		max = (tab[i] >= max) ? tab[i] : max;
	return (max);
}
