/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/03 15:37:21 by blackhole        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	min_to_top(t_vars *vars)
{
	int				moves;

	if (vars->min_a_index < vars->size_a / 2)
	{
		moves = vars->min_a_index;
		while (moves--)
			ra(vars, 1);
	}
	else
	{
		moves = vars->size_a - vars->min_a_index;
		while (moves--)
			rra(vars, 1);
	}
}

void	min_index_a(t_vars *vars)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = vars->stack_a;
	vars->min_a = INT_MAX;
	// vars->max_a = INT_MIN;
	while (temp)
	{
		if(temp->content < vars->min_a)
		{
			vars->min_a = temp->content;
			vars->min_a_index = i;
		}
		i++;
		temp = temp->next;
	}
}

void	set_struct(t_vars *vars)
{
	index_stacks(vars);
	min_index_a(vars);
	iterate_assign(vars);
}

void	sort(t_vars *vars)
{
	unsigned int	size;

	size = vars->size_b;
	while (size--)
	{
		set_struct(vars);
		vars->best_elem = get_the_best(vars);
		vars->best_elem->where_to_push = abs_val(where_to_push(vars, vars->best_elem));
		apply_moves(vars);
	}
	min_index_a(vars);
	min_to_top(vars);
}

bool    is_sorted(t_vars vars)
{
	t_list  *temp;
	int		prev_content;

	temp = vars.stack_a;
	prev_content = temp->content;
	while (temp)
	{
		if (prev_content > temp->content)
			return (false);
		prev_content = temp->content;
		temp = temp->next;
	}
	return (true);
}