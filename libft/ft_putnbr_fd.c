/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:51:48 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 17:51:51 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	z;
	int	x;
	int	y;

	z = 1;
	y = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
			n /= 10;
		n *= (-1);
	}
	x = n;
	while ((n /= 10) != 0)
		z *= 10;
	while (z != 0)
	{
		ft_putchar_fd((x / z) + '0', fd);
		x = x - (x / z) * z;
		z /= 10;
	}
	if (y == -2147483648)
		ft_putchar_fd('8', fd);
}
