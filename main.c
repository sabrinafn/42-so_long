/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/15 14:33:41 by sabrifer         ###   ########.fr       */
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
			printf("not a ber file\n");
			return (0);
		}
		game = init_map(av[1]);
		if (game)
		{
			if (check_map(game))
			{
				printf("check_map OK\n");
				init_window(game);
			}			
			else
				printf("check_map KO\n");
			free(game);
		}
		else
			printf("ERROR\n");
	}
	else
		printf("Error\n");
	return (0);
}
