/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:03:39 by jsaintho          #+#    #+#             */
/*   Updated: 2024/06/25 12:37:38 by jsaintho         ###   ########.fr       */
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
	t_stack	*head;

	head = *a;
	if (head->nbr > (head->next)->nbr)
		s_ab(a);
	write(1, "sa\n", 3);
	return;
}
