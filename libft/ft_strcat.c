/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:54:42 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 17:55:05 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	dest_size;

	dest_size = ft_strlen(dest);
	i = -1;
	while (src[++i] != '\0')
		dest[dest_size + i] = src[i];
	dest[dest_size + i] = '\0';
	return (dest);
}
