/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:49:42 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/16 01:49:43 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int	*arr;
	int	size;

	arr = parse_input(argc, argv, &size);
	if (!arr)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	free(arr);
	return (0);
}
