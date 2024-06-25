/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:11:04 by jsaintho          #+#    #+#             */
/*   Updated: 2024/06/25 12:36:30 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// Take the 1st top element of [STACK A] and put it at top of [STACK B].
// Do nothing if a is empty.
void	p_ab(t_stack **from_, t_stack **to_)
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

// Swap 2 top el of [STACK A or STACK B]
void	s_ab(t_stack **a_b)
{
	t_stack *head;
	int		temp;

	head = *a_b;
	if (!head || !head->nbr || !head->next)
		return ;
	
	temp = head->nbr;
	head->nbr = (head->next)->nbr;
	(head->next)->nbr = temp;
}


