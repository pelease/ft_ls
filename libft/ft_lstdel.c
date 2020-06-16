/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anime <anime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:37:30 by tgrandpa          #+#    #+#             */
/*   Updated: 2020/06/10 18:42:20 by anime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *f;
	t_list *x;

	if (!(alst && *alst && del))
		return ;
	f = *alst;
	while (f)
	{
		x = f->next;
		ft_lstdelone(&f, del);
		f = x;
	}
	*alst = NULL;
}
