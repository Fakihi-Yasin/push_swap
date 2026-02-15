/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:49:42 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/15 22:20:23 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	/* STEP 3: Added proper stack initialization */
	init_stacks(&a, &b);
	if (!parse_input(argc, argv, &a, &b))
	{
		free_stacks(&a, &b);
		write(2, "Error\n", 6);
		return (1);
	}
	/* STEP 3: Added early exit optimization - check if already sorted */
	if (is_sorted(a))
	{
		free_stacks(&a, &b);
		return (0);
	}
	/* STEP 4: Added sorting dispatch based on stack size */
	sort_stack(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
