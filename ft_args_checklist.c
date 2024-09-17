/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checklist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/17 14:13:50 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game *game)
{
	if (!is_rectangular(game))
		return (0);
	if (!is_wall(game))
		return (0);
	if (!is_invalid_char(game))
		return (0);
	if (!check_chars(game))
		return (0);
	if (!duplicate_exit_or_start(game))
		return (0);
	if (!is_map_valid(game))
		return (0);	
	if (game->height > 1080 && game->length > 1920)
		return(1);
	return (1);
}

int	check_ber(char *str)
{
	char	*str_found;

	str_found = ft_strrchr(str, '.');
	if (!str_found)
		return (0);
	if (ft_strncmp(str_found, ".ber", 4) == 0)
		return (1);
	return (0);
}
