/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:00:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/18 10:03:19 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

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
