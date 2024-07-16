/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:45:57 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/16 16:15:56 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bbl_sort(t_stack **a, long *arr, long i)
{
	t_stack	*h;
	long	j;
	long	temp;

	h = *a;
	while (i++ < ft_stacksize(*a) - 1)
	{
		arr[i] = h->nbr;
		h = h->next;
	}
	i = -1;
	while (i++ < ft_stacksize(*a) - 2)
	{
		j = -1;
		while (j++ < ft_stacksize(*a) - i - 2)
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

void	back_in_a(t_stack **a, t_stack **b)
{
	long	l;

	while (*b)
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
	}
}

void	xd(long *s, long *e)
{
	*e = (*e) + 1;
	*s = (*s) + 1;
}

void	z_sort(t_stack **a, t_stack **b, long *range_start, long *range_end)
{
	long	*stred_ar;
	long	len;

	len = ft_stacksize(*a);
	stred_ar = (long *) ft_calloc(len, sizeof(long));
	init_bbl_sort(a, stred_ar, -1);
	while (*a)
	{
		if (indx_from_arr(stred_ar, len, (*a)->nbr) <= *range_start)
		{
			p_ab(a, b, "pb\n");
			r_ab(b, "rb\n");
			xd(range_start, range_end);
		}
		else if (indx_from_arr(stred_ar, len, (*a)->nbr) > *range_start
			&& indx_from_arr(stred_ar, len, (*a)->nbr) < *range_end)
		{
			p_ab(a, b, "pb\n");
			xd(range_start, range_end);
		}
		else if (indx_from_arr(stred_ar, len, (*a)->nbr) >= *range_end)
			r_ab(a, "ra\n");
	}
	back_in_a(a, b);
	free(stred_ar);
}
