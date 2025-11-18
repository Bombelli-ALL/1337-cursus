/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:51:47 by alerradi          #+#    #+#             */
/*   Updated: 2025/11/18 18:16:14 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	**extract_line(char *remainder)
{
	size_t	i;
	char	**line_remainder;

	i = 0;
	while (remainder[i] != '\n' && remainder[i])
		i++;
	if (remainder[i] == '\n')
		i++;
	line_remainder = (char **)malloc(2 * sizeof(char *));
	*line_remainder = ft_substr(remainder, 0, i);
	*(line_remainder + 1) = ft_substr(remainder, i, ft_strlen(remainder) - i);
	free(remainder);
	return (line_remainder);
}

static char	*read_and_join(int fd, char *remainder)
{
	char	*temp;
	int		bytes_read;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && find_newline(remainder, '\n') == 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, temp, (size_t)bytes_read);
	}
	free(temp);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		*line;
	char		**temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder[fd] = read_and_join(fd, remainder[fd]);
	if (!remainder[fd] || remainder[fd][0] == '\0')
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	temp = extract_line(remainder[fd]);
	line = *temp;
	remainder[fd] = *(temp + 1);
	free(temp);
	return (line);
}
