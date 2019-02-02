/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:41:26 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/15 14:58:20 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nlist;
	t_list	*dlist;

	if (*alst && del)
	{
		nlist = *alst;
		while (nlist)
		{
			dlist = nlist;
			nlist = nlist->next;
			del(dlist->content, dlist->content_size);
			free(dlist);
		}
		*alst = NULL;
	}
}
