/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:11:04 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/01 18:07:10 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// ========================================
//					PUSH
// ========================================
// - Take the 1st top element of [STACK A] and put it at top of [STACK B].
// - Do nothing if a is empty.
void	p_ab(t_stack **from_, t_stack **to_, char *msg)
{
	t_stack	*head_from;
	t_stack	*head_to;
	t_stack *temp;

	if (ft_stacksize(*from_) == 0)
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
	write(1, msg, 3);
}

// ====================================
// 				 SWAP
// ====================================
// - Swap the first 2 elements at the top of stack b.
// - Do nothing if there is only one or no elements.
void	s_ab(t_stack **a_b, char *msg)
{
	t_stack *head;
	int		temp_nbr;
	int		temp_indx;

	head = *a_b;
	if (ft_stacksize(*a_b) < 2 || !head || !(head->next))
		return ;
	
	write(1, msg, 3);
	// ft_putendl_fd(msg, 1);
	//ft_putendl_fd("sa", 1);
	temp_nbr = head->nbr;
	temp_indx = head->index;
	head->nbr = (head->next)->nbr;
	head->index = (head->next)->index;
	(head->next)->nbr = temp_nbr;
	(head->next)->index = temp_indx;
}

// ====================================
// 				 ROTATE
// ====================================
// - ShiftUp^ all elements of stack a by 1.
// - The first element becomes the last one.
void r_ab(t_stack **a_b, char *msg)
{
	t_stack	*head;
	t_stack *last_;

	head = *a_b;
	if (!head || ft_stacksize(*a_b) < 2)
		return ;

	write(1, msg, 3);
	last_ = ft_stacklast(*a_b);
	*a_b = head->next;
	head->next = NULL;
	last_->next = head;
}

// ====================================
// 			  REVERSE ROTATE
// ====================================
// - ShiftDown all elements of stack a by 1.
// - The last element becomes the first one.
void	rr_ab(t_stack **a_b, char *msg)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_stacksize(*a_b) < 2)
		return ;

	head = *a_b;
	tail = ft_stacklast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	write(1, msg, 4);
	tail->next = *a_b;
	*a_b = tail;
}
