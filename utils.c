/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:23:05 by jsaintho          #+#    #+#             */
/*   Updated: 2024/06/25 16:42:06 by jsaintho         ###   ########.fr       */
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

int	get_dist(t_stack **s, int ix)
{
	t_stack *h;
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
