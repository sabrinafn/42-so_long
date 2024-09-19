/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checklist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/16 11:04:49 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_rectangular(t_game *game)
{
	int		i;
	int		current_len;

	i = 0;
	current_len = 0;
	while (game -> map[i])
	{
		current_len = ft_strlen(game -> map[i]);
		if (game -> map[i][current_len - 1] == '\n')
			current_len -= 1;
		if (current_len != game -> length)
			return (0);
		i++;
	}
	return (1);
}

int	is_wall(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game -> map[i])
	{
		j = 0;
		while (game -> map[i][j] != '\n' && game -> map[i][j] != '\0')
		{
			if (i == 0 || j == 0 || i == game -> height - 1
				|| j == game -> length - 1)
			{
				if (game -> map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	duplicate_exit_or_player(t_game *game)
{
	int		i;
	int		j;
	int		c;
	bool	char_arr[256];

	i = 0;
	ft_memset(char_arr, false, sizeof(char_arr));
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			c = game->map[i][j];
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

int	are_valid_chars_present(t_game *game)
{
	int		i;
	int		j;
	int		c;
	bool	char_arr[256];

	i = 0;
	j = 0;
	ft_memset(char_arr, false, sizeof(char_arr));
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			c = game->map[i][j];
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

int	is_valid_char(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (!ft_strrchr("01CEP", game -> map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
