/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:40:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/28 20:40:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_stack(t_stack *stack)
{
	return (stack_size(stack));
}

int	ft_chunk_size(int size)
{
	return (get_chunk_size(size));
}

int	ft_in_index(t_stack *stack, int target, int chunk_size)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index <= target + chunk_size)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

void	initindex(t_stack *stack, int *sorted_arr, int size)
{
	assign_indexes(stack, sorted_arr, size);
}

int	has_element_in_range(t_stack *stack, int min, int max)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index <= max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}