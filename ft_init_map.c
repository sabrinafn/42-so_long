/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/15 14:52:22 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (game);
}

int	count_line_infd(char *file_name)
{
	int			i;
	int			fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		if (!get_next_line(fd))
			break ;
		i++;
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

t_game	*init_map(char *file_name)
{
	int			fd;
	int			count;
	t_game		*game;
	char		**map_array;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	count = count_line_infd(file_name);
	map_array = read_map(fd, count);
	close(fd);
	if (!map_array)
		return (NULL);
	game = populate_map_struct(map_array);
	if (!game)
		return (NULL);
	return (game);
}
