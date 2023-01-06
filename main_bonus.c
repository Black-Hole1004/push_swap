/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/06 17:51:16 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_instructions(t_vars *vars, bool is_done)
{
	char	*ptr;

	ptr = malloc (5);
	ptr = get_next_line(0);
	while (ptr)
	{
		user_steps(&vars, ptr, &is_done);
		if (!is_done)
		{
			ft_printf("you did not provide a valid move !\n");
			free(ptr);
			exit(1);
		}
		free(ptr);
		ptr = get_next_line(0);
	}	
}

int	main(int argc, char **argv)
{
	t_vars			vars;
	int				i;
	int				content;
	bool			is_done;

	i = 0;
	if (argc == 1)
		return (0);
	vars.pars = parse_args(++argv);
	stacks_init(&vars);
	if (!check_valid(vars.numbers))
		return (ft_putstr_fd("\033[31mError\n", 2), 1);
	while (*vars.numbers)
	{
		content = ft_atoi(*vars.numbers);
		ft_lstadd_back(&vars.stack_a, ft_lstnew(content, i, 0));
		vars.numbers++;
		i++;
	}
	is_done = true;
	get_instructions(&vars, is_done);
	if (is_sorted(vars))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
