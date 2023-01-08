/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_and_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/08 12:31:26 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_init(int *lis, t_vars *vars)
{
	unsigned int	i;

	i = 0;
	while (i < vars->size_a)
		lis[i++] = 1;
}

void	lis_calculate(int *lis, t_vars *vars)
{
	t_list			*current;
	t_list			*prev;
	unsigned int	i;
	unsigned int	j;

	i = 1;
	current = vars->stack_a->next;
	while (current)
	{
		prev = vars->stack_a;
		j = 0;
		while (prev != current)
		{
			if (prev->content < current->content && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			prev = prev->next;
			j++;
		}
		current = current->next;
		i++;
	}
}

int	lis_find_max(int *lis, t_vars *vars, unsigned int i)
{
	int				max;
	int				temp;
	t_list			*current;

	max = lis[0];
	while (++i < vars->size_a)
		if (lis[i] > max)
			max = lis[i];
	i = 0;
	temp = max;
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
	return (free(lis), temp);
}

int	lis(t_vars *vars)
{
	int				*lis;
	unsigned int	i;

	i = -1;
	lis = malloc (vars->size_a * sizeof (int));
	if (!lis)
		return (0);
	lis_init(lis, vars);
	lis_calculate(lis, vars);
	return (lis_find_max(lis, vars, i));
}

void	do_pb(t_vars *vars)
{
	unsigned int	size;

	size = lis(vars);
	while (vars->size_a != size)
	{
		if (!vars->stack_a->in_lis)
			pb(vars, 1);
		else
			ra(vars, 1);
	}
}
