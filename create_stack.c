/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:33:53 by akaratas          #+#    #+#             */
/*   Updated: 2024/03/20 15:57:40 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	create_stack(int argc, char **argv, t_list **stack_ap)
{
	int		i;
	char	**num_arr;
	int		j;
	long	num;
	t_list	*new_node;

	numeric_check(argc, argv);
	i = 1;
	while (i < argc)
	{
		num_arr = ft_split(argv[i], ' ');
		j = 0;
		while (num_arr[j] != 0)
		{
			num = ft_atoi(num_arr[j]);
			int_range_check(num);
			repeat_check(*stack_ap, num);
			new_node = ft_lstnew(num);
			ft_lstadd_back(stack_ap, new_node);
			j++;
		}
		memory_leak_check(num_arr);
		i++;
	}
}
