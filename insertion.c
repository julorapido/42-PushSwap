/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:46:56 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/01 17:51:28 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ===================
//      QUICK SORT
// ===================
// - use median as the pivot
// - USE STACK B FOR VALUES LOWER THAN STACK-A MEDIAN
// === QUICK SORT A ===
// -I   Find median of [len] top numbers in STACK-A (for 1st iteration, [len] = [number of numbers] in list)
// -II  For [len] top numbers in list : 
//			- push those which are smaller than [median] onto STACK-B
//			- else rotate STACK-A (to go to next value)
// -III Use QuickSortA on [len / 2] elements left in STACK-A
// -IV  Use QuickSortB on [len / 2] elements left in STACK-B
//
// === QUICK SORT B ===
// -I   Find median of [len] top numbers in STACK-B (for 1st iteration, [len] = [(number of numbers) / 2] in list)
// -II  For [len] top numbers of stack :
//			- push those which are higher than the [median] onto STACK-A
// 			- else rotate STACK-B (to go to next value)
// -III Use QuickSortA on [len / 2] elements pushed in STACK-A
// -IV  Use QuickSortB on [len / 2] elements left in STACK-B

/*int	quick_sort_b(t_stack **a, t_stack **b, int len)
{
	int		len_l;
	long	median_v;
	int		push_under;

	push_under = 0;
	len_l = len;
	if (is_sorted(b))
	{
		while(*b)
			p_ab(b, a, "pa\n");
	}
	if (len <= 3)
	{
		th_n(b);
		return (1);
	}
	median_v = median(b);
	printf("MEDIAN [%ld] \n", median(b));
	while (len != len_l / 2)
	{p_ab(a, b, "pb\n")
		if ((*b)->nbr < median_v)
			p_ab(b, a, "pa\n");
		else if (push_under++)
			r_ab(b, "rb\n");
		len--;
	}
	while (push_under > 0)
	{
			rr_ab(b, "rrb\n");
			push_under --;
	}
	return (quick_sort_a(a, b, len_l / 2 + len % 2) && quick_sort_b(a, b, len_l / 2));
}

int	quick_sort_a(t_stack **a, t_stack **b, int len)
{
	int		len_l;
	long	median_v;
	int		push_under;

	push_under = 0;
	if (is_sorted(a))
		return (1);
	len_l = len;
	if(len <= 3 && (len_l = len))
	{
		th_n(a);
		return (1);
	}

	median_v = median(a);
	printf("MEDIAN [%ld] \n", median(a));
	while (len != len_l / 2 + len_l % 2)
	{
		if ((*a)->nbr < median_v )
			p_ab(a, b, "pb\n");
		else{
			push_under++;
			r_ab(a, "ra\n");
		}
		len--;
	}
	while (push_under > 0){
		rr_ab(a, "rra\n");
		push_under--;
	}	//printf("== %ld vs %ld ==", h->nbr, (*b)->nbr);

	return (quick_sort_a(a, b, len_l / 2 + len_l % 2) && quick_sort_b(a, b, len_l / 2));
	return (1);
}*/

int	count_e(t_stack **b, long v_)
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

void	insertion_sort(t_stack **a, t_stack **b)
{
	t_stack	*h;
	long	j;
	long	k;

	p_ab(a, b, "pb\n");
	h = *a;
	while (h)
	{
		if (h->nbr >= (*b)->nbr)
			p_ab(a, b, "pb\n");
		else
		{
			k = 0;
			j = count_e(b, (*a)->nbr);
			while (k < j)
			{
				r_ab(b, "rb\n");
				k++;
			}
			p_ab(a, b, "pb\n");
			while (k > 0)
			{
				rr_ab(b, "rrb\n");
				k--;
			}
		}
		h = *a;
	}
	while (*b)
		p_ab(b, a, "pa\n");
}
