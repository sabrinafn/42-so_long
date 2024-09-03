#ifndef SO_LONG_H
#define SO_LONG_H

//standard libraries
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

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
