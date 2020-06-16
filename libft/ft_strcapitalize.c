/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:40:51 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 17:54:32 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcapitalize(char *str)
{
	size_t	i;
	int		l;

	i = 0;
	l = 1;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
		{
			if (l && str[i] >= 'a' && str[i] <= 'z')
				str[i] = 'A' + str[i] - 'a';
			if (!l && str[i] >= 'A' && str[i] <= 'Z')
				str[i] = 'a' + str[i] - 'A';
			l = 0;
			i++;
		}
		else
		{
			i++;
			l = 1;
		}
	}
	return (str);
}
