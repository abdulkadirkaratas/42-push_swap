/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:55:36 by akaratas          #+#    #+#             */
/*   Updated: 2024/03/20 15:56:02 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	space_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != ' ')
			return ;
		i++;
	}
	error();
}

void	numeric_check(int argc, char **argv)
{
	int		i;
	char	*str;
	int		j;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		space_check(str);
		j = 0;
		while (str[j] != 0)
		{
			if (str[j] == '-' && (str[j + 1] >= '0' && str[j + 1] <= '9'))
			{
				j++;
				continue ;
			}
			else if (!((str[j] >= '0' && str[j] <= '9') || str[j] == ' '))
				error();
			j++;
		}
		i++;
	}
}

void	repeat_check(t_list *lst, int num)
{
	while (lst != NULL)
	{
		if (lst->content == num)
			error();
		lst = lst->next;
	}
}

void	int_range_check(long num)
{
	if ((num < -2147483648) || (num > 2147483647))
		error();
}

void	memory_leak_check(char **num_arr)
{
	int	i;

	i = 0;
	while (num_arr[i] != 0)
	{
		free(num_arr[i]);
		i++;
	}
	free(num_arr);
}
