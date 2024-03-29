/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:02:01 by lduhamel          #+#    #+#             */
/*   Updated: 2019/11/22 18:55:47 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strndup(const char *src, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = NULL;
	if (!(ptr = (char*)malloc(sizeof(char) * n + 1)))
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int		ft_nb_strings(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] != c)
		j = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			j++;
		i++;
	}
	return (j);
}

static void		ft_free(char **ptr, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**ptr;

	i = 0;
	j = 0;
	if (s == NULL || (!(ptr = (char**)malloc(sizeof(char *) *
			ft_nb_strings((char *)s, c) + 1))))
		return (NULL);
	while (s[i] != '\0' && j < ft_nb_strings((char*)s, c))
	{
		index = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			index++;
			i++;
		}
		if ((ptr[j++] = ft_strndup(s + i - index, index)) == NULL)
			ft_free(ptr, j);
	}
	ptr[j] = 0;
	return (ptr);
}
