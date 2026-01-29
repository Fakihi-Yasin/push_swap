/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:00:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/24 22:00:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Helper function: Swaps the first two elements of a stack
** Example: Stack=[3,2,1] → swap → Stack=[2,3,1]
*/
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)	// Need at least 2 elements
		return ;
	first = *stack;			// Save first element
	second = (*stack)->next;		// Save second element
	first->next = second->next;		// First points to third
	second->next = first;			// Second points to first
	*stack = second;			// Second becomes new top
}

/*
** sa: Swap top two elements in stack A, prints "sa"
** Example: A=[3,2,1] → sa → A=[2,3,1] + prints "sa"
*/
void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/*
** sb: Swap top two elements in stack B, prints "sb"
** Example: B=[6,5,4] → sb → B=[5,6,4] + prints "sb"
*/
void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/*
** ss: Swap both stacks simultaneously, prints "ss"
** Example: A=[3,2,1] B=[6,5] → ss → A=[2,3,1] B=[5,6] + prints "ss"
*/
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}