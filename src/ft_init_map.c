/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/18 17:22:15 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game	*populate_map_struct(char **map)
{
	t_game	*game;
	int		height;
	int		length;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	length = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	game->map = map;
	game->length = length - 1;
	game->height = height;
	game->moves = 0;
	return (game);
}

int	ft_file_len(char *filename)
{
	int			i;
	int			fd;
	char		*temp;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		i++;
		free(temp);
	}
	close(fd);
	return (i);
}

char	**read_map(int fd, int line_count)
{
	int			i;
	char		*line_gnl;
	char		**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	while (1)
	{
		line_gnl = get_next_line(fd);
		if (line_gnl == NULL)
			break ;
		map[i] = line_gnl;
		i++;
	}
	map[i] = NULL;
	if (map[0] == NULL)
		return (NULL);
	return (map);
}

t_game	*init_map(char *filename)
{
	int			fd;
	int			count;
	t_game		*game;
	char		**map_array;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	count = ft_file_len(filename);
	if (count == -1)
		return (NULL);
	map_array = read_map(fd, count);
	close(fd);
	if (!map_array)
		return (NULL);
	game = populate_map_struct(map_array);
	if (!game)
		return (NULL);
	return (game);
}
