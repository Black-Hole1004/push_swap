/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:57:31 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/27 15:14:57 by ahmaymou        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	index_stacks(t_vars *vars)
{
	t_list	*temp;
	int		i;

	temp = vars->stack_a;
	i = 0;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
	temp = vars->stack_b;
	i = 0;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}
unsigned int	abs_val(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

unsigned int	calcul_moves(t_vars *vars, int *pos)
{
	unsigned int	*to_return;
	unsigned int	sum;

	to_return = calloc (4, sizeof (int));
	if (pos[0] < 0)
		to_return[3] = vars->size_b - abs_val(pos[0]) + 1;
	else
		to_return[1] = pos[0];
	if (pos[1] < 0)
	{
		if (abs_val(pos[1]) < (vars->size_a))
			to_return[2] = vars->size_a - abs_val(pos[1]);
	}
	else
		to_return[0] = pos[1];
	sum = to_return[0] + to_return[1] + to_return[2] + to_return[3];
	return (sum);
}

void	set_best_elem_index(t_vars *vars)
{
	t_list			*temp;
	int				*pos;
	unsigned int	sum;

	index_stacks(vars);
	temp = vars->stack_b;
	vars->best_elem_index = 0;
	pos = calloc(2 , sizeof (int));
	sum = UINT_MAX;
	while (temp)
	{
		pos[0] = temp->index;
		pos[1] = get_index_pos(vars, temp);
		if (calcul_moves(vars, pos) < sum)
		{
			sum = calcul_moves(vars, pos);
			vars->best_elem_index = temp->index;
			if (vars->best_elem_index > vars->size_b / 2)
				vars->best_elem_index *= (-1);
		}
		temp = temp->next;
	}
	free (pos);
}

t_list	*find_elem(t_vars *vars, int index, char c)
{
	unsigned int	i;
	t_list			*temp;

	i = abs_val(index);
	if (c == 'b')
		temp = vars->stack_b;
	else
		temp = vars->stack_a;
	while (temp->index != i)
	{
		temp = temp->next;
		if (!temp)
			break ;
	}
	return (temp);
}

unsigned int	minimum(unsigned int a, unsigned int b)
{
	return (a < b ? a : b);
}

unsigned int	maximum(unsigned int a, unsigned int b)
{
	return (a > b ? a : b);
}

void	min_to_top(t_vars *vars)
{
	int				moves;

	if (vars->min_a_index <= vars->size_a / 2)
	{
		moves = vars->min_a_index;
		while (moves--)
			ra(vars, 1);
	}
	else
	{
		moves = vars->size_a - vars->min_a_index;
		while (moves--)
			rra(vars, 1);
	}
}

void	min_max_index_a(t_vars *vars)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = vars->stack_a;
	vars->min_a = INT_MAX;
	vars->max_a = INT_MIN;
	while (temp)
	{
		if(temp->content < vars->min_a)
		{
			vars->min_a = temp->content;
			vars->min_a_index = i;
		}
		if(temp->content > vars->max_a)
		{
			vars->max_a = temp->content;
			vars->max_a_index = i;
		}
		i++;
		temp = temp->next;
	}
}

// void	min_max_index_b(t_vars *vars)
// {
// 	int		i;
// 	t_list	*temp;

// 	i = 0;
// 	temp = vars->stack_b;
// 	vars->min_b = INT_MAX;
// 	vars->max_b = INT_MIN;
// 	while (temp)
// 	{
// 		if(temp->content < vars->min_b)
// 		{
// 			vars->min_b = temp->content;
// 			vars->min_b_index = i;
// 		}
// 		if(temp->content > vars->max_b)
// 			vars->max_b = temp->content;
// 		i++;
// 		temp = temp->next;
// 	}
// }

void	set_struct(t_vars *vars)
{
	index_stacks(vars);
	min_max_index_a(vars);
	// min_max_index_b(vars);
}

void	sort(t_vars *vars)
{
	unsigned int	size;

	size = vars->size_b;
	while (size--)
	{
		set_struct(vars);
		do_pa(vars);
	}
	min_max_index_a(vars);
	min_to_top(vars);
}

int	check_sign(t_vars *vars, unsigned int i)
{
	if (i <= vars->size_a / 2)
		return (1);
	else
		return (-1);
}

int	get_index_pos(t_vars *vars, t_list *temp)
{
	t_list				*tmp_stack;
	t_list				*head;
	unsigned int		i;

	tmp_stack = vars->stack_a;
	head = vars->stack_a;
	while (tmp_stack->next)
	{
		if ((temp->content > tmp_stack->content)
			&& (temp->content < tmp_stack->next->content))
		{
			i = tmp_stack->next->index;
			return (i * check_sign(vars, i));
		}
		tmp_stack = tmp_stack->next;
	}
	if (temp->content < head->content && temp->content > tmp_stack->content)
		i = head->index;
	else
	{
		tmp_stack = find_elem(vars, vars->min_a_index, 'a');
		i = tmp_stack->index;
	}
	return (i * check_sign(vars, i));
}

void	do_pa(t_vars *vars)
{
	int				index;
	t_list			*temp1;
	int				index2;
	unsigned int	max_i;
	int				moves[6];
	/* [0] = ra , [1] = rb, [2] = rra, [3] = rrb, [4] = rr, [5] = rrr*/
	set_best_elem_index(vars);
	temp1 = find_elem(vars, vars->best_elem_index, 'b');
	index = get_index_pos(vars, temp1);
	index2 = vars->best_elem_index;
	max_i = vars->size_a - 1;
	if (index2 >= 0)
	{
		moves[1] = index2;
		moves[3] = 0;
	}
	else
	{
		index2 = abs_val(index2);
		if ((int)vars->size_b > index2 + 1)
			index2 = vars->size_b - index2;
		else
			index2 = 1;
		moves[3] = index2;
		moves[1] = 0;
	}
	if (index < 0)
	{
		index = abs_val(index);
		moves[2] = max_i - index + 1;
		moves[0] = 0;
	}
	else
	{
		moves[0] = index;
		moves[2] = 0;
	}
	moves[4] = minimum(moves[0], moves[1]);
	while (moves[4]--)
	{
		rr(vars);
		moves[0]--;
		moves[1]--;
	}
	while (moves[0]--)
		ra(vars, 1);
	while (moves[1]--)
		rb(vars, 1);
	moves[5] = minimum(moves[2], moves[3]);
	while (moves[5]--)
	{
		rrr(vars);
		moves[2]--;
		moves[3]--;
	}
	while (moves[2]--)
		rra(vars, 1);
	while (moves[3]--)
		rrb(vars, 1);
	pa(vars, 1);
}