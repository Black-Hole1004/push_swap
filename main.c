/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/06 17:55:00 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (argc <= 4)
		sort3(&vars);
	else if (argc <= 6)
		sort5(&vars);
	else
	{
		do_pb(&vars);
		sort(&vars);
	}
	// print_list(vars);
	// system("leaks push_swap | grep total");
}
