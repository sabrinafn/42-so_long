/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/16 14:37:21 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac > 1)
	{
		if (!check_ber(av[1]))
		{
			//ft_putstr("not a ber file\n", 2);
			return (0);
		}
		game = init_map(av[1]);
		if (game)
		{
			if (check_map(game))
			{
				//ft_putstr("check_map OK\n", 1);
				init_window(game);
			}			
//			else
				//ft_putstr("check_map KO\n", 2);
			int i = 0;
			while (game->map[i])
			{
				free(game->map[i]);
				i++;
			}
			printf("[  FREE: GNL store line] main.c\n");
			free(game->map);
			printf("[  FREE: char ** for map] main.c\n");
			free(game);
			printf("[  FREE: t_game struct] main.c\n");
		}
//		else
			//ft_putstr("Error\n", 2);
	}
//	else
	//	ft_putstr("Error\n", 2);
	return (0);
}
