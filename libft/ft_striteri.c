/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:00:37 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 18:01:03 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	strsize;

	if (s && f)
	{
		strsize = ft_strlen(s);
		while (strsize)
		{
			strsize--;
			f(strsize, s + strsize);
		}
	}
}
