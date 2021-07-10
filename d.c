/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:49:08 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/22 14:09:02 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size(long nb, t_printf *s)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return ((F_DOT & s->flag) ? 10 : 11);
	if (nb < 0)
		i = 1;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_v1(long nb, t_printf *s)
{
	unsigned int	sign;
	unsigned int	j;
	long int		nbr;
	char			*str;

	str = NULL;
	sign = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_size(nb, s) + 1)))
		return (NULL);
	j = ft_size(nb, s);
	if ((nb < 0 && nb != INT_MIN) || (nb == INT_MIN && !(F_DOT & s->flag)))
	{
		str[0] = '-';
		sign = 1;
	}
	nbr = ((nb < 0) ? -nb : nb);
	str[j] = '\0';
	while (j-- > sign)
	{
		str[j] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

void	nodot_d(int *nb, char **str, int *length_input, t_printf *s)
{
	if ((F_ZERO & s->flag) && !(F_MINUS & s->flag))
	{
		if (*nb < 0 || *nb == INT_MIN)
			ft_putchar_v1('-', s);
		print(&s->counter, &s->width, *length_input, '0');
	}
	if (F_MINUS & s->flag)
		ft_putnb(nb, *str, length_input, s);
	if ((!(F_ZERO & s->flag)) || ((F_ZERO & s->flag) && (F_MINUS & s->flag)))
		print(&s->counter, &s->width, *length_input, 32);
	if (!(F_MINUS & s->flag))
		ft_putnb(nb, *str, length_input, s);
}

void	dot_d(int *nb, char **str, int *length_input, t_printf *s)
{
	int sign;

	sign = 1;
	if (!(F_MINUS & s->flag))
	{
		if (!(s->precision == -1))
			print_v2(*length_input, 32, s);
		if (*nb < 0 || *nb == INT_MIN)
			ft_putchar_v1('-', s);
		if (s->precision == -1)
			print(&s->counter, &s->width, *length_input, '0');
		print(&s->counter, &s->precision, *length_input, '0');
		ft_putnb(nb, *str, length_input, s);
	}
	if (F_MINUS & s->flag)
	{
		if (*nb < 0 || *nb == INT_MIN)
			ft_putchar_v1('-', s);
		print(&s->counter, &s->precision, *length_input, '0');
		ft_putnb(nb, *str, length_input, s);
		print_v2(*length_input, 32, s);
	}
}

int		display_d(va_list *ap, t_printf *s)
{
	char	*str;
	int		length_input;
	int		nb;
	int		sign;

	length_input = 0;
	sign = 1;
	nb = va_arg(*ap, int);
	if (nb < 0)
	{
		sign = -1;
		s->width = s->width - 1;
	}
	if (!(str = ft_itoa_v1(nb * sign, s)))
		return (-1);
	length_input = ft_strlen_nb(str);
	if ((*str == '0') && (F_DOT & s->flag))
		length_input = (s->precision == -1 ? 1 : 0);
	if (!(F_DOT & s->flag))
		nodot_d(&nb, &str, &length_input, s);
	else
		dot_d(&nb, &str, &length_input, s);
	free(str);
	return (1);
}
