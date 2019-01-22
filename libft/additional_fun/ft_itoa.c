/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:56:09 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/14 18:24:03 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ln(int n)
{
	int		len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	int		len_n;
	char	*s;
	int		flag;
	long	num;

	num = n;
	flag = (num < 0) ? 1 : 0;
	if (num < 0)
		num = -num;
	len_n = get_ln(num) + flag;
	if (!(s = ft_strnew(len_n)))
		return (NULL);
	while (len_n--)
	{
		s[len_n] = num % 10 + 48;
		num /= 10;
	}
	if (flag)
		s[0] = '-';
	return (s);
}
