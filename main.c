#include "so_long.h"
#include <fcntl.h>

/*typedef struct s_map
{
	char	**map;
	int		length;
	int		height;
}	t_map;
*/

t_map	populate_map_struct(char **map)
{
	t_map	map_struct;
	int		height;
	int		length;

	length = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	map_struct.map = map;
	map_struct.length = length;
	map_struct.height = height;
	return (map_struct);
}

int	is_rectangular(t_map map)
{
	int		i;
	
	i = 0;
	while (map.map[i])
	{
		if (ft_strlen(map.map[i]) != (size_t)map.length)
			return (0);
		i++;
	}
	return (1);
}

int	is_wall(t_map map)
{
	char	wall;
	int		i;
	int		j;

	wall  = '1';
	i = 0;
	j = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j] != '\n')
		{
			if (i == 0 || i == map.height - 1)
			{
				if (map.map[i][j] != wall)
					return (0);
			}
			if (j == 0 || j == map.length - 2)
			{
				if (map.map[i][j] != wall)
					return (0);
			}
			j++;		
		}
		i++;
	}
	return (1);
}

int	duplicate_exit_or_start(t_map map)
{
	int		i;
	int		j;
	bool	char_arr[256] = {false};
	char	exit;
	char	start;

	i = 0;
	j = 0;
	exit = 'E';
	start = 'P';
	int	c;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j] != '\n')
		{
			c = map.map[i][j];
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

int	collectibles(t_map map)
{
	int		i;
	int		j;
	char	coin;

	i = 0;
	j = 0;
	coin = 'C';
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j] != '\n')
		{
			if (map.map[i][j] == coin)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_map_valid(t_map map)
{
	t_map	map_copy;

	map_copy = malloc(sizeof(t_map));
	if (!map_copy)
	{
		printf("malloc null\n");
		return (-1);
	}
	
}

void	check_map(t_map map)
{
	if (!is_rectangular(map))	
		printf("not a rectangular map\n");
	if (!is_wall(map))
		printf("no wall in borders of map\n");
	if (!duplicate_exit_or_start(map))
		printf("there are more than 1 exit and 1 starting position\n");
	if (!collectibles(map))
		printf("there are no collectibles\n");
	if (!is_map_valid(map))
		printf("map is not valid\n");
}

void	read_map(char *str)
{
	int	fd;
	char *line_gnl;
	char *map[9999] = {NULL};

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return ;
	int i = 0;
	while (1)
	{
		line_gnl = get_next_line(fd);
		if (line_gnl == NULL)
			break;
		map[i] = line_gnl;
		i++;
	}
	t_map	map_struct;
	map_struct = populate_map_struct(map);
	// map arrays need to be freed after use.
	check_map(map_struct);
	/*
	int j = 0;
	while (j < i)
	{
		printf("%s", map[j]);
		j++;
	}
	*/
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
