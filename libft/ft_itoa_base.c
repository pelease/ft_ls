/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:26:06 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/11/08 21:38:50 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			digit_count(unsigned long long nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(unsigned long long value, int base, char type)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;

	if (base < 2 || base > 16)
		return (0);
	if (value == 0)
		return (ft_strdup("0"));
	tab_base = (type == 'x' || type == 'p' ?
		"0123456789abcdef" : "0123456789ABCDEF");
	taille = digit_count(value, base);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
	return (ret);
}
