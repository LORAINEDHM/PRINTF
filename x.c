/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:55:47 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/22 18:17:06 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x_size(unsigned int nb)
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

char	*ft_itox(unsigned int nb, char *base)
{
	int				i;
	char			*str;
	int				rest;
	int				j;

	str = NULL;
	j = 0;
	i = ft_x_size(nb);
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (nb == 0)
		str[j++] = '0';
	while (nb != 0)
	{
		rest = nb % 16;
		nb = nb / 16;
		str[j++] = base[rest];
	}
	str[j] = '\0';
	ft_reverse(str, &i);
	return (str);
}

void	dot_x(char **str, int *length_input, t_printf *s)
{
	int nb;

	nb = 1;
	if (!(F_MINUS & s->flag))
	{
		if ((!(s->precision == -1)))
			print_v2(*length_input, 32, s);
		else
			print(&s->counter, &s->width, *length_input, '0');
		print(&s->counter, &s->precision, *length_input, '0');
		ft_putnb(&nb, *str, length_input, s);
	}
	if (F_MINUS & s->flag)
	{
		print(&s->counter, &s->precision, *length_input, '0');
		ft_putnb(&nb, *str, length_input, s);
		print_v2(*length_input, 32, s);
	}
}

int		display_x(va_list *ap, char *base, t_printf *s)
{
	char	*str;
	int		nb;
	int		length_input;

	nb = 1;
	if (!(str = ft_itox(va_arg(*ap, int), base)))
		return (-1);
	length_input = ft_strlen_nb(str);
	length_input = (((*str == '0') && (F_DOT & s->flag)) ? 0 : length_input);
	if (!(F_DOT & s->flag))
	{
		if ((F_ZERO & s->flag) && !(F_MINUS & s->flag))
			print(&s->counter, &s->width, length_input, '0');
		if (F_MINUS & s->flag)
			ft_putnb(&nb, str, &length_input, s);
		if ((!(F_ZERO & s->flag))
		|| ((F_ZERO & s->flag) && (F_MINUS & s->flag)))
			print(&s->counter, &s->width, length_input, 32);
		if (!(F_MINUS & s->flag))
			ft_putnb(&nb, str, &length_input, s);
	}
	else
		dot_x(&str, &length_input, s);
	free(str);
	return (1);
}
