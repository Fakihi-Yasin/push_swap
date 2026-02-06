/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:00:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/24 22:00:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Helper function: Rotates stack up (top element goes to bottom)
** Example: Stack=[3,2,1] → rotate → Stack=[2,1,3]
*/
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)	// Need at least 2 elements
		return ;
	first = *stack;			// Save top element
	last = find_last(*stack);		// Find last element
	*stack = first->next;			// Second becomes new top
	first->next = NULL;			// Disconnect first
	last->next = first;			// Attach first to end
}

/*
** ra: Rotate stack A up, prints "ra"
** Example: A=[3,2,1] → ra → A=[2,1,3] + prints "ra"
*/
void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/*
** rb: Rotate stack B up, prints "rb"
** Example: B=[6,5,4] → rb → B=[5,4,6] + prints "rb"
*/
void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/*
** rr: Rotate both stacks up simultaneously, prints "rr"
** Example: A=[3,2,1] B=[6,5] → rr → A=[2,1,3] B=[5,6] + prints "rr"
*/
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}