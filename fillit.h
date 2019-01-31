/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:15:20 by ggrimes           #+#    #+#             */
/*   Updated: 2019/01/31 21:43:51 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_CL_FILLIT_H
# define FILLIT_CL_FILLIT_H
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# define BUFF_SIZE 21
# define TETRIMINO_SIZE 4
# define CHECK(val) if (!val) return (0);

typedef struct	s_prm
{
	int	pos;
	int	offset;
	int	x0;
	int	y0;
	int	cnt_tets;
	int	size_of_last_tet;
	int	l_size;
	int	map_size;
	int	index;
	int	cnt_elem;
}				t_prm;

int				**read_and_validate(int fd, t_prm *prm);
int				readbuf_sym_valid(char *buf, int size_buf);
int				readbuf_size_valid(char *buf, int size_buf);
int				*get_tet(char *buf, t_prm prm);
void			put_null_points(int x, int y, t_prm *prm);
int				tet_is_valid(int *tetrimino);
int				**add_tet(int ***tets, int count, int *tet);
char			*inscribe(int **tets, t_prm *prm);
int				inscribe_tets(char **map, int **tetriminos, t_prm prm);
int				inscribe_one_tet(char **map, int **tets, t_prm prm);
char			*create_map(t_prm *prm);
int				is_inscribe(char *map, int *tetrimino, t_prm prm);
int				write_tet(char **map, int *tetrimino, t_prm prm, char n_letter);
int				**del_one_tet(int **tetriminos, int tet_id, t_prm *prm);
void			print_map(char *map, int l_size);
int				print_error(void);
int				print_usage(void);

#endif
