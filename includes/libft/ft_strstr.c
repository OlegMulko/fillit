/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:31:17 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/02 20:40:19 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str1, const char *str2)
{
	size_t	i;
	size_t	len_str1;
	size_t	len_str2;

	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	if (!len_str2)
		return ((char *)str1);
	i = -1;
	while (++i < len_str1)
	{
		if (str1[i] == str2[0])
			if (!ft_memcmp((unsigned char *)str1 + i,
						(unsigned char *)str2, len_str2))
				return ((char *)str1 + i);
	}
	return (NULL);
}
