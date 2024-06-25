/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:33:54 by jsaintho          #+#    #+#             */
/*   Updated: 2024/06/25 15:46:23 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>


typedef unsigned long int	t_uli_;

typedef struct info_st
{
		t_uli_	a;
		t_uli_	b;
}		info_t;

typedef struct s_stack
{
		long nbr;
		long index;
		struct s_stack* next;
		struct s_stack* prev;
		long	stack_i_max;
}		t_stack;

// t_stack.c
t_stack	*ft_lstnew(int value);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
int		ft_lstsize(t_stack *head);
void	printList(t_stack *head);


// operations
void	s_ab(t_stack **a_b);
void	p_ab(t_stack **from_, t_stack **to_);
void	rr_ab(t_stack **a_b);
void	r_ab(t_stack **a_b);

// sort
void	tw_n(t_stack **a);
void	th_n(t_stack **a);

// radix
void	radix_sort(t_stack **a, t_stack **b);

#endif
