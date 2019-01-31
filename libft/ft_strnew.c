/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:12:25 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/04 19:13:24 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*nstr;

	if (!(nstr = (char *)ft_memalloc(size + 1)))
		return (NULL);
	return (ft_memset(nstr, 0, size + 1));
}
