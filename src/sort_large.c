/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:40:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/28 20:40:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* STEP 6: Large Stack Algorithm - Chunk sorting for 6+ elements */

#include "push_swap.h"

/*
** chunk_to_b: Pushes elements to B in chunks based on their index
** Elements with smaller indexes go to B first
*/
void	chunk_to_b(t_stack **a, t_stack **b, int chunk_size, int size)
{
	int	pushed;
	int	current_chunk;

	pushed = 0;
	current_chunk = 0;
	
	while (pushed < size - 3)
	{
		if ((*a)->index <= current_chunk)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}
		else if ((*a)->index <= current_chunk + chunk_size)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		
		if (pushed == current_chunk + chunk_size + 1)
			current_chunk += chunk_size;
	}
}

/*
** find_max_index: Finds the node with maximum index in stack B
** Used to determine which element to push back first
*/
t_stack	*find_max_index(t_stack *stack)
{
	t_stack	*max_node;
	int		max_index;

	if (!stack)
		return (NULL);
	max_node = stack;
	max_index = stack->index;
	
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

/*
** get_position: Gets position of a node in the stack
** Returns 0-based position from top
*/
int	get_position(t_stack *stack, t_stack *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

/*
** move_to_top: Moves target node to top of stack B
** Chooses shortest path (rotate or reverse rotate)
*/
void	move_to_top(t_stack **b, t_stack *target)
{
	int	pos;
	int	size;

	pos = get_position(*b, target);
	size = stack_size(*b);
	
	if (pos <= size / 2)
	{
		while (*b != target)
			rb(b);
	}
	else
	{
		while (*b != target)
			rrb(b);
	}
}