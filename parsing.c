/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:13:35 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/06 17:14:08 by ahmaymou         ###   ########.fr       */
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

void	user_steps(t_vars *vars, char *ptr, bool *is_done)
{
	if (!ft_strncmp(ptr, "sa\n", 3))
		sa(vars, 0);
	else if (!ft_strncmp(ptr, "sb\n", 3))
		sb(vars, 0);
	else if (!ft_strncmp(ptr, "ss\n", 3))
		ss(vars, 0);
	else if (!ft_strncmp(ptr, "ra\n", 3))
		ra(vars, 0);
	else if (!ft_strncmp(ptr, "rb\n", 3))
		rb(vars, 0);
	else if (!ft_strncmp(ptr, "rr\n", 3))
		rr(vars, 0);
	else if (!ft_strncmp(ptr, "rra\n", 4))
		rra(vars, 0);
	else if (!ft_strncmp(ptr, "rrb\n", 4))
		rrb(vars, 0);
	else if (!ft_strncmp(ptr, "rrr\n", 4))
		rrr(vars, 0);
	else if (!ft_strncmp(ptr, "pa\n", 3))
		pa(vars, 0);
	else if (!ft_strncmp(ptr, "pb\n", 3))
		pb(vars, 0);
	else
		*is_done = false;
}
