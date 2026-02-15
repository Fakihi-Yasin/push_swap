/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:49:09 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/13 10:32:54 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long				i;
	long				sign;
	unsigned long	result;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

static int	is_valid_int(const char *str)
{
	long	num;
	int		i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

static int	validate_and_convert(char **split, int *arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_valid_int(split[i]))
			return (0);
		arr[i] = (int)ft_atol(split[i]);
		i++;
	}
	return (1);
}

static int	build_stack(t_stack **a, int *arr, int count)
{
	t_stack	*node;
	int		i;

	i = 0;
	while (i < count)
	{
		node = new_node(arr[i]);
		if (!node)
			return (0);
		add_to_stack(a, node);
		i++;
	}
	return (1);
}

int	parse_input(int argc, char **argv, t_stack **a, t_stack **b)
{
	char	**split;
	int		count;
	int		*arr;

	if (argc == 1)
		return (0);
	*b = NULL;
	split = prepare_input(argc, argv, &count);
	if (!split)
		return (0);
	arr = malloc(sizeof(int) * count);
	if (!arr || !validate_and_convert(split, arr, count)
		|| has_duplicates(arr, count) || !build_stack(a, arr, count))
	{
		free(arr);
		free_split(split);
		return (0);
	}
	free(arr);
	free_split(split);
	return (1);
}
