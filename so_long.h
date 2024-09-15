/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:52:43 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/15 13:08:28 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

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
/*
typedef struct s_coins
{
	mlx_image_t			*data;
	struct s_coins		*next;
}	t_coins;
*/
typedef struct s_images
{
	mlx_image_t	*coins;
	mlx_image_t	*player;
	mlx_image_t	*exit;
}	t_images;

typedef struct s_map
{
	char			**map;
	int				length;
	int				height;
	int				moves;
	int				coins_amount;
	mlx_t			*mlx;
	t_images		images;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;
/*
// FT_LINKED_LIST_MANAGER.C	
t_coins	*create_node(void *data);
void	add_node_back(t_coins **coin, t_coins *new_node);
void	free_lst(t_coins *node);
void	ft_lstclear(t_coins **coin);
t_coins	*ft_lstlast(t_coins *coin);
*/
// FT_INIT_WINDOW
void	init_window(t_map *map);

// FT_PUT_IMAGES
void	place_exit(mlx_t *mlx, t_map *map);//char **map, int rows, int cols);
void	place_coin(mlx_t *mlx, t_map *map);//char **map, int rows, int cols);
void	place_player(mlx_t *mlx, t_map *map);//har **map, int rows, int cols);
void	render_initial_map(mlx_t *mlx, char **map, int rows, int cols);

/***GET_NEXT_LINE******/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);

/*********************/

// FT_UTILS.C
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *dest, int c, size_t count);

// FT_ARGS_CHECKLIST.C
int		is_invalid_char(t_map *map);
int		check_chars(t_map *map);
int		duplicate_exit_or_start(t_map *map);
int		is_wall(t_map *map);
int		is_rectangular(t_map *map);

// FT_ARGS_CHECK.C
int		check_map(t_map *map);
int		check_ber(char *str);

// 	FT_INIT_MAP.C
t_map	*populate_map_struct(char **map);
int		count_line_infd(char *file_name);
char	**read_map(int fd, int line_count);
t_map	*init_map(char *file_name);

// MAIN
int		is_map_valid(t_map *map);
int		check_flood_fill(t_map *map);
void	flood_fill(t_map *map, int x, int y);
t_coordinates	*find_start_pos(t_map *map);
t_coordinates	*populate_coord(char p, int x, int y);
t_map			*ft_map_copy(t_map *map);


#endif
