/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:42:51 by akaratas          #+#    #+#             */
/*   Updated: 2024/03/20 15:34:21 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_size;

	if (argc >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		create_stack(argc, argv, &stack_a);
		flag_assign(stack_a);
		if (is_sorted(stack_a, 0) == 1)
			exit(0);
		stack_size = ft_lstsize(stack_a);
		if (stack_size == 2)
			two_argument_sort(&stack_a, 0);
		else if (stack_size == 3)
			three_argument_sort(&stack_a, 0, 2);
		else if (stack_size == 4)
			four_argument_sort(&stack_a, &stack_b, 0, 3);
		else if (stack_size == 5)
			five_argument_sort(&stack_a, &stack_b);
		else if (stack_size >= 6)
			radix_sort(&stack_a, &stack_b);
	}
}
