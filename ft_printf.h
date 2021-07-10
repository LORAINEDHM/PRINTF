/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:26:04 by lduhamel          #+#    #+#             */
/*   Updated: 2020/01/23 12:38:52 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define F_MINUS		(1 << 0)
# define F_ZERO			(1 << 1)
# define F_DOT			(1 << 2)
# define F_ASTERISK		(1 << 3)
# define F_ASTERISK2	(1 << 4)
# define F_ZERO2		(1 << 5)

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_printf
{
	int		width;
	int		precision;
	char	flag;
	int		counter;
}				t_printf;

void			ft_putchar_v1(char c, t_printf *s);
size_t			ft_strlen_nb(const char *str);
int				ft_strchr_v1(char *str, char c);
void			ft_flag_bitwise(const char *str, int *i, t_printf *s);
int				ft_number(const char *str, int *i);
int				ft_options(va_list *ap, const char *content,
					int *i, t_printf *s);
int				ft_printf(const char *content, ...);
void			display_c(va_list *ap, t_printf *s);
void			print(int *counter, int *width, int length_input, char c);
int				ft_size(long nb, t_printf *s);
char			*ft_itoa_v1(long nb, t_printf *s);
unsigned int	ft_size_u(unsigned int nb);
char			*ft_itoa_u(unsigned int nb);
int				display_u(va_list *ap, t_printf *s);
void			display_s(va_list *ap, t_printf *s);
void			dot_d(int *nb, char **str, int *length_input, t_printf *s);
void			dot_u(char **str, int *length_input, t_printf *s);
void			ft_putstr_v1(char *str, t_printf *s);
void			ft_putaddress(char *str, t_printf *s);
int				display_x(va_list *ap, char *base, t_printf *s);
char			*ft_itox(unsigned int nb, char *base);
int				ft_x_size(unsigned int nb);
void			dot_x(char **str, int *length_input, t_printf *s);
void			display_purcent(t_printf *s);
void			ft_putnb(int *nb, char *str, int *length_input, t_printf *s);
void			ft_putnb_end(int *nb, t_printf *s);
void			print_v2(int length_input, char c, t_printf *s);
int				display_p(va_list *ap, t_printf *s);
int				ft_x_size_p(unsigned long int nb);
char			*ft_itox_p(unsigned long int nb, char *base);
size_t			ft_strlen_s(const char *str);
int				ft_display(va_list *ap, const char *content, int *i,
					t_printf *s);
int				display_d(va_list *ap, t_printf *s);
void			ft_reverse(char *str, int *i);
#endif
