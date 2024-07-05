/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:20 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/05 17:16:54 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	min_max_s(t_stack **s, int is_min)
{
	t_stack *h;
	long	i;

	h = *s;
	i = -100000000;
	if (is_min == 1)
		i = 100000000;
	while (h)
	{
		if (is_min)
		{
			if (h->nbr < i)
				i = h->nbr;
		}
		else
		{
			if (h->nbr > i)
				i = h->nbr;
		}
		h = h->next;
	}
	return (i);
}


static long	calc_n_insertion(long v, t_stack **a, t_stack **b)
{
	if (v >= min_max_s(b, 0)) // MAX
		return (1);
	if (v <= min_max_s(b, 1)) // MIN
		return (2);

	long L = ft_stacksize(*b);
	long x = count_e(b, v); 
	
	if (x <= L / 2)
		return ((x * 2) + 1);
	else
		return (((ft_stacksize(*b) - x) * 2) + 2);
}


void	alg(t_stack **a, t_stack **b)
{
	t_stack *h;
	long	i;
	long	j;
	long	nth_;
	long	L;
	long	v;

	p_ab(a, b, "pb\n"); p_ab(a, b, "pb\n"); p_ab(a, b, "pb\n");
	th_n(b);
	rr_ab(b, "rrb\n");
	p_ab(b, a, "pa\n");
	rr_ab(b, "rrb\n");
	p_ab(a, b, "pb\n");

	i = 0;
	L = ft_stacksize(*a);
	while(i < L)
	{
		v = 1000000;
		j = 0;
		h = *a;
		//	printTList(a, b);
		while (h)
		{
			long c = calc_n_insertion(h->nbr, a, b);	
			long price = c + j;
			//printf("-insert %ld in B costs [%ld $] \n", h->nbr, price);
			if (price < v)
			{
				v = price;
				nth_ = j;
			}
			j++;
			h = h->next;
		}
		//printf(">> INSERT %ld-nth (%ld spin) << \n", nth_ + 1, nth_);	
		insert_n(a, b, nth_);
		i++;
	}
	//printTList(a, b);
	while (*b)
		p_ab(b, a, "pa\n");
	printTList(a, b);
}
