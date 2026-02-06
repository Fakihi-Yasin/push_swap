/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:40:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/28 20:40:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Shanks algorithm implementation - exactly 5 functions */

#include "push_swap.h"

/*
** Shanks algorithm - exact implementation as requested
*/
void	chunk_to_b(t_stack **a, t_stack **b, int chunk_size, int size)
{
	int	i;

	(void)size;
	(void)chunk_size;
	chunk_size = ft_chunk_size(ft_len_stack(*a));
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
		else if (ft_in_index(*a, i, chunk_size) <= ft_len_stack(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}

/*
** find_chunk_element_pos: Find position of element in chunk range
*/
int	find_chunk_element_pos(t_stack *stack, int min, int max)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index <= max)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (0);
}