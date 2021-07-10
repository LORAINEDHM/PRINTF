/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:14:19 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/22 12:45:52 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strchr_v1(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr_v1(char *str, t_printf *s)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] == '0' && str[i + 1] == '\0')
		{
			if (((s->precision == 0 && (F_ZERO2 & s->flag))
				|| (s->precision > 0 && i >= s->precision)
				|| (s->precision == 0 && (F_DOT & s->flag))))
				break ;
		}
		else
		{
			if ((F_DOT & s->flag) && i >= s->precision && s->precision != -1)
				break ;
		}
		write(1, &str[i], 1);
		(s->counter)++;
		i++;
	}
}

void	ft_putaddress(char *str, t_printf *s)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		(s->counter)++;
		i++;
	}
}

void	ft_putnb_end(int *nb, t_printf *s)
{
	if (*nb < 0)
	{
		if (((F_MINUS & s->flag) && !(F_DOT & s->flag))
		|| (!(F_MINUS & s->flag) && !(F_DOT & s->flag)
		&& !(F_ZERO & s->flag)))
		{
			if (*nb != INT_MIN)
				ft_putchar_v1('-', s);
		}
	}
}

void	ft_putnb(int *nb, char *str, int *length_input, t_printf *s)
{
	int i;
	int width;

	if ((i = 0) == 0 && (*str == '0') && (F_DOT & s->flag)
	&& (s->precision != -1) && (width = 0) == 0)
		return ;
	ft_putnb_end(nb, s);
	while (str[i] != '\0')
	{
		if (*nb == '0')
		{
			if ((s->precision == 0 && (F_ZERO2 & s->flag) && width != 0)
			|| (s->precision > 0 && i >= s->precision) ||
			(s->precision == 0 && (F_DOT & s->flag) && !(F_MINUS & s->flag)))
				break ;
		}
		else
		{
			if (s->precision > 0 && i >= s->precision
			&& s->precision >= *length_input)
				break ;
		}
		write(1, &str[i++], 1);
		(s->counter)++;
	}
}
