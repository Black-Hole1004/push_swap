/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:30:40 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/20 12:36:49 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_split(const char *str, char c, int *i)
{
	char	**strings;

	if (!str)
		return (0);
	strings = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!strings)
		return (0);
	while (*str != '\0')
	{
		while (*str != '\0' && *str == c)
			str++;
		if (*str != '\0')
		{
			strings[*i] = ft_substr(str, 0, word_length(str, c));
			if (!strings[*i])
				return (free_all(strings));
		(*i)++;
		}
		while (*str && *str != c)
			str++;
	}
	strings[*i] = 0;
	return (strings);
}
