/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/19 15:05:15 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		i;

	if (ac != 2 || !is_ber_filetype(av[1]))
		ft_error("Error\nThe correct usage is: ./so_long filename\n");
	game = init_map(av[1]);
	if (!game)
		ft_error("Error\nThe file is not valid.\n");
	if (check_map(game))
		init_window(game);
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
	return (0);
}
