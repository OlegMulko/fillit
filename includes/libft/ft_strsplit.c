/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:09:30 by ggrimes           #+#    #+#             */
/*   Updated: 2018/12/14 19:45:59 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_wsl(const char *s, char c)
{
	size_t		i;
	size_t		len;

	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == c)
			continue ;
		len++;
		while (s[i] != c && s[i + 1])
			i++;
	}
	return (len);
}

static size_t	get_wl(const char *s, char c)
{
	size_t		len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static char		**clear_words(char **words)
{
	size_t		i;

	i = 0;
	while (*(words + i))
		free(*(words + i++));
	free(words);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**words;
	size_t		i;
	size_t		k;
	size_t		wl;

	if (!s)
		return (NULL);
	if (!(words = (char **)malloc(sizeof(char *) * (get_wsl(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			wl = get_wl(s + i, c);
			if (!(words[k++] = ft_strsub(s, i, wl)))
				return (clear_words(words));
			i += wl - 1;
		}
		i++;
	}
	words[k] = NULL;
	return (words);
}
