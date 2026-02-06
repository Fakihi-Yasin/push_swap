/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:00:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/28 21:00:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**prepare_input(int argc, char **argv, int *count)
{
	char	**all_numbers;
	int		total_count;

	total_count = count_total_numbers(argc, argv);
	if (total_count == 0)
		return (NULL);
	all_numbers = allocate_and_collect(argc, argv, total_count);
	*count = total_count;
	return (all_numbers);
}

int	*validate_and_convert(char **split, int count, int argc)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (!is_valid_int(split[i]))
		{
			free(arr);
			free_split(split, argc);
			return (NULL);
		}
		arr[i] = (int)ft_atol(split[i]);
		i++;
	}
	if (has_duplicates(arr, count))
	{
		free(arr);
		free_split(split, argc);
		return (NULL);
	}
	return (arr);
}

int	create_stack_from_array(t_stack **a, int *arr, int count, char **split, int argc)
{
	int		i;
	t_stack	*node;

	i = 0;
	while (i < count)
	{
		node = new_node(arr[i]);
		if (!node)
		{
			free(arr);
			free_split(split, argc);
			return (0);
		}
		add_to_stack(a, node);
		i++;
	}
	free(arr);
	free_split(split, argc);
	return (1);
}

int	count_total_numbers(int argc, char **argv)
{
	char	**split;
	int		total_count;
	int		i;
	int		j;

	total_count = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			total_count++;
			j++;
		}
		free_temp_split(split);
		i++;
	}
	return (total_count);
}

char	**allocate_and_collect(int argc, char **argv, int total_count)
{
	char	**all_numbers;
	int		k;

	all_numbers = malloc(sizeof(char*) * (total_count + 1));
	if (!all_numbers)
		return (NULL);
	k = 0;
	if (!collect_all_numbers(argc, argv, all_numbers, &k))
	{
		free_partial_array(all_numbers, k);
		return (NULL);
	}
	all_numbers[k] = NULL;
	return (all_numbers);
}