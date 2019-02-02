/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 14:30:44 by rstracke          #+#    #+#             */
/*   Updated: 2019/02/02 14:39:27 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*create_map(t_prm *prm)
{
	char	*map;
	int		tet_size;
	int		i;

	tet_size = (*prm).cnt_tets * TETRIMINO_SIZE;
	while (((*prm).map_size = (*prm).l_size * (*prm).l_size) < tet_size)
		(*prm).l_size++;
	(*prm).map_size = (*prm).l_size * (*prm).l_size;
	CHECK((map = malloc(sizeof(char *) * (*prm).map_size + 1)));
	i = -1;
	while (++i < (*prm).map_size)
		map[i] = '.';
	map[i] = '\0';
	return (map);
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

	CHECK((ntets = (int **)malloc(sizeof(int *) * --(*prm).cnt_tets + 1)));
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

int			*get_tet(char *buf, t_prm prm)
{
	int		*tet;
	int		x;

	CHECK((tet = (int *)malloc(sizeof(int) * TETRIMINO_SIZE * 2 + 1)));
	prm.pos = -1;
	prm.offset = 0;
	prm.index = 1;
	tet[0] = prm.cnt_tets;
	while (buf[++prm.pos])
	{
		if (buf[prm.pos] == '\n')
			prm.offset++;
		if (buf[prm.pos] == '#')
		{
			x = prm.pos - prm.offset * (TETRIMINO_SIZE + 1);
			if (prm.index == 1)
				put_null_points(x, prm.offset, &prm);
			tet[prm.index++] = x - prm.x0;
			tet[prm.index++] = prm.offset - prm.y0;
		}
	}
	return (tet);
}

int			**add_tet(int ***tets, int count, int *tet)
{
	int		i;
	int		**ntets;

	if (!(ntets = (int **)malloc(sizeof(int *) * count + 1)))
		return (NULL);
	i = -1;
	while (++i < count - 1)
		ntets[i] = (*tets)[i];
	ntets[count - 1] = tet;
	ntets[count] = NULL;
	ft_memdel((void **)tets);
	return (ntets);
}
