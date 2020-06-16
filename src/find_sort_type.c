/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sort_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 21:36:41 by anime             #+#    #+#             */
/*   Updated: 2020/06/11 01:58:31 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"

static int		sort_alpha(t_file *f1, t_file *f2)
{
	if (ft_strcmp(f1->name, f2->name) <= 0)
		return (1);
	return (0);
}

static int		sort_rev_alpha(t_file *f1, t_file *f2)
{
	if (ft_strcmp(f1->name, f2->name) >= 0)
		return (1);
	return (0);
}

static int		sort_alpha_time(t_file *f1, t_file *f2)
{
	if (f1->time - f2->time > 0)
		return (1);
	else if (f1->time - f2->time == 0)
	{
		if (f1->ntime - f2->ntime > 0)
			return (1);
		else if (f1->ntime - f2->ntime == 0)
			return (ft_strcmp(f1->name, f2->name) <= 0);
		else
			return (0);
	}
	else
		return (0);
}

static int		sort_rev_alpha_time(t_file *f1, t_file *f2)
{
	if (f1->time - f2->time < 0)
		return (1);
	else if (f1->time - f2->time == 0)
	{
		if (f1->ntime - f2->ntime < 0)
			return (1);
		else if (f1->ntime - f2->ntime == 0)
			return (ft_strcmp(f1->name, f2->name) >= 0);
		else
			return (0);
	}
	else
		return (0);
}

void			find_sort_type(t_look *look)
{
	if (look->flags['r'] && look->flags['t'])
		look->cmp = &sort_rev_alpha_time;
	else if (look->flags['t'])
		look->cmp = &sort_alpha_time;
	else if (look->flags['r'])
		look->cmp = &sort_rev_alpha;
	else
		look->cmp = &sort_alpha;
}
