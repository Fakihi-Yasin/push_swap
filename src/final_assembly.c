/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_assembly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:50:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/14 11:15:12 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack	*find_max_index(t_stack *stack)
{
	t_stack	*max;
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	max = stack;
	tmp = stack->next;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

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
	return (0);
}

void	move_to_top(t_stack **stack, t_stack *target)
{
	int	pos;
	int	size;

	pos = get_position(*stack, target);
	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (*stack != target)
			rb(stack);
	}
	else
	{
		while (*stack != target)
			rrb(stack);
	}
}

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

	size = stack_size(*a);
	sorted_arr = create_sorted_array(*a, size);
	if (!sorted_arr)
		return;
	assign_indexes(*a, sorted_arr, size);
	free(sorted_arr);
	chunk_size = get_chunk_size(size);
	chunk_to_b(a, b, chunk_size, size);
	push_back_sorted(a, b);
}
