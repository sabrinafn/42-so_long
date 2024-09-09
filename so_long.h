/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:52:43 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/09 14:30:40 by sabrifer         ###   ########.fr       */
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
//# include "mlx/mlx.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

// GET_NEXT_LINE
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);

char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *dest, int c, size_t count);

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

#endif
