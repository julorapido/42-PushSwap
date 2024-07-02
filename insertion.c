/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:46:56 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/02 17:59:08 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	count_e(t_stack **b, long v_)
{
	t_stack	*h;
	long	j;
	long	v_i;

	j = 0;
	h = *b;
	v_i = h->nbr;
	while (h)
	{
		if (v_ >= h->nbr && v_<= v_i)
			return (j);
		j++;
		v_i = h->nbr;
		h = h->next;
	}	
	return (j);
}

static void	insert_x(t_stack **from, t_stack *x, t_stack **insert_to, int print)
{
	long	a;
	long	b;
	long	v_;

	if (x->nbr >= (*insert_to)->nbr)
		p_ab(from, insert_to, "pb\n");
	else
	{
		a = count_e(insert_to, x->nbr);
		b = 0;
		while (b < a)
		{
			r_ab(insert_to, "rb\n");
			b++;
		}
		p_ab(from, insert_to, "pb\n");
		while (b > 0)
		{
			rr_ab(insert_to, "rrb\n");
			b--;
		}
	}
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	int		i;
	int		y;
	int		z;
	t_stack	*h;
	p_ab(a, b, "pb\n");
	
	printf("======== A ========== \n");
	printList(*a);
	printf("======== B ========== \n");
	printList(*b);
	
	int	md_ = median(a);
	h = *a;
	int L = ft_stacksize(*a);
	for(int i = 0; i < L; i++)
	{
		if (h->nbr > md_)
			p_ab(a, b, "pb\n");
		h = *a;
	}
	while(*a)
		p_ab(a, b, "pa\n");

	h = *b;
	while (h)
	{
		insert_x(b, h, a, 1);
		h = *b;
	}
	//while (*b)
	//	p_ab(b, a, "pa\n");
}
