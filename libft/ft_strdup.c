/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:40:42 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/02 17:48:11 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*cstr;
	int		i;

	if ((cstr = (char *)malloc(sizeof(*cstr) * ft_strlen(str) + 1)) == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		cstr[i] = str[i];
	cstr[i] = '\0';
	return (cstr);
}
