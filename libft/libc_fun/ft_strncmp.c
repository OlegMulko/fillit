/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:17:05 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/07 22:18:04 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (str1[i] == str2[i] && i < n - 1 && str1[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
