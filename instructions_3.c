/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:20 by akaratas          #+#    #+#             */
/*   Updated: 2024/03/20 15:45:02 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **stack_ap)
{
	t_list	*last;
	t_list	*node_iterator;

	if (stack_ap == NULL || ft_lstsize(*stack_ap) <= 1)
		return ;
	last = ft_lstlast(*stack_ap);
	node_iterator = *stack_ap;
	while ((node_iterator->next)->next != NULL)
		node_iterator = node_iterator->next;
	node_iterator->next = NULL;
	ft_lstadd_front(stack_ap, last);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **stack_bp)
{
	t_list	*last;
	t_list	*node_iterator;

	if (stack_bp == NULL || ft_lstsize(*stack_bp) <= 1)
		return ;
	last = ft_lstlast(*stack_bp);
	node_iterator = *stack_bp;
	while ((node_iterator->next)->next != NULL)
		node_iterator = node_iterator->next;
	node_iterator->next = NULL;
	ft_lstadd_front(stack_bp, last);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_list **stack_ap, t_list **stack_bp)
{
	reverse_rotate_a(stack_ap);
	reverse_rotate_b(stack_bp);
}
