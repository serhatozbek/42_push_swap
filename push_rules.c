/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:10:16 by sozbek            #+#    #+#             */
/*   Updated: 2025/03/01 23:14:40 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	int	i;

	if (stack->a_size > 0)
	{
		i = stack->a_size;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		i = 0;
		while (i < stack->b_size - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->a_size++;
		stack->b_size--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stack)
{
	int	i;

	if (stack->a_size > 0)
	{
		i = stack->b_size;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		i = 0;
		while (i < stack->a_size - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->b_size++;
		stack->a_size--;
		write(1, "pb\n", 3);
	}
}
