/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/16 14:56:01 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*ft_map_copy(t_game *game)
{
	t_game	*map_copy;
	char	**str;
	int		i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!str)
		return (NULL);
	printf("[MALLOC: char ** copy of original char **] ft_valid_map_functions.c\n");
	while (i < game->height)
	{
		str[i] = ft_strdup(game->map[i]);
		i++;
	}
	str[i] = NULL;
	printf("[MALLOC: char * copy of lines] ft_valid_map_functions.c\n");
	map_copy = populate_map_struct(str);
	return (map_copy);
}

t_coordinates	*populate_coord(char p, int x, int y)
{
	t_coordinates	*coord;

	coord = malloc(sizeof(t_coordinates));
	if (!coord)
		return (NULL);
	printf("[MALLOC: t_coordinates *] ft_valid_map_functions.c\n");
	coord -> value = p;
	coord -> x = x;
	coord -> y = y;
	return (coord);
}

t_coordinates	*find_start_pos(t_game *game)
{
	t_coordinates	*p_pos;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n' && game -> map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				p_pos = populate_coord(game->map[i][j], j, i);
				return (p_pos);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game -> map[y][x] == '1')
		return ;
	game -> map[y][x] = '1';
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y + 1);
}

int	check_flood_fill(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game -> map[i] != NULL)
	{
		j = 0;
		while (game -> map[i][j] != '\n' && game -> map[i][j] != '\0')
		{
			if (ft_strrchr("CEP", game -> map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_valid(t_game *game)
{
	t_game			*copy;
	t_coordinates	*player;
	int				res;
	int				j;

	j = 0;
	copy = ft_map_copy(game);
	if (!copy)
		return (0);
	player = find_start_pos(copy); // only send the str + int i and int j to pass to floodfill
	flood_fill(copy, player->x, player->y); // maybe call floodfill in another function
	// that call findstartpos as well. the function would return the value
	res = check_flood_fill(copy); 
	while (copy -> map[j])
	{
		free(copy -> map[j]);
		j++;
	}
	printf("[  FREE: char * copy of lines] ft_valid_map_functions.c\n");
	printf("[  FREE: char ** copy of original char **] ft_valid_map_functions.c\n");
	free(copy->map);
	printf("[  FREE: t_game struct] ft_init_map.c\n");
	free(copy);
	printf("[  FREE: t_coordinates *] ft_valid_map_functions.c\n");
	free(player);
	if (!res)
		return (0);
	return (1);
}
