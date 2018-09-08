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

int	get_next_int(int *sorted, int size, int previous)
{
	int	i;

	i = 0;
	while (i < size - 1 && sorted[i] != previous)
		i++;
	return ((i < size - 1) ? sorted[i + 1] : previous);
}

int	get_prev_int(int *sorted, int size, int next)
{
	int	i;

	i = 1;
	while (i < size && sorted[i] != next)
		i++;
	return ((i < size) ? sorted[i - 1] : next);
}
