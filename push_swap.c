/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:36:42 by jsaintho          #+#    #+#             */
/*   Updated: 2024/06/25 15:59:34 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_next_min(t_stack **s)
{
	t_stack	*head;
	t_stack *min;
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

static void	index_stack(t_stack **s)
{
	t_stack *head;
	int		index;

	index = 0;
	head = get_next_min(s);
	while (head)
	{
		head->index = index++;
		head = get_next_min(s);
	}
}

static int	init_stack(t_stack **s, int ac, char **av)
{
	int	i;
	t_stack	*n;

	i = 1;
	ac++;
	while(av[i])
	{
		n = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(s, n);
		i++;
	}
	index_stack(s);
	printList(*s);
	return (i - 1);
}

static void	call_sort(int len, t_stack **a, t_stack **b, info_t *l)
{
	printf("======= STACK OF [%d ELEMENTS] ======= \n", len);
	if (len == 2)
		tw_n(a);
	if (len == 3)
		th_n(a);
	printList(*a);
}

int main (int argc, char **argv)
{
	t_stack		**a;
	t_stack		**b;
	info_t		*inf_;
	int			l;

	if(argc < 2)
		return (-1);
	a = (t_stack **) malloc(sizeof(t_stack **));
	b = (t_stack **) malloc(sizeof(t_stack **));
	inf_ = (info_t *) malloc(sizeof(info_t *));
	if (!a || !b || !inf_)
		return (0);
	*a = *b = NULL;
	inf_->a = (t_uli_) (&a);
	inf_->b = (t_uli_) (&b);
	//printf("STACK A = %x %x \n", inf_->a, inf_->b);
	l = init_stack(a, argc, argv);
	call_sort(l, a, b, inf_);
	return (0);
}
