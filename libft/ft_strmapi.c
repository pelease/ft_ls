/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:04:28 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 18:05:11 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	strsize;

	if (!s || !f)
		return (NULL);
	strsize = ft_strlen(s);
	str = (char*)malloc(sizeof(*str) * strsize + 1);
	if (str && s && f)
	{
		str[strsize] = '\0';
		while (strsize)
		{
			strsize--;
			str[strsize] = f(strsize, s[strsize]);
		}
	}
	return (str);
}
