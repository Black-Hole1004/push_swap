/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:57:31 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/03 16:45:00 by blackhole        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_vars *vars, bool print)
{
	t_list			*temp;
	unsigned int	size;
	unsigned int	i = 1;

	size = vars->size_a;
	if (size < 2)
		return ;
	temp = ft_lstlast(vars->stack_a);
	ft_lstadd_front(&vars->stack_a, ft_lstnew(temp->content, 1, temp->in_lis));
	free(temp);
	temp = vars->stack_a;
	while (i++ < size)
		temp = temp->next;
	temp->next = NULL;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_vars *vars, bool print)
{
	t_list			*temp;
	unsigned int	size;
	unsigned int	i = 1;

	size = vars->size_b;
	if (size < 2)
		return ;
	temp = ft_lstlast(vars->stack_b);
	ft_lstadd_front(&vars->stack_b, ft_lstnew(temp->content, 1, temp->in_lis));
	free(temp);
	temp = vars->stack_b;
	while (i++ < size)
		temp = temp->next;
	temp->next = NULL;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_vars *vars)
{
	rra(vars, 0);
	rrb(vars, 0);
	if (!vars->size_a || !vars->size_b)
		return ;
	ft_printf("rrr\n");
}

void	print_list(t_vars vars)
{
	t_list *list = vars.stack_a;
	t_list *list2 = vars.stack_b;
	while (list || list2)
	{
		// if (list->in_lis)
			if (list)
				ft_printf("%d\t\t", list->content);
			else
				ft_printf(" \t\t");
			if (list2)
				ft_printf("%d\n", list2->content);
			else
				ft_printf(" \n");
		if (list)
			list = list->next;
		if (list2)
			list2 = list2->next;
	}
	ft_printf("==\t==\n[a]\t\t[b]\n");
}
