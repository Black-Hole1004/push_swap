/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:51 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/24 11:26:51 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_variable
{
	t_list			*stack_a;
	t_list			*stack_b;
	char			**numbers;
	char			*pars;
	unsigned int	size_a;
	unsigned int	size_b;
	int				min;
	unsigned int	min_index;
	int				max;
}					t_vars;

void	sa(t_vars *vars, bool print);
void	sb(t_vars *vars, bool print);
void	ss(t_vars *vars);
void	pa(t_vars *vars, bool print);
void	pb(t_vars *vars, bool print);
void	ra(t_vars *vars, bool print);
void	rb(t_vars *vars, bool print);
void	rr(t_vars *vars);
void	rra(t_vars *vars, bool print);
void	rrb(t_vars *vars, bool print);
void	rrr(t_vars *vars);
void	print_list(t_list *list);
bool	check_valid(char	**num);
bool	check_dup(char *str, char **num, int index);
char	*parse_args(char **args);
bool	check_blank(char *str);
char	**ft_split(t_vars *vars);

#endif
