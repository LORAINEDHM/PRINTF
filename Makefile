# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 17:22:23 by lduhamel          #+#    #+#              #
#    Updated: 2020/01/22 18:24:57 by lduhamel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = c.c s.c d.c u.c x.c p.c purcent.c ft_printf.c ft_printf_utils.c \
ft_printf_utils2.c

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a libftprintf.a
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -I$(HEADER) -o $@ $<

bonus:	$(OBJS) 
	ar rc $(NAME) $(OBJS) 

clean:
	make -C libft clean
	/bin/rm -f $(OBJS) 

fclean: clean		
	/bin/rm -f $(NAME)
	/bin/rm -f ./libft/libft.a 

re: fclean all

.PHONY: all clean fclean re 