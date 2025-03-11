/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:38:53 by sozbek            #+#    #+#             */
/*   Updated: 2025/01/26 21:21:04 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_strjoin(char *buffer, char *tmp)
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	if (!buffer || !tmp)
		return (NULL);
	result = malloc(ft_strlen(buffer) + ft_strlen(tmp) + 1);
	if (!result)
		return (NULL);
	while (buffer[++i])
		result[i] = buffer[i];
	while (tmp[j])
		result[i++] = tmp[j++];
	result[i] = '\0';
	free(buffer);
	return (result);
}

size_t	ft_get_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_newline_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
