/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:47:21 by akaratas          #+#    #+#             */
/*   Updated: 2024/03/20 15:18:31 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min_node(t_list *lst, long num)
{
	t_list	*min_node;
	int		min;

	min_node = NULL;
	min = INT_MAX;
	while (lst != NULL)
	{
		if ((lst->content) <= min && (lst->content) > num)
		{
			min_node = lst;
			min = lst->content;
		}
		lst = lst->next;
	}
	return (min_node);
}

void	flag_assign(t_list *stack_a)
{
	int		list_size;
	long	min_content;
	int		i;
	t_list	*min_node;

	if (stack_a == NULL)
		return ;
	list_size = ft_lstsize(stack_a);
	min_content = INT_MIN - 1;
	i = 0;
	while (i < list_size)
	{
		min_node = find_min_node(stack_a, min_content);
		min_node->flag = i;
		min_content = min_node->content;
		i++;
	}
}

int	is_sorted(t_list *stack_a, int min_flag)
{
	while (stack_a != NULL)
	{
		if (stack_a->flag != min_flag)
			return (0);
		stack_a = stack_a->next;
		min_flag++;
	}
	return (1);
}

void	radix_sort(t_list **stack_ap, t_list **stack_bp)
{
	int	stack_a_size;
	int	shift_counter;
	int	i;

	if (stack_ap == NULL || stack_bp == NULL || *stack_ap == NULL)
		return ;
	stack_a_size = ft_lstsize(*stack_ap);
	shift_counter = 0;
	while (is_sorted(*stack_ap, 0) == 0)
	{
		i = 0;
		while (i < stack_a_size)
		{
			if (((((*stack_ap)->flag) >> shift_counter) & 1) == 0)
				push_b(stack_ap, stack_bp);
			else
				rotate_a(stack_ap);
			i++;
		}
		while (*stack_bp != NULL)
			push_a(stack_ap, stack_bp);
		shift_counter++;
	}
}
