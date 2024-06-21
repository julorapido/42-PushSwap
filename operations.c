/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:11:04 by jsaintho          #+#    #+#             */
/*   Updated: 2024/06/21 12:28:09 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack **from_, t_stack **to_)
{
	t_stack	*head_from;
	t_stack	*head_to;
	t_stack *temp;

	if (ft_lstsize(*from_) == 0)
		return;
	head_to = *to_;
	head_from = *from_;
	temp = head_from;
	head_from = head_from->next;
	*from_ = head_from;
	if (!head_to)
	{
		head_to = temp;
		head_to->next = NULL;
		*to_ = head_to;
	}
	else
	{
		temp->next = head_to;
		*to_ = temp;
	}
}
