/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:45:11 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/10 23:26:27 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*cdest;

	i = 0;
	cdest = dest;
	while (i < n)
		cdest[i++] = (unsigned char)c;
	return (dest);
}
