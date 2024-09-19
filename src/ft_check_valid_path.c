/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/18 17:22:40 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_map_copy(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (NULL);
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	find_player_position(t_game *game)
{
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
				game->player_y = i;
				game->player_x = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y + 1);
}

int	check_flood_fill(char **map)
{	
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (ft_strrchr("CEP", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_valid(t_game *game)
{
	char			**map_copy;
	int				res;
	int				j;

	j = 0;
	map_copy = ft_map_copy(game);
	if (!map_copy)
		return (0);
	find_player_position(game);
	flood_fill(map_copy, game->player_x, game->player_y);
	res = check_flood_fill(map_copy);
	while (map_copy[j])
	{
		free(map_copy[j]);
		j++;
	}
	free(map_copy);
	if (!res)
		return (0);
	return (1);
}
