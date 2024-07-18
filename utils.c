/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:23:05 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/18 15:23:13 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*a;

	a = *stack;
	while (a && a->next)
	{
		if (a->nbr > (a->next)->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

void	check(t_stack **a, t_stack **b)
{
	if (!is_sorted(a))
		write(1, "KO\n", 3);
	if (is_sorted(a))
		write(1, "OK\n", 3);
	free_stack(a);
	free_stack(b);
}

long	indx_from_arr(long *arr, long en, long v__)
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

long	get_max_index(t_stack **b)
{
	t_stack	*h;
	long	n;
	long	j;
	long	v__j;

	j = 0;
	n = -2147483647;
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

long	get_max(t_stack **b)
{
	t_stack	*h;
	long	n;

	n = -2147483647;
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

int	get_dist(t_stack **s, int ix)
{
	t_stack	*h;
	int		dist;

	dist = 0;
	h = *s;
	while (h)
	{
		if (h->index == ix)
			break ;
		h = h->next;
		dist++;
	}
	return (dist);
}
long	median(t_stack **a)
{
	t_stack *h;
	long	*ar;
	int		z;
	int		i;
	int		j;

	ar = (long *) malloc(ft_stacksize(*a) * sizeof(long));
	h = *a;
	z = 0;
	while (h)
	{
		ar[z] = h->nbr;
		z++;
		h = h->next;
	}
	i = 0;	
	while (i < ft_stacksize(*a) - 1)
	{
		j = 0;
		while (j < ft_stacksize(*a) - i - 1)
		{
			if(ar[j] > ar[j + 1])
			{
				long t = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = t;
			}
			j++;
		}
		i++;
	}
	int n = (ft_stacksize(*a) + 1) / 2 - 1;
	return (ar[n]);
}

t_stack	*get_next_min(t_stack **s)
{
	t_stack	*head;
	t_stack	*min;
	int		z;

	min = NULL;
	z = 0;
	head = *s;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!z || head->nbr < min->nbr))
			{
				min = head;
				z = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_stack **s)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(s);
	while (head)
	{
		head->index = index++;
		head = get_next_min(s);
	}
}
*/
