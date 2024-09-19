/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/19 15:40:17 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_player_by_offset(t_game *game, int y, int x)
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
		print_moves(game->moves);
		if (game->map[next_y][next_x] == 'C')
			collect_coin(game, next_y, next_x);
		if (all_coins_collected(game->images.coins))
			game->images.exit->instances->enabled = true;
		if (game->map[next_y][next_x] == 'E'
			&& game->images.exit->instances->enabled == true)
			mlx_close_window(game->mlx);
		return (1);
	}
	return (0);
}

void	key_pressed_function(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	(void)keydata;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_player_by_offset(game, 0, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move_player_by_offset(game, 0, +1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_player_by_offset(game, -1, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_player_by_offset(game, +1, 0);
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
		ft_putstr_fd("Error\n", 2);
	render_map_images(game);
	mlx_key_hook(game->mlx, &key_pressed_function, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
