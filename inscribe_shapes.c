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

char		*inscribe_tetriminos (int ***tets, t_prm *prm)
{
	char	*map;

	CHECK((map = create_map(prm)))
	while (1)
	{
		(*prm).pos = -1;
		(*prm).offset = 0;
		if ((inscribe_tet(&map, *tets, *prm)))
			return (map);
		else
			CHECK((map = update_map(&map, prm)))
	}
}

char		*create_map(t_prm *prm)
{
	char	*map;
	int		tet_size;
	int		i;

	tet_size = (*prm).cnt_tets * TETRIMINO_SIZE;
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

int			inscribe_tet(char **map, int **tets , t_prm prm)
{
    int     **ntets;

	if (!prm.cnt_tets)
		return (1);
	while ((*map)[++prm.pos])
	{
		if (prm.pos - (prm.offset * prm.l_size) == prm.l_size)
			prm.offset++;
		if ((*map)[prm.pos] != '.')
            continue ;
		prm.index = -1;
		while (++prm.index < prm.cnt_tets)
		{
            if (is_inscribe(*map, tets[prm.index] + 1, prm))
            {
                write_tet(map, tets[prm.index] + 1, prm, 'A' + tets[prm.index][0]);
                ntets = del_tet(tets, tets[prm.index][0], &prm);
                if (inscribe_tet(map, ntets, prm))
                    return (1);
                else
                {
                    write_tet(map, tets[prm.index], prm, '.');
                    prm.cnt_tets++;
                    free(ntets);
                }

            }
		}
	}
	return (0);
}

int			is_inscribe(char *map, int *tetrimino, t_prm prm)
{
	int     newpos;
	int     x;
	int     y;

	if (prm.cnt_elem-- < 1)
		return (1);
	newpos = prm.pos + tetrimino[0] + (tetrimino[1] * prm.l_size);
	y = prm.offset + tetrimino[1];
	x = newpos - (y * prm.l_size);
	if ((x >= 0 && x < prm.l_size) && y < prm.l_size && map[newpos] == '.')
		if (is_inscribe(map, tetrimino + 2, prm))
			return (1);
	return (0);
}

int			write_tet(char **map, int *tetrimino, t_prm prm, char n_letter)
{
	int		newpos;

	if (prm.cnt_elem-- < 1)
		return (1);
	newpos = prm.pos + tetrimino[0] + (tetrimino[1] * prm.l_size);
	(*map)[newpos] = n_letter;
	if (write_tet(map, tetrimino + 2, prm, n_letter))
		return (1);
	return (0);
}

int			**del_tet(int **tets, int tet_id, t_prm *prm)
{
	int		**ntets;
	int		i;
	int		j;
    int     t = -1;

	CHECK((ntets = (int **)malloc(sizeof(int *) * --(*prm).cnt_tets)))
	i = 0;
	j = 0;
	while (i < (*prm).cnt_tets)
	{
		if (tets[i][0] == tet_id)
			i++;
        ntets[j++] = tets[i++];
	}

    while (++t < prm->cnt_tets)
        print_int(tets[t]);
	return (ntets);
}
