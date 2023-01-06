/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:57:31 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/06 20:06:54 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_vars *vars, bool print)
{
	t_list			*temp;
	unsigned int	size;
	unsigned int	i;

	i = 1;
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
	unsigned int	i;

	i = 1;
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

void	rrr(t_vars *vars, bool print)
{
	rra(vars, 0);
	rrb(vars, 0);
	if (!vars->size_a || !vars->size_b)
		return ;
	if (print)
		ft_printf("rrr\n");
}

void	fill_stack(t_vars *vars)
{
	int	i;
	int	content;

	i = 0;
	while (*vars->numbers)
	{
		content = ft_atoi(*vars->numbers);
		ft_lstadd_back(&vars->stack_a, ft_lstnew(content, i, 0));
		vars->numbers++;
		i++;
	}	
}

// void	print_list(t_vars vars)
// {
// 	t_list	*list;
// 	t_list	*list2;

// 	list = vars.stack_a;
// 	list2 = vars.stack_b;
// 	while (list || list2)
// 	{
// 		if (list)
// 			ft_printf("%d\t\t", list->content);
// 		else
// 			ft_printf(" \t\t");
// 		if (list2)
// 			ft_printf("%d\n", list2->content);
// 		else
// 			ft_printf(" \n");
// 		if (list)
// 			list = list->next;
// 		if (list2)
// 			list2 = list2->next;
// 	}
// 	ft_printf("==\t==\n[a]\t\t[b]\n");
// }
