/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:11:43 by sozbek            #+#    #+#             */
/*   Updated: 2025/03/02 21:45:15 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_stack *s)
{
	if (s->a[2] < s->a[1] || s->a[2] < s->a[0])
	{
		if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
			ra(s);
		else
			rra(s);
	}
	if (s->a[0] > s->a[1])
		sa(s);
}

static int	find_min_index(int *arr, int size)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = arr[0];
	index = 0;
	while (i < size)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static void	ra_or_rra(t_stack *stack, int min_value, int min_index)
{
	if (min_index >= stack->a_size / 2 + stack->a_size % 2)
		while (stack->a[0] != min_value && is_array_sorted(stack) == 0)
			rra(stack);
	else
		while (stack->a[0] != min_value && is_array_sorted(stack) == 0)
			ra(stack);
}

void	selection_sort(t_stack *stack)
{
	int	i;
	int	min_index;
	int	temp;
	int	size;

	i = 0;
	size = stack->a_size;
	while (i < size && is_array_sorted(stack) == 0)
	{
		min_index = find_min_index(stack->a, stack->a_size);
		temp = stack->a[min_index];
		if (stack->a[0] != temp && stack->a_size > 1)
			ra_or_rra(stack, temp, min_index);
		if (is_array_sorted(stack) == 0)
			pb(stack);
		i++;
	}
	while (stack->b_size > 0)
		pa(stack);
}
