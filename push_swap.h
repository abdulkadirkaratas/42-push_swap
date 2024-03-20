/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:42:41 by akaratas          #+#    #+#             */
/*   Updated: 2024/03/20 16:02:28 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

void	create_stack(int argc, char **argv, t_list **stack_ap);
void	error(void);
void	space_check(char *str);
void	numeric_check(int argc, char **argv);
void	repeat_check(t_list *lst, int num);
void	int_range_check(long num);
void	memory_leak_check(char **num_arr);

void	swap_a(t_list *lst);
void	swap_b(t_list *lst);
void	swap_ab(t_list *stack_a, t_list *stack_b);

void	push_a(t_list **stack_ap, t_list **stack_bp);
void	push_b(t_list **stack_ap, t_list **stack_bp);

void	rotate_a(t_list **stack_ap);
void	rotate_b(t_list **stack_bp);
void	rotate_ab(t_list **stack_ap, t_list **stack_bp);

void	reverse_rotate_a(t_list **stack_ap);
void	reverse_rotate_b(t_list **stack_bp);
void	reverse_rotate_ab(t_list **stack_ap, t_list **stack_bp);

void	flag_assign(t_list *stack_a);
int		is_sorted(t_list *stack_a, int min_flag);
void	radix_sort(t_list **stack_ap, t_list **stack_bp);

void	two_argument_sort(t_list **stack_ap, int min_flag);
void	three_argument_sort(t_list **stack_ap, int min_flag, int max_flag);
void	four_argument_sort(t_list **stack_ap, t_list **stack_bp, int min_flag,
			int max_flag);
void	five_argument_sort(t_list **stack_ap, t_list **stack_bp);

#endif
