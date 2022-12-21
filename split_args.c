/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:30:40 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/21 17:56:12 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

static int	count_words(const char *str, char charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charset)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != charset)
			i++;
	}
	return (count);
}

static int	word_length(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

char	**ft_split(t_vars *vars)
{
	char	**strings;

	if (!vars->pars)
		return (0);
	strings = (char **)malloc(sizeof(char *) * (count_words(vars->pars, ' ') + 1));
	if (!strings)
		return (0);
	while (*vars->pars != '\0')
	{
		while (*vars->pars != '\0' && *vars->pars == ' ')
			vars->pars++;
		if (*vars->pars != '\0')
		{
			strings[vars->size_a] = ft_substr(vars->pars, 0, word_length(vars->pars, ' '));
			if (!strings[vars->size_a])
				return (free_all(strings));
		vars->size_a++;
		}
		while (*vars->pars && *vars->pars != ' ')
			vars->pars++;
	}
	strings[vars->size_a] = 0;
	return (strings);
}
