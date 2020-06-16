/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 03:22:05 by anime             #+#    #+#             */
/*   Updated: 2020/05/24 03:27:08 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bubble_sort(char **arr, int n)
{
	int		i;
	int		flag;
	char	*swap;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < n - 1)
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
			{
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i++ + 1] = swap;
				flag = 1;
			}
			else
				i++;
	}
}
