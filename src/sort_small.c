/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:00:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/13 12:50:13 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* STEP 4: Small Sorting Algorithms - Hardcoded optimal solutions for 2-5 elements */

#include "push_swap.h"

/*
** sort_2: Sorts 2 elements - simple swap if needed
** Example: A=[2,1] → sa → A=[1,2]
*/
void	sort_2(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

/*
** sort_3: Sorts 3 elements - hardcoded optimal cases
** Handles all 6 possible permutations with minimal operations
*/
void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;

	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

/*
** sort_4: Sorts 4 elements - move min to B, sort 3, push back
** Strategy: Isolate smallest, sort remaining 3, reassemble
*/
void	sort_4(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	min = stack_min(*a);
	pos = find_position(*a, min);

	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
		rra(a);
	
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

static void	move_min_to_top(t_stack **a, int pos)
{
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
	{
		rra(a);
		rra(a);
	}
	else if (pos == 4)
		rra(a);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	min = stack_min(*a);
	pos = find_position(*a, min);
	move_min_to_top(a, pos);
	pb(a, b);
	min = stack_min(*a);
	pos = find_position(*a, min);
	if (pos <= 2)
		while (pos--)
			ra(a);
	else if (pos == 3)
		rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
