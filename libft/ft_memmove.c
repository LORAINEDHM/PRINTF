/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:53:16 by lduhamel          #+#    #+#             */
/*   Updated: 2019/11/22 19:38:00 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst2;
	unsigned char		*src2;

	if (dst == NULL || src == NULL)
		return (dst);
	i = 0;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	if (src2 < dst2)
		while (len > 0)
		{
			len--;
			dst2[len] = src2[len];
		}
	if (src2 > dst2)
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	return (dst);
}
