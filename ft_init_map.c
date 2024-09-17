/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/17 11:05:09 by sabrifer         ###   ########.fr       */
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
	printf("[MALLOC: t_game struct] ft_init_map.c\n");
	length = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	game->map = map;
	game->length = length - 1;
	game->height = height;
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
		printf("[MALLOC: GNL line count] ft_init_map.c\n");
		free(temp);
		printf("[  FREE: GNL line count] ft_init_map.c\n");
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
	printf("[MALLOC: char ** for map] ft_init_map.c\n");
	while (1)
	{
		line_gnl = get_next_line(fd);
		if (line_gnl == NULL)
			break ;
		map[i] = line_gnl;
		i++;
	}
	map[i] = NULL;
	printf("[MALLOC: GNL store line] ft_init_map.c\n");
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
