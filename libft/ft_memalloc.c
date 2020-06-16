/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:23:31 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 17:44:49 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*fm;
	size_t			i;

	i = 0;
	fm = (unsigned char*)malloc(size);
	if (fm)
		while (i < size)
			((unsigned char*)fm)[i++] = 0;
	return ((void*)fm);
}
