/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:30:03 by ds107             #+#    #+#             */
/*   Updated: 2020/06/10 18:58:07 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"

void			set_owner_group(t_file *f, uid_t uid, gid_t gid)
{
	struct passwd	*usr;
	struct group	*gr;

	if ((usr = getpwuid(uid)) && usr->pw_name)
		f->user = ft_strdup(usr->pw_name);
	else
		f->user = ft_itoa((long long int)uid);
	if ((gr = getgrgid(gid)) && gr->gr_name)
		f->group = ft_strdup(gr->gr_name);
	else
		f->group = ft_itoa((long long int)gid);
}

void			reset_file_name(t_file *file, char *path)
{
	char		name[PATH_MAX];
	char		*link;
	int			bytes;

	if ((bytes = readlink(path, name, PATH_MAX)) > 0)
	{
		name[bytes + 4] = '\0';
		while (--bytes >= 0)
			name[bytes + 4] = name[bytes];
		name[0] = ' ';
		name[1] = '-';
		name[2] = '>';
		name[3] = ' ';
		link = file->name;
		file->name = ft_strjoin(file->name, name);
		if (link)
			free(link);
	}
}

void			set_file_info(t_file *file, char *path, t_look *look)
{
	t_stat			st;
	char			full[PATH_MAX];

	join_by(path, file->name, '/', full);
	if (!lstat(full, &st))
	{
		file->size = st.st_size;
		file->mode = st.st_mode;
		file->st_blocks = st.st_blocks / 2;
		file->time = st.st_mtim.tv_sec;
		file->ntime = st.st_mtim.tv_nsec;
		file->st_nlink = st.st_nlink;
		look->blocks += file->st_blocks;
		set_owner_group(file, st.st_uid, st.st_gid);
		if (file->type == 'l' && look->flags['l'])
			reset_file_name(file, full);
		reset_format_ls(&look->fm, file);
		st.st_mtime = 123;
	}
}
