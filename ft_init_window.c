/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/14 13:29:32 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_map *map)
{
	int current_x = map->images.player->instances->x / TILE_SIZE;
	int current_y = map->images.player->instances->y / TILE_SIZE;

	if (map->map[current_y][current_x - 1] != '1')
	{
		//	move_left
		if (map->images.player->instances->x - 32 > 0)
		{
			map->images.player->instances->x -= 32;
			map->moves +=1;
			if (map->map[current_y][current_x - 1] == 'C')
				printf("coincoincoin\n");
				//mlx_delete_image(map->mlx, image);
			return (1);
		}
	}
	return (0);
}

int	move_right(t_map *map)
{
	int current_x = map->images.player->instances->x / TILE_SIZE;
	int current_y = map->images.player->instances->y / TILE_SIZE;

	if (map->map[current_y][current_x + 1] != '1')
	{
		//	move_right
		//TILE_SIZE * map->length = total_length_size
		int32_t x_total = (TILE_SIZE * map->length) - 32;
	
		// adding value to variable
		int32_t current = map->images.player->instances->x;
	
		if (current + 32 < x_total)
		{
			map->images.player->instances->x += 32;
			map->moves +=1;
			return (1);
		}
	}
	return (0);
}

int	move_up(t_map *map)
{
	int current_x = map->images.player->instances->x / TILE_SIZE;
	int current_y = map->images.player->instances->y / TILE_SIZE;

	if (map->map[current_y - 1][current_x] != '1')
	{
		//	move_up
		if (map->images.player->instances->y - 32 > 0)
		{
			map->images.player->instances->y -= 32;
			map->moves +=1;
			return (1);
		}
	}
	return (0);
}

	//map->images.player = player;
int	move_down(t_map *map)
{
	int current_x = map->images.player->instances->x / TILE_SIZE;
	int current_y = map->images.player->instances->y / TILE_SIZE;

	if (map->map[current_y + 1][current_x] != '1')
	{
		//	move_down
		//TILE_SIZE * map->height = total_length_size
		int32_t y_total = (TILE_SIZE * map->height) - 32;
		
		// adding value to variable
		int32_t current = map->images.player->instances->y;
	
		if (current + 32 < y_total)
		{
			map->images.player->instances->y += 32;
			map->moves +=1;
			return (1);
		}
	}
	return (0);
}

int	move_player(mlx_key_data_t keydata, t_map *map)
{
	//	move_left
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
	{
		if (move_left(map))
			return (1);
	}
	//	move_right
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
	{
		if (move_right(map))	
			return (1);
	}
	//	move_up
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
	{
		if (move_up(map))
			return (1);
	}
	//	move_down
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
	{
		if (move_down(map))
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
	t_map	*map;

	map = param;
	//	close window with esc
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(map->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(map->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
	{
		if (move_player(keydata, map))
			print_moves(map->moves);
	}
	
	// key down: act
	// key_hook: identify
//	printf("tecla num: %d\n", keydata.key);
	(void)keydata;
}

void	init_window(t_map *map)
{
	// DECLARE DATA AND OPEN WINDOW
//	mlx_t	*mlx; // declare data struct to hold value from connection with graphycal system
					// and store window
	int	WINDOW_HEIGHT = map->height * TILE_SIZE;
	int	WINDOW_LENGTH = map->length * TILE_SIZE;
	map->mlx = mlx_init(WINDOW_LENGTH, WINDOW_HEIGHT, "so_long", true);
	if (!map->mlx) // error check
		printf("error\n"); // free mlx if not possible to open the window
	// LOAD IMAGES/TEXTURE
	render_initial_map(map->mlx, map -> map, map -> height, map -> length);

	place_player(map->mlx, map);//map -> map, map -> height, map -> length);
	place_coin(map->mlx, map);//map -> map, map -> height, map -> length);
	place_exit(map->mlx, map);//map -> map, map -> height, map -> length);

	mlx_key_hook(map->mlx, &key_pressed_function, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx); // mlx_end_loop
}
