/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:32:10 by anime             #+#    #+#             */
/*   Updated: 2020/06/10 18:49:52 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	free_files(t_file *file)
{
	t_file	*tmp;

	if (file)
		while (file)
		{
			tmp = file->next;
			if (file->name)
				free(file->name);
			if (file->user)
				free(file->user);
			if (file->group)
				free(file->group);
			free(file);
			file = tmp;
		}
}

void	free_look(t_look *look)
{
	if (look)
	{
		free_files(look->arg_dirs);
		free_files(look->arg_files);
		free(look);
	}
}
