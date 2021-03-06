/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:54:13 by tgrandpa          #+#    #+#             */
/*   Updated: 2020/03/01 16:41:21 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_mem_2d(void **mem)
{
	int		i;

	i = -1;
	if (mem)
	{
		while (mem[++i])
			free(mem[i]);
		free(mem);
	}
}
