/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/16 13:33:51 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_initial_map(mlx_t *mlx, char **map, int rows, int cols)
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	int			i;
	int			j;

	wall = mlx_texture_to_image(mlx, mlx_load_png("./images/wall.png"));
	floor = mlx_texture_to_image(mlx, mlx_load_png("./images/floor.png"));
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == '1')
				mlx_image_to_window(mlx, wall, j * TILE_SIZE, i * TILE_SIZE);
			else
				mlx_image_to_window(mlx, floor, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	place_player(mlx_t *mlx, t_game *game)
{
	mlx_image_t	*player;
	int			i;
	int			j;

	player = mlx_texture_to_image(mlx, mlx_load_png("./images/bananacat.png"));
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->map[i][j] == 'P')
			{
				mlx_image_to_window(mlx, player, j * TILE_SIZE, i * TILE_SIZE);
				game->images.player = player;
			}
			j++;
		}
		i++;
	}
}

void	place_coin(mlx_t *mlx, t_game *game)
{
	mlx_image_t	*coin;
	int			i;
	int			j;

	coin = mlx_texture_to_image(mlx, mlx_load_png("./images/coin.png"));
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->map[i][j] == 'C')
			{
				mlx_image_to_window(mlx, coin, j * TILE_SIZE, i * TILE_SIZE);
				game->images.coins = coin;
			}
			j++;
		}
		i++;
	}
}

void	place_exit(mlx_t *mlx, t_game *game)
{
	mlx_image_t	*exit;
	int			i;
	int			j;

	exit = mlx_texture_to_image(mlx, mlx_load_png("./images/exit.png"));
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->map[i][j] == 'E')
			{
				mlx_image_to_window(mlx, exit, j * TILE_SIZE, i * TILE_SIZE);
				game->images.exit = exit;
				game->images.exit->instances->enabled = false;
			}
			j++;
		}
		i++;
	}
}
