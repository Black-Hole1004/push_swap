/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:57:31 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/22 21:30:57 by ahmaymou         ###   ########.fr       */
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
	ft_lstadd_front(&vars->stack_a, ft_lstnew(temp->content, 1));
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
	ft_lstadd_front(&vars->stack_b, ft_lstnew(temp->content, 1));
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

void	print_list(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->in_lis)
			ft_printf("%d\n", list->content);
		list = list->next;
		i++;
	}
}
