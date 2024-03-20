/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:18 by akaratas          #+#    #+#             */
/*   Updated: 2024/03/20 15:44:47 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_ap)
{
	t_list	*top_a;

	if (stack_ap == NULL || *stack_ap == NULL)
		return ;
	top_a = *stack_ap;
	*stack_ap = (*stack_ap)->next;
	top_a->next = NULL;
	ft_lstadd_back(stack_ap, top_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_bp)
{
	t_list	*top_b;

	if (stack_bp == NULL || *stack_bp == NULL)
		return ;
	top_b = *stack_bp;
	*stack_bp = (*stack_bp)->next;
	top_b->next = NULL;
	ft_lstadd_back(stack_bp, top_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_list **stack_ap, t_list **stack_bp)
{
	rotate_a(stack_ap);
	rotate_b(stack_bp);
}
