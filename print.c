#include "libft.h"
#include "wheel.h"

void	wheel_print_spoke(t_wheel *spoke)
{
	if (!spoke)
		return ;
	ft_putstr("Current spoke: ");
	if (spoke->is_head == true)
		ft_putendl("Head.");
	if (spoke->is_tail == true)
		ft_putendl("Tail.");
	ft_putnbr_endl(spoke->number);
	ft_putstr("--------\n");
}

void	wheel_print_wheel(t_wheel *spoke)
{
	if (spoke->is_head == true)
	{
		wheel_print_spoke(spoke);
		spoke = spoke->next;
	}
	while (spoke->is_head == false)
	{
		wheel_print_spoke(spoke);
		spoke = spoke->next;
	}
}