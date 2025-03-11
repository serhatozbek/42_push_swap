/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:11:36 by sozbek            #+#    #+#             */
/*   Updated: 2025/03/02 20:51:33 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stack;

void		sort_three_elements(t_stack *s);
void		selection_sort(t_stack *stack);
void		radix_sort(t_stack *s);

void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		rra(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		sa(t_stack *stack);

void		parse_numbers(t_stack *s);
void		create_index(t_stack *s);
void		start_stacks(int argc, char **argv, t_stack *s);
void		free_and_exit_message(t_stack *s, char *message);
void		exit_if_sorted_or_repeat(t_stack *s, int i);
int			is_array_sorted(t_stack *s);
int			ft_atol(const char *n, t_stack *s, char **tmp);
void		free_tmp(char **tmp);

#endif
