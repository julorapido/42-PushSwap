/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:36:42 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/01 18:07:55 by jsaintho         ###   ########.fr       */
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
	t_stack *prev;
	t_stack *first_;

	i = 1;
	ac++;
	while(av[i])
	{
		prev = n;
		n = ft_stacknew(ft_atoi(av[i]), prev);
		if (i == 1)
			first_ = n;
		ft_stackadd_back(s, n);
		i++;
	}
	first_->prev = n;
	//n->next = first_;
	index_stack(s);
	// printList(*s);
	return (i - 1);
}

static void	call_sort(int len, t_stack **a, t_stack **b)
{
	if (len == 2)
		tw_n(a);
	if (len == 3)
		th_n(a);
	if (len == 4)
		qu_n(a, b);
	if (len == 5)
		cq_n(a, b);
	if (len > 5)
		insertion_sort(a, b);
	printf("=== STACK-A === \n");
	printList(*a);
	printf("=== STACK-B === \n");
	printList(*b);
}

int main (int argc, char **argv)
{
	t_stack		**a;
	t_stack		**b;
	int			l;

	if(argc < 2)
		return (-1);
	a = (t_stack **) malloc(sizeof(t_stack **));
	b = (t_stack **) malloc(sizeof(t_stack **));
	if (!a || !b)
		return (0);
	*a = *b = NULL;
	l = init_stack(a, argc, argv);
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	call_sort(l, a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
