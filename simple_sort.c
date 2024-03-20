/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:17:56 by akaratas          #+#    #+#             */
/*   Updated: 2024/03/20 15:18:21 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_argument_sort(t_list **stack_ap, int min_flag)
{
	if (!(is_sorted(*stack_ap, min_flag)))
		swap_a(*stack_ap);
}

void	three_argument_sort(t_list **stack_ap, int min_flag, int max_flag)
{
	if ((*stack_ap)->flag == max_flag)
		rotate_a(stack_ap);
	else if (((*stack_ap)->next)->flag == max_flag)
		reverse_rotate_a(stack_ap);
	two_argument_sort(stack_ap, min_flag);
}

void	four_argument_sort(t_list **stack_ap, t_list **stack_bp, int min_flag,
		int max_flag)
{
	if (((*stack_ap)->next)->flag == min_flag)
		swap_a(*stack_ap);
	else if ((((*stack_ap)->next)->next)->flag == min_flag)
	{
		rotate_a(stack_ap);
		rotate_a(stack_ap);
	}
	else if (((((*stack_ap)->next)->next)->next)->flag == min_flag)
		reverse_rotate_a(stack_ap);
	if (is_sorted(*stack_ap, min_flag))
		return ;
	push_b(stack_ap, stack_bp);
	three_argument_sort(stack_ap, (min_flag + 1), max_flag);
	push_a(stack_ap, stack_bp);
}

void	five_argument_sort(t_list **stack_ap, t_list **stack_bp)
{
	if (((*stack_ap)->next)->flag == 0)
		swap_a(*stack_ap);
	else if ((((*stack_ap)->next)->next)->flag == 0)
	{
		rotate_a(stack_ap);
		rotate_a(stack_ap);
	}
	else if (((((*stack_ap)->next)->next)->next)->flag == 0)
	{
		reverse_rotate_a(stack_ap);
		reverse_rotate_a(stack_ap);
	}
	else if ((((((*stack_ap)->next)->next)->next)->next)->flag == 0)
		reverse_rotate_a(stack_ap);
	if (is_sorted(*stack_ap, 0))
		return ;
	push_b(stack_ap, stack_bp);
	four_argument_sort(stack_ap, stack_bp, 1, 4);
	push_a(stack_ap, stack_bp);
}
