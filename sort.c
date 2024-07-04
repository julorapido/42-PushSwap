/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:03:39 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/04 14:29:35 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_stack **stack, int val)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

// sort 2 numbersi
void	tw_n(t_stack **a)
{
	t_stack	*head;

	head = *a;
	if (head->nbr > (head->next)->nbr)
		s_ab(a, "sa\n");
	return ;
}

// sort 3 nnmbers
// 1. [0 1 2]
// 2. [1 0 2]
// 3. [0 2 1]
// 4. [1 2 0]
// 5. [2 0 1]
// 6. [2 1 0]
void	th_n(t_stack **a)
{
	t_stack	*i;
	t_stack	*j;
	t_stack	*k;

	i = *a;
	j = i->next;
	k = j->next;
	if (((i->nbr < j->nbr) && (j->nbr < k->nbr)) || (!i || !k || !j))
		return ;
	else if ((i->nbr < k->nbr && j->nbr < k->nbr) && (j->nbr < i->nbr))
		s_ab(a, "sa\n");
	else if ((i->nbr < j->nbr && j->nbr > k->nbr) && (i->nbr < k->nbr))
	{
		s_ab(a, "sa\n");
		r_ab(a, "ra\n");
	}
	else if ((i->nbr < j->nbr) && (k->nbr < i->nbr))
		rr_ab(a, "rra\n");
	else if ((i->nbr > k->nbr) && (j->nbr < k->nbr))
		r_ab(a, "ra\n");
	else if ((i->nbr > j->nbr) && (j->nbr > k->nbr))
	{
		s_ab(a, "sa\n");
		rr_ab(a, "rra\n");
	}
}

// sort 4 numbers
// 1. [1 0 2 3]
// 2. [1 2 0 3]
// 3. [1 2 3 0]
void	qu_n(t_stack **a, t_stack **b)
{
	int	dist;

	if (is_sorted(a))
		return ;
	dist = get_dist(a, get_min(a, -1));
	if (dist == 1)
		s_ab(a, "sa\n");
	else if (dist == 2)
	{
		r_ab(a, "ra\n");
		r_ab(a, "ra\n");
	}
	else if (dist == 3)
		rr_ab(a, "rra\n");
	if (is_sorted(a))
		return ;
	p_ab(a, b, "pb\n");
	th_n(a);
	p_ab(b, a, "pa\n");
}

// sort 5 numbers
// 1. [1 0 2 3 4]
// 2. [1 2 0 3 4]
// 3. [1 2 3 0 4]
// 4. [1 2 3 4 0]
void	cq_n(t_stack **a, t_stack **b)
{
	int	dist;	

	if (is_sorted(a))
		return ;
	dist = get_dist(a, get_min(a, -1));
	if (dist == 1)
		s_ab(a, "sa\n");
	else if (dist == 2)
	{
		r_ab(a, "ra\n");
		r_ab(a, "ra\n");
	}
	else if (dist == 3)
	{
		rr_ab(a, "rra\n");
		rr_ab(a, "rra\n");
	}
	else if (dist == 4)
		rr_ab(a, "rra\n");
	if (is_sorted(a))
		return ;
	p_ab(a, b, "pb\n");
	qu_n(a, b);
	p_ab(b, a, "pa\n");
}
