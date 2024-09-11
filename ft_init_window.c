/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/10 20:03:13 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define TILE_SIZE 32 // Each tile on the map will be 64x64 pixels

// Function to draw the map
void draw_map(mlx_t* mlx, char** map, int rows, int cols) {
    mlx_image_t* wall = mlx_texture_to_image(mlx, mlx_load_png("./images/wall.png"));
	mlx_image_t* ground = mlx_texture_to_image(mlx, mlx_load_png("./images/space.png"));

    // Loop through the map and draw the appropriate image for each tile
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            if (map[y][x] == '1') {
                mlx_image_to_window(mlx, wall, x * TILE_SIZE, y * TILE_SIZE);
            } else {
                mlx_image_to_window(mlx, ground, x * TILE_SIZE, y * TILE_SIZE);
            }
        }
    }
}

void	init_window(t_map *map)
{
	// DECLARE DATA AND OPEN WINDOW

	mlx_t	*mlx; // declare data struct to hold value from connection with graphycal system
					// and store window

	mlx = mlx_init(WINDOW_HEIGHT, WINDOW_WIDTH, "HELLO WORLD!", false);
	if (!mlx) // error check
		printf("error\n"); // free mlx if not possible to open the window

	// LOAD IMAGES/TEXTURE
	draw_map(mlx, map -> map, map -> height, map -> length);
	mlx_loop(mlx);

	mlx_terminate(mlx);
}
