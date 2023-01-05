/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:53:07 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/05 16:09:08 by blackhole        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_vars *vars, bool print)
{
	int	tmp;

	if (vars->size_a < 2)
		return ;
	tmp = vars->stack_a->content;
	vars->stack_a->content = vars->stack_a->next->content;
	vars->stack_a->next->content = tmp;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_vars *vars, bool print)
{
	int	tmp;

	if (vars->size_b < 2)
		return ;
	tmp = vars->stack_b->content;
	vars->stack_b->content = vars->stack_b->next->content;
	vars->stack_b->next->content = tmp;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_vars *vars, bool print)
{
	sa(vars, 0);
	sb(vars, 0);
	if ((vars->size_a > 1 || vars->size_b > 1) && print)
		ft_printf("ss\n");
}

void	pa(t_vars *vars, bool print)
{
	t_list	*new;

	if (!vars->size_b)
		return ;
	new = ft_lstnew(vars->stack_b->content, 1, vars->stack_b->in_lis);
	ft_lstadd_front(&vars->stack_a, new);
	new = vars->stack_b;
	vars->stack_b = (vars->stack_b)->next;
	free(new);
	vars->size_a++;
	vars->size_b--;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_vars *vars, bool print)
{
	t_list	*new;

	if (!vars->size_a)
		return ;
	new = ft_lstnew((vars->stack_a)->content, 1, vars->stack_a->in_lis);
	ft_lstadd_front(&vars->stack_b, new);
	new = vars->stack_a;
	vars->stack_a = (vars->stack_a)->next;
	free(new);
	vars->size_a--;
	vars->size_b++;
	if (print)
		ft_printf("pb\n");
}
