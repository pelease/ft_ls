/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:09:39 by tgrandpa          #+#    #+#             */
/*   Updated: 2020/02/29 20:46:34 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	arr_length(char const *s, char c)
{
	size_t	res;
	size_t	i;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			res++;
		}
		else
			i++;
	}
	return (res);
}

static size_t	word_length(const char **s, char c)
{
	size_t		res;
	const char	*tmp;

	tmp = *s;
	res = 0;
	while (*tmp)
	{
		if (*tmp && *tmp != c)
		{
			while (*tmp && *tmp != c)
			{
				tmp++;
				res++;
			}
			break ;
		}
		else
			tmp++;
	}
	*s = tmp;
	return (res);
}

char			*create_word(char *s, char const *w, size_t len)
{
	size_t	i;

	if ((s = (char*)malloc(sizeof(char) * (len + 1))))
	{
		i = 0;
		s[len] = 0;
		while (i < len)
		{
			s[i] = w[i];
			i++;
		}
		return (s);
	}
	else
		return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr;
	size_t		arr_len;
	size_t		wlen;
	size_t		i;

	arr_len = arr_length(s, c);
	arr = NULL;
	if (!(arr = (char**)malloc(sizeof(*arr) * (arr_len + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		wlen = word_length(&s, c);
		if (wlen && !(arr[i] = create_word(arr[i], s - wlen, wlen)))
		{
			while (i--)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		i += (wlen > 0 ? 1 : 0);
	}
	arr[i] = NULL;
	return (arr);
}
