/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:25:25 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/04 19:31:08 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
		str[i] = f(s[i]);
	return (str);
}
