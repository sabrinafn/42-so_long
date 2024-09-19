/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:52:43 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/19 16:36:00 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE 32
# define MAX_HEIGHT 992
# define MAX_LENGTH 1920

typedef struct s_images
{
	mlx_image_t	*coins;
	mlx_image_t	*player;
	mlx_image_t	*exit;
}	t_images;

typedef struct s_game
{
	char		**map;
	int			length;
	int			height;
	int			moves;
	int			player_x;
	int			player_y;
	mlx_t		*mlx;
	t_images	images;
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

// FT_ARGS_CHECKLIST.C

int		check_map_more(t_game *game);
int		check_map(t_game *game);
int		is_ber_filetype(char *str);

// FT_CHECK_ARGS.C

int		is_rectangular(t_game *game);
int		is_wall(t_game *game);
int		duplicate_exit_or_player(t_game *game);
int		are_valid_chars_present(t_game *game);
int		is_valid_char(t_game *game);

// FT_CHECK_VALID_PATH.C

char	**ft_map_copy(t_game *game);
void	find_player_position(t_game *game);
void	flood_fill(char **map, int x, int y);
int		check_flood_fill(char **map);
int		is_map_valid(t_game *game);

// FT_INIT_MAP.C

t_game	*populate_map_struct(char **map);
int		ft_file_len(char *filename);
char	**read_map(int fd, int line_count);
t_game	*init_map(char *filename);

// FT_INIT_WINDOW.C

int		move_player_by_offset(t_game *game, int x, int y);
void	key_pressed_function(mlx_key_data_t keydata, void *param);
void	init_window(t_game *game);

// FT_INIT_WINDOW_UTILS.C

void	collect_coin(t_game *game, int y, int x);
int		all_coins_collected(mlx_image_t *coin);
void	render_map_images(t_game *game);
void	print_moves(int moves);
void	check_for_coin_or_exit(t_game *game, int y, int x);

// FT_PUT_IMAGES.C

void	place_wall(mlx_t *mlx, t_game *game);
void	place_floor(mlx_t *mlx, t_game *game);
void	place_player(mlx_t *mlx, t_game *game);
void	place_coin(mlx_t *mlx, t_game *game);
void	place_exit(mlx_t *mlx, t_game *game);

// FT_UTILS.C

char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *dest, int c, size_t count);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
