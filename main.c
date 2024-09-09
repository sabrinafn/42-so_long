/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:40:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/09 19:45:07 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac > 1)
	{
		if (!check_ber(av[1]))
		{
			printf("not a ber file\n");
			return (0);
		}
		map = init_map(av[1]);
		if (map)
		{
			if (check_map(map))
				printf("check_map OK\n");
			else
				printf("check_map KO\n");
			free(map);
		}
		else
			printf("ERROR\n");
	}
	else
		printf("Error\n");
	return (0);
}
