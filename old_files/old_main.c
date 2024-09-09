/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/09 13:12:26 by sabrifer         ###   ########.fr       */
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
	/*length = 0;
	while (map[0][length] != '\0' && map[0][length] != '\n' && map[0][length] != '\r')
		length++;*/
	length = ft_strlen(map[0]); // len of first array found
	height = 0;
	while (map[height]) // how many arrays there are
		height++;
	map_struct -> map = map;
	map_struct -> length = length - 1; // previously: length;
	map_struct -> height = height;
	return (map_struct);
}
/*
int	is_rectangular(t_map *map)
{
	int		i;
	int		current_len;

	i = 0;
	current_len = 0;
	while (map -> map[i])
	{
		current_len = ft_strlen(map -> map[i]);
		if (i == (map -> height - 1) && current_len == map -> length - 1)
		{
			printf("first if statement == 1\n");
			return (1); // check if it's the last line and the line has no new line at the end
		}
		if (current_len != map -> length)
		{
			printf("second if statement == 0\n");
			return (0);
		}
		i++;
	}
	printf("end of function == 1\n");
	return (1);
}
*/
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
		printf("current_len = %d\n", current_len);
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
			if (i == 0 || j == 0)
			{
				if (map -> map[i][j] != wall)
					return (0);
			}
			else if (i == map -> height - 1 || j == map -> length - 1) // -2
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
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
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
	int		i;
	int		j;
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
	map_copy = (t_map *)malloc(sizeof(t_map));
	if (!map_copy)
	{
		printf("map_copy, malloc null\n");
		return (NULL);
	}
	str = (char **)malloc(sizeof(char *) * (map -> height + 1));
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
	map_copy -> map[i] = NULL;
	map_copy -> height = map -> height;
	map_copy -> length = map -> length;

	/* printing map_copy
	printf("copy copied: \n");
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
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (map -> map[i][j] == needle)
			{
				p_pos -> value = map -> map[i][j];
				p_pos -> x = j;
				p_pos -> y = i;
				//printf("pos: %c and x = %d and y = %d\n\n", p_pos -> value, p_pos -> x, p_pos -> y);
				return (p_pos);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void	flood_fill(t_map *map, int x, int y) //x == -, y == |
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map -> map[i] != NULL)
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
		/*	if (map -> map[i][j] == '0')
			{
				printf("found: 0\n");
				return (0);
			}*/
			if (map -> map[i][j] == 'C')
			{
				printf("found: C\n");
				return (0);
			}
			if (map -> map[i][j] == 'E')
			{
				printf("found: E\n");
				return (0);
			}
			if (map -> map[i][j] == 'P')
			{
				printf("found: P\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_valid(t_map *map)
{
	t_map	*copy;
	t_coordinates	*player;

	copy = ft_map_copy(map);
	if (!copy)
	{
		printf("ft_map_copy == null\n");
		return (0);
	}
	player = find_start_pos(copy);
	flood_fill(copy, player -> x, player -> y);
	int j = 0;
	/*while (copy -> map[j])
	{
		printf("%s", copy -> map[j]);
		j++;
	}
	j = 0;*/
	if (!check_flood_fill(copy))
	{
		while (copy -> map[j])
		{
			free(copy -> map[j]);
			j++;
		}
		free(copy);
		return (0);
	}
	while (copy -> map[j])
	{
		free(copy -> map[j]);
		j++;
	}
	free(copy);
	return (1);
}

int	check_map(t_map *map)
{
	if (!is_rectangular(map))
	{	
		printf("ERROR. not a rectangular map\n");
		return (0);
	}
	if (!is_wall(map))
	{
		printf("ERROR. not a wall found around map\n");
		return (0);
	}
	if (!not_valid_chars(map))
	{
		printf("ERROR. there are invalid chars in map\n");
		return (0);
	}
	if (!collectibles(map))
	{
		printf("ERROR. there are no collectibles\n");
		return (0);
	}
	if (!is_char_player(map))
	{
		printf("ERROR. there isn't a P char\n");
		return (0);
	}
	if (!is_char_map_exit(map))
	{
		printf("ERROR. there isn't a E char\n");
		return (0);
	}
	if (!duplicate_exit_or_start(map))
	{
		printf("ERROR. there are more than 1 exit and 1 starting position\n");
		return (0);
	}
	if (!is_map_valid(map))
	{
		printf("ERROR. there's not a valid path in map\n");
		printf("111111\n");
		return (0);
	}
	return (1);
}

int	read_map(char *str)
{
	int		i;
	int		fd;
	char	*line_gnl;
	char	*map[9999] = {NULL};
	t_map	*map_struct;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
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
		return (0);
	map_struct = populate_map_struct(map);
	if (!map_struct)
		return (0);
	/*int j = 0;
	while (map_struct -> map[j])
	{
		printf("%s", map_struct -> map[j]);
		j++;
	}*/
	if (!check_map(map_struct)) // map arrays need to be freed after use.
		return (0);
/*	j = 0;
	while (map_struct -> map[j])
	{
		free(map_struct -> map[j]);
		j++;
	}*/
	free(map_struct);
	close(fd);
	return (1);
}

int	check_ber(char *str)
{
	char	*str_found;
	int		i;

	i = 0;
	str_found = ft_strrchr(str, '.');
	if (!str_found)	//char	*ft_strrchr(const char *str, int c)
		return (0);
	if (ft_strncmp(str_found, ".ber", 4) == 0)
		return (1);
	return (0);	
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!check_ber(av[1]))
		{
			printf("not a ber file\n");
			return (0);
		}
		if (read_map(av[1]))
		{
			printf("ALL Ok\n");
		}
		else
			printf("ERROR\n");
	}
	else
		printf("Error\n");
	return (0);
}
