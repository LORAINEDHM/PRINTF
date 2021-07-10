/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purcent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:01:12 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/22 13:10:25 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		display_purcent(t_printf *s)
{
	if (F_MINUS & s->flag)
		write(1, "%", 1);
	if ((s->width != 0) && ((!(F_ZERO & s->flag)) ||
	((F_ZERO & s->flag) && (F_MINUS & s->flag))))
		print(&s->counter, &s->width, 1, 32);
	if ((s->width != 0) && ((F_ZERO & s->flag) && (!(F_MINUS & s->flag))))
		print(&s->counter, &s->width, 1, '0');
	if ((F_MINUS & s->flag) != F_MINUS)
		write(1, "%", 1);
	(s->counter)++;
}
