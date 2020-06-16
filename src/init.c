/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 04:54:11 by anime             #+#    #+#             */
/*   Updated: 2020/06/11 02:56:27 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void		reset_format_zero(t_form *fm)
{
	fm->user = 0;
	fm->group = 0;
	fm->links = 0;
	fm->blocks = 0;
	fm->size = 0;
}

void		init(t_look *look)
{
	int		i;

	i = -1;
	while (++i < 128)
		look->flags[i] = 0;
	look->flags['1'] = 1;
	look->err_type = 0;
	look->inv_opt = 0;
	look->arg_dirs = NULL;
	look->arg_files = NULL;
	look->blocks = 0;
	look->exist_args = 0;
	look->show_total = 1;
	reset_format_zero(&look->fm);
}

void		print_err(char *s)
{
	ft_putstr_fd("ls: cannot open directory '", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("': ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
}

void		reset_format_ls(t_form *fm, t_file *f)
{
	int		tmp;

	tmp = ft_strlen(f->user);
	if (tmp > fm->user)
		fm->user = tmp;
	tmp = ft_strlen(f->group);
	if (tmp > fm->group)
		fm->group = tmp;
	if (fm->links < f->st_nlink)
		fm->links = f->st_nlink;
	if (fm->blocks < f->st_blocks)
		fm->blocks = f->st_blocks;
	if (fm->size < f->size)
		fm->size = f->size;
}
