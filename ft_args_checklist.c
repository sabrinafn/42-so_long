/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checklist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/09 19:26:20 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_map *map)
{
	int		i;
	int		current_len;

	i = 0;
	current_len = 0;
	while (map -> map[i])
	{
		current_len = ft_strlen(map -> map[i]);
		if (map -> map[i][current_len - 1] == '\n')
			current_len -= 1;
		if (current_len != map -> length)
			return (0);
		i++;
	}
	return (1);
}

int	is_wall(t_map *map)
{
	char	wall;
	int		i;
	int		j;

	wall = '1';
	i = 0;
	j = 0;
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (i == 0 || j == 0 || i == map -> height - 1
				|| j == map -> length - 1)
			{
				if (map -> map[i][j] != wall)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	duplicate_exit_or_start(t_map *map)
{
	int		i;
	int		j;
	int		c;
	bool	char_arr[256];

	i = 0;
	ft_memset(char_arr, false, sizeof(char_arr));
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			c = map -> map[i][j];
			if (c == 'E' || c == 'P')
			{
				if (char_arr[c] == true)
					return (0);
				char_arr[c] = true;
			}
			j++;
		}
		i++;
	}
	return (1);
}
/*
int	is_char_map_exit(t_map *map)
{
	int		i;
	int		j;
	char	exit;

	i = 0;
	j = 0;
	exit = 'E';
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (map -> map[i][j] == exit)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_char_player(t_map *map)
{
	int		i;
	int		j;
	char	player;

	i = 0;
	j = 0;
	player = 'P';
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (map -> map[i][j] == player)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	collectibles(t_map *map)
{
	int		i;
	int		j;
	char	coin;

	i = 0;
	j = 0;
	coin = 'C';
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (map -> map[i][j] == coin)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}*/

int	check_chars(t_map *map)
{
	int		i;
	int		j;
	int		c;
	bool	char_arr[256];

	i = 0;
	j = 0;
	ft_memset(char_arr, false, sizeof(char_arr));
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			c = map -> map[i][j];
			if (c == 'C' || c == 'E' || c == 'P')
				char_arr[c] = true;
			j++;
		}
		i++;
	}
	if (char_arr[(unsigned char) 'C'] && char_arr[(unsigned char) 'E']
		&& char_arr[(unsigned char) 'P'])
		return (1);
	return (0);
}

int	is_invalid_char(t_map *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j] != '\n' && map -> map[i][j] != '\0')
		{
			if (!ft_strrchr("01CEP", map -> map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
