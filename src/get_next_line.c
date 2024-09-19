/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:38:46 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/04 10:50:13 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	store_remainder(char **string_of_read)
{
	char	*pos;
	char	*temp;
	int		pos_nl;

	if (!*string_of_read)
		return ;
	pos = ft_strchr(*string_of_read, '\n');
	if (pos)
	{
		pos_nl = pos - *string_of_read;
		temp = ft_strdup(*string_of_read + pos_nl + 1);
		free(*string_of_read);
		*string_of_read = temp;
	}
	else
		return ;
}

void	store_line_with_newline(char *string_of_read, char **line)
{
	char	*pos;
	int		i;
	int		pos_nl;

	if (!string_of_read)
		return ;
	pos = ft_strchr(string_of_read, '\n');
	if (pos)
	{
		pos_nl = pos - string_of_read;
		*line = (char *)malloc((pos_nl + 2) * sizeof(char));
		i = 0;
		while (i <= pos_nl)
		{
			(*line)[i] = string_of_read[i];
			i++;
		}
		(*line)[i] = '\0';
	}
	else
		return ;
}

void	read_buffer_and_store(int fd, char **string_of_read)
{
	char		*buffer;
	char		*joined_str;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return ;
	while (ft_strchr(*string_of_read, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		joined_str = ft_strjoin(*string_of_read, buffer);
		free(*string_of_read);
		*string_of_read = joined_str;
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char	*string_of_read[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (string_of_read[fd] == NULL)
		string_of_read[fd] = ft_strdup("");
	read_buffer_and_store(fd, &string_of_read[fd]);
	if (string_of_read[fd][0] == '\0')
	{
		free(string_of_read[fd]);
		string_of_read[fd] = NULL;
		return (NULL);
	}
	line = NULL;
	store_line_with_newline(string_of_read[fd], &line);
	if (line)
		store_remainder(&string_of_read[fd]);
	if (string_of_read[fd] && !line)
	{
		line = ft_strdup(string_of_read[fd]);
		free(string_of_read[fd]);
		string_of_read[fd] = NULL;
	}
	return (line);
}
