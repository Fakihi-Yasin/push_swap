/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafakihi <yafakihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:49:30 by yafakihi          #+#    #+#             */
/*   Updated: 2026/01/16 01:49:31 by yafakihi         ###   ########.fr       */
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

#endif /* PUSH_SWAP_H */
