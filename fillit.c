/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:54:03 by ggrimes           #+#    #+#             */
/*   Updated: 2019/01/21 19:59:42 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		**tetriminos;
	char	*map;
	t_prm	prm;
	char	*newmap;

	if (argc != 2)
		return (print_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (print_error());
	prm.count_tetriminos = 0;
	prm.l_size = 2;
	prm.step = TETRIMINO_SIZE;
	if (!(tetriminos = read_and_validate(fd, &prm)))
		return (print_error());
    CHECK((map = create_map(&prm)))
	if (!(newmap = inscribe_tetriminos(map, tetriminos, &prm)))
		return (print_error());
	print_map(newmap, prm.l_size);
	close(fd);
	return (0);
}
