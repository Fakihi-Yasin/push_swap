/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:49:49 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/17 18:39:29 by yafakihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* Argument parsing */
int	parse_input(int argc, char **argv, t_stack **a, t_stack **b);

/* Stack utilities */
t_stack	*new_node(int content);
void	free_stacks(t_stack **a, t_stack **b);
int		stack_size(t_stack *stack);
t_stack	*find_last(t_stack *stack);
int		is_sorted(t_stack *stack);

/* Push swap operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Small sorts */
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);

/* General sort */
void	radix_sort(t_stack *a, t_stack *b, int size);

#endif /* PUSH_SWAP_H */
