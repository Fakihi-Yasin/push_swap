/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:49:49 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/16 01:49:50 by yafakihi         ###   ########.fr       */
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
	int	*data;
	int	size;
	int	capacity;
}	t_stack;

/* Argument parsing */
int	*parse_input(int argc, char **argv, int *size);

/* Stack operations */
t_stack	*stack_init(int capacity);
void	stack_free(t_stack *stack);
int		stack_push(t_stack *stack, int value);
int		stack_pop(t_stack *stack);
int		stack_peek(t_stack *stack);
int		stack_is_empty(t_stack *stack);

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
