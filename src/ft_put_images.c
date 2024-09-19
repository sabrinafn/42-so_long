/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/19 13:36:37 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	place_wall(mlx_t *mlx, t_game *game)
{
	mlx_image_t		*wall;
	mlx_texture_t	*wall_texture;
	int				i;
	int				j;

	wall_texture = mlx_load_png("./images/wall.png");
	wall = mlx_texture_to_image(mlx, wall_texture);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->map[i][j] == '1')
				mlx_image_to_window(mlx, wall, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
	mlx_delete_texture(wall_texture);
}

void	place_floor(mlx_t *mlx, t_game *game)
{
	mlx_image_t		*floor;
	mlx_texture_t	*floor_texture;
	int				i;
	int				j;

	floor_texture = mlx_load_png("./images/floor.png");
	floor = mlx_texture_to_image(mlx, floor_texture);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->map[i][j] != '1')
				mlx_image_to_window(mlx, floor, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
	mlx_delete_texture(floor_texture);
}

void	place_player(mlx_t *mlx, t_game *game)
{
	mlx_image_t		*player;
	mlx_texture_t	*player_texture;
	int				i;
	int				j;

	player_texture = mlx_load_png("./images/bananacat.png");
	player = mlx_texture_to_image(mlx, player_texture);
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
	mlx_delete_texture(player_texture);
}

void	place_coin(mlx_t *mlx, t_game *game)
{
	mlx_image_t		*coin;
	mlx_texture_t	*coin_texture;
	int				i;
	int				j;

	coin_texture = mlx_load_png("./images/coin.png");
	coin = mlx_texture_to_image(mlx, coin_texture);
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
	mlx_delete_texture(coin_texture);
}

void	place_exit(mlx_t *mlx, t_game *game)
{
	mlx_image_t		*exit;
	mlx_texture_t	*exit_texture;
	int				i;
	int				j;

	exit_texture = mlx_load_png("./images/exit.png");
	exit = mlx_texture_to_image(mlx, exit_texture);
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
	mlx_delete_texture(exit_texture);
}
