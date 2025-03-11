/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:11:39 by sozbek            #+#    #+#             */
/*   Updated: 2025/03/02 21:04:40 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_array_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	radix_sort_stack_b(t_stack *s, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_sorted(s))
	{
		if (((s->b[0] >> j) & 1) == 0)
			rb(s);
		else
			pa(s);
	}
	if (is_array_sorted(s))
		while (s->b_size != 0)
			pa(s);
}

void	radix_sort(t_stack *s)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = s->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = s->a_size;
		while (size-- && !is_array_sorted(s))
		{
			if (((s->a[0] >> j) & 1) == 0)
				pb(s);
			else
				ra(s);
		}
		radix_sort_stack_b(s, s->b_size, bit_size, j + 1);
	}
	while (s->b_size != 0)
		pa(s);
}
