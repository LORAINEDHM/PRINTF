/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:24:06 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/22 17:01:41 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x_size_p(unsigned long int nb)
{
	int				i;
	int				rest;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		rest = nb % 16;
		nb = nb / 16;
		i++;
	}
	return (i);
}

char	*ft_itox_p(unsigned long int nb, char *base)
{
	int				i;
	char			*str;
	int				rest;
	int				j;

	str = NULL;
	j = 0;
	i = ft_x_size_p(nb);
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (nb == 0)
	{
		str[j] = '0';
		j++;
	}
	while (nb != 0)
	{
		rest = nb % 16;
		nb = nb / 16;
		str[j] = base[rest];
		j++;
	}
	str[j] = '\0';
	ft_reverse(str, &i);
	return (str);
}

int		display_p(va_list *ap, t_printf *s)
{
	char			*address;
	unsigned long	ptr;
	int				length_input;

	ptr = va_arg(*ap, unsigned long);
	if (!(address = ft_itox_p(ptr, "0123456789abcdef")))
		return (-1);
	length_input = (ft_strlen_nb("0x") + ft_strlen_nb(address));
	if ((ptr == 0) && (F_DOT & s->flag))
		s->width += 1;
	if (F_MINUS & s->flag)
	{
		ft_putaddress("0x", s);
		((F_DOT & s->flag) && (ptr == 0)) ? 0 : (ft_putaddress(address, s));
	}
	if (s->width != 0)
		print(&s->counter, &s->width, length_input, 32);
	if (!(F_MINUS & s->flag))
	{
		ft_putaddress("0x", s);
		((F_DOT & s->flag) && (ptr == 0)) ? 0 : (ft_putaddress(address, s));
	}
	free(address);
	return (1);
}
