/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/19 20:33:46 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*parse_args(char **args)
{
	char	*to_return;

	to_return = ft_strdup("");
	while (*args)
	{
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
	char	**numbers;
	char	*pars;

	(void) argc;
	pars = parse_args(argv);
	numbers = ft_split(pars, ' ');
	numbers++;
	if (!check_valid(numbers))
		write(2, "Error\n", 6);
	else
	{
		while (*numbers)
		{
			ft_printf("%d\n", ft_atoi(*numbers));
			numbers++;
		}
	}
	free(pars);
	// system("leaks push_swap");
	// while (1)
		// ;
}
