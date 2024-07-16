/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:36:42 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/16 16:10:26 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	check_args(char **args)
{
	long	i;
	long	j;
	long	n;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (ft_isdigit((int)args[i][j]) == 0 && args[i][j] != '-')
				return (-1);
			j++;
		}
		n = ft_atoi_l(args[i]);
		if (n <= -2147483648 || n > 2147483647)
			return (-1);
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi_l(args[j]) == n)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int	init_stack(t_stack **s, int ac, char **av)
{
	int		i;
	t_stack	*n;
	t_stack	*prev;
	t_stack	*first_;

	i = 1;
	n = 0;
	ac++;
	while (av[i])
	{
		prev = n;
		n = ft_stacknew((long) ft_atoi(av[i]), prev);
		if (i == 1)
			first_ = n;
		ft_stackadd_back(s, n);
		i++;
	}
	first_->prev = n;
	return (i - 1);
}

static void	call_sort(t_stack **a, t_stack **b)
{
	long	*start;
	long	*end;
	int		len;

	start = malloc (sizeof(long) * 1);
	end = malloc (sizeof(long) * 1);
	if (!start || !end)
		return ;
	len = ft_stacksize(*a);
	*start = 0;
	*end = 15;
	if (ft_stacksize(*a) > 100)
		*end = 30;
	if (len == 2)
		tw_n(a);
	if (len == 3)
		th_n(a);
	if (len == 4)
		qu_n(a, b);
	if (len == 5)
		cq_n(a, b);
	if (len > 5)
		z_sort(a, b, start, end);
	free(start);
	free(end);
}

int	main(int argc, char **argv)
{
	t_stack		**a;
	t_stack		**b;

	if (argc < 2)
		return (-1);
	if (check_args(argv) < 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	a = (t_stack **) malloc(sizeof(t_stack **));
	b = (t_stack **) malloc(sizeof(t_stack **));
	*a = NULL;
	*b = NULL;
	init_stack(a, argc, argv);
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	call_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
