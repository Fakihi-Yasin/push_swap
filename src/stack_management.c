/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:20:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/28 19:20:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* STEP 3: Stack Management Functions - Added validation and utility functions */

#include "push_swap.h"

/*
** is_sorted: Checks if stack A is sorted in ascending order
** Returns 1 if sorted, 0 if not sorted
** Example: A=[1,2,3] → returns 1, A=[3,1,2] → returns 0
*/
int	is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

/*
** init_stacks: Initializes both stacks to NULL
** Used at program start to ensure clean state
*/
void	init_stacks(t_stack **a, t_stack **b)
{
	*a = NULL;
	*b = NULL;
}

/*
** stack_min: Finds the minimum value in a stack
** Returns the smallest content value in the stack
*/
int	stack_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

/*
** stack_max: Finds the maximum value in a stack
** Returns the largest content value in the stack
*/
int	stack_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

/*
** find_position: Finds the position of a value in the stack
** Returns position (0-based) or -1 if not found
*/
int	find_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->content == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}