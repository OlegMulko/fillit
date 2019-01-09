/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:17:09 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/30 22:47:29 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_buflist		*new_buflist(const int fd)
{
	t_buflist			*buflist;

	if (!(buflist = (t_buflist *)malloc(sizeof(t_buflist))))
		return (NULL);
	buflist->fd = fd;
	buflist->buf = ft_strnew(0);
	buflist->next = NULL;
	return (buflist);
}

static t_buflist		*get_buflist(const int fd, t_buflist **list)
{
	t_buflist			*plist;

	if (!*list)
	{
		if (!(*list = new_buflist(fd)))
			return (NULL);
		return (*list);
	}
	plist = *list;
	while (plist->fd != fd && plist->next)
		plist = plist->next;
	if (plist->fd == fd)
		return (plist);
	else
		plist->next = new_buflist(fd);
	return (plist->next);
}

static int				read_line(char **buf, char *readbuf, int fd)
{
	int					readbytes;
	char				*copy_buf;

	while ((readbytes = read(fd, readbuf, BUFF_SIZE)))
	{
		if (readbytes < 0)
			return (-1);
		readbuf[readbytes] = '\0';
		if (!(copy_buf = ft_strjoin(*buf, readbuf)))
			return (-1);
		free(*buf);
		*buf = copy_buf;
		if (ft_strchr(*buf, 10))
			break ;
	}
	return (readbytes == 0 ? 0 : 1);
}

static char				*get_line(char **buf)
{
	char				*pos_chr;
	char				*copy_buf;
	char				*line;

	if (!*(*buf))
		return (NULL);
	pos_chr = ft_strchr(*buf, 10);
	if (pos_chr)
		*pos_chr = '\0';
	if (!(line = ft_strdup(*buf)))
		return (NULL);
	if (!(copy_buf = ft_strdup(!pos_chr ? ft_strchr(*buf, 0) : pos_chr + 1)))
	{
		free(line);
		return (NULL);
	}
	free(*buf);
	*buf = copy_buf;
	return (line);
}

int						get_next_line(const int fd, char **line)
{
	static t_buflist	*list;
	char				buf[BUFF_SIZE + 1];
	t_buflist			*buflist;
	int					fr;

	if (fd < 0)
		return (-1);
	buflist = get_buflist(fd, &list);
	if (ft_strchr(buflist->buf, 10))
	{
		if (!(*line = get_line(&(buflist->buf))))
			return (-1);
		return (1);
	}
	if ((fr = read_line(&(buflist->buf), buf, fd)) < 0)
		return (-1);
	if ((*line = get_line(&(buflist->buf))))
		return (1);
	if (!*line && !fr)
		return (0);
	else
		return (-1);
}
