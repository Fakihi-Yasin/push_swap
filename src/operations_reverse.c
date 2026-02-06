/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:00:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/24 22:00:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Helper function: Reverse rotates stack (bottom element goes to top)
** Example: Stack=[3,2,1] → reverse_rotate → Stack=[1,3,2]
*/
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)	// Need at least 2 elements
		return ;
	last = *stack;				// Start from top
	second_last = NULL;
	while (last->next)			// Find last and second_last
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;		// Disconnect last
	last->next = *stack;			// Last points to old top
	*stack = last;				// Last becomes new top
}

/*
** rra: Reverse rotate stack A (bottom to top), prints "rra"
** Example: A=[3,2,1] → rra → A=[1,3,2] + prints "rra"
*/
void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

/*
** rrb: Reverse rotate stack B (bottom to top), prints "rrb"
** Example: B=[6,5,4] → rrb → B=[4,6,5] + prints "rrb"
*/
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

/*
** rrr: Reverse rotate both stacks simultaneously, prints "rrr"
** Example: A=[3,2,1] B=[6,5] → rrr → A=[1,3,2] B=[5,6] + prints "rrr"
*/
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}