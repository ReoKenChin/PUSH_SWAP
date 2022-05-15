/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_sub.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:03:55 by mcherki           #+#    #+#             */
/*   Updated: 2022/05/15 12:04:36 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_flags(int *t, t_p1 *a)
{
	int	*flag;
	int	k;
	int	l;
	int	j;
	int	i;

	flag = (int *)ft_calloc(get_max_array(t, a->top), sizeof(int));
	if (!flag)
		exit (1);
	i = get_index_max(t, a->top, get_max_array(t, a->top));
	j = t_circle(a, i);
	k = i;
	l = 0;
	while (j != i)
	{
		if (a->arry[j] > a->arry[k])
		{
			flag[l] = a->arry[k];
			l++;
			k = j;
		}
		j = t_circle(a, j);
	}
	flag[l] = a->arry[k];
	return (flag);
}

int	get_head(t_p1 *a, int i, int j)
{
	int	k;
	int	count;

	count = 1;
	k = i;
	while (j != i)
	{
		if (a->arry[j] > a->arry[k])
		{
			count++;
			k = j;
		}
		j = t_circle(a, j);
	}
	return (count);
}

int	*the_long_list(t_p1 *a, int *p)
{
	int	i;
	int	j;
	int	*t;
	int	*flag;

	t = (int *)ft_calloc(a->top + 1, sizeof(int));
	if (!t)
		exit (1);
	i = a->top;
	j = t_circle(a, i);
	while (i)
	{
		t[i] = get_head(a, i, j);
		i--;
		j = t_circle(a, i);
	}
	flag = get_flags(t, a);
	*p = get_max_array(t, a->top);
	free(t);
	return (flag);
}

void	push_from_a_to_b(t_p1 *a, t_p1 *b)
{
	int	i;
	int	*flag;
	int	m;

	if (ft_check_sorted(a))
		exit(1);
	flag = the_long_list(a, &m);
	i = a->top;
	while (i >= 0)
	{
		if (!is_in_arr(flag, a->arry[a->top], m))
			push_top(a, b, "pb\n");
		else
			rotat_stack(a, "ra\n");
		i--;
	}
	free(flag);
}
