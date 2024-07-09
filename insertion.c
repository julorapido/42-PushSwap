/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:46:56 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/09 17:20:18 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	count_e(t_stack **b, long v_)
{
	t_stack	*h;
	long	j;
	long	v_i;

	if (v_ >= (*b)->nbr)
		return (0);
	j = 0;
	h = *b;
	v_i = h->nbr; 
	while (h)
	{
		if (v_ >= h->nbr && v_ <= v_i)
			return (j);
		j++;
		v_i = h->nbr;
		h = h->next;
	}	
	return (j);
}

void	ins_top(long a, t_stack **frm_, t_stack **to_)
{
	long	b;

	if ((*frm_)->nbr >= (*to_)->nbr)
	{
		p_ab(frm_, to_, "pb\n");
		return ;
	}
	b = 0;
	while (b < a)
	{
		r_ab(to_, "rb\n");
		b++;
	}
	p_ab(frm_, to_, "pb\n");
	while (b > 0)
	{
		rr_ab(to_, "rrb\n");
		b--;
	}
}

void	ins_bot(long a, t_stack **frm_, t_stack **to_)
{
	long	b;
	long	ll;

	ll = ft_stacksize(*to_);
	b = (ll - a);
	while (b > 0)
	{
		rr_ab(to_, "rrb\n");
		b--;
	}
	p_ab(frm_, to_, "pb\n");
	while (b < (ll - a) + 1)
	{
		r_ab(to_, "rb\n");
		b++;
	}
}

void	insert_n(t_stack **a, t_stack **b, long spin, int insert_top, long dbl_spin)
{
	long	c;
	long	c_;

	c = c_ = count_e(b, (*a)->nbr);
	if (insert_top)
	{
		while (spin > 0)
		{
			r_ab(a, "ra\n");
			spin--;
		}
	}
	else
	{
		spin = ABS(ft_stacksize(*a) - spin);
		while (spin > 0)
		{
			rr_ab(a, "rra\n");
			spin--;
		}		
	}
	c = count_e(b, (*a)->nbr);
	if (c_ <= ft_stacksize(*b) / 2)
		ins_top(c, a, b);
	else
		ins_bot(c, a, b);
}	
