/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:45:57 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/10 18:13:34 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	init_bbl_sort(t_stack **a, long *arr)
{
	t_stack *h;
	long	i;
	long	j;
	long	temp;

	h = *a;
	i = 0;
	while (i < ft_stacksize(*a))
	{
		arr[i] = h->nbr;
		i++;
		h = h->next;
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
	/*for(int i = 0; i < ft_stacksize(*a); i++)
		printf("%ld \n", arr[i]);
	printf("\n");*/
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
	long	j;

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
1st of all, after parsing the arguments into the stack a and checking if there is a weird character rather than a number,
we should create another stack that has the elements from the origin stack,
but this time the temporary stack should have the elements sorted (I have used the bubble sort to sort them).

secondly, hold the top of stack a and get its index from the sorted stack once you have it, 
let's check if does belong to the range or not.
========================================================
	printf("ANY SWAP ? %ld \n", arr[i])
---------------------------------------------------
100 -> The range will be something similar to (0.15)
500 -> The range will be something similar to (0.30)
---------------------------------------------------

==========================================================================
If the index of the top of STACK-A from the sorted stack is (<=) than start of the range :
	- pb element to STACK-B, rotate the STACK-B, [increase++] start && end of range by 1.
If the index of the top of STACK-A from the sorted stack is [(>) than start && (<) than end of range] :
	- pb element to STACK-B, [increase++] start && end of range by 1.
If the index of the top of STACK-A from the sorted stack is (>=) to the end of the range :
	- ra top of STACK-A.
======================================================================================================

===========================================================================================================
Once STACK-A is empty we get back elements from STACK-B
	- but this time elments in B has a form of a mirror pyramid, so all you have to do, is get the index of the max number in stack b
	- and check if the index is in the 2nd-half of STACK-B
	- then keep (rrb) the element until it reaches the top 
	--> then push it back to STACK-A (pa)
	--> otherwise (rb)
============================================================================================================

*/

void	z_sort(t_stack **a, t_stack **b)
{
	t_stack	*h;
	long	*stred_ar;
	long	range_end, range_start;
	long	len;
	int		oo;

	len = ft_stacksize(*a);
	stred_ar = (long *) malloc(len * sizeof(long));
	range_start = 0;
	range_end = 15;
	if (ft_stacksize(*a) > 100)
		range_start = 30;
	//printf("%ld arr \n", len);
	init_bbl_sort(a, stred_ar);

	oo = 0;
	h = *a;
	while (h)
	{
		if (indx_from_arr(stred_ar, len, h->nbr) <= range_start)
		{
			p_ab(a, b, "pb\n");
			r_ab(b, "rb\n");
			range_start++;
			range_end++;
			oo += 2;
		}else if (
			indx_from_arr(stred_ar, len, h->nbr) > range_start && 
			indx_from_arr(stred_ar, len, h->nbr) < range_end
		)
		{
			p_ab(a, b, "pb\n");
			range_end++;
			range_start++;
			oo++;
		}else if (indx_from_arr(stred_ar, len, h->nbr) >= range_end)
		{
			r_ab(a, "ra\n");
			oo++;
		}
		h = *a;
	}
	long l;
	l = get_max_index(b);
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
		}else
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
	/*printTList(a, b);
	printf("SORT LIST %d \n", oo);*/
}
