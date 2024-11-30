/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:28:42 by yaboukir          #+#    #+#             */
/*   Updated: 2024/11/30 17:29:04 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*restfd(char *str)
{
	char	*rest;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	rest = malloc(ft_strlen(str) - i + 1);
	if (!rest)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*next_line(char *str)
{
	char	*res;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!str || !(*str))
		return (NULL);
	while (str[x] && str[x] != '\n')
		x++;
	if (str[x] == '\n')
		x++;
	res = malloc(x + 1);
	if (!res)
		return (NULL);
	while (y < x)
	{
		res[y] = str[y];
		y++;
	}
	res[y] = '\0';
	return (res);
}

char	*ft_reading(char *str, int fd)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(str);
		return (NULL);
	}
	bytes = 1;
	while (bytes > 0 && ft_strchr(str, '\n') == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(str), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_reading(str, fd);
	if (!str)
		return (NULL);
	result = next_line(str);
	if (!result)
		return (free(str), str = NULL, NULL);
	str = restfd(str);
	return (result);
}
