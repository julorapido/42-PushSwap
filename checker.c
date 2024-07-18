/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:10:19 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/18 15:26:54 by jsaintho         ###   ########.fr       */
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

static int	run_operation_t(char *op, t_stack **a, t_stack **b)
{
	if (!(ft_strcmp(op, "ra\n")))
	{
		r_ab(a, "");
		return (0);
	}
	if (!(ft_strcmp(op, "rb\n")))
	{
		r_ab(b, "");
		return (0);
	}
	if (!(ft_strcmp(op, "rr\n")))
	{
		r_ab(a, "");
		r_ab(b, "");
		return (0);
	}
	if (!(ft_strcmp(op, "rra\n")))
	{
		rr_ab(a, "");
		return (0);
	}
	if (!(ft_strcmp(op, "rrb\n")))
	{
		rr_ab(b, "");
		return (0);
	}	
	if (!(ft_strcmp(op, "rrr\n")))
	{
		rr_ab(a, "");
		rr_ab(b, "");
		return (0);
	}
	return (1);
}

static int	run_operation(char *op, t_stack **a, t_stack **b)
{
	if (!(ft_strcmp(op, "sa\n")))
	{
		s_ab(a, "");
		return (0);
	}
	if (!(ft_strcmp(op, "sb\n")))
	{
		s_ab(b, "");
		return (0);
	}
	if (!(ft_strcmp(op, "ss\n")))
	{
		s_ab(a, "");
		s_ab(b, "");
		return (0);
	}
	if (!(ft_strcmp(op, "pa\n")))
	{
		p_ab(b, a, "");
		return (0);
	}
	if (!(ft_strcmp(op, "pb\n")))
	{
		p_ab(a, b, "");
		return (0);
	}
	return (run_operation_t(op, a, b));
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
