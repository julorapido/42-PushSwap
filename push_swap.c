/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:36:42 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/10 16:51:42 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_args(int *pos_i_arr, int *neg_i_arr, char **args)
{
	int i;
	int	j;
	int	n;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (ft_isdigit((int)args[i][j]) == 0
				&& args[i][j] != '-')
				return (-1);
			j++;
		}
		n = ft_atoi(args[i]);
		if ((pos_i_arr[n] && n >= 0) || (neg_i_arr[n] && n < 0))
			return (-1);
		if (n >= 0)
			pos_i_arr[n] = 1;
		else
			neg_i_arr[n] = 1;
		i++;
	}
	return (1);
}

static int	init_i_arrs(char **args)
{
	int	*pos_arr;
	int	*neg_arr;
	int	i;

	pos_arr = (int *) malloc(10000 * sizeof(int));
	neg_arr = (int *) malloc(10000 * sizeof(int));
	if(!pos_arr || !neg_arr)
		return (-1);
	i = 0;
	while (i < 10000)
	{
		pos_arr[i] = 0;
		neg_arr[i] = 0;
		i++;
	}
	i = check_args(pos_arr, neg_arr, args);
	free(pos_arr);
	free(neg_arr);
	return (i);
}

static int	init_stack(t_stack **s, int ac, char **av)

{
	int		i;
	t_stack	*n;
	t_stack	*prev;
	t_stack	*first_;

	i = 1;
	ac++;
	while (av[i])
	{
		prev = n;
		n = ft_stacknew(ft_atoi(av[i]), prev);
		if (i == 1)
			first_ = n;
		ft_stackadd_back(s, n);
		i++;
	}
	first_->prev = n;
	index_stack(s);
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
		z_sort(a, b);
	//alg(a, b);
	//radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack		**a;
	t_stack		**b;
	int			l;

	if (argc < 2 || init_i_arrs(argv) == -1)
		return (-1);
	a = (t_stack **) malloc(sizeof(t_stack **));
	b = (t_stack **) malloc(sizeof(t_stack **));
	if (!a || !b)
		return (0);
	*a = NULL;
	*b = NULL;
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
