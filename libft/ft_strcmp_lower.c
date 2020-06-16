/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:48:33 by tgrandpa          #+#    #+#             */
/*   Updated: 2020/06/11 03:31:27 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp_lower(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && ft_tolower(s1[i]) == ft_tolower(s2[i]))
		i++;
	return (ft_tolower((unsigned char)s1[i]) -
		ft_tolower((unsigned char)s2[i]));
}
