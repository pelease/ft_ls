/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:01:11 by tgrandpa          #+#    #+#             */
/*   Updated: 2020/05/31 23:21:38 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_with(char const *s1, char c, char const *s2)
{
	char	*strconcat;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	strconcat = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (strconcat)
	{
		while (s1[j] != '\0')
			strconcat[i++] = s1[j++];
		strconcat[i++] = c;
		j = 0;
		while (s2[j] != '\0')
			strconcat[i++] = s2[j++];
		strconcat[i] = '\0';
	}
	return (strconcat);
}
