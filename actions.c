#include "libft.h"
#include "wheel.h"

void	do_swap(t_wheel *wheel)
{
	wheel = wheel_go_to_head(wheel);
	wheel_swap_spokes(wheel, wheel->next);
}

void	do_push_atob(t_wheel *a, t_wheel *b)
{
	a = wheel_go_to_head(a);
	wheel_add_head(&b, a->number);
	wheel_delete_spoke(a);
}

void	do_push_btoa(t_wheel *a, t_wheel *b)
{
	b = wheel_go_to_head(b);
	wheel_add_head(&a, b->number);
	wheel_delete_spoke(b);
}

void	do_rotate(t_wheel *wheel)
{
	t_wheel	*mark;
	int	tmp;

	mark = wheel;
	tmp = wheel->number;
	wheel->number = wheel->prev->number;
	while ((wheel = wheel->prev) != mark)
		wheel->number = wheel->prev->number;
	wheel->next->number = tmp;
}

void	do_reverse_rotate(t_wheel *wheel)
{
	t_wheel	*mark;
	int	tmp;

	mark = wheel;
	tmp = wheel->number;
	wheel->number = wheel->next->number;
	while ((wheel = wheel->next) != mark)
		wheel->number = wheel->next->number;
	wheel->prev->number = tmp;
}
