/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:46:56 by jsaintho          #+#    #+#             */
/*   Updated: 2024/06/25 12:29:36 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ========  SHIFT  ========== 
//  x >> 1   <==>     x / 2
// ===========================
int		max_bits(t_stack **s)
{
	t_stack	*head;
	int		max;
	int		bits;

	head = *s;
	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int		bits_max;
	t_stack	*head;
	int		size;
	int		i;
	int		j;

	head = *a;
	bits_max = max_bits(a); // stack len shifted
	size = ft_lstsize(head);
	i = 0;
	while (i < bits_max)
	{
		j = 0;
		while (j++ < size)
		{
			head = *a;
		}
		i++;
	}
	*b = 0;	
}

void	insertion_sort(t_stack **a)
{
	
}
