/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:36:29 by tgrandpa          #+#    #+#             */
/*   Updated: 2020/03/01 16:42:23 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void		make_nb_str(char *arg, long long nb2, int size)
{
	if (nb2 < 0)
	{
		arg[0] = '-';
		nb2 = -nb2;
	}
	if (!nb2)
		arg[--size] = nb2 % 10 + '0';
	while (nb2)
	{
		arg[--size] = nb2 % 10 + '0';
		nb2 /= 10;
	}
}

char			*ft_itoa(long long nb)
{
	char			*arg;
	int				size;
	long long		nb2;

	if (nb == LONG_MIN)
		arg = ft_strdup("-9223372036854775808");
	else
	{
		size = 1;
		nb2 = nb;
		if (nb < 0)
			size++;
		while (nb /= 10)
			size++;
		if (!(arg = ft_strnew(size)))
			return (NULL);
		make_nb_str(arg, nb2, size);
	}
	return (arg);
}
