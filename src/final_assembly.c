/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_assembly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:50:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/28 20:50:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* STEP 7: Final Assembly - Push back from B to A in descending order */

#include "push_swap.h"

/*
** push_back_sorted: Pushes all elements from B back to A in descending order
** Always pushes the maximum element first to maintain sorted order
*/
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

/*
** sort_large_stack: Main function for large stack sorting
** 1. Create sorted array and assign indexes
** 2. Push elements to B in chunks
** 3. Sort remaining 3 elements in A
** 4. Push back from B to A in sorted order
*/
void	sort_large_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;
	int	*sorted_arr;

	size = stack_size(*a);
	chunk_size = get_chunk_size(size);
	
	/* Create sorted reference array */
	sorted_arr = create_sorted_array(*a, size);
	if (!sorted_arr)
		return;
	
	/* Assign indexes based on sorted position */
	assign_indexes(*a, sorted_arr, size);
	free(sorted_arr);
	
	/* Push elements to B in chunks */
	chunk_to_b(a, b, chunk_size, size);
	
	/* Sort remaining 3 elements in A */
	sort_3(a);
	
	/* Push back from B to A in sorted order */
	push_back_sorted(a, b);
}