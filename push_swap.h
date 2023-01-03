/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:51 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/03 20:47:23 by blackhole        ###   ########.fr       */
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
# include "get_next_line.h"

typedef struct s_variable
{
	t_list			*stack_a;
	t_list			*stack_b;
	char			**numbers;
	char			*pars;
	unsigned int	size_a;
	unsigned int	size_b;
	t_list			*best_elem;
	int				min_a;
	unsigned int	min_a_index;
}					t_vars;

void			sa(t_vars *vars, bool print);
void			sb(t_vars *vars, bool print);
void			ss(t_vars *vars);
void			pa(t_vars *vars, bool print);
void			pb(t_vars *vars, bool print);
void			ra(t_vars *vars, bool print);
void			rb(t_vars *vars, bool print);
void			rr(t_vars *vars);
void			rra(t_vars *vars, bool print);
void			rrb(t_vars *vars, bool print);
void			rrr(t_vars *vars);
void			print_list(t_vars vars);
void    		stacks_init(t_vars *vars);
void			lis_init(int lis[], t_vars *list);
void			lis_calculate(int lis[], t_vars *list);
int				lis_find_max(int lis[], t_vars *list);
int				lis(t_vars *list);
int 			lis(t_vars *list);
unsigned int	abs_val(int val);
t_list			*find_elem(t_vars *vars, int index, char c);
bool			check_valid(char	**num);
bool			check_dup(char *str, char **num, int index);
bool			check_blank(char *str);
bool    		is_sorted(t_vars vars);
char			*parse_args(char **args);
bool			check_blank(char *str);
void			index_stacks(t_vars *vars);
void			min_index_a(t_vars *vars);
void			min_to_top(t_vars *vars);
void			do_pb(t_vars *vars);
void			set_struct(t_vars *vars);
void			sort(t_vars *vars);
int				where_to_push(t_vars *vars, t_list *temp);
void			iterate_assign(t_vars *vars);
t_list			*get_the_best(t_vars *vars);
void			apply_moves(t_vars *vars);
void			simple(t_vars *vars, int b_content, int a_content);
void			common_moves(t_vars *vars, int b_content, int a_content);
void			common_rrr(t_vars *vars, int b_content, int a_content);
unsigned int	maximum(unsigned int a, unsigned int b);
unsigned int	minimum(unsigned int a, unsigned int b);
void    		index_1_2(t_vars *vars, t_list *elem, t_list *second);
void			sort3(t_vars *vars);
void			sort5(t_vars *vars);
char			**ft_split(t_vars *vars);
char			*get_next_line(int fd);

#endif
