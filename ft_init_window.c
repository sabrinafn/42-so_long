/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/16 13:35:05 by sabrifer         ###   ########.fr       */
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

int	move_left(t_game *game)
{
	int current_x = game->images.player->instances->x / TILE_SIZE;
	int current_y = game->images.player->instances->y / TILE_SIZE;

	if (game->map[current_y][current_x - 1] != '1')
	{
		//	move_left
		if (game->images.player->instances->x - 32 > 0)
		{
			game->images.player->instances->x -= 32;
			game->moves +=1;
			if (game->map[current_y][current_x - 1] == 'C')
				find_and_delete(game, current_y, current_x - 1);
			if (game->map[current_y][current_x -1] == 'E'
				&& all_coins_collected(game->images.coins)
				&& game->images.exit->instances->enabled == true)
				mlx_close_window(game->mlx);
			if (all_coins_collected(game->images.coins))
			{
				game->images.exit->instances->enabled = true;
				printf("*********\n");	
			}	
			return (1);
		}
	}
	return (0);
}

int	move_right(t_game *game)
{
	int current_x = game->images.player->instances->x / TILE_SIZE;
	int current_y = game->images.player->instances->y / TILE_SIZE;

	if (game->map[current_y][current_x + 1] != '1')
	{
		//	move_right
		//TILE_SIZE * map->length = total_length_size
		int32_t x_total = (TILE_SIZE * game->length) - 32;
	
		// adding value to variable
		int32_t current = game->images.player->instances->x;
	
		if (current + 32 < x_total)
		{
			game->images.player->instances->x += 32;
			game->moves +=1;
			if (game->map[current_y][current_x + 1] == 'C')
				find_and_delete(game, current_y, current_x + 1);
			if (game->map[current_y][current_x + 1] == 'E'
				&& all_coins_collected(game->images.coins)
				&& game->images.exit->instances->enabled == true)
				mlx_close_window(game->mlx);
			if (all_coins_collected(game->images.coins))
				game->images.exit->instances->enabled = true;
			return (1);
		}
	}
	return (0);
}

int	move_up(t_game *game)
{
	int current_x = game->images.player->instances->x / TILE_SIZE;
	int current_y = game->images.player->instances->y / TILE_SIZE;

	if (game->map[current_y - 1][current_x] != '1')
	{
		//	move_up
		if (game->images.player->instances->y - 32 > 0)
		{
			game->images.player->instances->y -= 32;
			game->moves +=1;
			if (game->map[current_y - 1][current_x] == 'C')
				find_and_delete(game, current_y - 1, current_x);
			if (game->map[current_y - 1][current_x] == 'E'
				&& all_coins_collected(game->images.coins)
				&& game->images.exit->instances->enabled == true)
				mlx_close_window(game->mlx);
			if (all_coins_collected(game->images.coins))
			{
				game->images.exit->instances->enabled = true;
				printf("*********\n");	
			}
			return (1);
		}
	}
	return (0);
}

	//map->images.player = player;
int	move_down(t_game *game)
{
	int current_x = game->images.player->instances->x / TILE_SIZE;
	int current_y = game->images.player->instances->y / TILE_SIZE;

	if (game->map[current_y + 1][current_x] != '1')
	{
		//	move_down
		//TILE_SIZE * map->height = total_length_size
		int32_t y_total = (TILE_SIZE * game->height) - 32;
		
		// adding value to variable
		int32_t current = game->images.player->instances->y;
	
		if (current + 32 < y_total)
		{
			game->images.player->instances->y += 32;
			game->moves +=1;
			if (game->map[current_y + 1][current_x] == 'C')
				find_and_delete(game, current_y + 1, current_x);
			if (all_coins_collected(game->images.coins))
				game->images.exit->instances->enabled = true;
			if (game->map[current_y + 1][current_x] == 'E'
				&& all_coins_collected(game->images.coins)
				&& game->images.exit->instances->enabled == true)
				mlx_close_window(game->mlx);
			return (1);
		}
	}
	return (0);
}

int	move_player(mlx_key_data_t keydata, t_game *game)
{
	//	move_left
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		if (move_left(game))
			return (1);
	}
	//	move_right
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		if (move_right(game))	
			return (1);
	}
	//	move_up
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		if (move_up(game))
			return (1);
	}
	//	move_down
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		if (move_down(game))
			return (1);
	}
	// key down: act
	// key_hook: identify
//	printf("tecla num: %d\n", keydata.key);
	(void)keydata;
	return (0);
}

void	print_moves(int	moves)
{
	printf("moves: %d\n", moves);
}

void	key_pressed_function(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	//	close window with esc
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		if (move_player(keydata, game))
			print_moves(game->moves);
	}
	
	// key down: act
	// key_hook: identify
//	printf("tecla num: %d\n", keydata.key);
	(void)keydata;
}

void	init_window(t_game *game)
{
	int	WINDOW_HEIGHT = game->height * TILE_SIZE;
	int	WINDOW_LENGTH = game->length * TILE_SIZE;
	game->mlx = mlx_init(WINDOW_LENGTH, WINDOW_HEIGHT, "so_long", true);
	if (!game->mlx) // error check
		printf("error\n"); // free mlx if not possible to open the window
	// LOAD IMAGES/TEXTURE
	render_initial_map(game->mlx, game -> map, game -> height, game -> length);

	place_player(game->mlx, game);//map -> map, map -> height, map -> length);
	place_coin(game->mlx, game);//map -> map, map -> height, map -> length);
	place_exit(game->mlx, game);//map -> map, map -> height, map -> length);

	mlx_key_hook(game->mlx, &key_pressed_function, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx); // mlx_end_loop
}
