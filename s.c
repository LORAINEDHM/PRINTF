/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:00:05 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/22 13:11:56 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		display_s(va_list *ap, t_printf *s)
{
	char	*str;
	int		length_input;

	str = (va_arg(*ap, char*));
	if (str == NULL)
		str = "(null)";
	length_input = ft_strlen_s(str);
	if (((s->precision != 0 && length_input >= s->precision)
	&& !(F_ZERO2 & s->flag) && s->precision != -1))
		length_input = s->precision;
	if ((s->precision == 0) && (F_DOT & s->flag))
		length_input = 0;
	if (F_MINUS & s->flag)
		ft_putstr_v1(str, s);
	print(&s->counter, &s->width, length_input, 32);
	if (!(F_MINUS & s->flag))
		ft_putstr_v1(str, s);
}
