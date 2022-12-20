/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:11:56 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/20 16:04:03 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int ))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
