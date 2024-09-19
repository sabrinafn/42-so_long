/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/18 15:16:12 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collect_coin(t_game *game, int y, int x)
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

void	render_map_images(t_game *game)
{
	place_wall(game->mlx, game);
	place_floor(game->mlx, game);
	place_player(game->mlx, game);
	place_coin(game->mlx, game);
	place_exit(game->mlx, game);
}

void	print_moves(int moves)
{
	ft_putstr_fd("Number of movements: ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putstr_fd("\n", 1);
}
