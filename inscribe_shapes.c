/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inscribe_shapes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:34:47 by ggrimes           #+#    #+#             */
/*   Updated: 2019/01/21 20:56:52 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*inscribe_tetriminos (char *map, int **tetriminos, t_prm *prm)
{
	int		i;
	char	*newmap;

	i = -1;
	newmap = map;
	while (++i < (*prm).count_tetriminos)
	{
		if (tetriminos[i] == NULL)
			continue ;
		while (!inscribe_tetrimino(&map, tetriminos[i], prm, (char)i))
			CHECK((map = update_map(&map, prm)))
		newmap = inscribe_tetriminos(map, del_tet(tetriminos, i), prm);
	}
	return (newmap);
}

char		*create_map(t_prm *prm)
{
	char	*map;
	int		tet_size;
	int		i;

	tet_size = (*prm).count_tetriminos * TETRIMINO_SIZE;
	while (((*prm).map_size = (*prm).l_size * (*prm).l_size) < tet_size)
		(*prm).l_size++;
	CHECK((map = malloc(sizeof(char *) * (*prm).map_size + 1)))
		i = -1;
	while (++i < (*prm).map_size)
		map[i] = '.';
	map[i] = '\0';
	return (map);
}

char		*update_map(char **map, t_prm *prm)
{
	char	*newmap;
	int		i;

	(*prm).map_size = ((*prm).l_size + 1) * ((*prm).l_size + 1);
	CHECK((newmap = (char *)malloc(sizeof(char) * (*prm).map_size + 1)))
	i = 0;
	(*prm).pos = -1;
	(*prm).offset = 0;
	while ((*map)[++(*prm).pos])
	{
		if ((*prm).pos - ((*prm).offset * (*prm).l_size) == (*prm).l_size)
		{
			newmap[i++] = '.';
			(*prm).offset++;
		}
		newmap[i++] = (*map)[(*prm).pos];
	}
	while (i < (*prm).map_size)
		newmap[i++] = '.';
	newmap[i] = '\0';
	(*prm).l_size++;
	ft_memdel((void **)map);
	return (newmap);
}

int			inscribe_tetrimino(char **map, int *tetrimino , t_prm *prm, char n_letter)
{
	(*prm).pos = -1;
	(*prm).offset = 0;
	while ((*map)[++(*prm).pos])
	{
		if ((*prm).pos - ((*prm).offset * (*prm).l_size) == (*prm).l_size)
			(*prm).offset++;
		if ((*map)[(*prm).pos] != '.')
			continue;
		if (is_inscribe(*map, tetrimino, *prm))
			if (write_tetrimino(map, tetrimino, *prm, n_letter))
				return (1);
	}
	return (0);
}

int			is_inscribe(char *map, int *tetrimino, t_prm prm)
{
	int     newpos;
	int     x;
	int     y;

	if (prm.step < 1)
		return (1);
	prm.step--;
	newpos = prm.pos + tetrimino[0] + (tetrimino[1] * prm.l_size);
	y = prm.offset + tetrimino[1];
	x = newpos - (y * prm.l_size);
	if ((x >= 0 && x < prm.l_size) && y < prm.l_size && map[newpos] == '.')
		if (is_inscribe(map, tetrimino + 2, prm))
			return (1);
	return (0);
}

int			write_tetrimino(char **map, int *tetrimino, t_prm prm, char n_letter)
{
	int		newpos;

	if (prm.step < 1)
		return (1);
	prm.step--;
	newpos = prm.pos + tetrimino[0] + (tetrimino[1] * prm.l_size);
	(*map)[newpos] = 'A' + n_letter;
	if (write_tetrimino(map, tetrimino + 2, prm, n_letter))
		return (1);
	return (0);
}

int         **del_tet(int **tetriminos, int n_tet)
{
    tetriminos[n_tet] = NULL;
    return (tetriminos);
}
