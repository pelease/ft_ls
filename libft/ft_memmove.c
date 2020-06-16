/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:40:46 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/25 12:11:58 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	b;
	char	*x1;
	char	*x2;

	i = 0;
	b = dst - src;
	x1 = (char*)dst;
	x2 = (char*)src;
	if (src < dst && len > b)
	{
		while (i < len - b)
		{
			x1[len - 1 - i] = x1[len - b - 1 - i];
			i++;
		}
		len = b;
		i = 0;
	}
	while (i < len)
	{
		x1[i] = x2[i];
		i++;
	}
	return (dst);
}
