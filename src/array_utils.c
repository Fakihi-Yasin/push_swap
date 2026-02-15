/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:30:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/14 16:18:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* STEP 5: Index Assignment & Array Utilities - Prepare for chunk algorithm */

#include "push_swap.h"

/*
** create_sorted_array: Creates sorted copy of stack contents
** Used to assign indexes based on sorted position
*/
int	*create_sorted_array(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	t_stack	*tmp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	sort_array(arr, size);
	return (arr);
}

/*
** sort_array: Simple bubble sort for array
** Used to create sorted reference for index assignment
*/
void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/*
** assign_indexes: Assigns sorted position index to each stack element
** 0 = smallest, 1 = second smallest, etc.
*/
void	assign_indexes(t_stack *stack, int *sorted_arr, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == sorted_arr[i])
			{
				tmp->index = i;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

/*
** get_chunk_size: Calculates optimal chunk size based on stack size
** Smaller chunks for smaller stacks, larger for bigger stacks
*/
int	get_chunk_size(int size)
{
	if (size <= 10)
		return (5);
	else if (size <= 100)
		return (15);
	else
		return (30);
}