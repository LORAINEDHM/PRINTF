/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:34:49 by lduhamel          #+#    #+#             */
/*   Updated: 2019/12/11 16:36:19 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// int main() 
// {
//       int bmagic;
//       int c = 10;
//       int i;
	
//       bmagic = 0xFF & c;  //(= bmagic = 11111111 & 00001010)
//       for (i = 0; i < 8; i++) 
//             printf("%d", !!((bmagic << i) & 0x80));   //(0x80 = 128 = 10000000)
//       return 0;
// }

// if %
// {
//    while != cspdiuxX ==> presence d un flag 
//    {
//          stocker largeur, precision ou bitwise
//    }
//    if c => print c
//    if s => print s
//    if p => print p
//    if d || i => print
//    if u => print u
// etc 
// }
// else
//    putchar


// flag 0 => se trouve avant width
// width seul => precede d espaces


# define F_MINUS	(1 << 0)
# define F_ZERO		(1 << 1)
# define F_DOT		(1 << 2)
# define F_ASTERISK	(1 << 3)

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void        ft_putchar(char c)
{
	write(1, &c, 1);
}

int        ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void        ft_flag_bitwise(char c, char *flag)
{
	if (c == '-')
		*flag = *flag | F_MINUS;
	if (c == '0')
		*flag = *flag | F_ZERO;
	if (c == '.')
		*flag = *flag | F_DOT;
	if (c == '*')
		*flag = *flag | F_ASTERISK;
}

int			ft_number(const char *str, int *i)
{
	long long number;
	long long previous;
	long long result;
	
	previous = 0;
	number = 0;
	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		number = number * 10 + (str[(*i)++] - '0');
		if (number < previous || number > 9223372036854775807)
			number = -1;
		previous = number;
	}
	(*i)--;
	if (!(result = (int)malloc(sizeof(int) * number)))
		return (0);
	result = number;
	return (result);
}

void        *print(int width, int length_input, char c)
 {
	int i;

	i = -1;
	while ((++i + length_input) < width)
		write(1, &c, 1);
 }

int         ft_printf(const char *str, ...)
{
	long long width;
	long long precision;
	int i;
//	int length_input; //ps: inclure '-' dedans si presence
	char flag;
	int j;

	i = 0;
	width = 0;
	precision = 0;
	flag = 0;
//	length_input = 10;
	j = 0;
	while (str[i])
	{
	//	printf("1 = %d\n", i);
		if (str[i] == '%')
		{
			while (ft_strchr("cspdiuxX%", str[++i]) == 0)
			{
				write(1, &str[i], 1);
				if (ft_strchr("-0.*", str[i]) == 1)
				{
					printf("\nflag found\n");
					ft_flag_bitwise(str[i], &flag);
					//printf("flag = %c\n", flag);
					for (j = 0; j < 8; j++) 
					printf("%d", !!((flag << j) & 0x80));   //(0x80 = 128 = 10000000)
					printf("\n");
				}
				if (str[i] > '0' && str[i] <= '9')
				{
					if (str[i-1] == '.')
					{
						precision = (ft_number(str, &i));
						printf("precision = %lld\n", precision);
					}
					else
					{
						width = (ft_number(str, &i));
						printf("width = %lld\n", width);
					}
				}
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}	
}

int main (void)
{
     ft_printf("coucou = %50.3*-d");
		// int a;
		// a = 5;
		// printf("%50d\n", a);
}
