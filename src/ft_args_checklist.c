/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checklist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/18 17:28:26 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_more(t_game *game)
{
	if (!duplicate_exit_or_player(game))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map contains duplicate exits or players on the map.\n", 2);
		return (0);
	}
	if (!is_map_valid(game))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The map does not have a valid path.\n", 2);
		return (0);
	}
	if (game->height * TILE_SIZE > MAX_HEIGHT)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The map exceeds the maximum allowed dimensions.\n", 2);
		return (0);
	}
	if (game->length * TILE_SIZE > MAX_LENGTH)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The map exceeds the maximum allowed dimensions.\n", 2);
		return (0);
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!is_rectangular(game))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The map is not rectangular.\n", 2);
		return (0);
	}
	if (!is_wall(game))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The map's boudaries are not surrounded by walls.\n", 2);
		return (0);
	}
	if (!is_valid_char(game))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The map contains invalid characters.\n", 2);
		return (0);
	}
	if (!are_valid_chars_present(game))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The map lacks required characters.\n", 2);
		return (0);
	}
	return (check_map_more(game));
}

int	is_ber_filetype(char *str)
{
	char	*str_found;

	str_found = ft_strrchr(str, '.');
	if (!str_found)
		return (0);
	if (ft_strncmp(str_found, ".ber", 4) == 0)
		return (1);
	return (0);
}
