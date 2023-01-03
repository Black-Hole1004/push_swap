/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:53:10 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/03 10:31:03 by blackhole        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_vars *vars, bool print)
{
	t_list	*temp;
	// t_list	*last;

	if (vars->size_a < 2)
		return ;
	// last = ft_lstlast(vars->stack_a);
	ft_lstadd_back(&vars->stack_a, ft_lstnew((vars->stack_a)->content, 1,vars->stack_a->in_lis));
	temp = vars->stack_a;
	vars->stack_a = (vars->stack_a)->next;
	free(temp);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_vars *vars, bool print)
{
	t_list	*temp;
	// t_list	*last;

	if (vars->size_b < 2)
		return ;
	// last = ft_lstlast(vars->stack_b);
	ft_lstadd_back(&vars->stack_b, ft_lstnew((vars->stack_b)->content, 1, vars->stack_b->in_lis));
	temp = vars->stack_b;
	vars->stack_b = vars->stack_b->next;
	free(temp);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_vars *vars)
{
	ra(vars, 0);
	rb(vars, 0);
	if (vars->size_a < 2 || vars->size_b < 2)
		return ;
	ft_printf("rr\n");
}

void    stacks_init(t_vars *vars)
{
	vars->stack_b = NULL;
	vars->stack_a = NULL;
	vars->size_a = 0;
	vars->size_b = 0;
	vars->best_elem = NULL;
	vars->min_a = 0;
	vars->numbers = ft_split(vars);
}