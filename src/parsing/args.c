/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:49:09 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/19 18:10:13 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long			i;
	long			sign;
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
	arr = validate_and_convert(split, count, argc);
	if (!arr)
		return (0);
	if (!create_stack_from_array(a, arr, count))
	{
		free_split(split, argc);
		return (0);
	}
	free_split(split, argc);
	return (1);
}

int	is_empty_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
