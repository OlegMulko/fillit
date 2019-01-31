/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:02:22 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/22 19:45:36 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	i = -1;
	if (!dest && !src)
		return (NULL);
	csrc = (unsigned char *)src;
	cdest = dest;
	if (cdest > csrc)
		while ((int)(--n) >= 0)
			cdest[n] = csrc[n];
	else
		while (++i < n)
			cdest[i] = csrc[i];
	return (dest);
}
