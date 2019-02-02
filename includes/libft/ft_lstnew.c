/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:02:48 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/14 19:43:55 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;
	void	*copy_cont;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content && content_size)
	{
		if (!(copy_cont = (void *)malloc(sizeof(void *) * content_size)))
		{
			free(newlist);
			return (NULL);
		}
		copy_cont = ft_memcpy(copy_cont, content, content_size);
		newlist->content = copy_cont;
	}
	else
		newlist->content = NULL;
	newlist->content_size = (content_size && content) ? content_size : 0;
	newlist->next = NULL;
	return (newlist);
}
