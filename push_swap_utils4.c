/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:57:31 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/27 15:14:57 by ahmaymou        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	index_stacks(t_vars *vars)
{
	t_list	*temp;
	int		i;

	temp = vars->stack_a;
	i = 0;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
	temp = vars->stack_b;
	i = 0;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}
unsigned int	abs_val(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int	which_move(t_vars *vars)
{
	/*rra rrb rrr negatives ; ra rb rr positives*/
	int				tab;
	unsigned int	pos;

	tab = 0;
	pos = get_index_pos(vars);
	if (pos < vars->size_a / 2 && vars->min_b_index < vars->size_b / 2)
		if (pos < vars->min_b_index)
			tab = pos;
		else
		tab = vars->min_b_index;
	else if (pos >= vars->size_a / 2 && vars->min_b_index >= vars->size_b / 2)
	{
		if (pos >= vars->min_b_index)
			tab = -pos;
		else
			tab = -(vars->min_b_index);
	}
	return (tab);
}

void	normal_rot(t_vars *vars)
{
	// 	unsigned int	index;

	// index = get_index_pos(vars);
	// // if (index == 0)
	// // {
	// // 	pa(vars, 1);
	// // 	// sa(vars, 1);
	// // }
	// if (index < vars->size_a / 2)
	// {
	// 	// temp = index + 1;
	// 	while (index--)
	// 		ra(vars, 1);
	// 	// pa(vars, 1);
	// 	// while (temp--)
	// 	// 	rra(vars, 1);
	// }
	// else
	// {
	// 	index = vars->size_a - index;
	// 	// temp = index + 1;
	// 	while (index--)
	// 		rra(vars, 1);
	// 	// pa(vars, 1);
	// 	// while (temp--)
	// 	// 	ra(vars, 1);
	// }
	if (vars->min_a_index < vars->size_a / 2)
		while (vars->stack_a->content != vars->min_a)
			ra(vars, 1);
	else
		while (vars->stack_a->content != vars->min_a)
			rra(vars, 1);
	if (vars->min_b_index < vars->size_b / 2)
		while (vars->stack_b->content != vars->min_b)
			rb(vars, 1);
	else
		while (vars->stack_b->content != vars->min_b)
			rrb(vars, 1);
}

void	min_to_top(t_vars *vars)
{
	int	tab;

	tab = which_move(vars);
	if (tab < 0)
	{
		tab = abs_val(tab);
		// printf("suuiii");
		while (tab--)
			rrr(vars);
		normal_rot(vars);
	}
	else
	{
		while (tab--)
			rr(vars);
		normal_rot(vars);
	}
}

void	min_max_index_a(t_vars *vars)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = vars->stack_a;
	vars->min_a = INT_MAX;
	vars->max_a = INT_MIN;
	while (temp)
	{
		if(temp->content < vars->min_a)
		{
			vars->min_a = temp->content;
			vars->min_a_index = i;
		}
		if(temp->content > vars->max_a)
			vars->max_a = temp->content;
		i++;
		temp = temp->next;
	}
}

void	min_max_index_b(t_vars *vars)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = vars->stack_b;
	vars->min_b = INT_MAX;
	vars->max_b = INT_MIN;
	while (temp)
	{
		if(temp->content < vars->min_b)
		{
			vars->min_b = temp->content;
			vars->min_b_index = i;
		}
		if(temp->content > vars->max_b)
			vars->max_b = temp->content;
		i++;
		temp = temp->next;
	}
}

void	set_struct(t_vars *vars)
{
	index_stacks(vars);
	min_max_index_a(vars);
	min_max_index_b(vars);
	min_to_top(vars);
	// do_pa(vars);
}

void	sort(t_vars *vars)
{
	unsigned int	size;

	size = vars->size_b;
	while (size--)
	{
		set_struct(vars);
		do_pa(vars);
	// printf("suuuiii\n");
	}
	ra(vars, 1);
	// normal_rot(vars);
	// min_to_top(vars);
}

int	get_index_pos(t_vars *vars)
{
	t_list	*temp;
	int		i;

	temp = vars->stack_a;
	i = 0;
	while (temp->content < vars->stack_b->content)
	{
		i++;
		temp = temp->next;
		if (!temp)	
			break ;
	}
	return (i);
}

void	do_pa(t_vars *vars)
{
	unsigned int	index;
	// int				temp;

	index = get_index_pos(vars);
	if (index == 0)
	{
		pa(vars, 1);
		// sa(vars, 1);
	}
	else if (index < vars->size_a / 2)
	{
		// temp = index + 1;
		while (index--)
			ra(vars, 1);
		pa(vars, 1);
		// while (temp--)
		// 	rra(vars, 1);
	}
	else
	{
		index = vars->size_a - index;
		// temp = index + 1;
		while (index--)
			rra(vars, 1);
		pa(vars, 1);
		// while (temp--)
		// 	ra(vars, 1);
	}
}