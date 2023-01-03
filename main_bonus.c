# include "push_swap.h"

// bool    is_sorted(t_vars vars)
// {
// 	t_list  *temp;
// 	int		prev_content;

// 	temp = vars.stack_a;
// 	prev_content = temp->content;
// 	while (temp)
// 	{
// 		if (prev_content > temp->content)
// 			return (false);
// 		prev_content = temp->content;
// 		temp = temp->next;
// 	}
// 	return (true);
// }

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

void	user_steps(t_vars *vars, char *ptr)
{
	if (!ft_strncmp(ptr, "sa\n", 3))
		sa(vars, 1);
	else if (!ft_strncmp(ptr, "sb\n", 3))
		sb(vars, 1);
	else if (!ft_strncmp(ptr, "ss\n", 3))
		ss(vars);
	else if (!ft_strncmp(ptr, "ra\n", 3))
		ra(vars, 1);
	else if (!ft_strncmp(ptr, "rb\n", 3))
		rb(vars, 1);
	else if (!ft_strncmp(ptr, "rr\n", 3))
		rr(vars);
	else if (!ft_strncmp(ptr, "rra\n", 4))
		rra(vars, 1);
	else if (!ft_strncmp(ptr, "rrb\n", 4))
		rra(vars, 1);
	else if (!ft_strncmp(ptr, "rrr\n", 4))
		rrr(vars);
	else if (!ft_strncmp(ptr, "pa\n", 3))
		pa(vars, 0);
	else if (!ft_strncmp(ptr, "pb\n", 3))
		pb(vars, 1);
	else
		exit(1);
	// i++;

}

int	main(int argc, char **argv)
{
	t_vars			vars;
	int				i;
	int 			content;
	char 			*ptr;

	i = 0;
	if (argc == 1)
		return (0);
	ptr = malloc(5);
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
	ptr = get_next_line(0);
	while (ptr)
	{
		// ft_printf("====%s", ptr);
		user_steps(&vars, ptr);
		free(ptr);
		ptr = get_next_line(0);
	}
	if (is_sorted(vars))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}