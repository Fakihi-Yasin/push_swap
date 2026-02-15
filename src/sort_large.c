/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:40:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/14 14:14:50 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Shanks algorithm implementation - exactly 5 functions */

#include "push_swap.h"

/*
** Shanks algorithm - exact implementation as requested
*/
static int	find_index_pos(t_stack *stack, int min_idx, int max_idx)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index >= min_idx && tmp->index <= max_idx)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

void	chunk_to_b(t_stack **a, t_stack **b, int chunk_size, int size)
{
	int	i;

	(void)size;
	i = 0;
	
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else if (find_index_pos(*a, i, i + chunk_size) <= stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}

/*
** find_chunk_element_pos: Find position of element in chunk range
*/
// int	find_chunk_element_pos(t_stack *stack, int min, int max)
// {
// 	int		pos;
// 	t_stack	*tmp;

// 	pos = 0;
// 	tmp = stack;
// 	while (tmp)
// 	{
// 		if (tmp->index >= min && tmp->index <= max)
// 			return (pos);
// 		tmp = tmp->next;
// 		pos++;
// 	}
// 	return (0);
// }