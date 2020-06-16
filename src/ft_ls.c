/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:15:54 by anime             #+#    #+#             */
/*   Updated: 2020/06/11 03:29:01 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errors.h"
#include "ft_ls.h"

void		join_by(char *s1, char *s2, char del, char *s3)
{
	int			i;

	i = 0;
	while (s1 && *s1)
		s3[i++] = *s1++;
	if (i > 0 && s3[i - 1] != '\0' && s3[i - 1] != '/')
		s3[i++] = del;
	while (s2 && *s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
}

void		read_inner(t_look *look, t_file *file, char *path)
{
	DIR			*dir;
	char		full[PATH_MAX];

	reset_format_zero(&look->fm);
	while (file)
	{
		join_by(path, file->name, '/', full);
		dir = opendir(full);
		if (dir != NULL)
		{
			ft_putchar(10);
			read_dir(look, dir, full);
		}
		else if (errno == EACCES)
			print_err(full);
		file = file->append;
	}
}

void		read_dir(t_look *look, DIR *dir, char *path)
{
	t_file		*dirs;
	t_file		*files;
	t_file		*new;
	t_dirent	*dirent;

	files = NULL;
	dirs = NULL;
	while ((dirent = readdir(dir)))
		if (dirent->d_name && (dirent->d_name[0] != '.'
			|| (dirent->d_name[0] == '.' && look->flags['a'])))
		{
			new = create_file(dirent->d_name, get_file_type(dirent->d_type));
			set_file_info(new, path, look);
			push_file(&files, new, look->cmp);
			if (dirent->d_type == DT_DIR &&
				ft_strcmp(new->name, ".") && ft_strcmp(new->name, ".."))
				push_dir(&dirs, new, look->cmp);
		}
	parse_result(look, files, path);
	closedir(dir);
	if (look->flags['R'])
		read_inner(look, dirs, path);
	free_files(files);
}

void		ft_ls(t_look *look)
{
	t_file		*arg_dirs;
	DIR			*dir;

	if (!look->arg_dirs && !look->arg_files &&
	!look->exist_args && (dir = opendir(".")))
		read_dir(look, dir, ".");
	else
	{
		look->show_total = 0;
		arg_dirs = look->arg_dirs;
		parse_result(look, look->arg_files, NULL);
		look->show_total = 1;
		while (arg_dirs)
		{
			if ((dir = opendir(arg_dirs->name)))
			{
				if (arg_dirs->prev || look->arg_files)
					ft_putchar(10);
				read_dir(look, dir, arg_dirs->name);
			}
			else if (errno == EACCES)
				print_err(arg_dirs->name);
			arg_dirs = arg_dirs->next;
		}
	}
}

int			main(int argc, char **argv)
{
	t_look	*look;

	look = (t_look*)malloc(sizeof(t_look));
	init(look);
	parse_args(look, argc, argv);
	ft_ls(look);
	free_look(look);
	return (0);
}
