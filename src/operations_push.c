/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:00:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/29 11:52:35 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Helper function: Moves top element from one stack to another
** Example: A=[3,2,1] B=[6,5] → push(A,B) → A=[2,1] B=[3,6,5]
*/
static void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!*from)		// Do nothing if source stack is empty
		return ;
	tmp = *from;		// Save top element
	*from = (*from)->next;	// Remove from source
	tmp->next = *to;	// Link to destination top
	*to = tmp;		// Make it new top
}

/*
** pa: Push from B to A, prints "pa"
** Example: A=[2,1] B=[5,4] → pa → A=[5,2,1] B=[4] + prints "pa"
*/
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

/*
** pb: Push from A to B, prints "pb"
** Example: A=[3,2,1] B=[6] → pb → A=[2,1] B=[3,6] + prints "pb"
*/
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}