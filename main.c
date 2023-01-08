/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/08 20:11:51 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vars			vars;

	if (argc == 1)
		return (0);
	vars.pars = parse_args(++argv);
	stacks_init(&vars);
	if (!check_valid(vars.numbers))
		return (ft_putstr_fd("\033[31mError\n", 2), 1);
	fill_stack(&vars);
	if (vars.size_a <= 4)
		sort3(&vars);
	else if (vars.size_a <= 6)
		sort5(&vars);
	else
	{
		do_pb(&vars);
		sort(&vars);
	}
}
