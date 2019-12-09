/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:34:49 by lduhamel          #+#    #+#             */
/*   Updated: 2019/12/09 17:43:50 by lduhamel         ###   ########.fr       */
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

# define F_MINUS		(1 << 0)
# define F_ZERO		(1 << 1)
# define F_DOT		(1 << 2)
# define F_ASTERISK	(1 << 3)
//# define F_UPCASE	(1 << 4)

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void        ft_putchar(char c)
{
      write(1, &c, 1);
}

int        ft_strchr(char *s, int c)
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

char        ft_flag_bitwise(char c, char flag)
{
      if (c == '-')
      flag = flag | 1;
      if (c == '0')
      flag = flag | (1 << 1);
      if (c == '.')
      flag = flag | (1 << 2);
      if (c == '*')
      flag = flag | (1 << 3);
      return (flag);
}

// char        *print(char *str2, int width, int length_input, char c)
//  {
//       int i;
// //      char *str;

//       i = 0;
//  //     if (!(str = (char*)malloc(sizeof(char) * (width - length_input) + 1)))
// //		return (NULL);
//       while ((i + length_input) < width)
//       {
//             str2[i] = c;
//             i++;
//       }
//       return (str2);
// }

// int         ft_printf(const char *str, ...)
// {
//       int width;
//       int precision;
//       int flag_bitwise;
//       int i;

//       i = 0;
//       width = 0;
//       precision = 0;
//       flag_bitwise = 0;
//       if (str[i] == '%')
//       {
//             while (strchr("cspdiuxX%", str[++i]) == NULL)
//             {
//                   if (str[i] == '0')
                        

//             }
//       }

// }




// #include <stdio.h>
// #include <unistd.h>



int main (void)
{
     printf("strchr = %d\n", ft_strchr("cspdiuxX%", 'a'));
}
