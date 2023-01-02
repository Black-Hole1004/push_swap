/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:57:31 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/02 13:42:39 by blackhole        ###   ########.fr       */
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

t_list	*find_elem(t_vars *vars, int index, char c)
{
	unsigned int	i;
	t_list			*temp;

	i = abs_val(index);
	if (c == 'b')
		temp = vars->stack_b;
	else
		temp = vars->stack_a;
	while (temp->index != i)
	{
		temp = temp->next;
		if (!temp)
			break ;
	}
	return (temp);
}

unsigned int	minimum(unsigned int a, unsigned int b)
{
	return (a < b ? a : b);
}

unsigned int	maximum(unsigned int a, unsigned int b)
{
	return (a > b ? a : b);
}
