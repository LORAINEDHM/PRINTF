/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:12:39 by lduhamel          #+#    #+#             */
/*   Updated: 2019/11/22 15:18:38 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b2;

	if (b == NULL)
		return (NULL);
	b2 = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		b2[i] = c;
		i++;
	}
	return (b);
}
