/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:03:55 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 18:04:18 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	strsize;

	if (!s || !f)
		return (NULL);
	strsize = ft_strlen(s);
	str = (char*)malloc(sizeof(*str) * strsize + 1);
	if (str)
	{
		str[strsize] = '\0';
		while (strsize)
		{
			strsize--;
			str[strsize] = f(s[strsize]);
		}
	}
	return (str);
}
