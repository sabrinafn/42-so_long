/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/09 18:24:54 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*populate_map_struct(char **map)
{
	t_map	*map_struct;
	int		height;
	int		length;

	map_struct = (t_map *)malloc(sizeof(t_map));
	if (!map_struct)
		return (NULL);
	length = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	map_struct -> map = map;
	map_struct -> length = length - 1;
	map_struct -> height = height;
	return (map_struct);
}

int	is_rectangular(t_map *map)
{
	int		i;
	int		current_len;

	i = 0;
	current_len = 0;
	while (map -> map[i])
	{
		current_len = ft_strlen(map -> map[i]);
		if (map -> map[i][current_len - 1] == '\n')
			current_len -= 1;
		if (current_len != map -> length)
			return (0);
		i++;
	}
	return (1);
}

int	is_wall(t_map *map)
{
	char	wall;
	int		i;
	int		j;

	wall = '1';
	i = 0;
	j = 0;
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (i == 0 || j == 0 || i == map -> height - 1
				|| j == map -> length - 1)
			{
				if (map -> map[i][j] != wall)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	duplicate_exit_or_start(t_map *map)
{
	int		i;
	int		j;
	int		c;
	bool	char_arr[256];

	i = 0;
	ft_memset(char_arr, false, sizeof(char_arr));
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			c = map -> map[i][j];
			if (c == 'E' || c == 'P')
			{
				if (char_arr[c] == true)
					return (0);
				char_arr[c] = true;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_char_map_exit(t_map *map)
{
	int		i;
	int		j;
	char	exit;

	i = 0;
	j = 0;
	exit = 'E';
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (map -> map[i][j] == exit)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_char_player(t_map *map)
{
	int		i;
	int		j;
	char	player;

	i = 0;
	j = 0;
	player = 'P';
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (map -> map[i][j] == player)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	collectibles(t_map *map)
{
	int		i;
	int		j;
	char	coin;

	i = 0;
	j = 0;
	coin = 'C';
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (map -> map[i][j] == coin)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	not_valid_chars(t_map *map)
{
	int			i;
	int			j;
	const char	valid_char[] = "01CEP";

	i = 0;
	j = 0;
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (!ft_strrchr(valid_char, map -> map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_map	*ft_map_copy(t_map *map)
{
	t_map	*map_copy;
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (map -> height + 1));
	if (!str)
		return (NULL);
	while (i < map -> height)
	{
		str[i] = ft_strdup(map -> map[i]);
		i++;
	}
	str[i] = NULL;
	map_copy = populate_map_struct(str);
	return (map_copy);
}

t_coordinates	*populate_coord(char p, int x, int y)
{
	t_coordinates	*coord;

	coord = (t_coordinates *)malloc(sizeof(t_coordinates));
	if (!coord)
		return (NULL);
	coord -> value = p;
	coord -> x = x;
	coord -> y = y;
	return (coord);
}

t_coordinates	*find_start_pos(t_map *map)
{
	t_coordinates	*p_pos;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (map -> map[i][j] == 'P')
			{
				p_pos = populate_coord(map -> map[i][j], j, i);
				return (p_pos);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void	flood_fill(t_map *map, int x, int y)
{
	if (map -> map[y][x] == '1')
		return ;
	map -> map[y][x] = '1';
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y + 1);
}

int	check_flood_fill(t_map *map)
{
	int		i;
	int		j;
	char	*valid_char;

	i = 0;
	j = 0;
	valid_char = "CEP";
	while (map -> map[i] != NULL)
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (ft_strrchr(valid_char, map -> map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_valid(t_map *map)
{
	t_map			*copy;
	t_coordinates	*player;
	int				res;
	int				j;

	j = 0;
	copy = ft_map_copy(map);
	if (!copy)
		return (0);
	player = find_start_pos(copy);
	flood_fill(copy, player -> x, player -> y);
	res = check_flood_fill(copy);
	while (copy -> map[j])
	{
		free(copy -> map[j]);
		j++;
	}
	free(copy);
	if (!res)
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	if (!is_rectangular(map))
		return (0);
	if (!is_wall(map))
		return (0);
	if (!not_valid_chars(map))
		return (0);
	if (!collectibles(map))
		return (0);
	if (!is_char_player(map))
		return (0);
	if (!is_char_map_exit(map))
		return (0);
	if (!duplicate_exit_or_start(map))
		return (0);
	if (!is_map_valid(map))
		return (0);
	return (1);
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
	map = (char **)malloc(sizeof(char *) * line_count + 1);
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

t_map	*init_map(char *file_name)
{
	int			fd;
	int			count;
	t_map		*map_struct;
	char		**map_array;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	count = count_line_infd(file_name);
	map_array = read_map(fd, count);
	close(fd);
	if (!map_array)
		return (NULL);
	map_struct = populate_map_struct(map_array);
	if (!map_struct)
		return (NULL);
	return (map_struct);
}

int	check_ber(char *str)
{
	char	*str_found;
	int		i;

	i = 0;
	str_found = ft_strrchr(str, '.');
	if (!str_found)
		return (0);
	if (ft_strncmp(str_found, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac > 1)
	{
		if (!check_ber(av[1]))
		{
			printf("not a ber file\n");
			return (0);
		}
		map = init_map(av[1]);
		if (map)
		{
			if (check_map(map))
				printf("check_map OK\n");
			else
				printf("check_map KO\n");
			free(map);
		}
		else
			printf("ERROR\n");
	}
	else
		printf("Error\n");
	return (0);
}
