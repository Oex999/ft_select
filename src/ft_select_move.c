/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 07:19:34 by oexall            #+#    #+#             */
/*   Updated: 2016/07/12 09:04:31 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_move_last(t_main *all)
{
	t_list	*list;

	list = all->lst;
	while (list)
	{
		list->line = 0;
		if (!(list->next))
			list->line = 1;
		list = list->next;
	}
}

void	ft_move_down(t_main *all)
{
	t_list	*list;

	list = all->lst;
	while (list)
	{
		if (list->line == 1)
		{
			list->line = 0;
			if (list->next)
				list->next->line = 1;
			else
				all->lst->line = 1;
			return ;
		}
		list = list->next;
	}
}

void	ft_move_up(t_main *all)
{
	t_list	*list;

	list = all->lst;
	while (list)
	{
		if (all->lst->line == 1 && all->lst->next->line == 0)
		{
			ft_move_last(all);
			return ;
		}
		else if (list->next && list->next->line == 1)
		{
			list->line = 1;
			list->next->line = 0;
			return ;
		}
		list = list->next;
	}
}
