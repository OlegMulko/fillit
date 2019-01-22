/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:41:23 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/14 20:44:38 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*nlist;

	if (lst && f)
	{
		nlist = lst;
		while (nlist)
		{
			f(nlist);
			nlist = nlist->next;
		}
	}
}
