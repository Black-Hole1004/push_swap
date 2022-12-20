/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/20 22:06:55 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"\

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

void	print_list(t_list *list)
{
	int i = 0;

	while (list)
	{
		ft_printf("%d\n", list->content);
		list = list->next;
		i++;
	}
}

void	sa(t_list **list, bool print)
{
	int	tmp;

	if (ft_lstsize(*list) < 2)
		return ;
	tmp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = tmp;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_list **list, bool print)
{
	int	tmp;

	if (ft_lstsize(*list) < 2)
		return ;
	tmp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = tmp;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_list **list_a, t_list **list_b)
{
	sa(list_a, 0);
	sb(list_b, 0);
	ft_printf("ss\n");
}

void	pa(t_list **list_a, t_list **list_b)
{
	if (!(*list_a))
		return ;
	t_list	*new;

	new = ft_lstnew((*list_b)->content);
	ft_lstadd_front(list_a, new);
	/* delete the first element of the list_b*/
}

void	pb(t_list **list_a, t_list **list_b)
{
	if (!(*list_a))
		return ;
	t_list	*new;

	new = ft_lstnew((*list_a)->content);
	ft_lstadd_front(list_b, new);
	/* delete the first element of the list_a*/
}

void	ra(t_list **list_a, bool print)
{
	t_list	*temp;
	t_list	*last;

	last = ft_lstlast(*list_a);
	ft_lstadd_back(list_a, ft_lstnew((*list_a)->content));
	temp = *list_a;
	*list_a = (*list_a)->next;
	free(temp);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_list **list_b, bool print)
{
	t_list	*temp;
	t_list	*last;

	last = ft_lstlast(*list_b);
	ft_lstadd_back(list_b, ft_lstnew((*list_b)->content));
	temp = *list_b;
	*list_b = (*list_b)->next;
	free(temp);
	if (print)
		ft_printf("ra\n");
}

void	rr(t_list **list_a, t_list **list_b)
{
	ra(list_a, 0);
	rb(list_b, 0);
	ft_printf("rr\n");
}

void	rra(t_list **list_a, unsigned int size, bool print)
{
	t_list	*temp;
	
	temp = ft_lstlast(*list_a);
	ft_lstadd_front(list_a, ft_lstnew(temp->content));
	free(temp);
	temp = *list_a;
	while (size-- > 1)
		temp = temp->next;
	temp->next = NULL;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_list **list_b, unsigned int size, bool print)
{
	t_list	*temp;

	temp = ft_lstlast(*list_b);
	temp->next = *list_b;
	*list_b = temp;
	free(temp);
	temp = *list_b;
	while (size--)
		temp = temp->next;
	temp->next = NULL;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_list **list_a, unsigned int size, t_list **list_b)
{
	rra(list_a, size, 0);
	rrb(list_b, size, 0);
	ft_printf("rrr\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b = NULL;
	t_list	*new;
	char	**numbers;
	char	*pars;
	int		ints;

	(void) argc;
	(void) stack_b;
	ints = 0;
	pars = parse_args(argv);
	numbers = ft_split(pars, ' ', &ints);
	if (numbers)
		numbers++;
	if (!check_valid(numbers))
	{
		ft_putstr_fd("\033[31mError\n", 2);
		exit(1);
	}
	while (*numbers)
	{
		new = ft_lstnew(ft_atoi(*numbers));
		ft_lstadd_back(&stack_a, new);
		numbers++;
	}
	ft_printf("\033[92mnumber of elements in the stack : [%d]\n\033[0m", (ints - 1));
	ft_printf("\033[36mprinting the stack before SA ... : \n\033[0m");
	print_list(stack_a);
	// print_list(stack_b);
	// ra(&stack_a, 1);
	rra(&stack_a, (ints - 1), 1);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// sb(&stack_b, 1);
	// ft_printf("\033[36mprinting the stack after SA ... : \n\033[0m");
	// ss(&stack_a, &stack_b);
	// print_list(stack_a);
	// printf("salam\n");
	print_list(stack_a);
	free(pars);
	system("leaks push_swap");
	while (1)
		;
}
