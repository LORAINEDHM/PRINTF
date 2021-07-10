/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:34:49 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/23 12:38:41 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_bitwise(const char *str, int *i, t_printf *s)
{
	if ((str[*i] == '-') || s->width < 0)
		s->flag = s->flag | F_MINUS;
	if (str[*i] == '0')
	{
		if (str[(*i) - 1] != '.')
			s->flag = s->flag | F_ZERO;
		else
		{
			if (s->width != 0)
				s->flag = s->flag | F_ZERO2;
		}
	}
	if (str[*i] == '*')
	{
		if (str[(*i) - 1] == '.')
			s->flag = s->flag | F_ASTERISK2;
		else
			s->flag = s->flag | F_ASTERISK;
	}
	if (str[*i] == '.')
		s->flag = s->flag | F_DOT;
}

int		ft_number(const char *str, int *i)
{
	long long	number;
	long long	previous;
	int			sign;

	previous = 0;
	number = 0;
	sign = 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		number = number * 10 + (str[(*i)++] - '0');
		if (number < previous || number > 9223372036854775807)
			number = (sign == -1) ? 0 : -1;
		previous = number;
	}
	(*i)--;
	return (number);
}

int		ft_options(va_list *ap, const char *content, int *i, t_printf *s)
{
	while (content[(*i) + 1] && ft_strchr_v1("cspdiuxX%", content[++(*i)]) == 0)
	{
		if (ft_strchr_v1("-0.*", content[*i]) == 1)
		{
			if (content[*i] == '*' && content[(*i) - 1] != '.')
				s->width = va_arg(*ap, int);
			ft_flag_bitwise(content, i, s);
			if (content[*i] == '*' && content[(*i) - 1] == '.')
				s->precision = va_arg(*ap, int);
		}
		if (content[*i] >= '0' && content[*i] <= '9')
		{
			if (content[(*i) - 1] == '.')
			{
				while (content[*i] == '0')
					(*i)++;
				s->precision = (ft_number(content, i));
			}
			else
				(s->width = (ft_number(content, i)));
		}
	}
	s->width = (s->width < 0 ? s->width * -1 : s->width);
	s->precision = (s->precision < 0 ? -1 : s->precision);
	return (1);
}

int		ft_display(va_list *ap, const char *content, int *i, t_printf *s)
{
	content[*i] == 'c' ? display_c(ap, s) : 0;
	content[*i] == 's' ? display_s(ap, s) : 0;
	content[*i] == '%' ? display_purcent(s) : 0;
	if (content[*i] == 'p' && display_p(ap, s) == -1)
		return (-1);
	if ((content[*i] == 'd' || content[*i] == 'i') && display_d(ap, s) == -1)
		return (-1);
	if (content[*i] == 'u' && display_u(ap, s) == -1)
		return (-1);
	if (content[*i] == 'x' && display_x(ap, "0123456789abcdef", s) == -1)
		return (-1);
	if (content[*i] == 'X' && display_x(ap, "0123456789ABCDEF", s) == -1)
		return (-1);
	return (1);
}

int		ft_printf(const char *content, ...)
{
	t_printf	s;
	va_list		ap;
	int			i;

	i = 0;
	s.counter = 0;
	va_start(ap, content);
	while (content[i])
	{
		if (content[i] == '%')
		{
			s.width = 0;
			s.precision = 0;
			s.flag = 0;
			if (ft_options(&ap, content, &i, &s) == -1)
				return (-1);
			if (ft_display(&ap, content, &i, &s) == -1)
				return (-1);
		}
		else
			ft_putchar_v1(content[i], &s);
		i++;
	}
	va_end(ap);
	return (s.counter);
}
