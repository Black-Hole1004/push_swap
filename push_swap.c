/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/24 12:52:29 by ahmaymou         ###   ########.fr       */
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

int lis(t_vars *list) {
    // Initialize the LIS array to 1 for all elements
    int lis[list->size_a];

    for (unsigned int i = 0; i < list->size_a; i++) {
        lis[i] = 1;
    }
    // Iterate through the linked list, starting at the second element
    t_list *current = list->stack_a->next;
    unsigned int i = 1;
    while (current != NULL) {
        // For each element, consider the longest increasing subsequence ending at each previous position
        t_list *prev = list->stack_a;
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
    // Find the maximum value in the LIS array
    int max = lis[0];
    for (unsigned int i = 0; i < list->size_a; i++) {
		if (lis[i] > max) {
            max = lis[i];
        }
    }
	i = 0;
	int temp = max;
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
	return (temp);
}

// void	get_lis(t_vars *list, int *tab)
// {
// 	t_list 			*prev;
// 	t_list 			*current;
// 	unsigned int	i;
// 	unsigned int 	j;

// 	i = 0;
// 	int lis[list->size_a];
//     while (i < list->size_a)
//         lis[i++] = 1;
//     current = list->stack_a->next;
//     i = 1;
//     while (current)
// 	{
//         j = 0;
//         prev = list->stack_a;
//         while (prev != current)
// 		{
//             if (prev->content < current->content && lis[i] < lis[j] + 1)
//                 lis[i] = lis[j] + 1;
//             prev = prev->next;
//             j++;
//         }
//         current = current->next;
//         i++;
//     }
// 	i = 0;
// 	while (i < list->size_a){
// 		tab[i] = lis[i];
// 		i++;
// 	}
// }

// unsigned int lis(t_vars *list)
// {
// 	unsigned int	i;
//     int 			*lis;
// 	t_list			*current;
// 	int				max;

// 	lis = malloc(list->size_a);
// 	get_lis(list, lis);
// 	i = 0;
//     max = lis[0];
//     while (i < list->size_a)
// 	{
// 		if (lis[i] > max)
//             max = lis[i];
// 		i++;
// 	}
// 	unsigned int temp = max;
// 	i = 0;
// 	while (lis[i] != max)
// 		i++;
// 	while (max)
// 	{
// 		current = list->stack_a;
// 		while (current->index != i)
// 		{
// 			ft_printf(" [%d] ", current->content);
// 			current = current->next;
// 		}
// 		ft_printf(" [%d] ", current->content);
// 		current->in_lis = true;
// 		puts("");
// 		max--;
// 		while (lis[i] != max && max > 0)
// 			i--;
// 	}
// 	free(lis);
// 	return (temp);
// }

int	main(int argc, char **argv)
{
	t_vars			vars;
	int				i;
	unsigned int 	size;

	i = 0;
	int toto;
	(void) argc;
	vars.min = INT_MAX;
	vars.max = INT_MIN;
 	vars.stack_b = NULL;
	vars.stack_a = NULL;
	vars.size_a = 0;
	vars.pars = parse_args(++argv);
	vars.numbers = ft_split(&vars);
	if (!check_valid(vars.numbers))
		return (ft_putstr_fd("\033[31mError\n", 2), 1);
	while (*vars.numbers)
	{
		toto = ft_atoi(*vars.numbers);
		ft_lstadd_back(&vars.stack_a, ft_lstnew(toto, i, 0));
		if(toto < vars.min)
		{
			vars.min = toto;
			vars.min_index = i;
		}
		if(toto > vars.max)
			vars.max = toto;
		vars.numbers++;
		i++;
	}
	i = 0;
	// if (vars.min_index < vars.size_a / 2)
	// {
	// 	while (vars.stack_a->content != vars.min)
	// 		ra(&vars, 1);
	// }
	// else
	// 	while (vars.stack_a->content != vars.min)
	// 		rra(&vars, 1);
	// t_list *tmp = vars.stack_a;
	// while (tmp)
	// {
	// 	tmp->index = i;
	// 	i++;
	// 	tmp = tmp->next;
	// }
	// print_list(vars.stack_a);
	size = lis(&vars);
	// print_list(vars.stack_a);
	// ft_printf("====== size_a [%d]\n", vars.stack_a->content);
	while (vars.size_a != size)
	{
		if (!vars.stack_a->in_lis)
			pb(&vars, 1);
		rra(&vars, 1);
	}
	ra(&vars, 1);
	// ft_printf("====== size_a [%d]\n", vars.size_a);
	print_list(vars.stack_a);
	ft_printf("======\n");
	print_list(vars.stack_b);
	// system("leaks push_swap | grep total");
}
