#include "libft.h"
#include "wheel.h"
#include <stdio.h> //Take this out! And replace printf with ft_printf.

void	wheel_print_spoke(t_wheel *spoke)
{
	if (!spoke)
		return ;
//	ft_putstr("Current spoke: ");
//	if (spoke->is_head == true)
//		ft_putendl("Head.");
//	if (spoke->is_tail == true)
//		ft_putendl("Tail.");
	ft_putnbr(spoke->number);
	ft_putchar(' ');
	//ft_putstr("--------\n");
}

void	wheel_print_wheel(t_wheel *spoke)
{
	if (!spoke)
		return ;
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

void	print_game_state(t_wheel *a, t_wheel *b)
{
	a = wheel_go_to_head(a);
	b = wheel_go_to_head(b);
	ft_putstr("a: ");
	wheel_print_wheel(a);
	ft_putstr("\nb: ");
	wheel_print_wheel(b);
	ft_putchar('\n');
}
