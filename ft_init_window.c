/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/11 17:58:34 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_pressed_function(mlx_key_data_t keydata, void *param)
{
	(void)param;
	/*
	if (mlx_key_down(param, MLX_KEY_ESCAPE))
		mlx_end_loop();
	if (mlx_key_down(param, MLX_KEY_LEFT))
		function_to_move_player(left);
		
	else if (sys == left)
	gklgksldg
	
	else
		return;

	// key down: act
	// key_hook: identify
	*/
	printf("tecla num: %d\n", keydata.key);
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
	place_exit(mlx, map -> map, map -> height, map -> length);	

	mlx_key_hook(mlx, &key_pressed_function, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx); // mlx_end_loop
}
