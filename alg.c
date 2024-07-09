/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:20 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/09 17:26:04 by jsaintho         ###   ########.fr       */
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
	long	l;
	long	x;

	if (v >= min_max_s(b, 0)) // MAX
		return (1);
	if (v <= min_max_s(b, 1)) // MIN
		return (2);

	l = ft_stacksize(*b);
	x = count_e(b, v); 
	
	if (x <= l / 2)
		return ((x * 2) + 1);
	else
		return (((ft_stacksize(*b) - x) * 2) + 2);
}

/*
void	pre_tri(t_stack **a, t_stack **b)
{
	long L = (median(a));
	t_stack	*h;
	long	j;

	// printf("PRE-TRI %ld \n", median(a));
	while (h)
	{
		if (h->nbr <= L)
		{
			p_ab(a, b, "pb\n");
			r_ab(b, "rb\n");
		}else
		{
			p_ab(a, b, "pb\n");
		}
		h = *a;
	}
	while (*b)
		p_ab(b, a, "pa\n");
}*/

void	alg(t_stack **a, t_stack **b)
{
	t_stack *h;
	long	i;
	long	j;
	long	nth_;
	long	L;
	long	v;
	int		oo;


	oo = 7;
	//printf("PREEEE TRIII \n");
	printTList(a, b);
	//pre_tri(a, b);
	//while (*b)
	//	p_ab(b, a, "pa\n");
	p_ab(a, b, "pb\n"); p_ab(a, b, "pb\n"); p_ab(a, b, "pb\n");
	th_n(b);
	rr_ab(b, "rrb\n");
	p_ab(b, a, "pa\n");
	rr_ab(b, "rrb\n");
	p_ab(a, b, "pb\n");
	
	printTList(a, b);
	i = 0;
	L = ft_stacksize(*a);
	while(i < L)
	{
		v = 1000000;
		j = 0;
		h = *a;
		printTList(a, b);
		long price;
		int insert_and_spin_top;
		long double_spin;
		while (h)
		{
			insert_and_spin_top = ( ((j <= ft_stacksize(*a) / 2) && (count_e(b, h->nbr) <= ft_stacksize(*b) / 2)))
						|| 
				(( (j > ft_stacksize(*a) / 2) && (count_e(b, h->nbr) > ft_stacksize(*b) / 2)))
				? 1 : 0;
			long c = calc_n_insertion(h->nbr, a, b);
			long d = ( j <= ft_stacksize(*a) / 2 ?  (j) : (ft_stacksize(*a) - j) );

			price = c + d;
			double_spin = 0;
			if (insert_and_spin_top == 1 && price > 2)
			{
				long rest = (c - 1) / 2;
				double_spin = rest;
				if (c > d)
					double_spin = ((c - 1) / 2) >= d ? d : ((c - 1) / 2);
			}
			price = (c + d) - double_spin;
			printf("-insert %ld in-B costs |%d| [%ld $] (%ld spin && ct_e %ld) %ld \n",
					h->nbr, insert_and_spin_top, price - double_spin, d, c, double_spin);
			if (price < v)
			{
				v = price;
				nth_ = d;
			}
			j++;
			h = h->next;
		}
		printf(">>>> INSERT [%ld-nth] (%ld spin & %ld dbl_spin) <<<<< \n",  nth_ + 1, nth_, double_spin);	
		oo += v;
		insert_n(a, b, nth_, (j <= (ft_stacksize(*a) / 2)) ? (1) : (0), double_spin);
		i++;
	}
	while (*b)
	{
		p_ab(b, a, "pa\n");
		oo++;
	}
	printTList(a, b);
	printf("%d OPERATIONS \n", oo);
}
