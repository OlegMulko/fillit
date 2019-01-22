/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:19:35 by ggrimes           #+#    #+#             */
/*   Updated: 2019/01/21 20:29:38 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			**read_and_validate(int fd, t_prm *prm)
{
	int		ret;
	char	*readbuf;
	int		**tetriminos;
	int		*tetrimino;

	tetriminos = NULL;
	readbuf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, readbuf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		readbuf[ret] = '\0';
		CHECK(readbuf_size_valid(readbuf, ret))
		CHECK(readbuf_sym_valid(readbuf, ret))
		CHECK((tetrimino = get_tetrimino(readbuf, *prm)))
		CHECK(tetrimino_is_valid(tetrimino))
		CHECK(!(++(*prm).count_tetriminos > 26))
		CHECK((tetriminos = add_tetrimino(&tetriminos,
						(*prm).count_tetriminos, tetrimino)))
	}
	ft_strdel(&readbuf);
	return (tetriminos);
}

int			readbuf_size_valid(char *buf, int size_buf)
{
	if (size_buf == BUFF_SIZE)
		if (buf[size_buf - 1] == '\n' && buf[size_buf - 2] == '\n')
			return (1);
	if (size_buf == BUFF_SIZE - 1)
		if (buf[size_buf - 1])
			return (1);
	return (0);
}

int			readbuf_sym_valid(char *buf, int size_buf)
{
	int		count_lb;
    int		count_hash;
    int		max_lb;

	count_lb = 0;
	count_hash = 0;
	max_lb = (size_buf == BUFF_SIZE) ? 5 : 4;
	while (*buf)
	{
		if (*buf != '#' && *buf != '.' && *buf != '\n')
			return (0);
		if (((*buf == '\n') ? ++count_lb : count_lb) > max_lb)
			return (0);
		if (((*buf == '#') ? ++count_hash : count_hash) > TETRIMINO_SIZE)
			return (0);
		buf++;
	}
	return (1);
}

int			*get_tetrimino(char *buf, t_prm prm)
{
	int		*tetrimino;
	int		x;

	prm.pos = -1;
	prm.offset = 0;
	prm.step = 0;
	CHECK((tetrimino = (int *)malloc(sizeof(int) * TETRIMINO_SIZE * 2)))
	while (buf[++prm.pos] && prm.step < TETRIMINO_SIZE)
	{
		if (buf[prm.pos] == '\n')
			prm.offset++;
		if (buf[prm.pos] == '#')
		{
			x = prm.pos - prm.offset * (TETRIMINO_SIZE + 1);
			if (!prm.step)
				put_null_points(x, &prm.x0, prm.offset, &prm.y0);
			tetrimino[prm.step * 2] = x - prm.x0;
			tetrimino[prm.step * 2 + 1] = prm.offset - prm.y0;
			prm.step++;
		}
	}
	return (tetrimino);
}

void		put_null_points(int x, int *x0, int y, int *y0)
{
	*x0 = x;
	*y0 = y;
}

int			tetrimino_is_valid(int *tetrimino)
{
	int		count_comm;
	int		i;
	int		j;

	count_comm = 0;
	i = -1;
	while (++i < TETRIMINO_SIZE - 1)
	{
		j = i;
		while(++j <= TETRIMINO_SIZE - 1)
		{
			if (tetrimino[i * 2] + 1 == tetrimino[j * 2]
					&& tetrimino[i * 2 + 1] == tetrimino[j * 2 + 1])
				count_comm++;
			if (tetrimino[i * 2] == tetrimino[j * 2]
					&& tetrimino[i * 2 + 1] + 1 == tetrimino[j * 2 + 1])
				count_comm++;
		}
	}
	if (count_comm == 3 || count_comm == 4)
		return (1);
	return (0);
}

int			**add_tetrimino(int ***tetriminos, int count, int *tetrimino)
{
	int		i;
	int		**newtetriminos;

	i = -1;
	if (!(newtetriminos = (int **)malloc(sizeof(int *) * count)))
		return (NULL);
	while (++i < count - 1)
		newtetriminos[i] = (*tetriminos)[i];
	newtetriminos[count - 1] = tetrimino;
	ft_memdel((void **)tetriminos);
	return (newtetriminos);
}

