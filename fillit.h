/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:15:20 by ggrimes           #+#    #+#             */
/*   Updated: 2019/01/21 20:30:17 by ggrimes          ###   ########.fr       */
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
	int		pos;
	int		offset;
	int		x0;
	int		y0;
	int		count_tetriminos;
	int		l_size;
	int		map_size;
	int		index;
	int		cnt_elem;
}				t_prm;

int		**read_and_validate(int fd, t_prm *prm);
int		readbuf_sym_valid(char *buf, int size_buf);
int		readbuf_size_valid(char *buf, int size_buf);
int		*get_tetrimino(char *buf, t_prm prm);
void	put_null_points(int x, int *x0, int y, int *y0);
int		tetrimino_is_valid(int *tetrimino);
int		**add_tetrimino(int ***tetriminos, int count, int *tetrimino);
char	*inscribe_tetriminos (int ***tetriminos, t_prm *prm);
int	    inscribe_tetrimino(char **map, int **tetriminos, t_prm prm, int cur_tet);
char	*create_map(t_prm *prm);
char	*update_map(char **map, t_prm *prm);
int		is_inscribe(char *map, int *tetrimino, t_prm prm);
int		write_tetrimino(char **map, int *tetrimino, t_prm prm, char n_letter);
int     **del_tet(int **tetriminos, int tet_id, t_prm *prm);
void	print_map(char *map, int l_size);
int		print_error(void);
int		print_usage(void);
void	print_int(int *arr);
void    print_tetrimins_list(int **shapes, int count);

#endif
