/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:43:23 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/09 14:30:22 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	uc;
	int				len;

	len = ft_strlen((char *)str);
	uc = (unsigned char)c;
	while (len >= 0)
	{
		if (str[len] == uc)
			return ((char *)str + len);
		len--;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*new;
	unsigned char	j;
	size_t			i;

	new = dest;
	j = c;
	i = 0;
	while (i < count)
	{
		new[i] = j;
		i++;
	}
	return (dest);
}
