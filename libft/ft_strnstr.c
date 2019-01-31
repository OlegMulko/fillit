/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:56:19 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/08 22:38:48 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*str2)
		return ((char *)str1);
	i = -1;
	while (++i < n && str1[i])
	{
		j = 0;
		while (str1[i + j] == str2[j] && (i + j) < n)
		{
			if (!str2[j + 1])
				return ((char *)str1 + i);
			j++;
		}
	}
	return (NULL);
}
