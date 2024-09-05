/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:52:43 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/05 10:53:35 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

//standard libraries
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

//minilibx
//# include "mlx/mlx.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

// GET_NEXT_LINE
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}	t_list;

typedef struct s_coordinates
{
	char	value;
	int		x;
	int		y;
}	t_coordinates;

typedef struct s_map
{
	char	**map;
	int		length;
	int		height;
}	t_map;

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}	t_data;

typedef struct s_rect
{
	int x;
	int y;
	int width;
	int height;
	int color;
}	t_rect;


#endif
