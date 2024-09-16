/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:52:43 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/16 14:06:09 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//standard libraries
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

//minilibx
# include "MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE 32 // each tile on the map will be 32x32 pixels

// STRUCTURES FOR THE ARGS CHECK

typedef struct s_coordinates
{
	char	value;
	int		x;
	int		y;
}	t_coordinates;

// STRUCTURES FOR THE MAP WINDOW?

typedef struct s_images
{
	mlx_image_t	*coins;
	mlx_image_t	*player;
	mlx_image_t	*exit;
}	t_images;

typedef struct s_game
{
	char			**map;
	int				length;
	int				height;
	int				moves;
	mlx_t			*mlx;
	t_images		images;
}	t_game;

/***GET_NEXT_LINE******/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);

/*********************/

// FT_INIT_WINDOW
void	init_window(t_game *game);

// FT_PUT_IMAGES
void	place_exit(mlx_t *mlx, t_game *game);//char **map, int rows, int cols);
void	place_coin(mlx_t *mlx, t_game *game);//char **map, int rows, int cols);
void	place_player(mlx_t *mlx, t_game *game);//har **map, int rows, int cols);
void	render_initial_map(mlx_t *mlx, char **map, int rows, int cols);

// FT_UTILS.C
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *dest, int c, size_t count);

// FT_ARGS_CHECKLIST.C
int		is_invalid_char(t_game *game);
int		check_chars(t_game *game);
int		duplicate_exit_or_start(t_game *game);
int		is_wall(t_game *game);
int		is_rectangular(t_game *game);

// FT_ARGS_CHECK.C
int		check_map(t_game *game);
int		check_ber(char *str);

// 	FT_INIT_MAP.C
t_game	*populate_map_struct(char **map);
int		count_line_infd(char *file_name);
char	**read_map(int fd, int line_count);
t_game	*init_map(char *file_name);

// MAIN
int		is_map_valid(t_game *game);
int		check_flood_fill(t_game *game);
void	flood_fill(t_game *game, int x, int y);
t_coordinates	*find_start_pos(t_game *game);
t_coordinates	*populate_coord(char p, int x, int y);
t_game			*ft_map_copy(t_game *game);

#endif
