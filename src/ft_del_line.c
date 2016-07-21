/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 13:34:21 by oexall            #+#    #+#             */
/*   Updated: 2016/07/12 15:23:56 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_del_list(char *value, t_list **begin_list)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *begin_list;
	prev = NULL;
	while (ft_strcmp(tmp->value, value) != 0 && tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->value, value) == 0)
	{
		if (prev)
			prev->next = tmp->next;
		else
			(*begin_list) = tmp->next;
		free(tmp);
	}
}

int		ft_del_line(t_main *all)
{
	t_list	*list;

	list = all->lst;
	while (list)
	{
		if (list->line == 1)
		{
			if (list->next)
				list->next->line = 1;
			else
				all->lst->line = 1;
			ft_del_list(list->value, &all->lst);
			return (1);
		}
		else
			list = list->next;
	}
	return (1);
}
