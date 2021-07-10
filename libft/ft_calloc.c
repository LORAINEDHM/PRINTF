/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:47:03 by lduhamel          #+#    #+#             */
/*   Updated: 2019/11/22 18:56:18 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = NULL;
	if (!(ptr = (char*)malloc(sizeof(char) * (count * size))))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
