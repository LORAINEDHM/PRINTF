/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:36:05 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/22 13:00:31 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_v1(char c, t_printf *s)
{
	write(1, &c, 1);
	(s->counter)++;
}

void	display_c(va_list *ap, t_printf *s)
{
	char c;

	c = (va_arg(*ap, int));
	if (F_MINUS & s->flag)
		ft_putchar_v1(c, s);
	if ((s->width != 0) && !(F_ZERO & s->flag))
		print(&s->counter, &s->width, 1, 32);
	if ((s->width != 0) && (F_ZERO & s->flag))
		print(&s->counter, &s->width, 1, '0');
	if (!(F_MINUS & s->flag))
		ft_putchar_v1(c, s);
}
