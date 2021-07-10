/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:46:01 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/22 13:09:44 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reverse(char *str, int *i)
{
	int		j;
	int		temp;

	j = 0;
	while (j < ((*i) - 1))
	{
		temp = str[j];
		str[j] = str[(*i) - 1];
		str[(*i) - 1] = temp;
		j++;
		(*i)--;
	}
}

void	print(int *counter, int *width, int length_input, char c)
{
	int i;

	i = -1;
	while ((++i + length_input) < *width)
	{
		write(1, &c, 1);
		(*counter)++;
	}
}

void	print_v2(int length_input, char c, t_printf *s)
{
	int i;

	i = -1;
	if (s->precision > length_input)
		length_input = s->precision;
	while ((++i + length_input) < s->width)
	{
		write(1, &c, 1);
		(s->counter)++;
	}
}

size_t	ft_strlen_nb(const char *str)
{
	size_t i;
	size_t sign;

	i = 0;
	sign = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	if (sign == 1)
		i -= 1;
	return (i);
}

size_t	ft_strlen_s(const char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}
