/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:55:46 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/11/08 17:46:48 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		size;

	if (!src)
		return (NULL);
	i = 0;
	size = 0;
	while (src[i++] != '\0')
		size++;
	dup = (char*)malloc(sizeof(*dup) * size + 1);
	i = 0;
	if (dup)
	{
		while (i < size)
		{
			dup[i] = src[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
	return (NULL);
}
