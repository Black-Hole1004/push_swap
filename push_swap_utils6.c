/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/08 11:24:15 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	where_to_push(t_vars *vars, t_list *temp)
{
	t_list				*tmp;
	t_list				*head;
	unsigned int		i;

	tmp = vars->stack_a;
	head = vars->stack_a;
	while (tmp->next)
	{
		if ((temp->content > tmp->content)
			&& (temp->content < tmp->next->content))
		{
			i = tmp->next->index;
			return (i);
		}
		tmp = tmp->next;
	}
	if (temp->content < head->content && temp->content > tmp->content)
		i = head->index;
	else
	{
		tmp = find_elem(vars, vars->min_a_index, 'a');
		i = tmp->index;
	}
	return (i);
}

int	normal_calc(t_vars *vars, t_list *elem)
{
	int				moves;
	unsigned int	half_a;
	unsigned int	half_b;

	half_a = vars->size_a / 2;
	half_b = vars->size_b / 2;
	moves = 0;
	if (elem->index <= half_b)
		moves += elem->index;
	else
		moves += vars->size_b - elem->index - 1;
	if (elem->where_to_push <= half_a)
		moves += elem->where_to_push;
	else
		moves += vars->size_a - elem->where_to_push - 1;
	return (moves);
}

void	assign_number_moves(t_vars *vars, t_list *elem)
{
	unsigned int	half_a;
	unsigned int	half_b;
	int				pos;
	int				pos_to_push;

	half_a = vars->size_a / 2;
	half_b = vars->size_b / 2;
	pos = vars->size_b - elem->index - 1;
	pos_to_push = vars->size_a - elem->where_to_push - 1;
	if ((elem->index > half_b && elem->where_to_push > half_a)
		|| (elem->index <= half_b && elem->where_to_push <= half_a))
	{
		if ((elem->index > half_b && elem->where_to_push > half_a))
			elem->num_moves = maximum(pos, pos_to_push);
		else
			elem->num_moves = maximum(elem->index, elem->where_to_push);
	}
	else
		elem->num_moves = normal_calc(vars, elem);
}

void	iterate_assign(t_vars *vars)
{
	t_list	*tmp;

	tmp = vars->stack_b;
	while (tmp)
	{
		tmp->where_to_push = where_to_push(vars, tmp);
		assign_number_moves(vars, tmp);
		tmp = tmp->next;
	}
}

t_list	*get_the_best(t_vars *vars)
{
	t_list	*tmp;
	t_list	*best_stack;
	int		best;

	tmp = vars->stack_b;
	best = INT_MAX;
	while (tmp)
	{
		if (best > tmp->num_moves)
		{
			best_stack = tmp;
			best = tmp->num_moves;
		}
		tmp = tmp->next;
	}
	return (best_stack);
}
