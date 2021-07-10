/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 03:12:32 by lduhamel          #+#    #+#             */
/*   Updated: 2019/11/12 15:34:30 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if (*alst == NULL)
	{
		*alst = new;
		new->next = NULL;
		return ;
	}
	if (alst && new)
	{
		list = *alst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
		new->next = NULL;
	}
}
