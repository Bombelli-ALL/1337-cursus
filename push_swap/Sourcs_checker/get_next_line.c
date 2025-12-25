/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:51:47 by alerradi          #+#    #+#             */
/*   Updated: 2025/12/21 01:49:11 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **remainder)
{
	size_t	i;
	size_t	j;	
	char	*line;
	char	*temp;

	i = 0;
	while ((*remainder)[i] != '\n' && (*remainder)[i])
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	line = ft_substr(*remainder, 0, i);
	if (!line)
		return (NULL);
	j = ft_strlen(*remainder) - i;
	temp = ft_substr(*remainder, i, j);
	free(*remainder);
	*remainder = temp;
	if (!remainder && j > 0)
		return (free(line), NULL);
	return (line);
}

static char	*read_and_join(int fd, char *remainder)
{
	char	*temp;
	ssize_t	bytes_read;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && find_newline(remainder, '\n') == 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			free(remainder);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, temp, (size_t)bytes_read);
	}
	free(temp);
	return (remainder);
}

int	get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	remainder = read_and_join(fd, remainder);
	if (!remainder || remainder[0] == '\0')
	{
		free(remainder);
		remainder = NULL;
		return (-2);
	}
	line = extract_line(&remainder);
	if (!line)
	{
		free(remainder);
		remainder = NULL;
		return (-1);
	}
	i = convert(line);
	if (i == -1)
		free(remainder);
	free(line);
	return (i);
}
