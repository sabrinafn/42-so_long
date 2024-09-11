/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/11 13:43:11 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define TILE_SIZE 32 // each tile on the map will be 32x32 pixels

/*******************************\
typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	size_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;
\*******************************/

// they're not linked
// create two structures first. space and wall.
// return these structures to pass to function to initialise map

// create structures for coin and player / coin, player and exit
// they are placed on the map after the map is initialised

// place exit at the end / place exit together with coin and player

void	render_initial_map(mlx_t* mlx, char** map, int rows, int cols)
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

void	place_player(mlx_t *mlx, char **map, int rows, int cols)
{
	mlx_image_t	*player;
	int			i;
	int			j;

	player = mlx_texture_to_image(mlx, mlx_load_png("./images/bananacat.png"));
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'P')
				mlx_image_to_window(mlx, player, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	place_coin(mlx_t *mlx, char **map, int rows, int cols)
{
	mlx_image_t	*coin;
	int			i;
	int			j;

	coin = mlx_texture_to_image(mlx, mlx_load_png("./images/coin.png"));
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'C')
				mlx_image_to_window(mlx, coin, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	init_window(t_map *map)
{
	// DECLARE DATA AND OPEN WINDOW

	mlx_t	*mlx; // declare data struct to hold value from connection with graphycal system
					// and store window

	mlx = mlx_init(WINDOW_HEIGHT, WINDOW_WIDTH, "so_long", true);
	if (!mlx) // error check
		printf("error\n"); // free mlx if not possible to open the window

	// LOAD IMAGES/TEXTURE
	render_initial_map(mlx, map -> map, map -> height, map -> length);
	
	place_player(mlx, map -> map, map -> height, map -> length);	
	place_coin(mlx, map -> map, map -> height, map -> length);	



	mlx_loop(mlx);

	mlx_terminate(mlx);
}
