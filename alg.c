/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:20 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/15 15:38:17 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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
	x = count_e_alt(b, v); 
	
	if (x <= l / 2)
		return x + 1; //((x * 2) + 1);
	else
		return (((ft_stacksize(*b) - x)) + 2);
			//(((ft_stacksize(*b) - x) * 2) + 2);
}


void	pre_tri(t_stack **a, t_stack **b)
{
	long L = (median(a));
	t_stack	*h;
	long	j;

	while (h)
	{
		if (h->nbr <= L)
		{
			p_ab(a, b, "");
			r_ab(b, "");
		}else
		{
			p_ab(a, b, "");
		}
		h = *a;
	}
	while (*b)
		p_ab(b, a, "");
}

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
	printf("PREEEE TRIII \n");
	printTList(a, b);
	pre_tri(a, b);
	printTList(a, b);
	p_ab(a, b, "pb\n"); p_ab(a, b, "pb\n"); p_ab(a, b, "pb\n");
	th_n(b);
	rr_ab(b, "rrb\n");
	p_ab(b, a, "pa\n");
	rr_ab(b, "rrb\n");
	p_ab(a, b, "pb\n");
	
	printTList(a, b);
	i = 0;
	L = ft_stacksize(*a);
	while(i < L - 3)
	{
		v = 1000000;
		j = 0;
		h = *a;
		//printTList(a, b);
		long price;
		int insert_and_spin_top;
		long double_spin, saved_dblSpin = 0;
		while (h)
		{
			insert_and_spin_top = ( ((j <= ft_stacksize(*a) / 2) && 
						(count_e(b, h->nbr) <= ft_stacksize(*b) / 2)))
						|| 
				(( (j > ft_stacksize(*a) / 2) && 
				   	(count_e(b, h->nbr) > ft_stacksize(*b) / 2)))
				? 1 : 0;
			long c = calc_n_insertion(h->nbr, a, b);
			long d = ( j <= ft_stacksize(*a) / 2 ?  
					(j) : (ft_stacksize(*a) - j) );
			price = c + d;
			double_spin = 0;
			if (insert_and_spin_top && price > 2)
			{
				double_spin = (c - 1) / 2;
				if (c > d)
					double_spin = ((c - 1) / 2) >= d ? d : ((c - 1) / 2);
			}
			//printf("-insert %ld in-B costs |%d| .
					[%ld $] (%ld spin && ct_e %ld) %ld \n",
			//		h->nbr, insert_and_spin_top,
					price - double_s//if ((c + d) - double_spin < price)
			//	price = (c + d) - double_spin;pin, d, c, double_spin);
			if ((c + d) - double_spin < v)
			{
				saved_dblSpin = double_spin;
				v = (c + d) - double_spin;
				nth_ = d;
			}
			else if (price < v)
			{
				v = price;
				nth_ = d;
			}
			j++;
			h = h->next;
		}
		//printf("{>>>>>> INSERT [%ld-nth | %ld$] 
			(%ld spin & %ld dbl_spin) <<<<<<<}\n", 
					nth_ + 1, v, nth_, saved_dblSpin);	
		oo += v;
		insert_n(a, b, nth_, (j <= (ft_stacksize(*a) / 2)) 
					? (1) : (0), double_spin);
		i++;
	}
	while (*b)
	{
		p_ab(b, a, "pa\n");
		//oo++;
	}
	printTList(a, b);
	printf("%d OPERATIONS \n", oo);


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

long	count_e_alt(t_stack **b, long v_)
{
	t_stack	*h;
	long	j;
	long	saved_prev;
	long	ix_;

	if (v_ >= (*b)->nbr)
		return (0);
	j = 0;
	h = *b;
	saved_prev = -100000; 
	while (h)
	{
		if (v_ >= h->nbr && h->nbr > saved_prev)
		{
			printf("%ld on top of %ld \n", v_, h->nbr);
			ix_ = j;
			saved_prev = h->nbr;
		}
		j++;
		h = h->next;
	}	
	return (ix_ - 1);
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

int	significant_bit_n(long n)
{
	int	msb;
	if (n == 0)
		return 0;

    msb = 0;
    n = n / 2;
    while (n != 0)
	{
        n /= 2;
        msb++;
    }
    return (1 << msb);
}

int	max_bit_instack(t_stack **a)
{
	t_stack	*h;
	int		j;
	int		max;

	max = 0;
	h = *a;
	while (h)
	{
		j = significant_bit_n(h->nbr);
		if (j > max)
			max = j;
		h = h->next;
	}
	return (max);
}

int	read_bit(int val, int bit)
{
	return ((val >> bit) & 1);
}

int	find_max_bit(t_stack *a)
{
	long	max_v;
	int		i;

	max_v = 0;
	while (a)
	{
		if (max_v < a->nbr)
			max_v = a->nbr;
		a = a->next;
	}
	i = 12;
	while (i >= 0)
	{
		if (read_bit(max_v, i))
			return (i);
		i--;
	}
	return (0);
}



void	radix_sort(t_stack **a, t_stack **b)
{
	long	max_b;
	long	i;
	long	j;
	int		L;
	int		o;

	o = 0;
	L = ft_stacksize(*a);
	max_b = find_max_bit(*a);
	i = 0;
	while (i < max_b)
	{
		if (is_sorted(a))
			return ;
		j = 0;
		while (j++ < L)
		{
			if ((((*a)->nbr >> i) & 1) == 0)
				p_ab(a, b, "pb\n");
			else
				r_ab(a, "ra\n");
			o++;
		}
		while (*b)
		{
			p_ab(b, a, "pa\n");
			o++;
		}
		i++;
	}
}

*/
