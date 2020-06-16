/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 20:00:56 by ds107             #+#    #+#             */
/*   Updated: 2020/06/11 03:16:26 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"

static void		display_chmod(mode_t mode, char type)
{
	char	chmod[12];

	chmod[0] = type;
	chmod[1] = (S_IRUSR & mode) ? 'r' : '-';
	chmod[2] = (S_IWUSR & mode) ? 'w' : '-';
	chmod[3] = (S_IXUSR & mode) ? 'x' : '-';
	chmod[4] = (S_IRGRP & mode) ? 'r' : '-';
	chmod[5] = (S_IWGRP & mode) ? 'w' : '-';
	chmod[6] = (S_IXGRP & mode) ? 'x' : '-';
	chmod[7] = (S_IROTH & mode) ? 'r' : '-';
	chmod[8] = (S_IWOTH & mode) ? 'w' : '-';
	chmod[9] = (S_IXOTH & mode) ? 'x' : '-';
	chmod[10] = ' ';
	chmod[11] = '\0';
	if (S_ISUID & mode)
		chmod[3] = chmod[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		chmod[6] = chmod[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		chmod[9] = chmod[9] == '-' ? 'T' : 't';
	ft_putstr(chmod);
}

static int		diff_time(time_t t)
{
	time_t					raw;
	long long int			res;

	time(&raw);
	res = (long long int)(raw - t);
	if (res < 0 || res / 2629743 >= 6)
		return (7);
	return (0);
}

static void		display_time(t_file *file)
{
	char	*s;

	s = ctime(&(file->time));
	s = ft_strup(s, ' ');
	ft_put_until(s, ' ');
	ft_putstr(" ");
	s = ft_strup(s, ' ');
	ft_put_until(s, ' ');
	ft_putchar(' ');
	if (diff_time(file->time) >= 6)
	{
		s = ft_strup(s, ' ');
		s = ft_strup(s, ' ');
		ft_putstr(s);
	}
	else
	{
		s = ft_strup(s, ' ');
		ft_put_until(s, ':');
		ft_putchar(':');
		s = ft_strup(s, ':');
		ft_put_until(s, ':');
	}
	ft_putchar(' ');
}

static void		print_format_ls(t_form *fm, t_file *f)
{
	display_chmod(f->mode, f->type);
	ft_printf("%*d ", fm->links, f->st_nlink);
	ft_printf("%-*s %-*s ", fm->user, f->user, fm->group, f->group);
	ft_printf("%*d ", fm->size, f->size);
	display_time(f);
	ft_putstr(f->name);
}

void			parse_result(t_look *look, t_file *file, char *path)
{
	look->fm.links = ft_numcount(look->fm.links) - 1;
	look->fm.size = ft_numcount(look->fm.size) - 1;
	look->fm.blocks = ft_numcount(look->fm.blocks) - 1;
	if (path && ((look->arg_dirs && (look->arg_files
	|| look->arg_dirs->next || look->err_type)) || look->flags['R']))
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (look->flags['l'] && look->show_total)
		ft_printf("total %lld\n", look->blocks);
	look->blocks = 0;
	while (file)
	{
		if (look->flags['l'])
			print_format_ls(&look->fm, file);
		else
			ft_putstr(file->name);
		ft_putchar('\n');
		file = file->next;
	}
}
