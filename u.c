/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:24:17 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/22 18:28:28 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_size_u(unsigned int nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa_u(unsigned int nb)
{
	int		j;
	char	*str;

	str = NULL;
	if (!(str = (char*)malloc(sizeof(char) * ft_size_u(nb) + 1)))
		return (NULL);
	j = ft_size_u(nb);
	str[j] = '\0';
	while (j-- > 0)
	{
		str[j] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

void			dot_u(char **str, int *length_input, t_printf *s)
{
	int sign;

	sign = 1;
	if (!(F_MINUS & s->flag))
	{
		if ((!(s->precision == -1)))
			print_v2(*length_input, 32, s);
		else
			print(&s->counter, &s->width, *length_input, '0');
		print(&s->counter, &s->precision, *length_input, '0');
		ft_putnb(&sign, *str, length_input, s);
	}
	if (F_MINUS & s->flag)
	{
		print(&s->counter, &s->precision, *length_input, '0');
		ft_putnb(&sign, *str, length_input, s);
		print_v2(*length_input, 32, s);
	}
}

int				display_u(va_list *ap, t_printf *s)
{
	char			*str;
	unsigned int	nb;
	int				length_input;
	int				sign;

	nb = va_arg(*ap, int);
	if (!(str = ft_itoa_u(nb)))
		return (-1);
	length_input = ft_strlen_nb(str);
	length_input = (((*str == '0') && (F_DOT & s->flag)) ? 0 : length_input);
	if (!(F_DOT & s->flag) && (sign = 1) == 1)
	{
		if ((F_ZERO & s->flag) && !(F_MINUS & s->flag))
			print(&s->counter, &s->width, length_input, '0');
		if (F_MINUS & s->flag)
			ft_putnb(&sign, str, &length_input, s);
		if (!(F_ZERO & s->flag) || ((F_ZERO & s->flag) && (F_MINUS & s->flag)))
			print(&s->counter, &s->width, length_input, 32);
		if (!(F_MINUS & s->flag))
			ft_putnb(&sign, str, &length_input, s);
	}
	else
		dot_u(&str, &length_input, s);
	free(str);
	return (1);
}
