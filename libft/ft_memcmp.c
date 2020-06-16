/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:46:48 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/16 13:30:33 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*x1;
	unsigned const char	*x2;

	i = 0;
	x1 = (unsigned const char*)s1;
	x2 = (unsigned const char*)s2;
	while (i < n)
	{
		if (x1[i] < x2[i])
			return (x1[i] - x2[i]);
		else if (x1[i] > x2[i])
			return (x1[i] - x2[i]);
		else
			i++;
	}
	return (0);
}
