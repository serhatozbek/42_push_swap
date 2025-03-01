/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:18:31 by sozbek            #+#    #+#             */
/*   Updated: 2025/03/01 23:15:23 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->a_size > 1)
	{
		tmp = stack->a[0];
		i = -1;
		while (++i < stack->a_size - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = tmp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->b_size > 1)
	{
		tmp = stack->b[0];
		i = -1;
		while (++i < stack->b_size - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = tmp;
		write(1, "rb\n", 3);
	}
}

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->a_size > 1)
	{
		tmp = stack->a[stack->a_size - 1];
		i = stack->a_size;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[i] = tmp;
		write(1, "rra\n", 4);
	}
}
