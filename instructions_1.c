/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:43:09 by akaratas          #+#    #+#             */
/*   Updated: 2024/03/20 15:45:10 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *lst)
{
	int	top1;
	int	top2;
	int	flag1;
	int	flag2;

	if (ft_lstsize(lst) <= 1)
		return ;
	top1 = lst->content;
	top2 = (lst->next)->content;
	flag1 = lst->flag;
	flag2 = (lst->next)->flag;
	lst->content = top2;
	(lst->next)->content = top1;
	lst->flag = flag2;
	(lst->next)->flag = flag1;
	write(1, "sa\n", 3);
}

void	swap_b(t_list *lst)
{
	int	top1;
	int	top2;
	int	flag1;
	int	flag2;

	if (ft_lstsize(lst) <= 1)
		return ;
	top1 = lst->content;
	top2 = (lst->next)->content;
	flag1 = lst->flag;
	flag2 = (lst->next)->flag;
	lst->content = top2;
	(lst->next)->content = top1;
	lst->flag = flag2;
	(lst->next)->flag = flag1;
	write(1, "sb\n", 3);
}

void	swap_ab(t_list *stack_a, t_list *stack_b)
{
	swap_a(stack_a);
	swap_a(stack_b);
}

void	push_a(t_list **stack_ap, t_list **stack_bp)
{
	t_list	*top_b;

	if (stack_ap == NULL || stack_bp == NULL || *stack_bp == NULL)
		return ;
	top_b = *stack_bp;
	*stack_bp = (*stack_bp)->next;
	ft_lstadd_front(stack_ap, top_b);
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_ap, t_list **stack_bp)
{
	t_list	*top_a;

	if (stack_ap == NULL || stack_bp == NULL || *stack_ap == NULL)
		return ;
	top_a = *stack_ap;
	*stack_ap = (*stack_ap)->next;
	ft_lstadd_front(stack_bp, top_a);
	write(1, "pb\n", 3);
}
