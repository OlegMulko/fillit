/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:39:07 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/22 19:48:39 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	i = -1;
	if (!dest && !src)
		return (NULL);
	cdest = dest;
	csrc = (unsigned char *)src;
	while (++i < n)
		cdest[i] = csrc[i];
	return (dest);
}
