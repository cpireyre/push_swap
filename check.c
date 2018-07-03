#include "libft.h"
#include "wheel.h"
#include "actions.h"

t_bool	check_wheel_sortedness(t_wheel *wheel)
{
	if (wheel->is_head == false)
		wheel = wheel_go_to_head(wheel);
	while (wheel->is_tail == false)
	{
		if (wheel->number > wheel->next->number)
			return (false);
		wheel = wheel->next;
	}
	return (true);
}
