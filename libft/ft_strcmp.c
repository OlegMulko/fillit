/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:15:03 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/02 19:16:32 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)str1[i] == (unsigned char)str2[i]
			&& (unsigned char)str1[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
