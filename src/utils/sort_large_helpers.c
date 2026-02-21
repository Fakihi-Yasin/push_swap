/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:40:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/28 20:40:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
