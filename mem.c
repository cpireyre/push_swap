#include "header.h"

void	ft_exit(const char *errmsg)
{
	ft_putendl_fd(errmsg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_ps(t_ps *ps)
{
	if (ps->a)
		free(ps->a);
	if (ps->b)
		free(ps->b);
	if (ps->sorted)
		free(ps->sorted);
	if (ps)
		free(ps);
}
