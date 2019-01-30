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

char		*inscribe(int **tets, t_prm *prm)
{
	char	*map;
	int 	res;

	CHECK((map = create_map(prm)))
	while (1)
	{
		(*prm).pos = -1;
		(*prm).offset = 0;
		if ((res = inscribe_tets(&map, tets, *prm)) == 1)
			return (map);
		if (res == -1)
			return (NULL);
		else
		{
            (*prm).l_size++;
			free(map);
			CHECK((map = create_map(prm)))
		}
	}
}

char		*create_map(t_prm *prm)
{
	char	*map;
	//int		tet_size;
	int		i;

	/*tet_size = (*prm).cnt_tets * TETRIMINO_SIZE;
	while (((*prm).map_size = (*prm).l_size * (*prm).l_size) < tet_size)
		(*prm).l_size++;*/
	(*prm).map_size = (*prm).l_size * (*prm).l_size;
	CHECK((map = malloc(sizeof(char *) * (*prm).map_size + 1)))
		i = -1;
	while (++i < (*prm).map_size)
		map[i] = '.';
	map[i] = '\0';
	return (map);
}

int			inscribe_tets(char **map, int **tets , t_prm prm)
{
	int		res;

	if (!*tets)
		return (1);
	while ((*map)[++prm.pos])
	{
		if (prm.pos - (prm.offset * prm.l_size) == prm.l_size)
			prm.offset++;
		if ((*map)[prm.pos] != '.')
            continue ;
		if ((res = inscribe_one_of_tet(map, tets, prm)) == 1)
			return (1);
		if (res == -1)
			return (-1);
	}
	return (0);
}

int 		inscribe_one_of_tet(char **map, int **tets, t_prm prm)
{
	int     **ntets;

	prm.index = -1;
	while (tets[++prm.index])
	{
		if (is_inscribe(*map, tets[prm.index] + 1, prm))
		{
			write_tet(map, tets[prm.index] + 1, prm, 'A' + tets[prm.index][0]);
			if (!(ntets = del_one_tet(tets, tets[prm.index][0], &prm)))
				return (-1);
			if (inscribe_tets(map, ntets, prm))
				return (1);
			else
			{
				write_tet(map, tets[prm.index], prm, '.');
				prm.cnt_tets++;
				free(ntets);
			}

		}
	}
	return (0);
}

int			is_inscribe(char *map, int *tet, t_prm prm)
{
	int     newpos;
	int     x;
	int     y;

	if (prm.cnt_elem-- < 1)
		return (1);
 	newpos = prm.pos + tet[0] + (tet[1] * prm.l_size);
	y = prm.offset + tet[1];
	x = newpos - (y * prm.l_size);
	if ((x >= 0 && x < prm.l_size) && y < prm.l_size && map[newpos] == '.')
		if (is_inscribe(map, tet + 2, prm))
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

int			**del_one_tet(int **tets, int tet_id, t_prm *prm)
{
	int		**ntets;
	int		i;
	int		j;

	CHECK((ntets = (int **)malloc(sizeof(int *) * --(*prm).cnt_tets + 1)))
	i = -1;
	j = 0;
	while (tets[++i])
	{
		if (tets[i][0] == tet_id)
			continue ;
        ntets[j++] = tets[i];
	}
	ntets[j] = NULL;
	return (ntets);
}
