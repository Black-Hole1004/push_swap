/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_and_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/03 10:41:11 by blackhole        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void lis_init(int lis[], t_vars *vars)
{
	unsigned int	i;

	i = 0;
	while (i < vars->size_a)
		lis[i++] = 1;
}

// Iterate through the linked list, starting from the second element
void lis_calculate(int lis[], t_vars *vars)
{
	t_list 		*current;
	t_list 		*prev;
	unsigned int i;

	current = vars->stack_a->next;
	i  = 1;
	while (current)
	{
		// For each element, consider the longest increasing subsequence ending at each previous position
		prev = vars->stack_a;
		unsigned int j = 0;
		while (prev != current) {
			// If the element at the previous position is less than the current element and the LIS ending at that
			// position is longer than the current LIS, update the current LIS
			if (prev->content < current->content && lis[i] < lis[j] + 1) {
				lis[i] = lis[j] + 1;
			}
			prev = prev->next;
			j++;
		}
		current = current->next;
		i++;
	}
}

// Find the maximum value in the LIS array
int	lis_find_max(int lis[], t_vars *vars)
{
	int				max;
	unsigned int	i;
	t_list 			*current;

	max = lis[0];
	while (i < vars->size_a)
	{
		if (lis[i] > max) {
			max = lis[i];
		}
		i++;
	}
	i = 0;
	int temp = max;
	while (lis[i] != max)
		i++;
	while (max)
	{
		current = vars->stack_a;
		while (current->index != i)
			current = current->next;
		current->in_lis = true;
		max--;
		while (lis[i] != max && max > 0)
			i--;
	}
	return (temp);
}

int lis(t_vars *vars)
{
	int lis[vars->size_a];
	lis_init(lis, vars);
	lis_calculate(lis, vars);
	return lis_find_max(lis, vars);
}

void    do_pb(t_vars *vars)
{
	unsigned int size;

	size = lis(vars);
	while (vars->size_a != size)
	{
		if (!vars->stack_a->in_lis)
			pb(vars, 1);
		else
			ra(vars, 1);
	}
}