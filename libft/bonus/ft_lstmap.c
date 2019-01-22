/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:14:50 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/17 20:35:41 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delcont(void *cont, size_t n)
{
	free(cont);
	n = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*nlist;

	if (!lst)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	nlist = new;
	lst = lst->next;
	while (lst)
	{
		if (!(nlist->next = f(lst)))
		{
			ft_lstdel(&new, delcont);
			return (NULL);
		}
		lst = lst->next;
		nlist = nlist->next;
	}
	return (new);
}
