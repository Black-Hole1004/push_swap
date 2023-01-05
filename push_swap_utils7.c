/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/05 16:06:55 by blackhole        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_moves(t_vars *vars)
{
	unsigned int	middle_a;
	unsigned int	middle_b;
	t_list			*elem;
	t_list 			*voisin;
	int a_content;
	int	b_content;

	elem = vars->best_elem;
	b_content = elem->content;
	middle_a = vars->size_a / 2;
	middle_b = vars->size_b / 2;
	voisin = find_elem(vars, elem->where_to_push, 'a');
	a_content = voisin->content;
	if ((elem->index > middle_b && elem->where_to_push > middle_a)
		|| (elem->index <= middle_b && elem->where_to_push <= middle_a))
		common_moves(vars, b_content, a_content);
	else
		simple(vars, b_content, a_content);
	pa(vars, 1);
}

void	simple(t_vars *vars, int b_content, int a_content)
{
	unsigned int		middle_a;
	unsigned int		middle_b;
	t_list				*elem;

	elem = vars->best_elem;
	middle_a = vars->size_a / 2;
	middle_b = vars->size_b / 2;
	if (elem->index > middle_b)
		while (vars->stack_b->content != b_content)
			rrb(vars, 1);
	else
		while (vars->stack_b->content != b_content)
			rb(vars, 1);
	if (elem->where_to_push > middle_a)
		while (vars->stack_a->content != a_content)
			rra(vars, 1);
	else
		while (vars->stack_a->content != a_content)
			ra(vars, 1);
}

void	common_moves(t_vars *vars, int b_content, int a_content)
{

	unsigned int		middle_b;
	t_list				*elem;

	middle_b = vars->size_b / 2;
	elem = vars->best_elem;
	if (elem->index <= middle_b)
	{
		while (vars->stack_a->content != a_content
			&& vars->stack_b->content != b_content)
			rr(vars, 1);
		while (vars->stack_a->content != a_content)
			ra(vars, 1);
		while (vars->stack_b->content != b_content)
			rb(vars, 1);
	}
	else
		common_rrr(vars, b_content, a_content);
}

void	common_rrr(t_vars *vars, int b_content, int a_content)
{
	while (vars->stack_a->content != a_content && vars->stack_b->content != b_content)
		rrr(vars, 1);
	while (vars->stack_a->content != a_content)
		rra(vars, 1);
	while (vars->stack_b->content != b_content)
		rrb(vars, 1);
}