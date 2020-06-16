/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:58:42 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 18:00:03 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + 1;
	while (size)
	{
		size--;
		if (s1[size] != s2[size])
			return (0);
	}
	return (1);
}
