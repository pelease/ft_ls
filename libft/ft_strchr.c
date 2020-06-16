/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:55:48 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 17:56:18 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == (char)c)
			return ((char*)s + i);
	if (s[i] == (char)c)
		return ((char*)s + i);
	else
		return (NULL);
}
