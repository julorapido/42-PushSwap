/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:46:56 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/04 14:15:01 by jsaintho         ###   ########.fr       */
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
		if (v_ >= h->nbr && v_ <= v_i)
			return (j);
		j++;
		v_i = h->nbr;
		h = h->next;
	}	
	return (j);
}

static void	i_x_stack_y(long a, t_stack **frm_, t_stack **to_)
{
	long	b;

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

static void	i_x_stack_z(int ll, long a, t_stack **frm_, t_stack **to_)
{
	long	b;

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

static void	insert_x(t_stack **from, t_stack *x, t_stack **insert_to, int L)
{
	long	a;
	int		ll;

	if (x->nbr >= (*insert_to)->nbr)
		p_ab(from, insert_to, "pb\n");
	else
	{
		ll = ft_stacksize(*insert_to);
		a = count_e(insert_to, x->nbr);
		if (a < (L / 2) - 1)
			i_x_stack_y(a, from, insert_to);
		else
			i_x_stack_z(ll, a, from, insert_to);
	}
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	int		l;
	int		*d;
	t_stack	*h;

	p_ab(a, b, "pb\n");
	l = ft_stacksize(*a);
	h = *a;
	d = malloc (1 * sizeof(int));
	*d = 0;
	while (h)
	{
		insert_x(a, h, b, l);
		h = *a;
	}
	while (*b)
		p_ab(b, a, "pa\n");
	free(d);
}
