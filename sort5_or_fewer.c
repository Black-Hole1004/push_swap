
# include "push_swap.h"

void    index_1_2(t_vars *vars, t_list *elem, t_list *second)
{
    if (vars->min_a_index == 2)
	{
		if (elem->content > second->content)
			sa(vars, 1);
		rra(vars, 1);
	}
	else if (vars->min_a_index == 1)
	{
		if (vars->size_a == 2)
			sa(vars, 1);
		else if (elem->content > second->next->content)
			ra(vars, 1);
		else
			sa(vars, 1);
	}
}

void	sort3(t_vars *vars)
{
	t_list	*elem;
	t_list	*second;

	elem = vars->stack_a;
	second = elem->next;
	min_index_a(vars);
    if (vars->min_a_index == 2 || vars->min_a_index == 1)
        index_1_2(vars, elem, second);
	else
	{
		if (vars->size_a > 2 && second->content > second->next->content)
		{
			sa(vars, 1);
			ra(vars, 1);
		}
	}
}

void	pb_5(t_vars *vars)
{
	int moves;

	if (vars->min_a_index <= vars->size_a / 2)
	while (vars->min_a_index)
	{
		ra(vars, 1);
		vars->min_a_index--;
	}
	else
	{
		moves = vars->size_a - vars->min_a_index;
		while (moves--)
			rra(vars, 1);
	}
	pb(vars, 1);
}

void	sort5(t_vars *vars)
{
	min_index_a(vars);
	while (vars->size_a >= 4)
		pb_5(vars);
	sort3(vars);
	if (!vars->stack_b->next)
		pa(vars, 1);
	else if (vars->stack_b->content > vars->stack_b->next->content)
		pa(vars, 1);
	else
	{
		sb(vars, 1);
		pa(vars, 1);
	}
	pa(vars, 1);
}
