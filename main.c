/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:11:28 by sozbek            #+#    #+#             */
/*   Updated: 2025/03/02 21:01:18 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit_message(t_stack *s, char *message)
{
	if (message)
		write(2, message, ft_strlen(message));
	if (s)
	{
		if (s->a)
			free(s->a);
		if (s->b)
			free(s->b);
		if (s->join_args)
			free(s->join_args);
		free(s);
	}
	exit(1);
}

static void	argument_control_two(int argc, char **argv)
{
	int	j;
	int	i;
	int	c;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		c = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == '-' || argv[i][j
					+ 1] == '+'))
				free_and_exit_message(NULL, "Error\n");
			if (ft_isdigit(argv[i][j]))
				c = 1;
			j++;
		}
		if (c != 1)
			free_and_exit_message(NULL, "Error\n");
	}
}

static void	argument_control(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0])
			free_and_exit_message(NULL, "Error\n");
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != '-'
				&& argv[i][j] != '+' && argv[i][j] != ' '))
				|| (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
				|| (argv[i][j] == '+' && !ft_isdigit(argv[i][j + 1])))
				free_and_exit_message(NULL, "Error\n");
			j++;
		}
	}
	argument_control_two(argc, argv);
}

static void	join_args(int argc, char **argv, t_stack *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->join_args = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	if (!s->join_args)
		free_and_exit_message(s, "Error\n");
}

int	main(int argc, char **argv)
{
	t_stack	*s;

	if (argc < 2)
		free_and_exit_message(NULL, "");
	argument_control(argc, argv);
	s = malloc(sizeof(t_stack));
	if (s == NULL)
		exit(1);
	start_stacks(argc, argv, s);
	join_args(argc, argv, s);
	parse_numbers(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		sa(s);
	else if (s->a_size == 3)
		sort_three_elements(s);
	else if (s->a_size <= 32)
		selection_sort(s);
	else
	{
		create_index(s);
		radix_sort(s);
	}
	exit_if_sorted_or_repeat(s, 1);
	free_and_exit_message(s, "Error\n");
	return (0);
}
