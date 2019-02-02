/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:31:34 by ggrimes           #+#    #+#             */
/*   Updated: 2019/02/02 15:46:41 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(char *map, int l_size)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		if (i - (j * l_size) == l_size)
		{
			ft_putchar('\n');
			j++;
		}
		ft_putchar(map[i]);
	}
	ft_putchar('\n');
}

int			print_error(void)
{
	ft_putstr("error\n");
	return (1);
}

int			print_usage(void)
{
	ft_putstr("usage: ./fillit [file]\n");
	return (0);
}
