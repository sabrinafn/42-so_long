/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/09 19:46:38 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_map *map)
{
	if (!is_rectangular(map))
		return (0);
	if (!is_wall(map))
		return (0);
	if (!is_invalid_char(map))
		return (0);
	if (!check_chars(map))
		return (0);
	if (!duplicate_exit_or_start(map))
		return (0);
	if (!is_map_valid(map))
		return (0);
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
