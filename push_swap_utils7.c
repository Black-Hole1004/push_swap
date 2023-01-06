/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/06 16:52:30 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_moves(t_vars *vars)
{
	unsigned int	half_size_a;
	unsigned int	half_size_b;
	t_list			*elem;
	int				a_content;
	int				b_content;

	elem = vars->best_elem;
	b_content = elem->content;
	half_size_a = vars->size_a / 2;
	half_size_b = vars->size_b / 2;
	a_content = find_elem(vars, elem->where_to_push, 'a')->content;
	if ((elem->index > half_size_b && elem->where_to_push > half_size_a)
		|| (elem->index <= half_size_b && elem->where_to_push <= half_size_a))
		common_moves(vars, b_content, a_content);
	else
		simple(vars, b_content, a_content);
	pa(vars, 1);
}

void	simple(t_vars *vars, int b_content, int a_content)
{
	unsigned int		half_size_a;
	unsigned int		half_size_b;
	t_list				*elem;

	elem = vars->best_elem;
	half_size_a = vars->size_a / 2;
	half_size_b = vars->size_b / 2;
	if (elem->index > half_size_b)
		while (vars->stack_b->content != b_content)
			rrb(vars, 1);
	else
		while (vars->stack_b->content != b_content)
			rb(vars, 1);
	if (elem->where_to_push > half_size_a)
		while (vars->stack_a->content != a_content)
			rra(vars, 1);
	else
		while (vars->stack_a->content != a_content)
			ra(vars, 1);
}

void	common_moves(t_vars *vars, int b_content, int a_content)
{
	unsigned int		half_size_b;
	t_list				*elem;

	half_size_b = vars->size_b / 2;
	elem = vars->best_elem;
	if (elem->index <= half_size_b)
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
	while (vars->stack_a->content != a_content
		&& vars->stack_b->content != b_content)
		rrr(vars, 1);
	while (vars->stack_a->content != a_content)
		rra(vars, 1);
	while (vars->stack_b->content != b_content)
		rrb(vars, 1);
}
