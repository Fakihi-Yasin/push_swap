/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:10:00 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/15 17:44:59 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* STEP 4: Sorting Dispatch - Routes to appropriate algorithm based on size */

#include "push_swap.h"

/*
** sort_stack: Main sorting dispatcher
** Routes to appropriate algorithm based on stack size:
** - 2 elements: sort_2() - simple swap
** - 3 elements: sort_3() - hardcoded cases  
** - 4 elements: sort_4() - move min, sort 3
** - 5 elements: sort_5() - move 2 min, sort 3
** - 6+ elements: TODO - chunk algorithm
*/
void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else
	{
		sort_large_stack(a, b);
	}
}