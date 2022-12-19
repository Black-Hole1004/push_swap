/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:05:21 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/19 15:56:06 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char			*to_return;
	unsigned int	i;
	unsigned int	len;
	unsigned int	len_s;

	if (!s2)
		return (NULL);
	len_s = ft_strlen(s1);
	len = len_s + ft_strlen(s2);
	i = 0;
	to_return = (char *)malloc((len + 1)
			* sizeof(char));
	if (!to_return)
		return (NULL);
	ft_strlcpy(to_return, s1, len_s + 1);
	while (s2[i] && (i < (len - len_s)))
	{
		to_return[len_s + i] = s2[i];
		i++;
	}
	to_return[len] = '\0';
	free(s1);
	return (to_return);
}
