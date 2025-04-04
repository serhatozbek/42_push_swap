/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:50:16 by sozbek            #+#    #+#             */
/*   Updated: 2025/03/02 21:03:24 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i][0] != '\0')
		free(tmp[i++]);
	if (tmp)
		free(tmp);
}
