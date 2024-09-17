/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/17 14:52:21 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_and_delete(t_game *game, int y, int x)
{
	int		lst_y;
	int		lst_x;
	size_t	i;

	i = 0;
	while (i < game->images.coins->count)
	{
		lst_y = game->images.coins->instances[i].y / TILE_SIZE;
		lst_x = game->images.coins->instances[i].x / TILE_SIZE;
		if (lst_y == y && lst_x == x)
			game->images.coins->instances[i].enabled = false;
		i++;
	}
}

int	all_coins_collected(mlx_image_t *coin)
{
	size_t		i;

	i = 0;
	while (i < coin->count)
	{
		if (coin->instances[i].enabled == true)
			return (0);
		i++;
	}
	return (1);
}

int	moveit_moveit(t_game *game, int x, int y)
{
	int	current_x;
	int	current_y;
	int	next_x;
	int	next_y;

	current_x = game->images.player->instances->x / TILE_SIZE;
	current_y = game->images.player->instances->y / TILE_SIZE;
	next_x = current_x + x;
	next_y = current_y + y;
	if (game->map[next_y][next_x] != '1')
	{
		game->images.player->instances->y = next_y * TILE_SIZE;
		game->images.player->instances->x = next_x * TILE_SIZE;
		game->moves += 1;
		if (game->map[next_y][next_x] == 'C')
			find_and_delete(game, next_y, next_x);
		if (all_coins_collected(game->images.coins))
			game->images.exit->instances->enabled = true;
		if (game->map[next_y][next_x] == 'E'
			&& game->images.exit->instances->enabled == true)
			mlx_close_window(game->mlx);
		return (1);
	}
	return (0);
}
/*
int	move_player(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		return (moveit_moveit(game, -1, 0));
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		return (moveit_moveit(game, +1, 0));
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		return (moveit_moveit(game, 0, -1));
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		return (moveit_moveit(game, 0, +1));
	return (0);
}

void	key_pressed_function(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	(void)keydata;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		if (move_player(game))
			printf("moves: %d\n", moves);
	}
}*/

void	key_pressed_function(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	(void)keydata;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		if (moveit_moveit(game, -1, 0))
			printf("moves: %d\n", game->moves);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		if (moveit_moveit(game, +1, 0))
			printf("moves: %d\n", game->moves);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		if (moveit_moveit(game, 0, -1))
			printf("moves: %d\n", game->moves);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		if (moveit_moveit(game, 0, +1))
			printf("moves: %d\n", game->moves);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

void	init_window(t_game *game)
{
	int	window_height;
	int	window_length;

	window_height = game->height * TILE_SIZE;
	window_length = game->length * TILE_SIZE;
	game->mlx = mlx_init(window_length, window_height, "so_long", true);
	if (!game->mlx)
		printf("error\n");
	place_floor(game->mlx, game);
	place_wall(game->mlx, game);
	place_player(game->mlx, game);
	place_coin(game->mlx, game);
	place_exit(game->mlx, game);
	mlx_key_hook(game->mlx, &key_pressed_function, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
