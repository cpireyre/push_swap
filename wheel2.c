#include <stdlib.h>
#include "libft.h"
#include "wheel.h"

t_wheel		*wheel_retrieve_spoke(t_wheel *wheel, int to_find)
{
	t_wheel	*mark;

	mark = wheel;
	if (wheel->number == to_find)
		return (wheel);
	wheel = wheel->next;
	while (wheel->number != to_find && wheel != mark)
		wheel = wheel->next;
	if (wheel->number == to_find)
		return (wheel);
	else
		return (NULL);
}

t_wheel	*wheel_go_to_head(t_wheel *ptr)
{
	while (ptr && ptr->is_head == false)
		ptr = ptr->prev;
	return (ptr);
}

t_wheel	*wheel_go_to_tail(t_wheel *ptr)
{
	while (ptr && ptr->is_tail == false)
		ptr = ptr->next;
	return (ptr);
}

t_wheel	*wheel_add_tail(t_wheel **oldtail, int input)
{
	t_wheel	*new;

	if (!(new = malloc(sizeof(t_wheel))))
	{
		wheel_free_all(*oldtail);
		exit(1);
	}
	if (*oldtail)
	{
		(*oldtail)->is_tail = false;
		new->prev = *oldtail;
		new->next = wheel_go_to_head(*oldtail);
		new->is_head = false;
		(*oldtail)->next = new;
		new->next->prev = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
		new->is_head = true;
	}
	new->is_tail = true;
	new->number = input;
	return (new);
}

t_wheel	*wheel_add_head(t_wheel **oldhead, int input)
{
	t_wheel	*new;

	if (!(new = malloc(sizeof(t_wheel))))
	{
		wheel_free_all(*oldhead);
		exit(1);
	}
	if (*oldhead)
	{
		(*oldhead)->is_head = false;
		new->is_tail = false;
		(*oldhead)->prev = new;
		new->next = *oldhead;
		new->prev = wheel_go_to_tail(*oldhead);
		new->prev->next = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
		new->is_tail = true;
	}
	new->is_head = true;
	new->number = input;
	return (new);
}
