/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:31:47 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/04 19:32:54 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len_s;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = -1;
	len_s = ft_strlen(s);
	if (!(str = ft_strnew(len_s)))
		return (NULL);
	while (++i < len_s)
		str[i] = f(i, s[i]);
	return (str);
}
