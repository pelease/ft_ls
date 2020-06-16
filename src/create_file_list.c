/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 03:02:29 by anime             #+#    #+#             */
/*   Updated: 2020/06/10 22:34:51 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char		get_file_type_2(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

char		get_file_type(unsigned char type)
{
	if (type == DT_DIR)
		return ('d');
	else if (type == DT_BLK)
		return ('b');
	else if (type == DT_CHR)
		return ('c');
	else if (type == DT_LNK)
		return ('l');
	else if (type == DT_FIFO)
		return ('p');
	else if (type == DT_SOCK)
		return ('s');
	else
		return ('-');
}

t_file		*create_file(char *name, char type)
{
	t_file		*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	file->name = ft_strdup(name);
	file->next = NULL;
	file->prev = NULL;
	file->append = NULL;
	file->user = NULL;
	file->group = NULL;
	file->type = type;
	return (file);
}

void		push_dir(t_file **file, t_file *newf,
				int (*cmp)(t_file *, t_file *))
{
	t_file		*it;

	if (!*file)
		*file = newf;
	else if (!cmp(*file, newf))
	{
		newf->append = *file;
		*file = newf;
	}
	else
	{
		it = *file;
		while (it && it->append && cmp(it->append, newf))
			it = it->append;
		newf->append = it->append;
		it->append = newf;
	}
}

void		push_file(t_file **file, t_file *newf,
					int (*cmp)(t_file *, t_file *))
{
	t_file		*it;

	if (!*file)
		*file = newf;
	else if (!cmp(*file, newf))
	{
		newf->next = *file;
		(*file)->prev = newf;
		*file = newf;
	}
	else
	{
		it = *file;
		while (it && it->next && cmp(it->next, newf))
			it = it->next;
		newf->prev = it;
		newf->next = it->next;
		if (it->next)
			it->next->prev = newf;
		it->next = newf;
	}
}
