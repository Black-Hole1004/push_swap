/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:51 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/31 18:38:44 by blackhole        ###   ########.fr       */
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
	unsigned int	best_elem_index;
	int				min_a;
	int				max_a;
	int				min_b;
	int				max_b;
	unsigned int	min_a_index;
	unsigned int	min_b_index;
	unsigned int	max_a_index;
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
void	print_list(t_vars vars);
bool	check_valid(char	**num);
bool	check_dup(char *str, char **num, int index);
char	*parse_args(char **args);
bool	check_blank(char *str);
void	index_stacks(t_vars *vars);
void	min_max_index_a(t_vars *vars);
void	min_max_index_b(t_vars *vars);
void	min_to_top(t_vars *vars);
void	do_pb(t_vars *vars);
void	set_struct(t_vars *vars);
void	sort(t_vars *vars);
void	do_pa(t_vars *vars);
int		get_index_pos(t_vars *vars, t_list *temp);
char	**ft_split(t_vars *vars);

#endif
