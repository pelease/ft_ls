/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whybread <whybread@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:14:05 by tgrandpa          #+#    #+#             */
/*   Updated: 2020/02/22 15:17:27 by whybread         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*strtrim;
	size_t	len_s;
	size_t	wspaces;
	size_t	i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	wspaces = 0;
	i = 0;
	while (s[wspaces] == ' ' || s[wspaces] == '\n' || s[wspaces] == '\t')
		wspaces++;
	while (s[len_s - i - 1] == ' ' || s[len_s - i - 1] == '\n'
		|| s[len_s - i - 1] == '\t')
		i++;
	s = s + wspaces;
	if (*s != '\0')
		wspaces += i;
	strtrim = (char*)malloc(sizeof(*strtrim) * (len_s - wspaces) + 1);
	if (strtrim)
	{
		ft_strncpy(strtrim, s, len_s - wspaces);
		strtrim[len_s - wspaces] = '\0';
	}
	return (strtrim);
}
