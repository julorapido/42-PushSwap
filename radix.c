/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:51:06 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/10 16:23:28 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	//pre_tri(a, b);
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
	//printf("%d OPERATIONS [RADIX] ! \n", o);
}
