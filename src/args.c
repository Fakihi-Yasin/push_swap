/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:49:09 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/16 01:49:20 by yafakihi         ###   ########.fr       */
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
	int	i;
	long	num;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_input(int argc, char **argv, int *size)
{
	char	**split;
	int		i;
	int		*arr;
	int		count;

	if (argc == 1)
		return (NULL);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (NULL);
		count = 0;
		while (split[count])
			count++;
	}
	else
	{
		split = argv + 1;
		count = argc - 1;
	}
	if (count == 0)
		return (NULL);
	arr = malloc(sizeof(int) * count);
	if (!arr)
	{
		if (argc == 2)
		{
			int j = 0;
			while (split[j])
				free(split[j++]);
			free(split);
		}
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		if (!is_valid_int(split[i]))
		{
			free(arr);
			if (argc == 2)
			{
				int j = 0;
				while (split[j])
					free(split[j++]);
				free(split);
			}
			return (NULL);
		}
		arr[i] = ft_atol(split[i]);
		i++;
	}
	if (has_duplicates(arr, count))
	{
		free(arr);
		if (argc == 2)
		{
			int j = 0;
			while (split[j])
				free(split[j++]);
			free(split);
		}
		return (NULL);
	}
	if (argc == 2)
	{
		int j = 0;
		while (split[j])
			free(split[j++]);
		free(split);
	}
	*size = count;
	return (arr);
}
