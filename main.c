/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/05 11:45:20 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

/*
	MAP STRUCT
typedef struct s_map
{
	char	**map;
	int		length;
	int		height;
}	t_map;

	CHAR AND POSITION STRUCT
typedef struct s_coordinates
{
	char	value;
	int		x;
	int		y;
}	t_coordinates;

*/

t_map	*populate_map_struct(char **map)
{
	t_map	*map_struct;
	int		height;
	int		length;

	map_struct = (t_map *)malloc(sizeof(t_map));
	if (!map_struct)
	{
		printf("map_struct, malloc return NULL\n");
		return (NULL);
	}
	length = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	map_struct -> map = map;
	map_struct -> length = length;
	map_struct -> height = height;
	return (map_struct);
}

int	is_rectangular(t_map *map)
{
	int		i;

	i = 0;
	while (map -> map[i])
	{
		if (ft_strlen(map -> map[i]) != (size_t)map -> length)
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
		while (map -> map[i][j] != '\n')
		{
			if (i == 0 || i == map -> height - 1 || j == 0 || j == map -> length - 2)
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
	bool	char_arr[256] = {false};
	char	exit;
	char	start;

	i = 0;
	j = 0;
	exit = 'E';
	start = 'P';
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n')
		{
			c = map -> map[i][j];
			if (c == exit || c == start)
			{
				if (char_arr[c] == false)
					char_arr[c] = true;
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
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
		while (map -> map[i][j] != '\n')
		{
			if (map -> map[i][j] == coin)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_map	*ft_map_copy(t_map *map)
{
	t_map	*map_copy;
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map_copy = (t_map *)malloc(sizeof(t_map));
	if (!map_copy)
	{
		printf("map_copy, malloc null\n");
		return (NULL);
	}
	str = (char **)malloc(sizeof(char *) * map -> height + 1);
	if (!str)
	{
		printf("str, malloc null\n");
		return (NULL);
	}
	map_copy -> map = str;
	while (map -> map[i] != NULL)
	{
		map_copy -> map[i] = ft_strdup(map -> map[i]);
		i++;
	}
	/* printing map_copy
	while (j < i)
	{
		printf("%s", map_copy -> map[j]);
		j++;
	}*/
	return (map_copy);
}

t_coordinates	*find_start_pos(t_map *map)
{
	t_coordinates	*p_pos;
	int				i;
	int				j;
	char			needle;
	
	i = 0;
	j = 0;
	needle = 'P';
	p_pos = (t_coordinates *)malloc(sizeof(t_coordinates));
	if (!p_pos)
	{
		printf("p_pos, malloc null\n");
		return (NULL);
	}
	//char	value;
	//int		x; == length
	//int		y; == height
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n')
		{
			if (map -> map[i][j] == needle)
			{
				p_pos -> value = map -> map[i][j];
				p_pos -> x = j;
				p_pos -> y = i;
				return (p_pos);
			}
			j++;
		}
		i++;
	}
	printf("NULL\n");
	return (NULL);
}

void	flood_fill(t_map *map, int x, int y) //x == -, y == |
{
	if (map -> map[y][x] != '1')
	{
		printf("set mapyx to X\n");
		map -> map[y][x] = 'X';
	}
	else if (map -> map[y][x] == 'X')
	{
		printf("returning\n");
		return ;
	}
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y + 1);
	printf("*\n");
}

int	is_map_valid(t_map *map)
{
	t_map	*copy;
	t_coordinates	*player;

	copy = ft_map_copy(map);
	if (!copy)
	{
		printf("ft_map_copy == null\n");
		return (-1);
	}
	player = find_start_pos(copy);

	/*printf("[player -> value = %c]\n", player -> value);
	printf("[player -> x = %d]\n", player -> x);
	printf("[player -> y = %d]\n", player -> y);
	*/
	printf("0\n");
	flood_fill(copy, player -> x, player -> y);
	printf("001\n");
	int j = 0;
	while (j < copy -> height)
	{
		printf("%s", copy -> map[j]);
		j++;
	}
	return (1);
}

void	check_map(t_map *map)
{
	if (!is_rectangular(map))
		printf("not a rectangular map\n");
	else
		printf("it's a rectangular map\n");
	if (!is_wall(map))
		printf("no wall in borders of map\n");
	else
		printf("wall in borders of map\n");
	if (!duplicate_exit_or_start(map))
		printf("there are more than 1 exit and 1 starting position\n");
	else
		printf("only 1 exit and 1 starting position\n");
	if (!collectibles(map))
		printf("there are no collectibles\n");
	else
		printf("there is at least 1 collectible\n");
	if (!is_map_valid(map))
		printf("there's not a valid path in map\n");
	else
		printf("there's a valid path in map\n");
}

void	read_map(char *str)
{
	int		i;
	int		fd;
	char	*line_gnl;
	char	*map[9999] = {NULL};
	t_map	*map_struct;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		line_gnl = get_next_line(fd);
		if (line_gnl == NULL)
			break ;
		map[i] = line_gnl;
		i++;
	}
	map_struct = populate_map_struct(map);
	int j = 0;
	while (j < i)
	{
		printf("%s", map[j]);
		j++;
	}
	check_map(map_struct); // map arrays need to be freed after use.
	
	j = 0;
	while (j < i)
	{
		printf("%s", map[j]);
		j++;
	}
	
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		read_map(av[1]);
	}
	else
		printf("Error\n");
	return (0);
}
