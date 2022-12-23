/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/23 20:18:55 by ahmaymou         ###   ########.fr       */
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

int	*get_lis(t_vars *list, int *lis)
{
	unsigned int	i;

	i = 0;
    while (i < list->size_a)
        lis[i++] = 1;
    t_list *current = list->stack_a->next;
    i = 1;
    while (current != NULL)
	{
        t_list *prev = list->stack_a;
        unsigned int j = 0;
        while (prev != current) {
            if (prev->content < current->content && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
            prev = prev->next;
            j++;
        }
        current = current->next;
        i++;
    }
	return (lis);
}

unsigned int lis(t_vars *list)
{
	unsigned int	i;
    int 			*lis;
	t_list			*current;

	lis = malloc(list->size_a);
	lis = get_lis(list, lis);
    int max = lis[0];
	i = 0;
    while (i < list->size_a)
	{
		if (lis[i] > max)
            max = lis[i];
		i++;
	}
	unsigned int temp = max;
	i = 0;
	while (lis[i] != max)
		i++;
	while (max)
	{
		current = list->stack_a;
		while (current->index != i)
			current = current->next;
		current->in_lis = true;
		max--;
		while (lis[i] != max && max > 0)
			i--;
	}
	free(lis);
	return (temp);
}

int	main(int argc, char **argv)
{
	t_vars			vars;
	int				i;
	unsigned int 	size;

	i = 0;
	(void) argc;
	vars.stack_b = NULL;
	vars.size_a = 0;
	vars.pars = parse_args(++argv);
	vars.numbers = ft_split(&vars);
	if (!check_valid(vars.numbers))
		return (ft_putstr_fd("\033[31mError\n", 2), 1);
	while (*vars.numbers)
	{
		ft_lstadd_back(&vars.stack_a, ft_lstnew(ft_atoi(*vars.numbers), i, 0));
		vars.numbers++;
		i++;
	}
	i = 0;
	print_list(vars.stack_a);

	size = lis(&vars);
	print_list(vars.stack_a);
	while (vars.size_a != size)
	{
		if (!vars.stack_a->in_lis)
			pb(&vars, 1);
		ra(&vars, 1);
	}
	ft_printf("======");
	print_list(vars.stack_a);
	// print_list(vars.stack_a);
	system("leaks push_swap | grep total");
}
