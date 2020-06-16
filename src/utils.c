/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 02:32:18 by anime             #+#    #+#             */
/*   Updated: 2020/06/11 03:30:30 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <errno.h>
#include <stdio.h>

char		*ft_strup(char *s, char c)
{
	while (*s != c)
		s++;
	return (++s);
}

void		ft_put_until(char *s, char c)
{
	while (*s && *s != c)
		ft_putchar(*s++);
}

int			ft_numcount(int nb)
{
	int		l;

	l = 1;
	if (nb < 0)
		l++;
	while (nb || l == 1)
	{
		nb /= 10;
		l++;
	}
	return (l);
}
