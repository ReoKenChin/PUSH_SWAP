/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:05:50 by mcherki           #+#    #+#             */
/*   Updated: 2022/05/15 12:05:59 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*push(t_p1 *stack, int val)
{
	if (stack->top == (int)(stack->capacity - 1))
		return (0);
	stack->arry[++stack->top] = val;
	return (&stack->arry[stack->top]);
}

int	*pop(t_p1 *stack)
{
	if (stack->top == -1)
		return (0);
	return (&stack->arry[stack->top--]);
}

int	ft_check_sorted(t_p1 *a)
{
	int	i;
	int	*tmp;

	i = a->top;
	tmp = a->arry;
	while (i > 0)
	{
		if (tmp[i] > tmp[i - 1])
			return (0);
		i--;
	}
	return (1);
}
