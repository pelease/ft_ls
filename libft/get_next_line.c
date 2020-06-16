/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whybread <whybread@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:53:48 by mikim             #+#    #+#             */
/*   Updated: 2020/03/01 13:44:40 by whybread         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*make_line(char *stat_str, char *x, char **line)
{
	stat_str = ft_strchr(stat_str, 10);
	if (stat_str)
	{
		*line = ft_strsub(x, 0, ft_strlen(x) - ft_strlen(stat_str));
		stat_str = ft_strsub(stat_str + 1, 0, ft_strlen(stat_str + 1));
	}
	else
		*line = ft_strjoin("", x);
	free(x);
	return (stat_str);
}

char		*check_line(char *stat_str, char **x, int *ret, int fd)
{
	char			str[BUFF_SIZE + 1];

	if (!stat_str)
		stat_str = ft_strnew(1);
	while ((*ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[*ret] = 0;
		*x = ft_strjoin(stat_str, str);
		free(stat_str);
		stat_str = *x;
		if (ft_strchr(str, 10))
			break ;
	}
	return (stat_str);
}

int			get_next_line(const int fd, char **line)
{
	static char		*stat_str[10240];
	char			*x;
	int				ret;

	if (fd < 0 || fd > 10240 || !line)
		return (-1);
	if ((x = stat_str[fd]) && ft_strchr(stat_str[fd], 10))
		stat_str[fd] = make_line(stat_str[fd], x, line);
	else
	{
		stat_str[fd] = check_line(stat_str[fd], &x, &ret, fd);
		if (ret < 0)
			return (-1);
		if (ret == 0 && *stat_str[fd] == 0)
			return (0);
		stat_str[fd] = make_line(stat_str[fd], x, line);
	}
	return (1);
}
