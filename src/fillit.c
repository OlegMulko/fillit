/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:54:03 by ggrimes           #+#    #+#             */
/*   Updated: 2019/01/31 21:35:19 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		**tets;
	char	*map;
	t_prm	prm;

	if (argc != 2)
		return (print_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (print_error());
	prm.cnt_tets = 0;
	prm.l_size = 2;
	prm.cnt_elem = TETRIMINO_SIZE;
	if (!(tets = read_and_validate(fd, &prm)))
		return (print_error());
	if (!(map = inscribe(tets, &prm)))
		return (print_error());
	print_map(map, prm.l_size);
	close(fd);
	return (0);
}
