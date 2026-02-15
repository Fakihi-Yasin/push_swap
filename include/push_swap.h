/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:49:30 by yafakihi          #+#    #+#             */
/*   Updated: 2026/02/15 17:51:02 by yafakihi         ###   ########.fr       */
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
	int	content;
	int	index;
	struct s_stack	*next;
}	t_stack;

/* Argument parsing */
int	parse_input(int argc, char **argv, t_stack **a, t_stack **b);
<<<<<<< HEAD
long	ft_atol(const char *str);
char	**prepare_input(int argc, char **argv, int *count);
int	*validate_and_convert(char **split, int count, int argc);
int	create_stack_from_array(t_stack **a, int *arr, int count, char **split, int argc);
int	count_total_numbers(int argc, char **argv);
char	**allocate_and_collect(int argc, char **argv, int total_count);
int	collect_all_numbers(int argc, char **argv, char **all_numbers, int *k);
void	free_temp_split(char **split);
void	free_partial_array(char **arr, int count);
int	is_valid_int(const char *str);
void	free_split(char **split, int argc);
int	has_duplicates(int *arr, int size);
=======
char	**prepare_input(int argc, char **argv, int *count);
void	free_split(char **split);
int	has_duplicates(int *arr, int size);
long	ft_atol(const char *str);
>>>>>>> recovery-branch

/* Stack utilities */
t_stack	*new_node(int content);
void	add_to_stack(t_stack **stack, t_stack *new);
t_stack	*find_last(t_stack *stack);
void	free_stacks(t_stack **a, t_stack **b);
int	stack_size(t_stack *stack);

/* Stack management */
/* STEP 3: Added stack validation and utility functions */
int	is_sorted(t_stack *a);
void	init_stacks(t_stack **a, t_stack **b);
int	stack_min(t_stack *stack);
int	stack_max(t_stack *stack);
int	find_position(t_stack *stack, int value);

/* Sorting algorithms */
/* STEP 4: Added small sorting algorithms for 2-5 elements */
void	sort_2(t_stack **a);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);

/* Array utilities */
/* STEP 5: Added index assignment and array utilities */
int	*create_sorted_array(t_stack *stack, int size);
void	sort_array(int *arr, int size);
void	assign_indexes(t_stack *stack, int *sorted_arr, int size);
int	get_chunk_size(int size);

/* Large stack algorithm */
/* STEP 6: Added chunk sorting for large stacks */
void	chunk_to_b(t_stack **a, t_stack **b, int chunk_size, int size);
t_stack	*find_max_index(t_stack *stack);
int	get_position(t_stack *stack, t_stack *target);
void	move_to_top(t_stack **b, t_stack *target);
<<<<<<< HEAD
int	ft_len_stack(t_stack *stack);
int	ft_chunk_size(int size);
int	ft_in_index(t_stack *stack, int target, int chunk_size);
void	initindex(t_stack *stack, int *sorted_arr, int size);
int	has_element_in_range(t_stack *stack, int min, int max);
int	find_in_range_pos(t_stack *stack, int min, int max);
int	has_element_in_current_chunk(t_stack *stack, int min, int max);
int	find_chunk_element_pos(t_stack *stack, int min, int max);
=======
>>>>>>> recovery-branch

/* Final assembly */
/* STEP 7: Added final assembly functions */
void	push_back_sorted(t_stack **a, t_stack **b);
void	sort_large_stack(t_stack **a, t_stack **b);

/* Push operations */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* Swap operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* Rotate operations */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* Reverse rotate operations */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif /* PUSH_SWAP_H */
