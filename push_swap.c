/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/21 20:46:35 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_blank(char *str)
{
	while (*str && *str == ' ')
		str++;
	if (!(*str))
		return (true);
	else
		return (false);
}

char	*parse_args(char **args)
{
	char	*to_return;

	to_return = ft_strdup("");
	while (*args)
	{
		if (check_blank(*args))
			return (NULL);
		to_return = ft_strjoin(to_return, *args);
		to_return = ft_strjoin(to_return, " ");
		args++;
	}
	return (to_return);
}

bool	check_dup(char *str, char **num, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (ft_atoi(str) == ft_atoi(num[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_valid(char	**num)
{
	int	good;
	int	i;

	i = 0;
	good = 0;
	if (!num)
		return (false);
	while (num[i])
	{
		if (ft_atoi(num[i]) != UINT_MAX && check_dup(num[i], num, i))
			good++;
		i++;
	}
	if (good == i && i)
		return (true);
	else
		return (false);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void) argc;
	vars.stack_b = NULL;
	vars.size_a = 0;
	vars.pars = parse_args(argv);
	vars.numbers = ft_split(&vars);
	if (vars.numbers)
		vars.numbers++;
	if (!check_valid(vars.numbers))
		return (ft_putstr_fd("\033[31mError\n", 2), 1);
	while (*vars.numbers)
	{
		ft_lstadd_back(&vars.stack_a, ft_lstnew(ft_atoi(*vars.numbers)));
		vars.numbers++;
	}
	// ft_printf("\033[92mnumber of elements in the stack : [%d]\n\033[0m", (vars.size_a - 1));
	// ft_printf("\033[36mprinting the stack_a before instractions... : \n\033[0m");
	// print_list(vars.stack_a);
	// ft_printf("\033[36mprinting the stack_b before instractions... : \n\033[0m");
	sa(&vars, 1);
	// rra(&stack_a, &vars, 1);
	// ft_lstadd_back(&stack_b, ft_lstnew(1004));
	// pa(&stack_a, &stack_a, &vars);
	pb(&vars, 1);
	// ft_printf("\033[92mnumber of elements in the stack : [%d]\n\033[0m", (vars.size_a - 1));
	pb(&vars, 1);
	pb(&vars, 1);
	// ft_printf(" ===============\n");
	// print_list(vars.stack_a);
	// ft_printf(" ===============\n");
	// print_list(vars.stack_b);
	rr(&vars);
	// ra(&vars, 1);
	// rra(&vars, 1);
	// rrb(&vars, 1);
	rrr(&vars);
	// ft_printf(" ===============\n");
	// print_list(vars.stack_a);
	// ft_printf(" ===============\n");
	// print_list(vars.stack_b);
	// rrr(&vars);
	// ft_printf("====== [%d] ===", ft_lstsize(stack_b));
	// rb(&stack_b, vars, 1);
	// pb(&stack_a, &stack_b, &vars);
	sa(&vars, 1);
	pa(&vars, 1);
	pa(&vars, 1);
	pa(&vars, 1);
	// ft_printf("================\n");
	// print_list(vars.stack_a);
	// ft_printf("\033[36mprinting the stack after SA ... : \n\033[0m");
	// ss(&stack_a, &stack_b, vars);
	// print_list(stack_a);
	// printf("salam\n");
	// ft_printf("stack_b ===============\n");
	// print_list(stack_a);
	// ft_printf("stack_b ===============\n");
	// print_list(stack_a);
	// free(vars.pars);
	// system("leaks push_swap");
	// while (1)
	// ;
}
