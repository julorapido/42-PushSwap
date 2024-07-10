/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:33:54 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/10 16:53:05 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_el
{
	int		index;
	int		cost;
	long	val_;
}	t_el;

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
	long			stack_i_max;
}	t_stack;


# define ABS(x) x < 0 ? -x : x

// t_stack.c
t_stack	*ft_stacknew(int value, t_stack *pre);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *head);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
long	ft_stacksize(t_stack *s);
void	printList(t_stack *head);
t_stack	**ft_stack_createCopy(t_stack **copy_from);
void	free_stack(t_stack **s);
void	printTList(t_stack **a, t_stack **b);
t_stack	*ft_stack_nth(t_stack **s, long v);

// operations
void	s_ab(t_stack **a_b, char *m);
void	p_ab(t_stack **from_, t_stack **to_, char *s);
void	rr_ab(t_stack **a_b, char *s);
void	r_ab(t_stack **a_b, char *s);
void	rrr_ab(t_stack **a, t_stack **b);
void	rvrr_ab(t_stack **a, t_stack **b);

// sort specifics
void	tw_n(t_stack **a);
void	th_n(t_stack **a);
void	qu_n(t_stack **a, t_stack **b);
void	cq_n(t_stack **a, t_stack **b);
void	insertion_sort(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);
void	alg(t_stack **a, t_stack **b);
void	insert_n(t_stack **a, t_stack **b, long spin, int enable_dblRt, long dbl_spin);
//void	insert_n(t_stack **a, t_stack **b, long spin, int enable_dblRt);
long	count_e(t_stack **b, long v_);
void	quick_sort(t_stack **a, t_stack **b);
long	count_e_alt(t_stack **b, long v_);

void	z_sort(t_stack **a, t_stack **b);

// utils
int		get_dist(t_stack **s, int ix);
int		is_sorted(t_stack **s);
void	index_stack(t_stack **s);
t_stack	*get_next_min(t_stack **s);
long	median(t_stack **a);

#endif
