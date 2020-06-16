/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 03:25:40 by anime             #+#    #+#             */
/*   Updated: 2020/06/11 03:28:25 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "errors.h"

void		show_err_type_2(char *arg)
{
	if (!ft_strcmp(arg, "-r"))
		ft_putstr("ls: option '--r' is ambiguous; possibilities: \
'--reverse' '--recursive'\n");
	else if (!ft_strcmp(arg, "-a"))
		ft_putstr("ls: option '--a' is ambiguous; possibilities: \
'--all' '--almost-all' '--author'\n");
	else if (!ft_strcmp(arg, "-R"))
		ft_putstr(RECURSIVE_ERR);
	else if (!ft_strcmp(arg, "-t"))
		ft_putstr("ls: option '--t' is ambiguous; possibilities: \
'--tabsize' '--time' '--time-style'\n");
	ft_putstr(LS_HELP);
	ft_putchar(10);
	exit(1);
}

void		parse_flags(char *flags, char *arg, t_look *look)
{
	if (!(ft_strcmp(arg, "-")))
	{
		if (look->err_type == 0)
			look->err_type = 1;
		flags['1'] = 1;
	}
	else if (look->err_type == 0 && (!ft_strcmp(arg, "-r") ||
	!ft_strcmp(arg, "-a") || !ft_strcmp(arg, "-t") || !ft_strcmp(arg, "-R")))
		show_err_type_2(arg);
	else if (!(ft_strcmp(arg, "-l")))
		flags['1'] = 1;
	else
		while (*arg)
		{
			if (look->err_type == 0 && (*arg == 'l' || *arg == 'a'
			|| *arg == 'r' || *arg == 't' || *arg == 'R' || *arg == '1'))
				flags[(int)*arg] = 1;
			else if (look->err_type == 0)
			{
				printf("ls: invalid option -- '%c'\n%s\n", *arg, LS_HELP);
				exit(1);
			}
			arg++;
		}
}

void		handle_arg_files_dirs(t_look *look, char *arg)
{
	t_file			*new;
	t_stat			buff;
	char			type;

	if (!stat(arg, &buff) || !lstat(arg, &buff))
	{
		type = get_file_type_2(buff.st_mode);
		new = create_file(arg, type);
		if (new)
		{
			set_file_info(new, NULL, look);
			if (type == 'd')
				push_file(&(look->arg_dirs), new, look->cmp);
			else
				push_file(&(look->arg_files), new, look->cmp);
		}
	}
	else
		printf("ls: cannot access '%s': No such file or directory\n", arg);
	look->exist_args = 1;
}

void		parse_args(t_look *look, int argc, char **argv)
{
	int		i;
	char	min_min_one_passed;

	i = 0;
	min_min_one_passed = 0;
	while (++i < argc)
		if (argv[i][0] == '-')
			parse_flags(look->flags, argv[i] + 1, look);
	i = 0;
	find_sort_type(look);
	while (++i < argc)
	{
		if (!(ft_strcmp(argv[i], "--")) && !min_min_one_passed)
			min_min_one_passed = 1;
		else if (argv[i][0] == '-' && !(argv[i][1]))
		{
			ft_putstr("ls: cannot access '-': No such file or directory\n");
			look->exist_args = 1;
			look->err_type = 1;
		}
		else if (argv[i][0] != '-' || min_min_one_passed == 1)
			handle_arg_files_dirs(look, argv[i]);
	}
}
