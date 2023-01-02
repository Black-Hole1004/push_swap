/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_and_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/02 18:19:55 by blackhole        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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