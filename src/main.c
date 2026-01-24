/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:49:42 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/24 21:36:34 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_input(argc, argv, &a, &b))
	{
		free_stacks(&a, &b);
		write(2, "Error\n", 6);
		return (1);
	}
	// TODO: Add sorting logic here
	free_stacks(&a, &b);
	return (0);
}
