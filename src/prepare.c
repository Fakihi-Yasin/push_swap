/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:00:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/12 12:00:00 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
	}
}

int	has_duplicates(int *arr, int size)
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

static int	count_total(int argc, char **argv)
{
	char	**split;
	int		total;
	int		i;
	int		j;

	total = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j++])
			total++;
		j = 0;
		while (split[j])
			free(split[j++]);
		free(split);
		i++;
	}
	return (total);
}

static int	copy_split(char **all, char **split, int k)
{
	int	j;

	j = 0;
	while (split[j])
	{
		all[k] = ft_strdup(split[j]);
		if (!all[k])
		{
			while (k > 0)
				free(all[--k]);
			return (-1);
		}
		k++;
		j++;
	}
	return (k);
}

char	**prepare_input(int argc, char **argv, int *count)
{
	char	**all;
	char	**split;
	int		k;
	int		i;

	*count = count_total(argc, argv);
	if (*count <= 0)
		return (NULL);
	all = malloc(sizeof(char *) * (*count + 1));
	if (!all)
		return (NULL);
	k = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		if (!split)
			return (free(all), NULL);
		k = copy_split(all, split, k);
		free_split(split);
		if (k == -1)
			return (free(all), NULL);
	}
	all[k] = NULL;
	return (all);
}
