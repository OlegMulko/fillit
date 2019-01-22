/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:38:01 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/04 19:39:21 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_s;
	size_t	i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if ((start + len) > len_s)
		return (NULL);
	if (!(substr = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
		substr[i++] = s[start++];
	return (substr);
}
