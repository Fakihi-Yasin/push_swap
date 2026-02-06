/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_assembly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:50:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/31 22:46:24 by yafakihi         ###   ########.fr       */
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
** sort_large_stack: Main function for large stack sorting using shanks algorithm
** 1. Create sorted array and assign indexes
** 2. Use shanks algorithm to push elements to B
** 3. Sort remaining 3 elements in A
** 4. Push back from B to A in sorted order
*/
void	sort_large_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;
	int	*sorted_arr;
	int	remaining;

	size = stack_size(*a);
	chunk_size = get_chunk_size(size);
	
	/* Create sorted reference array */
	sorted_arr = create_sorted_array(*a, size); //return arr strted
	if (!sorted_arr)
		return;
	
	/* Assign indexes based on sorted position - required for shanks algorithm */
	initindex(*a, sorted_arr, size);
	free(sorted_arr);
	
	/* Use shanks algorithm to push elements to B */
	chunk_to_b(a, b, chunk_size, size);
	
	/* Sort remaining elements in A based on how many are left */
	remaining = stack_size(*a);
	if (remaining == 3)
		sort_3(a);
	else if (remaining == 2)
		sort_2(a);
	/* If remaining == 1 or 0, no sorting needed */
	
	/* Push back from B to A in sorted order */
	push_back_sorted(a, b);
}