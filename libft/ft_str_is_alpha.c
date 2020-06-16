/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:35:07 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 17:53:22 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_is_alpha(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isalpha(str[i])))
			return (0);
		i++;
	}
	return (1);
}
