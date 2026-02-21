/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_assembly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:50:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/21 14:42:22 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_sorted(t_stack **a, t_stack **b)
{
	t_stack	*max_node;

	while (*b)
	{
		max_node = find_max_index(*b);
		move_to_top(b, max_node);
		pa(a, b);
	}
}

void	sort_large_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;
	int	*sorted_arr;
	int	remaining;

	size = stack_size(*a);
	chunk_size = get_chunk_size(size);
	sorted_arr = create_sorted_array(*a, size);
	if (!sorted_arr)
		return ;
	assign_indexes(*a, sorted_arr, size);
	free(sorted_arr);
	chunk_to_b(a, b, chunk_size, size);
	remaining = stack_size(*a);
	if (remaining == 3)
		sort_3(a);
	else if (remaining == 2)
		sort_2(a);
	push_back_sorted(a, b);
}
