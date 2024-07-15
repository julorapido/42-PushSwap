/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:45:57 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/15 16:06:31 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_bbl_sort(t_stack **a, long *arr)
{
	t_stack	*h;
	long	i;
	long	j;
	long	temp;

	h = *a;
	i = 0;
	while (i < ft_stacksize(*a))
	{
		arr[i] = h->nbr;
		h = h->next;
		i++;
	}
	i = -1;
	while (i++ < ft_stacksize(*a) - 1)
	{
		j = -1;
		while (j++ < ft_stacksize(*a) - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

static long	indx_from_arr(long *arr, long en, long v__)
{
	long	i;

	i = 0;
	while (i < en)
	{
		if (v__ == arr[i])
			return (i);
		i++;
	}
	return (i);
}

static long	get_max_index(t_stack **b)
{
	t_stack	*h;
	long	n;
	long	j;
	long	v__j;

	j = 0;
	n = -10000000;
	h = *b;
	while (h)
	{
		if (h->nbr > n)
		{
			n = h->nbr;
			v__j = j;
		}
		j++;
		h = h->next;
	}
	return (v__j);
}

static long	get_max(t_stack **b)
{
	t_stack	*h;
	long	n;

	n = -10000000;
	h = *b;
	while (h)
	{
		if (h->nbr > n)
			n = h->nbr;
		h = h->next;
	}
	return (n);
}
/*
========================================================
1st of all
 - bubble sort el of Stack-A to get indexes
2nd go trough all el of Stack-A
 - let's check if does belong to the range or not.
========================================================
---------------------------------------------------
100 -> The range will be something similar to (0.15)
500 -> The range will be something similar to (0.30)
---------------------------------------------------

========================================================
If index top of STACK-A from sorted-stack is (<=) start ofrange :
	- pb element to STACK-B, rotate STACK-B, [increase++] start-end of range.
If index top of STACK-A from sorted-stack is [(>) start && (<) end range]
	- pb element to STACK-B, [increase++] start-end of range.
If index top of STACK-A from sorted-stack is (>=) to the end of the range :
	- ra top of STACK-A.
=================================================================

==============================================================================
Once STACK-A is empty we get back elements from STACK-B
	- but this time elments in B has a form of a mirror pyramid, 
	so all you have to do, is get the index of the max number in stack b
	- and check if the index is in the 2nd-half of STACK-B
	- then keep (rrb) the element until it reaches the top 
	--> then push it back to STACK-A (pa)
	--> otherwise (rb)
=============================================================================
*/

static void	back_in_a(t_stack **a, t_stack **b)
{
	long	l;
	t_stack	*h;

	h = *b;
	while (h)
	{
		l = get_max_index(b);
		if (l > ft_stacksize(*b) / 2)
		{
			while ((*b)->nbr != get_max(b))
			{
				rr_ab(b, "rrb\n");
				l--;
			}
		}
		else
		{
			while ((*b)->nbr != get_max(b))
			{
				r_ab(b, "rb\n");
				l--;
			}
		}
		p_ab(b, a, "pa\n");
		h = *b;
	}
}

void	z_sort(t_stack **a, t_stack **b, long range_start, long range_end)
{
	t_stack	*h;
	long	*stred_ar;
	long	len;

	len = ft_stacksize(*a);
	stred_ar = (long *) malloc(len * sizeof(long));
	init_bbl_sort(a, stred_ar);
	h = *a;
	while (h)
	{
		if (indx_from_arr(stred_ar, len, h->nbr) <= range_start)
		{
			p_ab(a, b, "pb\n");
			r_ab(b, "rb\n");
			range_start++;
			range_end++;
		}
		else if (indx_from_arr(stred_ar, len, h->nbr) > range_start &&
			indx_from_arr(stred_ar, len, h->nbr) < range_end)
		{
			p_ab(a, b, "pb\n");
			range_end++;
			range_start++;
		}
		else if (indx_from_arr(stred_ar, len, h->nbr) >= range_end)
			r_ab(a, "ra\n");
		h = *a;
	}
	back_in_a(a, b);
}
