/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:10:19 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/16 16:34:21 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	check_args(char **args, long i)
{
	long	j;
	long	n;

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

static int	run_operation(char *op, t_stack **a, t_stack **b)
{
	if (!(ft_strcmp(op, "sa")))
	{
		s_ab(a, "");
		return (0);
	}
	if (!(ft_strcmp(op, "sb")))
	{
		s_ab(b, "");
		return (0);
	}
	if (!(ft_strcmp(op, "ss")))
	{
		s_ab(a, "");
		s_ab(b, "");
		return (0);
	}
	if (!(ft_strcmp(op, "pa")))
	{
		p_ab(b, a, "");
		return (0);
	}
	if (!(ft_strcmp(op, "pb")))
	{
		p_ab(a, b, "");
		return (0);
	}
	if (!(ft_strcmp(op, "ra")))
	{
		r_ab(a, "");
		return (0);
	}
	if (!(ft_strcmp(op, "rb")))
	{
		r_ab(b, "");
		return (0);
	}
	if (!(ft_strcmp(op, "rr")))
	{
		r_ab(a, "");
		r_ab(b, "");
		return (0);
	}
	if (!(ft_strcmp(op, "rra")))
	{
		rr_ab(a, "");
		return (0);
	}
	if (!(ft_strcmp(op, "rrb")))
	{
		rr_ab(b, "");
		return (0);
	}	
	if (!(ft_strcmp(op, "rrr")))
	{
		rr_ab(a, "");
		rr_ab(b, "");
		return (0);
	}
	return (1);
}

static void	check(t_stack **a, t_stack **b)
{
	if (!is_sorted(a))
		write(1, "KO\n", 3);
	if (is_sorted(a))
		write(1, "OK\n", 3);
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack		**a;
	t_stack		**b;
	char		*line;

	if (argc < 2)
		return (-1);
	if (check_args(argv, 1) < 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	a = (t_stack **) malloc(sizeof(t_stack **));
	b = (t_stack **) malloc(sizeof(t_stack **));
	*a = NULL;
	*b = NULL;
	init_stack(a, argc, argv);
	line = get_next_line(0);
	while (line)
	{
		if (run_operation(line, a, b))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		free(line);
		line = get_next_line(0);
	}
	check(a, b);
	return (0);
}
