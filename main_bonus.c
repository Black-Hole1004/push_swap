/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/08 20:13:00 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_instructions(t_vars *vars, bool is_done)
{
	char	*ptr;

	ptr = get_next_line(0);
	while (ptr)
	{
		user_steps(vars, ptr, &is_done);
		if (!is_done)
		{
			ft_printf("Error\n");
			exit(1);
		}
		ptr = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_vars			vars;
	int				i;
	bool			is_done;

	i = 0;
	if (argc == 1)
		return (0);
	vars.pars = parse_args(++argv);
	stacks_init(&vars);
	if (!check_valid(vars.numbers))
		return (ft_putstr_fd("Error\n", 2), 1);
	fill_stack(&vars);
	is_done = true;
	get_instructions(&vars, is_done);
	if (is_sorted(vars) && !vars.size_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
