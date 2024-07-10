/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:32:35 by amait-ou          #+#    #+#             */
/*   Updated: 2023/02/17 17:27:29 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_free_stack(int *arr)
{
	if (arr)
		free(arr);
}

void	ft_free_all(t_stack *sta, t_stack *stb)
{
	ft_free_stack(sta->arr);
	ft_free_stack(sta->c_arr);
	ft_free_stack(stb->arr);
	ft_free_stack(stb->c_arr);
}
