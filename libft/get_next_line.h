/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 04:31:16 by whybread          #+#    #+#             */
/*   Updated: 2020/06/10 20:50:05 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 15
# include <fcntl.h>
# include "libft.h"

int		get_next_line(int fd, char **line);
char	*make_line(char *stat_str, char *x, char **line);
char	*check_line(char *stat_str, char **x, int *ret, int fd);

#endif
