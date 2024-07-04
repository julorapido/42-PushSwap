/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:20 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/04 18:00:04 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	min_s(t_stack **s)
{
	t_stack *h;
	long	i;

	h = *s;
	i = 100000000;
	while (h)
	{
		if (h->nbr < i)
			i = h->nbr;
		h = h->next;
	}
	return (i);
}

int	calc_n_insertion(long v, t_stack **a, t_stack **b)
{
	t_stack *h

	h = *b;
	if (v < min_s(b))
		return (1);
	while (h)
	{
		if ()
		h = h->next;
	}
}


void	alg(t_stack **a, t_stack **b)
{
	t_stack *a;

	p_ab(a, b, "pb\n");
	p_ab(a, b, "pb\n");
	while (h)
	{
		h = h->next;
	}
}
