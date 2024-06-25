/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:03:39 by jsaintho          #+#    #+#             */
/*   Updated: 2024/06/25 16:08:19 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://techy.asia/posts/how-to-solve-push-swap/
#include "push_swap.h"

void	tw_n(t_stack **a)
{
	t_stack	*head;

	head = *a;
	if (head->nbr > (head->next)->nbr)
		s_ab(a);
	write(1, "sa\n", 3);
	return;
}

void	th_n(t_stack **a)
{
	t_stack	*i;
	t_stack *j;
	t_stack	*k;

	i = *a;
	j = i->next;
	k = j->next;
	// 0 1 2
	if ( ((i->nbr < j->nbr) && (j->nbr < k->nbr)) || (!i || !k || !j))
		return ;
	// 1 0 2
	else if ((i->nbr < k->nbr && j->nbr < k->nbr) && (j->nbr < i->nbr))
		s_ab(a);
	// 0 2 1
	else if ((i->nbr < j->nbr && j->nbr > k->nbr) && (i->nbr < k->nbr))
	{
		s_ab(a);
		r_ab(a);
	}
	// 1 2 0
	else if ((i->nbr < j->nbr) && (k->nbr < i->nbr))
		rr_ab(a);
	// 2 0 1
	else if ((i->nbr > k->nbr) && (j->nbr < k->nbr)){
		r_ab(a); printf("201 type \n");}
	// 2 1 0
	else if ((i->nbr > j->nbr) && (j->nbr > k->nbr))
	{
		s_ab(a);
		rr_ab(a);
	}
}
